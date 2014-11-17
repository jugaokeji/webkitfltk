/*
 * Copyright (C) 2008, 2014 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"
#include "DOMTimer.h"

#include "FrameView.h"
#include "HTMLPlugInElement.h"
#include "InspectorInstrumentation.h"
#include "Logging.h"
#include "PluginViewBase.h"
#include "ScheduledAction.h"
#include "ScriptExecutionContext.h"
#include "UserGestureIndicator.h"
#include <wtf/CurrentTime.h>
#include <wtf/HashSet.h>
#include <wtf/MathExtras.h>
#include <wtf/NeverDestroyed.h>
#include <wtf/StdLibExtras.h>

#if PLATFORM(IOS)
#include "Chrome.h"
#include "ChromeClient.h"
#include "Frame.h"
#include "Page.h"
#include "WKContentObservation.h"
#endif

namespace WebCore {

static const int maxIntervalForUserGestureForwarding = 1000; // One second matches Gecko.
static const int minIntervalForNonUserObservableChangeTimers = 1000; // Empirically determined to maximize battery life.
static const int maxTimerNestingLevel = 5;
static const double oneMillisecond = 0.001;

class DOMTimerFireState {
public:
    explicit DOMTimerFireState(ScriptExecutionContext& context)
        : m_context(context)
        , m_contextIsDocument(is<Document>(m_context))
    {
        // For worker threads, don't update the current DOMTimerFireState.
        // Setting this from workers would not be thread-safe, and its not relevant to current uses.
        if (m_contextIsDocument) {
            m_initialDOMTreeVersion = downcast<Document>(context).domTreeVersion();
            m_previous = current;
            current = this;
        }
    }

    ~DOMTimerFireState()
    {
        if (m_contextIsDocument)
            current = m_previous;
    }

    void setScriptMadeUserObservableChanges() { m_scriptMadeUserObservableChanges = true; }
    void setScriptMadeNonUserObservableChanges() { m_scriptMadeNonUserObservableChanges = true; }
    void setScriptMadeNonUserObservableChangesToElementStyle(StyledElement& element)
    {
        m_scriptMadeNonUserObservableChanges = true;
        m_elementsChangedOutsideViewport.add(&element);
    }

    bool scriptMadeNonUserObservableChanges() const { return m_scriptMadeNonUserObservableChanges; }
    bool scriptMadeUserObservableChanges() const
    {
        if (m_scriptMadeUserObservableChanges)
            return true;

        // To be conservative, we also consider any DOM Tree change to be user observable.
        return m_contextIsDocument && downcast<Document>(m_context).domTreeVersion() != m_initialDOMTreeVersion;
    }

    void setChangedStyleOfElementOutsideViewport(StyledElement& element)
    {
        m_elementsChangedOutsideViewport.add(&element);
    }

    void elementsChangedOutsideViewport(Vector<RefPtr<StyledElement>>& elements) const
    {
        copyToVector(m_elementsChangedOutsideViewport, elements);
    }

    static DOMTimerFireState* current;

private:
    ScriptExecutionContext& m_context;
    uint64_t m_initialDOMTreeVersion;
    DOMTimerFireState* m_previous;
    HashSet<RefPtr<StyledElement>> m_elementsChangedOutsideViewport;
    bool m_contextIsDocument;
    bool m_scriptMadeNonUserObservableChanges { false };
    bool m_scriptMadeUserObservableChanges { false };
};

DOMTimerFireState* DOMTimerFireState::current = nullptr;

struct NestedTimersMap {
    typedef HashMap<int, DOMTimer*>::const_iterator const_iterator;

    static NestedTimersMap* instanceForContext(ScriptExecutionContext& context)
    {
        // For worker threads, we don't use NestedTimersMap as doing so would not
        // be thread safe.
        if (is<Document>(context))
            return &instance();
        return nullptr;
    }

    void startTracking()
    {
        // Make sure we start with an empty HashMap. In theory, it is possible the HashMap is not
        // empty if a timer fires during the execution of another timer (may happen with the
        // in-process Web Inspector).
        nestedTimers.clear();
        isTrackingNestedTimers = true;
    }

    void stopTracking()
    {
        isTrackingNestedTimers = false;
        nestedTimers.clear();
    }

    void add(int timeoutId, DOMTimer* timer)
    {
        if (isTrackingNestedTimers)
            nestedTimers.add(timeoutId, timer);
    }

    void remove(int timeoutId)
    {
        if (isTrackingNestedTimers)
            nestedTimers.remove(timeoutId);
    }

    const_iterator begin() const { return nestedTimers.begin(); }
    const_iterator end() const { return nestedTimers.end(); }

private:
    static NestedTimersMap& instance()
    {
        static NeverDestroyed<NestedTimersMap> map;
        return map;
    }

    static bool isTrackingNestedTimers;
    HashMap<int /* timeoutId */, DOMTimer*> nestedTimers;
};

bool NestedTimersMap::isTrackingNestedTimers = false;

static inline bool shouldForwardUserGesture(int interval, int nestingLevel)
{
    return UserGestureIndicator::processingUserGesture()
        && interval <= maxIntervalForUserGestureForwarding
        && !nestingLevel; // Gestures should not be forwarded to nested timers.
}

DOMTimer::DOMTimer(ScriptExecutionContext& context, std::unique_ptr<ScheduledAction> action, int interval, bool singleShot)
    : SuspendableTimer(context)
    , m_nestingLevel(context.timerNestingLevel())
    , m_action(WTF::move(action))
    , m_originalInterval(interval)
    , m_throttleState(Undetermined)
    , m_currentTimerInterval(intervalClampedToMinimum())
    , m_shouldForwardUserGesture(shouldForwardUserGesture(interval, m_nestingLevel))
{
    RefPtr<DOMTimer> reference = adoptRef(this);

    // Keep asking for the next id until we're given one that we don't already have.
    do {
        m_timeoutId = context.circularSequentialID();
    } while (!context.addTimeout(m_timeoutId, reference));

    if (singleShot)
        startOneShot(m_currentTimerInterval);
    else
        startRepeating(m_currentTimerInterval);
}

DOMTimer::~DOMTimer()
{
    if (isIntervalDependentOnViewport())
        unregisterForViewportChanges();
}

int DOMTimer::install(ScriptExecutionContext& context, std::unique_ptr<ScheduledAction> action, int timeout, bool singleShot)
{
    // DOMTimer constructor passes ownership of the initial ref on the object to the constructor.
    // This reference will be released automatically when a one-shot timer fires, when the context
    // is destroyed, or if explicitly cancelled by removeById. 
    DOMTimer* timer = new DOMTimer(context, WTF::move(action), timeout, singleShot);
#if PLATFORM(IOS)
    if (is<Document>(context)) {
        Document& document = downcast<Document>(context);
        bool didDeferTimeout = document.frame() && document.frame()->timersPaused();
        if (!didDeferTimeout && timeout <= 100 && singleShot) {
            WKSetObservedContentChange(WKContentIndeterminateChange);
            WebThreadAddObservedContentModifier(timer); // Will only take affect if not already visibility change.
        }
    }
#endif

    timer->suspendIfNeeded();
    InspectorInstrumentation::didInstallTimer(&context, timer->m_timeoutId, timeout, singleShot);

    // Keep track of nested timer installs.
    if (NestedTimersMap* nestedTimers = NestedTimersMap::instanceForContext(context))
        nestedTimers->add(timer->m_timeoutId, timer);

    return timer->m_timeoutId;
}

void DOMTimer::removeById(ScriptExecutionContext& context, int timeoutId)
{
    // timeout IDs have to be positive, and 0 and -1 are unsafe to
    // even look up since they are the empty and deleted value
    // respectively
    if (timeoutId <= 0)
        return;

    if (NestedTimersMap* nestedTimers = NestedTimersMap::instanceForContext(context))
        nestedTimers->remove(timeoutId);

    InspectorInstrumentation::didRemoveTimer(&context, timeoutId);
    context.removeTimeout(timeoutId);
}

void DOMTimer::updateThrottlingStateIfNecessary(const DOMTimerFireState& fireState)
{
    if (fireState.scriptMadeUserObservableChanges()) {
        if (m_throttleState != ShouldNotThrottle) {
            m_throttleState = ShouldNotThrottle;
            ASSERT(m_elementsCausingThrottling.isEmpty());
            updateTimerIntervalIfNecessary();
        }
    } else if (fireState.scriptMadeNonUserObservableChanges()) {
        if (m_throttleState != ShouldThrottle) {
            m_throttleState = ShouldThrottle;
            fireState.elementsChangedOutsideViewport(m_elementsCausingThrottling);
            updateTimerIntervalIfNecessary();
        }
    }
}

void DOMTimer::scriptDidInteractWithPlugin(HTMLPlugInElement& pluginElement)
{
    if (!DOMTimerFireState::current)
        return;

    if (pluginElement.isUserObservable())
        DOMTimerFireState::current->setScriptMadeUserObservableChanges();
    else
        DOMTimerFireState::current->setScriptMadeNonUserObservableChanges();
}

void DOMTimer::scriptDidUpdateStyleOfElement(StyledElement& styledElement, bool changed)
{
    if (!DOMTimerFireState::current)
        return;

    if (!changed) {
        // The script set a CSS property on the Element but it did not cause any change.
        DOMTimerFireState::current->setScriptMadeNonUserObservableChanges();
        return;
    }

    if (styledElement.isInsideViewport())
        DOMTimerFireState::current->setScriptMadeUserObservableChanges();
    else
        DOMTimerFireState::current->setScriptMadeNonUserObservableChangesToElementStyle(styledElement);
}

void DOMTimer::fired()
{
    // Retain this - if the timer is cancelled while this function is on the stack (implicitly and always
    // for one-shot timers, or if removeById is called on itself from within an interval timer fire) then
    // wait unit the end of this function to delete DOMTimer.
    RefPtr<DOMTimer> reference = this;

    ASSERT(scriptExecutionContext());
    ScriptExecutionContext& context = *scriptExecutionContext();

    DOMTimerFireState fireState(context);
    if (isIntervalDependentOnViewport()) {
        // We re-evaluate if the timer interval is dependent on the viewport every time it fires.
        unregisterForViewportChanges();
    }

#if PLATFORM(IOS)
    Document* document = nullptr;
    if (is<Document>(context)) {
        document = &downcast<Document>(context);
        ASSERT(!document->frame()->timersPaused());
    }
#endif
    context.setTimerNestingLevel(std::min(m_nestingLevel + 1, maxTimerNestingLevel));

    ASSERT(!isSuspended());
    ASSERT(!context.activeDOMObjectsAreSuspended());
    UserGestureIndicator gestureIndicator(m_shouldForwardUserGesture ? DefinitelyProcessingUserGesture : PossiblyProcessingUserGesture);
    // Only the first execution of a multi-shot timer should get an affirmative user gesture indicator.
    m_shouldForwardUserGesture = false;

    InspectorInstrumentationCookie cookie = InspectorInstrumentation::willFireTimer(&context, m_timeoutId);

    // Simple case for non-one-shot timers.
    if (isActive()) {
        if (m_nestingLevel < maxTimerNestingLevel) {
            m_nestingLevel++;
            updateTimerIntervalIfNecessary();
        }

        m_action->execute(context);

        InspectorInstrumentation::didFireTimer(cookie);
        updateThrottlingStateIfNecessary(fireState);

        return;
    }

    context.removeTimeout(m_timeoutId);

#if PLATFORM(IOS)
    bool shouldReportLackOfChanges;
    bool shouldBeginObservingChanges;
    if (document) {
        shouldReportLackOfChanges = WebThreadCountOfObservedContentModifiers() == 1;
        shouldBeginObservingChanges = WebThreadContainsObservedContentModifier(this);
    } else {
        shouldReportLackOfChanges = false;
        shouldBeginObservingChanges = false;
    }

    if (shouldBeginObservingChanges) {
        WKBeginObservingContentChanges(false);
        WebThreadRemoveObservedContentModifier(this);
    }
#endif

    // Keep track nested timer installs.
    NestedTimersMap* nestedTimers = NestedTimersMap::instanceForContext(context);
    if (nestedTimers)
        nestedTimers->startTracking();

    m_action->execute(context);

#if PLATFORM(IOS)
    if (shouldBeginObservingChanges) {
        WKStopObservingContentChanges();

        if (WKObservedContentChange() == WKContentVisibilityChange || shouldReportLackOfChanges)
            if (document && document->page())
                document->page()->chrome().client().observedContentChange(document->frame());
    }
#endif

    InspectorInstrumentation::didFireTimer(cookie);

    // Check if we should throttle nested single-shot timers.
    if (nestedTimers) {
        for (auto& keyValue : *nestedTimers) {
            auto* timer = keyValue.value;
            if (timer->isActive() && !timer->repeatInterval())
                timer->updateThrottlingStateIfNecessary(fireState);
        }
        nestedTimers->stopTracking();
    }

    context.setTimerNestingLevel(0);
}

void DOMTimer::didStop()
{
    // Need to release JS objects potentially protected by ScheduledAction
    // because they can form circular references back to the ScriptExecutionContext
    // which will cause a memory leak.
    m_action = nullptr;
}

void DOMTimer::registerForViewportChanges()
{
    ASSERT(isIntervalDependentOnViewport());
    if (auto* frameView = downcast<Document>(*scriptExecutionContext()).view())
        frameView->registerThrottledDOMTimer(this);
}

void DOMTimer::unregisterForViewportChanges()
{
    if (auto* frameView = downcast<Document>(*scriptExecutionContext()).view())
        frameView->unregisterThrottledDOMTimer(this);

    m_elementsCausingThrottling.clear();
}

void DOMTimer::updateTimerIntervalIfNecessary()
{
    ASSERT(m_nestingLevel <= maxTimerNestingLevel);

    double previousInterval = m_currentTimerInterval;
    m_currentTimerInterval = intervalClampedToMinimum();

    if (WTF::areEssentiallyEqual(previousInterval, m_currentTimerInterval, oneMillisecond))
        return;

    // Timer was throttled / unthrottled, make sure we register / unregister
    // from the FrameView if the timer's interval is dependent on viewport.
    if (isIntervalDependentOnViewport())
        registerForViewportChanges();
    else if (m_throttleState == ShouldNotThrottle)
        unregisterForViewportChanges();

    if (repeatInterval()) {
        ASSERT(WTF::areEssentiallyEqual(repeatInterval(), previousInterval, oneMillisecond));
        LOG(DOMTimers, "%p - Updating DOMTimer's repeat interval from %g ms to %g ms due to throttling.", this, previousInterval * 1000., m_currentTimerInterval * 1000.);
        augmentRepeatInterval(m_currentTimerInterval - previousInterval);
    } else {
        LOG(DOMTimers, "%p - Updating DOMTimer's fire interval from %g ms to %g ms due to throttling.", this, previousInterval * 1000., m_currentTimerInterval * 1000.);
        augmentFireInterval(m_currentTimerInterval - previousInterval);
    }
}

void DOMTimer::updateThrottlingStateAfterViewportChange(const IntRect& visibleRect)
{
    ASSERT(isIntervalDependentOnViewport());
    // Check if the elements that caused this timer to be throttled are still outside the viewport.
    for (auto& element : m_elementsCausingThrottling) {
        // Skip elements that were removed from the document.
        if (!element->inDocument())
            continue;

        if (element->isInsideViewport(&visibleRect)) {
            LOG(DOMTimers, "%p - Script is changing style of an element that is now inside the viewport, unthrottling the timer.", this);
            m_throttleState = ShouldNotThrottle;
            updateTimerIntervalIfNecessary();
            break;
        }
    }
}

double DOMTimer::intervalClampedToMinimum() const
{
    ASSERT(scriptExecutionContext());
    ASSERT(m_nestingLevel <= maxTimerNestingLevel);

    double intervalInSeconds = std::max(oneMillisecond, m_originalInterval * oneMillisecond);

    // Only apply throttling to repeating timers.
    if (m_nestingLevel < maxTimerNestingLevel)
        return intervalInSeconds;

    // Apply two throttles - the global (per Page) minimum, and also a per-timer throttle.
    intervalInSeconds = std::max(intervalInSeconds, scriptExecutionContext()->minimumTimerInterval());
    if (m_throttleState == ShouldThrottle)
        intervalInSeconds = std::max(intervalInSeconds, minIntervalForNonUserObservableChangeTimers * oneMillisecond);
    return intervalInSeconds;
}

double DOMTimer::alignedFireTime(double fireTime) const
{
    double alignmentInterval = scriptExecutionContext()->timerAlignmentInterval();
    if (alignmentInterval) {
        double currentTime = monotonicallyIncreasingTime();
        if (fireTime <= currentTime)
            return fireTime;

        double alignedTime = ceil(fireTime / alignmentInterval) * alignmentInterval;
        return alignedTime;
    }

    return fireTime;
}

} // namespace WebCore

/*
 * Copyright (c) 2010, Google Inc. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ScrollAnimator_h
#define ScrollAnimator_h

#include "FloatSize.h"
#include "PlatformWheelEvent.h"
#include "ScrollTypes.h"
#include <wtf/FastMalloc.h>
#include <wtf/Forward.h>

#if ENABLE(CSS_SCROLL_SNAP) && PLATFORM(MAC)
#include "AxisScrollSnapAnimator.h"
#include "Timer.h"
#endif

namespace WebCore {

class FloatPoint;
class PlatformTouchEvent;
class ScrollableArea;
class Scrollbar;

#if ENABLE(CSS_SCROLL_SNAP) && PLATFORM(MAC)
class ScrollAnimator : public AxisScrollSnapAnimatorClient {
#else
class ScrollAnimator {
#endif
    WTF_MAKE_FAST_ALLOCATED;
public:
    static PassOwnPtr<ScrollAnimator> create(ScrollableArea*);

    virtual ~ScrollAnimator();

    // Computes a scroll destination for the given parameters.  Returns false if
    // already at the destination.  Otherwise, starts scrolling towards the
    // destination and returns true.  Scrolling may be immediate or animated.
    // The base class implementation always scrolls immediately, never animates.
    virtual bool scroll(ScrollbarOrientation, ScrollGranularity, float step, float multiplier);

    virtual void scrollToOffsetWithoutAnimation(const FloatPoint&);

    ScrollableArea* scrollableArea() const { return m_scrollableArea; }

    virtual bool handleWheelEvent(const PlatformWheelEvent&);

#if ENABLE(TOUCH_EVENTS)
    virtual bool handleTouchEvent(const PlatformTouchEvent&);
#endif

#if PLATFORM(COCOA)
    virtual void handleWheelEventPhase(PlatformWheelEventPhase) { }
#endif

    void setCurrentPosition(const FloatPoint&);
    FloatPoint currentPosition() const;

    virtual void cancelAnimations() { }
    virtual void serviceScrollAnimations() { }

    virtual void contentAreaWillPaint() const { }
    virtual void mouseEnteredContentArea() const { }
    virtual void mouseExitedContentArea() const { }
    virtual void mouseMovedInContentArea() const { }
    virtual void mouseEnteredScrollbar(Scrollbar*) const { }
    virtual void mouseExitedScrollbar(Scrollbar*) const { }
    virtual void willStartLiveResize() { }
    virtual void contentsResized() const { }
    virtual void willEndLiveResize() { }
    virtual void contentAreaDidShow() const { }
    virtual void contentAreaDidHide() const { }

    virtual void lockOverlayScrollbarStateToHidden(bool) { }
    virtual bool scrollbarsCanBeActive() const { return true; }

    virtual void didAddVerticalScrollbar(Scrollbar*) { }
    virtual void willRemoveVerticalScrollbar(Scrollbar*) { }
    virtual void didAddHorizontalScrollbar(Scrollbar*) { }
    virtual void willRemoveHorizontalScrollbar(Scrollbar*) { }

    virtual void verticalScrollbarLayerDidChange() { }
    virtual void horizontalScrollbarLayerDidChange() { }

    virtual bool shouldScrollbarParticipateInHitTesting(Scrollbar*) { return true; }

    virtual void notifyContentAreaScrolled(const FloatSize& delta) { UNUSED_PARAM(delta); }

    virtual bool isRubberBandInProgress() const { return false; }

#if ENABLE(CSS_SCROLL_SNAP) && PLATFORM(MAC)
    void processWheelEventForScrollSnap(const PlatformWheelEvent&);
    void updateScrollAnimatorsAndTimers();
    virtual LayoutUnit scrollOffsetInAxis(ScrollEventAxis) override;
    virtual void immediateScrollInAxis(ScrollEventAxis, float delta) override;
    virtual void startScrollSnapTimer(ScrollEventAxis) override;
    virtual void stopScrollSnapTimer(ScrollEventAxis) override;
#endif

protected:
    explicit ScrollAnimator(ScrollableArea*);

    virtual void notifyPositionChanged(const FloatSize& delta);

#if ENABLE(CSS_SCROLL_SNAP) && PLATFORM(MAC)
    // Trivial wrappers around the actual update loop in AxisScrollSnapAnimator, since WebCore Timer requires a Timer argument.
    void horizontalScrollSnapTimerFired();
    void verticalScrollSnapTimerFired();
#endif

    ScrollableArea* m_scrollableArea;
    float m_currentPosX; // We avoid using a FloatPoint in order to reduce
    float m_currentPosY; // subclass code complexity.
#if ENABLE(CSS_SCROLL_SNAP) && PLATFORM(MAC)
    std::unique_ptr<AxisScrollSnapAnimator> m_horizontalScrollSnapAnimator;
    std::unique_ptr<Timer> m_horizontalScrollSnapTimer;
    // FIXME: Find a way to consolidate both timers into one variable.
    std::unique_ptr<AxisScrollSnapAnimator> m_verticalScrollSnapAnimator;
    std::unique_ptr<Timer> m_verticalScrollSnapTimer;
#endif
};

} // namespace WebCore

#endif // ScrollAnimator_h

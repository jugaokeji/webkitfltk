/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GamepadManager_h
#define GamepadManager_h

#if ENABLE(GAMEPAD)

#include "GamepadProviderClient.h"
#include <wtf/HashSet.h>
#include <wtf/NeverDestroyed.h>
#include <wtf/RefPtr.h>

namespace WebCore {

class Gamepad;
class NavigatorGamepad;

class GamepadManager : public GamepadProviderClient {
    WTF_MAKE_NONCOPYABLE(GamepadManager);
    friend class NeverDestroyed<GamepadManager>;
public:
    static GamepadManager& shared();

    virtual void platformGamepadConnected(unsigned index) override final;
    virtual void platformGamepadDisconnected(unsigned index) override final;

    void registerNavigator(NavigatorGamepad*);
    void unregisterNavigator(NavigatorGamepad*);

private:
    GamepadManager();

    HashSet<NavigatorGamepad*> m_navigators;
};

} // namespace WebCore

#endif // ENABLE(GAMEPAD)
#endif // GamepadManager_h

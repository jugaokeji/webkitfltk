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

#include "config.h"
#include "AudioHardwareListenerMac.h"

#if PLATFORM(MAC)

#include <algorithm>

enum {
    kAudioHardwarePropertyProcessIsRunning = 'prun'
};

namespace WebCore {
    
static AudioHardwareActivityType isAudioHardwareProcessRunning()
{
    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwarePropertyProcessIsRunning,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMaster
    };
    
    if (!AudioObjectHasProperty(kAudioObjectSystemObject, &propertyAddress))
        return AudioHardwareActivityType::Unknown;
    
    UInt32 result = 0;
    UInt32 resultSize = sizeof(UInt32);

    if (AudioObjectGetPropertyData(kAudioObjectSystemObject, &propertyAddress, 0, 0, &resultSize, &result))
        return AudioHardwareActivityType::Unknown;

    if (result)
        return AudioHardwareActivityType::IsActive;
    else
        return AudioHardwareActivityType::IsInactive;
}
    
PassRefPtr<AudioHardwareListener> AudioHardwareListener::create(Client& client)
{
    return AudioHardwareListenerMac::create(client);
}

PassRefPtr<AudioHardwareListenerMac> AudioHardwareListenerMac::create(Client& client)
{
    return adoptRef(new AudioHardwareListenerMac(client));
}

AudioHardwareListenerMac::AudioHardwareListenerMac(Client& client)
    : AudioHardwareListener(client)
{
    m_activity = isAudioHardwareProcessRunning();
    if (hardwareActivity() == AudioHardwareActivityType::Unknown)
        return;

    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwarePropertyProcessIsRunning,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMaster
    };

    m_block = Block_copy(^(UInt32, const AudioObjectPropertyAddress[]) {
        setHardwareActive(isAudioHardwareProcessRunning());
    });

    AudioObjectAddPropertyListenerBlock(kAudioObjectSystemObject, &propertyAddress, dispatch_get_main_queue(), m_block);
}

AudioHardwareListenerMac::~AudioHardwareListenerMac()
{
    if (hardwareActivity() == AudioHardwareActivityType::Unknown)
        return;
    
    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwarePropertyProcessIsRunning,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMaster
    };

    AudioObjectAddPropertyListenerBlock(kAudioObjectSystemObject, &propertyAddress, dispatch_get_main_queue(), m_block);

    Block_release(m_block);
}

void AudioHardwareListenerMac::setHardwareActive(AudioHardwareActivityType activity)
{
    if (activity == m_activity)
        return;
    m_activity = activity;
    
    if (hardwareActivity() == AudioHardwareActivityType::IsActive)
        m_client.audioHardwareDidBecomeActive();
    else if (hardwareActivity() == AudioHardwareActivityType::IsInactive)
        m_client.audioHardwareDidBecomeInactive();
}

}

#endif

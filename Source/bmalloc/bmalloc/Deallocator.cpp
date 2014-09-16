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
 */

#include "BAssert.h"
#include "BeginTag.h"
#include "LargeChunk.h"
#include "Deallocator.h"
#include "Heap.h"
#include "Inline.h"
#include "PerProcess.h"
#include "SmallChunk.h"
#include <algorithm>
#include <sys/mman.h>

using namespace std;

namespace bmalloc {

Deallocator::Deallocator()
{
}

Deallocator::~Deallocator()
{
    scavenge();
}
    
void Deallocator::scavenge()
{
    processObjectLog();
}

void Deallocator::deallocateLarge(void* object)
{
    std::lock_guard<StaticMutex> lock(PerProcess<Heap>::mutex());
    PerProcess<Heap>::getFastCase()->deallocateLarge(lock, object);
}

void Deallocator::deallocateXLarge(void* object)
{
    std::lock_guard<StaticMutex> lock(PerProcess<Heap>::mutex());
    PerProcess<Heap>::getFastCase()->deallocateXLarge(lock, object);
}

void Deallocator::processObjectLog()
{
    std::lock_guard<StaticMutex> lock(PerProcess<Heap>::mutex());
    Heap* heap = PerProcess<Heap>::getFastCase();
    
    for (auto object : m_objectLog) {
        if (isSmall(object)) {
            SmallLine* line = SmallLine::get(object);
            if (!line->deref(lock))
                continue;
            heap->deallocateSmallLine(lock, line);
        } else {
            BASSERT(isSmallOrMedium(object));
            MediumLine* line = MediumLine::get(object);
            if (!line->deref(lock))
                continue;
            heap->deallocateMediumLine(lock, line);
        }
    }
    
    m_objectLog.clear();
}

void Deallocator::deallocateSlowCase(void* object)
{
    BASSERT(!deallocateFastCase(object));

    if (!object)
        return;

    if (isSmallOrMedium(object)) {
        processObjectLog();
        m_objectLog.push(object);
        return;
    }

    BeginTag* beginTag = LargeChunk::beginTag(object);
    if (!beginTag->isXLarge())
        return deallocateLarge(object);
    
    return deallocateXLarge(object);
}

} // namespace bmalloc

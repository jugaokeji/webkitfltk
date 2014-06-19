/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef BlobRegistryImpl_h
#define BlobRegistryImpl_h

#include "BlobData.h"
#include "BlobRegistry.h"
#include <wtf/HashMap.h>
#include <wtf/text/StringHash.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class URL;
class ResourceHandle;
class ResourceHandleClient;
class ResourceRequest;

// BlobRegistryImpl is not thread-safe. It should only be called from main thread.
class BlobRegistryImpl final : public BlobRegistry {
    WTF_MAKE_FAST_ALLOCATED;
public:
    virtual ~BlobRegistryImpl();

    BlobData* getBlobDataFromURL(const URL&) const;

    PassRefPtr<ResourceHandle> createResourceHandle(const ResourceRequest&, ResourceHandleClient*);

private:
    void appendStorageItems(BlobData*, const BlobDataItemList&, long long offset, long long length);

    virtual void registerFileBlobURL(const WebCore::URL&, PassRefPtr<BlobDataFileReference>, const String& contentType) override;
    virtual void registerBlobURL(const URL&, Vector<BlobPart>, const String& contentType) override;
    virtual void registerBlobURL(const URL&, const URL& srcURL) override;
    virtual void registerBlobURLForSlice(const URL&, const URL& srcURL, long long start, long long end) override;
    virtual void unregisterBlobURL(const URL&) override;
    virtual bool isBlobRegistryImpl() const override { return true; }

    virtual unsigned long long blobSize(const URL&) override;

    HashMap<String, RefPtr<BlobData>> m_blobs;
};

} // namespace WebCore

#endif // BlobRegistryImpl_h

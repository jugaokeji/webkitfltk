/*
 * Copyright (C) 2006, 2007, 2008, 2013 Apple Inc. All rights reserved.
 * Copyright (C) Research In Motion Limited 2011. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GlyphPage_h
#define GlyphPage_h

#include "Glyph.h"
#include <string.h>
#include <unicode/utypes.h>
#include <wtf/PassRefPtr.h>
#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>

namespace WebCore {

class SimpleFontData;

// Holds the glyph index and the corresponding SimpleFontData information for a given
// character.
struct GlyphData {
    GlyphData(Glyph g = 0, const SimpleFontData* f = 0)
        : glyph(g)
        , fontData(f)
    {
    }
    Glyph glyph;
    const SimpleFontData* fontData;
};

#if COMPILER(MSVC)
#pragma warning(push)
#pragma warning(disable: 4200) // Disable "zero-sized array in struct/union" warning
#endif

// A GlyphPage contains a fixed-size set of GlyphData mappings for a contiguous
// range of characters in the Unicode code space. GlyphPages are indexed
// starting from 0 and incrementing for each 256 glyphs.
//
// One page may actually include glyphs from other fonts if the characters are
// missing in the primary font.
class GlyphPage : public RefCounted<GlyphPage> {
public:
    static PassRefPtr<GlyphPage> createForMixedFontData()
    {
        void* slot = fastMalloc(sizeof(GlyphPage) + sizeof(SimpleFontData*) * GlyphPage::size);
        return adoptRef(new (NotNull, slot) GlyphPage(nullptr));
    }

    static PassRefPtr<GlyphPage> createCopyForMixedFontData(const GlyphPage& original)
    {
        RefPtr<GlyphPage> page = createForMixedFontData();
        for (unsigned i = 0; i < GlyphPage::size; ++i)
            page->setGlyphDataForIndex(i, original.glyphDataForIndex(i));
        return page.release();
    }

    static PassRefPtr<GlyphPage> createForSingleFontData(const SimpleFontData* fontData)
    {
        ASSERT(fontData);
        return adoptRef(new GlyphPage(fontData));
    }

    ~GlyphPage()
    {
        --s_count;
    }

    bool isImmutable() const { return m_isImmutable; }
    void setImmutable() { m_isImmutable = true; }

    static unsigned count() { return s_count; }

    static const size_t size = 256; // Covers Latin-1 in a single page.
    static_assert((!(0xD800 % size)) && (!(0xDC00 % size)) && (!(0xE000 % size)), "GlyphPages must never straddle code-unit length boundaries");
    static unsigned indexForCharacter(UChar32 c) { return c % GlyphPage::size; }

    ALWAYS_INLINE GlyphData glyphDataForCharacter(UChar32 c) const
    {
        return glyphDataForIndex(indexForCharacter(c));
    }

    ALWAYS_INLINE GlyphData glyphDataForIndex(unsigned index) const
    {
        ASSERT_WITH_SECURITY_IMPLICATION(index < size);
        Glyph glyph = m_glyphs[index];
        if (hasPerGlyphFontData())
            return GlyphData(glyph, m_perGlyphFontData[index]);
        return GlyphData(glyph, glyph ? m_fontDataForAllGlyphs : 0);
    }

    ALWAYS_INLINE Glyph glyphAt(unsigned index) const
    {
        ASSERT_WITH_SECURITY_IMPLICATION(index < size);
        return m_glyphs[index];
    }

    ALWAYS_INLINE const SimpleFontData* fontDataForCharacter(UChar32 c) const
    {
        unsigned index = indexForCharacter(c);
        if (hasPerGlyphFontData())
            return m_perGlyphFontData[index];
        return m_glyphs[index] ? m_fontDataForAllGlyphs : 0;
    }

    void setGlyphDataForCharacter(UChar32 c, Glyph g, const SimpleFontData* f)
    {
        setGlyphDataForIndex(indexForCharacter(c), g, f);
    }

    void setGlyphDataForIndex(unsigned index, Glyph glyph, const SimpleFontData* fontData)
    {
        ASSERT_WITH_SECURITY_IMPLICATION(index < size);
        ASSERT(!m_isImmutable);
        
        m_glyphs[index] = glyph;

        // GlyphPage getters will always return a null SimpleFontData* for glyph #0 if there's no per-glyph font array.
        if (hasPerGlyphFontData()) {
            m_perGlyphFontData[index] = glyph ? fontData : 0;
            return;
        }

        // A single-font GlyphPage already assigned m_fontDataForAllGlyphs in the constructor.
        ASSERT(!glyph || fontData == m_fontDataForAllGlyphs);
    }

    void setGlyphDataForIndex(unsigned index, const GlyphData& glyphData)
    {
        setGlyphDataForIndex(index, glyphData.glyph, glyphData.fontData);
    }

    // Implemented by the platform.
    bool fill(unsigned offset, unsigned length, UChar* characterBuffer, unsigned bufferLength, const SimpleFontData*);
#if PLATFORM(COCOA)
    static bool mayUseMixedFontDataWhenFilling(const UChar* characterBuffer, unsigned bufferLength, const SimpleFontData*);
#else
    static bool mayUseMixedFontDataWhenFilling(const UChar*, unsigned, const SimpleFontData*) { return false; }
#endif

private:
    explicit GlyphPage(const SimpleFontData* fontDataForAllGlyphs)
        : m_fontDataForAllGlyphs(fontDataForAllGlyphs)
    {
        memset(m_glyphs, 0, sizeof(m_glyphs));
        if (hasPerGlyphFontData())
            memset(m_perGlyphFontData, 0, sizeof(SimpleFontData*) * GlyphPage::size);
        ++s_count;
    }

    bool hasPerGlyphFontData() const { return !m_fontDataForAllGlyphs; }

    const SimpleFontData* m_fontDataForAllGlyphs;
    Glyph m_glyphs[size];

    bool m_isImmutable { false };
    // NOTE: This array has (GlyphPage::size) elements if m_fontDataForAllGlyphs is null.
    const SimpleFontData* m_perGlyphFontData[0];

    static unsigned s_count;
};

#if COMPILER(MSVC)
#pragma warning(pop)
#endif

} // namespace WebCore

#endif // GlyphPage_h

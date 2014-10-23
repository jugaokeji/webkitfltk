#! /usr/bin/perl
#
#   This file is part of the WebKit project
#
#   Copyright (C) 1999 Waldo Bastian (bastian@kde.org)
#   Copyright (C) 2007, 2008, 2012, 2014 Apple Inc. All rights reserved.
#   Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)
#   Copyright (C) 2010 Andras Becsi (abecsi@inf.u-szeged.hu), University of Szeged
#   Copyright (C) 2013 Google Inc. All rights reserved.
#
#   This library is free software; you can redistribute it and/or
#   modify it under the terms of the GNU Library General Public
#   License as published by the Free Software Foundation; either
#   version 2 of the License, or (at your option) any later version.
#
#   This library is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   Library General Public License for more details.
#
#   You should have received a copy of the GNU Library General Public License
#   along with this library; see the file COPYING.LIB.  If not, write to
#   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
#   Boston, MA 02110-1301, USA.
use Getopt::Long;
use preprocessor;
use strict;
use warnings;

my $defines;
my $preprocessor;
GetOptions('defines=s' => \$defines,
           'preprocessor=s' => \$preprocessor);

my @NAMES = applyPreprocessor("CSSPropertyNames.in", $defines, $preprocessor);
die "We've reached more than 1024 CSS properties, please make sure to update CSSProperty/StylePropertyMetadata accordingly" if (scalar(@NAMES) > 1024);

my %namesHash;
my @duplicates = ();

my $numPredefinedProperties = 1;
my @names = ();
my %nameIsInherited;
# FIXME: Eventually all properties should use the new style builder and the following
# variable should go away.
my %propertiesUsingNewStyleBuilder;
my %newStyleBuilderOptions = (
  Converter => 1, # Defined in Source/WebCore/css/StyleBuilderConverter.h
  Getter => 1,
  Initial => 1,
  NameForMethods => 1,
  Setter => 1,
  TypeName => 1,
);
my %nameToId;
my @aliases = ();
foreach (@NAMES) {
  next if (m/(^\s*$)/);
  next if (/^#/);

  # Input may use a different EOL sequence than $/, so avoid chomp.
  $_ =~ s/\s*\[(.+?)\]\r?$//;
  my @options = ();
  if ($1) {
    @options = split(/\s*,\s*/, $1);
  }

  $_ =~ s/[\r\n]+$//g;
  if (exists $namesHash{$_}) {
    push @duplicates, $_;
  } else {
    $namesHash{$_} = 1;
  }
  if ($_ =~ /=/) {
    if (@options) {
        die "Options are specified on an alias $_: ", join(", ", @options) . "\n";
    }
    push @aliases, $_;
  } else {
    $nameIsInherited{$_} = 0;
    foreach my $option (@options) {
      my ($optionName, $optionValue) = split(/=/, $option);
      if ($optionName eq "Inherited") {
        $nameIsInherited{$_} = 1;
      } elsif ($optionName eq "NewStyleBuilder") {
        # FIXME: This is temporary. Eventually, all properties will use the new
        # style builder and this option will go away.
        $propertiesUsingNewStyleBuilder{$_} = {};
      } elsif ($newStyleBuilderOptions{$optionName}) {
        die "\"" . $optionName . "\" option was used without \"NewStyleBuilder\" option for " . $_ . " property." if not exists($propertiesUsingNewStyleBuilder{$_});
        $propertiesUsingNewStyleBuilder{$_}{$optionName} = $optionValue;
      } else {
        die "Unrecognized \"" . $optionName . "\" option for " . $_ . " property.";
      }
    }

    my $id = $_;
    $id =~ s/(^[^-])|-(.)/uc($1||$2)/ge;
    $nameToId{$_} = $id;

    push @names, $_;
  }
}

if (@duplicates > 0) {
    die 'Duplicate CSS property names: ', join(', ', @duplicates) . "\n";
}

open GPERF, ">CSSPropertyNames.gperf" || die "Could not open CSSPropertyNames.gperf for writing";
print GPERF << "EOF";
%{
/* This file is automatically generated from CSSPropertyNames.in by makeprop, do not edit */
#include "config.h"
#include \"CSSProperty.h\"
#include \"CSSPropertyNames.h\"
#include \"HashTools.h\"
#include <string.h>

#include <wtf/ASCIICType.h>
#include <wtf/text/AtomicString.h>
#include <wtf/text/WTFString.h>

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored \"-Wunknown-pragmas\"
#pragma clang diagnostic ignored \"-Wdeprecated-register\"
#pragma clang diagnostic ignored \"-Wimplicit-fallthrough\"
#endif

namespace WebCore {
EOF

print GPERF "const char* const propertyNameStrings[numCSSProperties] = {\n";
foreach my $name (@names) {
  print GPERF "    \"$name\",\n";
}
print GPERF "};\n\n";

print GPERF << "EOF";
%}
%struct-type
struct Property;
%omit-struct-type
%language=C++
%readonly-tables
%global-table
%compare-strncmp
%define class-name CSSPropertyNamesHash
%define lookup-function-name findPropertyImpl
%define hash-function-name propery_hash_function
%define word-array-name property_wordlist
%enum
%%
EOF

foreach my $name (@names) {
  print GPERF $name . ", CSSProperty" . $nameToId{$name} . "\n";
}

foreach my $alias (@aliases) {
  $alias =~ /^([^\s]*)[\s]*=[\s]*([^\s]*)/;
  my $name = $1;
  print GPERF $name . ", CSSProperty" . $nameToId{$2} . "\n";
}

print GPERF<< "EOF";
%%
const Property* findProperty(const char* str, unsigned int len)
{
    return CSSPropertyNamesHash::findPropertyImpl(str, len);
}

const char* getPropertyName(CSSPropertyID id)
{
    if (id < firstCSSProperty)
        return 0;
    int index = id - firstCSSProperty;
    if (index >= numCSSProperties)
        return 0;
    return propertyNameStrings[index];
}

const AtomicString& getPropertyNameAtomicString(CSSPropertyID id)
{
    if (id < firstCSSProperty)
        return nullAtom;
    int index = id - firstCSSProperty;
    if (index >= numCSSProperties)
        return nullAtom;

    static AtomicString* propertyStrings = new AtomicString[numCSSProperties]; // Intentionally never destroyed.
    AtomicString& propertyString = propertyStrings[index];
    if (propertyString.isNull()) {
        const char* propertyName = propertyNameStrings[index];
        propertyString = AtomicString(propertyName, strlen(propertyName), AtomicString::ConstructFromLiteral);
    }
    return propertyString;
}

String getPropertyNameString(CSSPropertyID id)
{
    // We share the StringImpl with the AtomicStrings.
    return getPropertyNameAtomicString(id).string();
}

String getJSPropertyName(CSSPropertyID id)
{
    char result[maxCSSPropertyNameLength + 1];
    const char* cssPropertyName = getPropertyName(id);
    const char* propertyNamePointer = cssPropertyName;
    if (!propertyNamePointer)
        return emptyString();

    char* resultPointer = result;
    while (char character = *propertyNamePointer++) {
        if (character == '-') {
            char nextCharacter = *propertyNamePointer++;
            if (!nextCharacter)
                break;
            character = (propertyNamePointer - 2 != cssPropertyName) ? toASCIIUpper(nextCharacter) : nextCharacter;
        }
        *resultPointer++ = character;
    }
    *resultPointer = '\\0';
    return WTF::String(result);
}

static const bool isInheritedPropertyTable[numCSSProperties + $numPredefinedProperties] = {
    false, // CSSPropertyInvalid
EOF

foreach my $name (@names) {
  my $id = $nameToId{$name};
  my $value = $nameIsInherited{$name} ? "true " : "false";
  print GPERF "    $value, // CSSProperty$id\n";
}

print GPERF<< "EOF";
};

bool CSSProperty::isInheritedProperty(CSSPropertyID id)
{
    ASSERT(id >= 0 && id <= lastCSSProperty);
    ASSERT(id != CSSPropertyInvalid);
    return isInheritedPropertyTable[id];
}

} // namespace WebCore

#if defined(__clang__)
#pragma clang diagnostic pop
#endif
EOF

open HEADER, ">CSSPropertyNames.h" || die "Could not open CSSPropertyNames.h for writing";
print HEADER << "EOF";
/* This file is automatically generated from CSSPropertyNames.in by makeprop, do not edit */

#ifndef CSSPropertyNames_h
#define CSSPropertyNames_h

#include <string.h>
#include <wtf/HashFunctions.h>
#include <wtf/HashTraits.h>

namespace WTF {
class AtomicString;
class String;
}

namespace WebCore {

enum CSSPropertyID {
    CSSPropertyInvalid = 0,
EOF

my $first = $numPredefinedProperties;
my $i = $numPredefinedProperties;
my $maxLen = 0;
foreach my $name (@names) {
  print HEADER "    CSSProperty" . $nameToId{$name} . " = " . $i . ",\n";
  $i = $i + 1;
  if (length($name) > $maxLen) {
    $maxLen = length($name);
  }
}
my $num = $i - $first;
my $last = $i - 1;

print HEADER "};\n\n";
print HEADER "const int firstCSSProperty = $first;\n";
print HEADER "const int numCSSProperties = $num;\n";
print HEADER "const int lastCSSProperty = $last;\n";
print HEADER "const size_t maxCSSPropertyNameLength = $maxLen;\n";

print HEADER << "EOF";

const char* getPropertyName(CSSPropertyID);
const WTF::AtomicString& getPropertyNameAtomicString(CSSPropertyID id);
WTF::String getPropertyNameString(CSSPropertyID id);
WTF::String getJSPropertyName(CSSPropertyID);

inline CSSPropertyID convertToCSSPropertyID(int value)
{
    ASSERT((value >= firstCSSProperty && value <= lastCSSProperty) || value == CSSPropertyInvalid);
    return static_cast<CSSPropertyID>(value);
}

} // namespace WebCore

namespace WTF {
template<> struct DefaultHash<WebCore::CSSPropertyID> { typedef IntHash<unsigned> Hash; };
template<> struct HashTraits<WebCore::CSSPropertyID> : GenericHashTraits<WebCore::CSSPropertyID> {
    static const bool emptyValueIsZero = true;
    static const bool needsDestruction = false;
    static void constructDeletedValue(WebCore::CSSPropertyID& slot) { slot = static_cast<WebCore::CSSPropertyID>(WebCore::lastCSSProperty + 1); }
    static bool isDeletedValue(WebCore::CSSPropertyID value) { return value == (WebCore::lastCSSProperty + 1); }
};
}

#endif // CSSPropertyNames_h

EOF

close HEADER;

#
# StyleBuilder.cpp generator.
#

foreach my $name (@names) {
  # Skip properties not using the new style builder yet.
  next unless exists($propertiesUsingNewStyleBuilder{$name});

  my $nameForMethods = $nameToId{$name};
  $nameForMethods =~ s/Webkit//g;
  if (exists($propertiesUsingNewStyleBuilder{$name}{"NameForMethods"})) {
    $nameForMethods = $propertiesUsingNewStyleBuilder{$name}{"NameForMethods"};
  }

  if (!exists($propertiesUsingNewStyleBuilder{$name}{"TypeName"})) {
    $propertiesUsingNewStyleBuilder{$name}{"TypeName"} = "E" . $nameForMethods;
  }
  if (!exists($propertiesUsingNewStyleBuilder{$name}{"Getter"})) {
    $propertiesUsingNewStyleBuilder{$name}{"Getter"} = lcfirst($nameForMethods);
  }
  if (!exists($propertiesUsingNewStyleBuilder{$name}{"Setter"})) {
    $propertiesUsingNewStyleBuilder{$name}{"Setter"} = "set" . $nameForMethods;
  }
  if (!exists($propertiesUsingNewStyleBuilder{$name}{"Initial"})) {
    $propertiesUsingNewStyleBuilder{$name}{"Initial"} = "initial" . $nameForMethods;
  }
}

open STYLEBUILDER, ">StyleBuilder.cpp" || die "Could not open StyleBuilder.cpp for writing";
print STYLEBUILDER << "EOF";
/* This file is automatically generated from CSSPropertyNames.in by makeprop, do not edit */

#include "config.h"
#include "StyleBuilder.h"

#include "CSSPrimitiveValueMappings.h"
#include "CSSProperty.h"
#include "RenderStyle.h"
#include "StyleBuilderConverter.h"
#include "StyleResolver.h"

namespace WebCore {

class StyleBuilderFunctions {
public:
EOF

foreach my $name (@names) {
  # Skip properties not using the new style builder yet.
  next unless exists($propertiesUsingNewStyleBuilder{$name});

  my $setValue = "styleResolver.style()->" . $propertiesUsingNewStyleBuilder{$name}{"Setter"};
  print STYLEBUILDER "    static void applyInitial" . $nameToId{$name} . "(StyleResolver& styleResolver)\n";
  print STYLEBUILDER "    {\n";
  print STYLEBUILDER "        " . $setValue . "(RenderStyle::" . $propertiesUsingNewStyleBuilder{$name}{"Initial"} . "());\n";
  print STYLEBUILDER "    }\n";
  print STYLEBUILDER "    static void applyInherit" . $nameToId{$name} . "(StyleResolver& styleResolver)\n";
  print STYLEBUILDER "    {\n";
  print STYLEBUILDER "        " . $setValue . "(styleResolver.parentStyle()->" .  $propertiesUsingNewStyleBuilder{$name}{"Getter"} . "());\n";
  print STYLEBUILDER "    }\n";
  print STYLEBUILDER "    static void applyValue" . $nameToId{$name} . "(StyleResolver& styleResolver, CSSValue& value)\n";
  print STYLEBUILDER "    {\n";
  my $convertedValue;
  if (exists($propertiesUsingNewStyleBuilder{$name}{"Converter"})) {
    $convertedValue = "StyleBuilderConverter::convert" . $propertiesUsingNewStyleBuilder{$name}{"Converter"} . "(styleResolver, value)";
  } else {
    $convertedValue = "static_cast<" . $propertiesUsingNewStyleBuilder{$name}{"TypeName"} . ">(downcast<CSSPrimitiveValue>(value))";
  }
  print STYLEBUILDER "        " . $setValue . "(" . $convertedValue . ");\n";
  print STYLEBUILDER "    }\n";
}

print STYLEBUILDER << "EOF";
};

bool StyleBuilder::applyProperty(CSSPropertyID property, StyleResolver& styleResolver, CSSValue& value, bool isInitial, bool isInherit)
{
    switch (property) {
EOF

foreach my $name (@names) {
  # Skip properties not using the new style builder yet.
  next unless exists($propertiesUsingNewStyleBuilder{$name});

  print STYLEBUILDER "    case CSSProperty" . $nameToId{$name} . ":\n";
  print STYLEBUILDER "        if (isInitial)\n";
  print STYLEBUILDER "            StyleBuilderFunctions::applyInitial" . $nameToId{$name} . "(styleResolver);\n";
  print STYLEBUILDER "        else if (isInherit)\n";
  print STYLEBUILDER "            StyleBuilderFunctions::applyInherit" . $nameToId{$name} . "(styleResolver);\n";
  print STYLEBUILDER "        else\n";
  print STYLEBUILDER "            StyleBuilderFunctions::applyValue" . $nameToId{$name} . "(styleResolver, value);\n";
  print STYLEBUILDER "        return true;\n";
}

print STYLEBUILDER << "EOF";
        default:
            return false;
    };
}

} // namespace WebCore
EOF

close STYLEBUILDER;

my $gperf = $ENV{GPERF} ? $ENV{GPERF} : "gperf";
system("\"$gperf\" --key-positions=\"*\" -D -n -s 2 CSSPropertyNames.gperf --output-file=CSSPropertyNames.cpp") == 0 || die "calling gperf failed: $?";

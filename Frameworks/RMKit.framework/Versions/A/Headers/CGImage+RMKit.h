//***************************************************************************

// Copyright (C) 2008 Realmac Software Ltd
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//***************************************************************************

#pragma once

//***************************************************************************

#include <ApplicationServices/ApplicationServices.h>
#import <AppKit/AppKit.h>

/// Creates a CGImageRef from a given NSImage, with the given final size.  The returned CGImageRef follows the standard Core Foundation "create" rule (i.e. the caller owns it and is responsible for releasing it).
CGImageRef CGImageCreateWithNSImage(NSImage* image, const CGSize size);

/// Similar to CGImageCreateCopyWithColorSpace(), but re-interprets the image's color space in the destination color space rather than doing a raw copy.
CGImageRef CGImageCreateCopyConvertingToColorSpace(CGImageRef const image, CGColorSpaceRef const colorSpace);

CGImageSourceRef CGImageSourceCreateWithCGImage(CGImageRef const image);

//***************************************************************************

/// Transforms the given imageSource to the imageDestination, using the given transformation properties.
/** Note that you still need to manully invoke CGImageDestinationFinalize() on the imageDestination. */
bool CGImageTransform(CGImageSourceRef const imageSource, CFDictionaryRef const transformProperties, CGImageDestinationRef const imageDestination, CFDictionaryRef const destinationImageProperties);

extern CFStringRef const kCGImageTransformToThumbnailMaximumDimension;	// NSNumber*
extern CFStringRef const kCGImageTransformToCGColorSpace;	// CGColorSpaceRef
extern CFStringRef const kCGImageTransformToNSColorSpace;	// NSColorSpace*

//***************************************************************************

/// Appends a rounded rectangle to a mutable graphics path.
void CGPathAddRoundedRect(CGContextRef context, const CGRect rect, const CGSize cornerSize);

/// Paints a rounded rectangle path.
void CGContextStrokeRoundedRect(CGContextRef context, const CGRect rect, const CGSize cornerSize);

//***************************************************************************

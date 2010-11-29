//***************************************************************************

// Copyright (C) 2005-2008 Realmac Software Pty Ltd
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

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface NSImage (ImageFromWebPage)

/// Returns an NSImage that is a snapshot of the webpage at the given URL.
/** The simulated Web browser has a viewing size of 800x600.  This would be
  * trivially customisable, but, well, we haven't needed to change it yet.
  * You also have to specify a string encoding for now... */
+ (NSImage*)imageFromWebPageAtURL:(NSURL*)url encoding:(NSStringEncoding)encoding;

@end

//***************************************************************************

@interface NSImage (ImageNamedInBundle)

+ (NSImage*)imageNamed:(NSString*)name bundle:(NSBundle*)bundle;

@end

//***************************************************************************

@interface NSImage (CIImage)

- (NSImage*)croppedImageFromRect:(NSRect)rect;

- (NSBitmapImageRep*)fastBitmapImageRepresentation;
- (NSBitmapImageRep*)bitmapImageRepresentation;

- (CIImage*)CIImage;
- (NSImage*)initWithCIImage:(CIImage*)image;
+ (NSImage*)imageWithCIImage:(CIImage*)image;

@end

//***************************************************************************

@interface NSImage (UTI)

+ (NSString*)UTIForImageData:(NSData*)imageData;

@end

//***************************************************************************

@interface NSImage (RWImage)

- (NSSize)fullResolutionSize;
- (BOOL)isJPEGImage;

@end

//***************************************************************************

@interface RWImageIO : NSObject

+ (BOOL)available;

// Renamed the method to respect proper Cocoa naming conventions.
// Please update your code to use the non-deprecated method.
// Note: The caller is responsible for releasing the image with CFRelease() or CGImageRelease().
+ (CGImageRef)imageFromFile:(NSString*)path DEPRECATED_ATTRIBUTE;
+ (CGImageRef)newImageFromFile:(NSString*)path;

// Renamed the method to respect proper Cocoa naming conventions.
// Please update your code to use the non-deprecated method.
// Note: The caller is responsible for releasing the image with CFRelease() or CGImageRelease().
+ (CGImageRef)thumbnailFromFile:(NSString*)path size:(NSInteger)size DEPRECATED_ATTRIBUTE;
+ (CGImageRef)newThumbnailFromFile:(NSString*)path size:(NSInteger)size;
+ (NSDictionary*)propertiesFromFile:(NSString*)path;

+ (NSImage*)imageFromCGImage:(CGImageRef)image;

+ (BOOL)writeImage:(NSImage*)image to:(NSString*)path as:(NSString*)format;

@end

//***************************************************************************

@interface NSImage (RWTransformImage)

- (NSImage*)transformImageUsingAttributes:(NSDictionary*)attributes;
- (NSImage*)transformImageUsingAttributesAndScreenResolution:(NSDictionary*)attributes;

@end

//***************************************************************************

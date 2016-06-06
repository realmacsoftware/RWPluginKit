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

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface RWQTExport : NSObject {
	NSString* _path;
	NSString* _source;
	NSData* _data;
	NSColor* _fillColour;
	NSBitmapImageFileType _format;
	NSInteger _quality;
	OSStatus _status;
	CGFloat _width, _height;
	BOOL _hqScaling;
	BOOL _flipHorizontally;
	BOOL _flipVertically;
	BOOL _clip;
	BOOL _squareImage;
	CGFloat _shadowOffset;
	CGFloat _shadowBlur;
	NSColor* _shadowColour;
	CGFloat _rotation;
	NSDictionary* _attributes;
	CGImageSourceRef _sourceImage;
	BOOL _ignoreOrientation;
}

enum {
	RWExportQualityLossless = 0,
	RWExportQualityHigh,
	RWExportQualityMedium,
	RWExportQualityLow
};

@property (nonatomic, assign) NSInteger quality;
@property (nonatomic, assign) NSBitmapImageFileType format;

- (id)initWithData:(NSData*)data;
- (id)initWithPath:(NSString*)path;

+ (id)exporterWithData:(NSData*)data;
+ (id)exporterWithFile:(NSString*)path;

- (void)setDestination:(NSString*)path;
- (void)setWidth:(CGFloat)width;
- (void)setHeight:(CGFloat)height;

- (void)setAttributes:(NSDictionary *)attributes;

- (BOOL)highQualityScaling;
- (void)setHighQualityScaling:(BOOL)flag;

- (BOOL)flipHorizontally;
- (void)setFlipHorizontally:(BOOL)flag;

- (BOOL)flipVertically;
- (void)setFlipVertically:(BOOL)flag;

- (CGFloat)rotation;
- (void)setRotation:(CGFloat)rotation;

- (BOOL)clip;
- (void)setClip:(BOOL)clip;

- (BOOL)squareImage;
- (void)setSquareImage:(BOOL)squareImage;

- (NSColor*)fillColour;
- (void)setFillColour:(NSColor*)colour;

- (CGFloat)shadowOffset;
- (void)setShadowOffset:(CGFloat)offset;

- (CGFloat)shadowBlur;
- (void)setShadowBlur:(CGFloat)offset;

- (NSColor*)shadowColour;
- (void)setShadowColour:(NSColor*)colour;

- (BOOL)ignoreOrientation;
- (void)setIgnoreOrientation:(BOOL)ignoreOrientation;

- (OSStatus)export;
- (OSStatus)status;

+ (NSString *)quicktimeEmbedHTMLForSrc:(NSString *)path width:(NSInteger)width height:(NSInteger)height autoplay:(BOOL)autoplay;

// Deprecated in the move to 64-bit. These methods were dependant on the QuickTime framework which is 32-bit only.
// These methods will return NSZeroSize, NO or nil as appropriate.

+ (void *)getImageDescription:(NSString *)path DEPRECATED_ATTRIBUTE;

+ (NSSize)getMovieDimensions:(NSString *)path DEPRECATED_ATTRIBUTE;
+ (NSSize)getMovieDimensionsFromData:(NSData *)data DEPRECATED_ATTRIBUTE;
+ (BOOL)getPotentialQuickTimeMovie:(NSString *)path DEPRECATED_ATTRIBUTE;
+ (NSString *)flattenQuickTimeMovieForFastStart:(NSString *)path intoTempDirectory:(NSString *)directory DEPRECATED_ATTRIBUTE;

@end

//***************************************************************************

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
#if !defined(__ppc64__) && !defined(__x86_64__)
#import <QuickTime/QuickTime.h>

@interface RWQTExport : NSObject {
	NSString* _path;
	NSString* _source;
	NSData* _data;
	NSColor* _fillColour;
	OSType _format;
	CodecQ _quality;
	ComponentInstance _importer;
	ComponentInstance _exporter;
	OSStatus _status;
	CGFloat _width, _height;
	BOOL _hqScaling;
	BOOL _retainProfiles;
	BOOL _flipHorizontally;
	BOOL _flipVertically;
	BOOL _clip;
	BOOL _squareImage;
	CGFloat _shadowOffset;
	CGFloat _shadowBlur;
	NSColor* _shadowColour;
	CGFloat _rotation;
	NSData* _tiff;
	__weak NSDictionary* _attributes;
	CGImageSourceRef _sourceImage;
}

- (id)initWithData:(NSData*)data;
//- (id)initWithFile:(NSString*)path;

- (id)initWithPath:(NSString*)path;

+ (id)exporterWithData:(NSData*)data;
+ (id)exporterWithFile:(NSString*)path;

- (void)setDestination:(NSString*)path;
- (void)setFormat:(OSType)format;
- (void)setQuality:(CodecQ)quality;
- (void)setWidth:(CGFloat)width;
- (void)setHeight:(CGFloat)height;

- (void)setAttributes:(NSDictionary*)attributes;

- (BOOL)highQualityScaling;
- (void)setHighQualityScaling:(BOOL)flag;

- (BOOL)retainProfiles;
- (void)setRetainProfiles:(BOOL)flag;

- (BOOL)flipHorizontally;
- (void)setFlipHorizontally:(BOOL)flag;

- (BOOL)flipVertically;
- (void)setFlipVertically:(BOOL)flag;

- (float)rotation;
- (void)setRotation:(float)rotation;

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

- (OSStatus)export;
- (OSStatus)status;

+ (ImageDescriptionHandle)getImageDescription:(NSString*)path;

+ (NSSize)getMovieDimensions:(NSString*)path;
+ (NSSize)getMovieDimensionsFromData:(NSData*)data;
+ (BOOL)getPotentialQuickTimeMovie:(NSString*)path;
+ (NSString*)quicktimeEmbedHTMLForSrc:(NSString*)path width:(NSInteger)width height:(NSInteger)height autoplay:(BOOL)autoplay;
+ (NSString*)flattenQuickTimeMovieForFastStart:(NSString*)path intoTempDirectory:(NSString*)directory;

@property (setter=setFormat:) OSType _format;
@property (setter=setQuality:) CodecQ _quality;
@property (getter=rotation,setter=setRotation:) CGFloat _rotation;
@property (retain) NSData* _data;
@property ComponentInstance _importer;
@property (retain) NSData* _tiff;
@property (getter=status) OSStatus _status;
@property (getter=shadowBlur,setter=setShadowBlur:) CGFloat _shadowBlur;
@property (getter=shadowOffset,setter=setShadowOffset:) CGFloat _shadowOffset;
@property ComponentInstance _exporter;
@property (retain,getter=fillColour) NSColor* _fillColour;
@property CGImageSourceRef _sourceImage;
@property (retain) NSString* _source;
@property (retain,getter=shadowColour) NSColor* _shadowColour;
@property (assign,setter=setAttributes:) __weak NSDictionary* _attributes;
@property (retain,setter=setDestination:) NSString* _path;
@end
#endif

//***************************************************************************

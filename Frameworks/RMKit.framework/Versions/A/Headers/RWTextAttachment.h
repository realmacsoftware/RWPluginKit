//***************************************************************************

// Copyright (C) 2005-2008 Realmac Software Ltd
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

@interface NSDictionary (RWTextAttachmentAttributes)
- (BOOL)flipVertically;
- (BOOL)flipHorizontally;
- (BOOL)lockRatios;
- (CGFloat)width;
- (CGFloat)originalWidth;
- (CGFloat)widthOrOriginalWidth;
- (CGFloat)height;
- (CGFloat)originalHeight;
- (CGFloat)heightOrOriginalHeight;
- (BOOL)square;
- (CGFloat)scale;
- (float)rotation;
- (BOOL)clip;
- (NSString*)altTag;
- (NSString*)fileName;
- (NSColor*)fillColour;
enum {
	kMediaAttachmentImageType = 1,
	kMediaAttachmentMovieType
};
- (NSInteger)mediaType;
- (BOOL)enableShadow;
- (CGFloat)shadowOffset;
- (CGFloat)shadowBlur;
- (NSColor*)shadowColour;
- (BOOL)enableBorder;
- (CGFloat)borderOffset;
- (CGFloat)borderBlur;
- (NSColor*)borderColour;
@end

@interface RWTextAttachment : NSTextAttachment {
	@private
	NSMutableDictionary* _attributes;
	NSImage* _image;
	NSData* _cachedImage;
}

- (NSImage*)image;
- (void)updateImage;

- (NSData*)cachedImage;
- (void)setCachedImage:(NSData*)cachedImage;
- (void)clearCachedImage;

- (void)setMediaType:(NSInteger)type;

- (NSMutableDictionary*)mediaAttributes;
- (BOOL)normalise;

@property (retain,getter=cachedImage) NSData* _cachedImage;
@property (retain) NSMutableDictionary* _attributes;
@property (retain) NSImage* _image;
@end

//***************************************************************************

//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************

@import Foundation;
@import Cocoa;

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
- (NSString *)altTag;
- (NSString *)fileName;
- (NSColor *)fillColour;

enum
{
	kMediaAttachmentImageType = 1,
	kMediaAttachmentMovieType
};

- (NSInteger)mediaType;
- (BOOL)enableShadow;
- (CGFloat)shadowOffset;
- (CGFloat)shadowBlur;
- (NSColor *)shadowColour;
- (BOOL)enableBorder;
- (CGFloat)borderOffset;
- (CGFloat)borderBlur;
- (NSColor *)borderColour;

@end

//***************************************************************************

@interface RWTextAttachment : NSTextAttachment

@property (strong) NSMutableDictionary *attributes;
//@property (strong) NSData *cachedImage;

@property (strong, nonatomic) id resource;
@property (strong, nonatomic) NSString *resourceIdentifier;
@property (strong, nonatomic) NSFileWrapper *resourceFileWrapper;

@property (readonly, nonatomic) id cgImageSourceRef;
@property (readonly, nonatomic) id cgImageRef;

- (NSMutableDictionary *)mediaAttributes;
- (BOOL)mediaAttributesHaveChanged;
- (void)setMediaType:(NSInteger)type;

- (void)updateImage;
- (void)clearCachedImage;

@property (nonatomic, strong) NSNumber  *mediaAttributesWidth;
@property (nonatomic, strong) NSNumber  *mediaAttributesHeight;
@property (nonatomic, strong) NSNumber  *mediaAttributesOriginalWidth;
@property (nonatomic, strong) NSNumber  *mediaAttributesOriginalHeight;
@property (nonatomic, strong) NSNumber  *mediaAttributesLockRatios;
@property (nonatomic, strong) NSNumber  *mediaAttributesFlipHorizontally;
@property (nonatomic, strong) NSNumber  *mediaAttributesFlipVertically;
@property (nonatomic, strong) NSNumber  *mediaAttributesScale;
@property (nonatomic, strong) NSNumber  *mediaAttributesRotation;
@property (nonatomic, strong) NSNumber  *mediaAttributesClip;
@property (nonatomic, strong) NSString  *mediaAttributesAltTag;
@property (nonatomic, strong) NSString  *mediaAttributesFilename;
@property (nonatomic, strong) NSColor  *mediaAttributesFillColor;
@property (nonatomic, strong) NSNumber  *mediaAttributesFillColorEnabled;
@property (nonatomic, strong) NSNumber  *mediaAttributesEnableShadow;
@property (nonatomic, strong) NSNumber  *mediaAttributesShadowOffset;
@property (nonatomic, strong) NSNumber  *mediaAttributesShadowBlur;
@property (nonatomic, strong) NSColor  *mediaAttributesShadowColor;
@property (nonatomic, strong) NSNumber  *mediaAttributesEnableBorder;
@property (nonatomic, strong) NSNumber  *mediaAttributesBorderSize;
@property (nonatomic, strong) NSNumber  *mediaAttributesBorderBlur;
@property (nonatomic, strong) NSColor  *mediaAttributesBorderColor;

@end

//***************************************************************************

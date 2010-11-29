//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// This software is supplied to you by Realmac Software Ltd ("Realmac").
// in consideration of your agreement to the following terms, and your use,
// installation, modification or redistribution of this Realmac software
// constitutes acceptance of these terms.  If you do not agree with these
// terms, please do not use, install, modify or redistribute this Realmac
// software.
//
// In consideration of your agreement to abide by the following terms, and
// subject to these terms, Realmac grants you a personal, non-exclusive
// license, under Realmac's copyrights in this original Realmac software (the
// "Software"), to use, reproduce, modify and redistribute the Software, with
// or without modifications, in source and/or binary forms; provided that if
// you redistribute the Software in its entirety and without modifications,
// you must retain this notice and the following text and disclaimers in all
// such redistributions of the Software.
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

typedef enum
{
	RWWebImageTransformationParametersUseSize,
	RWWebImageTransformationParametersUseScale
}
RWWebImageTransformationParametersUseSizeOrScale;

//---------------------------------------------------------------------------

@interface RWWebImageTransformationParameters : NSObject
{
	RWWebImageTransformationParametersUseSizeOrScale _sizeOrScale;
	NSSize _size;
	CGFloat _scale;
	
	CGFloat _rotationInDegrees;
	BOOL _flippedHorizontally;
	BOOL _flippedVertically;
	BOOL _isClipped;
	
	NSColor* _fillColour;
	
	BOOL _shadowEnabled;
	CGFloat _shadowOffset;
	CGFloat _shadowBlur;
	NSColor* _shadowColour;
	
	BOOL _borderEnabled;
	CGFloat _borderWidth;
	NSColor* _borderColour;
}

- (RWWebImageTransformationParameters*)init;
- (RWWebImageTransformationParameters*)initWithDictionary:(NSDictionary*)dictionary;

- (NSDictionary*)dictionaryWithOriginalImageSize:(NSSize)originalImageSize;
- (NSDictionary*)propertyList;

@property RWWebImageTransformationParametersUseSizeOrScale sizeOrScale;
@property NSSize size;
@property CGFloat scale;

@property CGFloat rotationInDegrees;
@property BOOL flippedHorizontally;
@property BOOL flippedVertically;
@property BOOL isClipped;

@property (copy) NSColor* fillColour;

@property BOOL shadowEnabled;
@property CGFloat shadowOffset;
@property CGFloat shadowBlur;
@property (copy) NSColor* shadowColour;

@property BOOL borderEnabled;
@property CGFloat borderWidth;
@property (copy) NSColor* borderColour;

@end

//***************************************************************************

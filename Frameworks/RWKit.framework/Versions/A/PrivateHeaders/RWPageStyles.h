//
//  RWPageStyles.h
//  RapidWeaver
//
//  Created by Simon Taylor on 27/07/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWPage;

extern NSString *kRWPageStyleDidChangeNotification;

@interface RWPageStyles : NSObject <NSCoding>
{
 @private
	RWPage *_page;
	
	NSImage *_backgroundImage;
	NSColor *_backgroundColour;
	NSString *_customCSS;
	NSString *_customJavaScript;
	NSString *_customHeader;
	NSString *_customBody;
	NSString *_customSiteTitle;
	NSString *_customSlogan;
	NSString *_customCopyright;
	
	BOOL _useBackgroundImage;
	BOOL _repeatbackGroundImageX;
	BOOL _repeatbackGroundImageY;
	BOOL _useBackgroundColour;
	BOOL _useCustomSiteTitle;
	BOOL _useCustomSlogan;
	BOOL _useCustomCopyright;
}

@property (nonatomic, assign) RWPage *page;

- (id)initWithPage:(RWPage *)page;

- (BOOL)useBackgroundImage;
- (NSImage *)backgroundImage;

- (BOOL)useBackgroundColour;
- (NSColor *)backgroundColour;

- (BOOL)useCustomSiteTitle;
- (NSString *)customSiteTitle;

- (BOOL)useCustomSlogan;
- (NSString *)customSlogan;

- (BOOL)useCustomCopyright;
- (NSString *)customCopyright;

- (NSString *)customCSS;
- (NSString *)customJavaScript;
- (NSString *)customHeader;
- (NSString *)customBody;

- (void)setCustomCSS:(NSString *)css;
- (void)setCustomJavaScript:(NSString *)js;
- (void)setCustomHeader:(NSString *)header;
- (void)setCustomBody:(NSString *)body;
- (void)setUseCustomSiteTitle:(BOOL)flag;
- (void)setCustomSiteTitle:(NSString *)title;
- (void)setUseCustomSlogan:(BOOL)flag;
- (void)setCustomSlogan:(NSString *)slogan;
- (void)setUseCustomCopyright:(BOOL)flag;
- (void)setCustomCopyright:(NSString *)copyright;

@end

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
	
	BOOL _repeatbackGroundImageX;
	BOOL _repeatbackGroundImageY;
}

@property (nonatomic, weak) RWPage *page;

@property (nonatomic, assign) BOOL useBackgroundImage;
@property (nonatomic, strong) NSImage *backgroundImage;

@property (nonatomic, assign) BOOL useBackgroundColour;
@property (nonatomic, strong) NSColor *backgroundColour;

@property (nonatomic, assign) BOOL useCustomSiteTitle;
@property (nonatomic, strong) NSString *customSiteTitle;

@property (nonatomic, assign) BOOL useCustomSlogan;
@property (nonatomic, strong) NSString *customSlogan;

@property (nonatomic, assign) BOOL useCustomCopyright;
@property (nonatomic, strong) NSString *customCopyright;

@property (nonatomic, strong) NSString *customCSS;
@property (nonatomic, strong) NSString *customJavaScript;
@property (nonatomic, strong) NSString *customHeader;
@property (nonatomic, strong) NSString *customBody;

@property (nonatomic, assign) BOOL useCustomLanguage;
@property (nonatomic, strong) NSString *customLanguage;
@property (nonatomic, strong) NSString *customLanguageDirection;

- (id)initWithPage:(RWPage *)page;

@end

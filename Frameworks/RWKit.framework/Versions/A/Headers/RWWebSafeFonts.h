//
//  RWWebSafeFonts.h
//  RapidWeaver
//
//  Created by Simon Taylor on 04/04/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>


@interface RWWebSafeFonts : NSObject {

	BOOL _nilOnWebUnsafeFont;
	
}

+ (void)styliseFontMenu:(NSMenu*)menu;
+ (NSFont*)menuItemTitleToFont:(NSString*)item;

+ (BOOL)containsWebUnsafeFonts:(NSAttributedString*)string;

- (void)setNilOnWebUnsafeFont:(BOOL)flag;
- (NSString*)styleStringForFont:(NSFont*)font;

@property (setter=setNilOnWebUnsafeFont:) BOOL _nilOnWebUnsafeFont;
@end

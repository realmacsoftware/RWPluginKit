//
//  RWHTMLView.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 19/08/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>

@class RWLineCountView;

@interface RWHTMLView : NSTextView {
	RWLineCountView* _lineView;
	BOOL _wrapHTML;
}

- (void)setString:(NSString*)string lazily:(BOOL)settingLazily;

- (void)setShowLineNumbers:(BOOL)flag;
- (NSMutableAttributedString *)colorize:(NSString *)source;
- (void)colorize;

@property (retain) RWLineCountView* _lineView;
@end

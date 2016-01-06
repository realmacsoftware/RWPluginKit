//
//  RWCodeView.h
//  RapidWeaver
//
//  Created by Simon Maddox on 05/12/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//

#import <Cocoa/Cocoa.h>

extern NSString * const RWCodeHighlightingLanguageHTML;
extern NSString * const RWCodeHighlightingLanguageCSS;
extern NSString * const RWCodeHighlightingLanguagePHP;
extern NSString * const RWCodeHighlightingLanguageJavascript;
extern NSString * const RWCodeHighlightingLanguageMarkdown;

@interface RWCodeView : NSView <NSTextDelegate>

@property (nonatomic, retain) NSString *string;
@property (nonatomic, assign) IBOutlet id <NSTextDelegate> delegate;

@property (nonatomic) BOOL showLineNumbers;
@property (nonatomic, copy) NSString *language;
@property (nonatomic) BOOL hasBorder;
@property (nonatomic) BOOL editable;
@property (nonatomic) BOOL autocompleteEnabled;
@property (nonatomic) NSInteger fontSize;

@end

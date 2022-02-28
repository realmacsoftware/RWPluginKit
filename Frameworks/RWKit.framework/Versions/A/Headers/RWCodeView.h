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

@interface RWCodeView : NSView

@property (nonatomic, strong) NSString *string;
@property (nonatomic, readonly) NSTextView *textView;

@property (nonatomic, weak) IBOutlet id <NSTextViewDelegate> delegate;

@property (nonatomic, assign) BOOL showLineNumbers;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, assign) BOOL hasBorder;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, assign) CGFloat fontSize;

@property (nonatomic, assign) BOOL autocompleteEnabled DEPRECATED_MSG_ATTRIBUTE("Auto complete is no longer supported");

@end

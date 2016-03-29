//
//  RWCodeHighlightingController.h
//  RapidWeaver
//
//  Created by Simon Maddox on 05/12/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const RWCodeHighlightingLanguageHTML;
extern NSString * const RWCodeHighlightingLanguageCSS;
extern NSString * const RWCodeHighlightingLanguagePHP;
extern NSString * const RWCodeHighlightingLanguageJavascript;
extern NSString * const RWCodeHighlightingLanguageMarkdown;

@interface RWCodeHighlightingController : NSObject

- (instancetype) initWithView:(NSView *)view;

@property (nonatomic, copy) NSString *language;
@property (nonatomic, copy) NSString *string;
@property (nonatomic) BOOL showLineNumbers;
@property (nonatomic) BOOL autocompleteEnabled;
@property (nonatomic, assign) CGFloat fontSize;

- (NSTextView *)textView;

@end

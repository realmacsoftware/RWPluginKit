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

- (void) setLanguage:(NSString *)language;
- (NSString *) language;

- (void) setString:(NSString *)string;
- (NSString *) string;

- (void) setShowLineNumbers:(BOOL)flag;
- (BOOL) showLineNumbers;

- (NSTextView *)textView;

@end

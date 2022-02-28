//
//  RWtextView.h
//  RWPluginUtilities
//
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>
#import <Quartz/Quartz.h>

#import "RWLinkPanel.h"

@class RWAbstractPlugin;

@interface RWTextView : NSTextView <RWLinkPanelDelegate>

- (NSArray*)attachments;
- (NSArray*)selectedAttachments;
- (id)currentMedia;

- (IBAction)addLink:(id)sender;
- (IBAction)removeLink:(id)sender;

- (void)applyIgnoreFormattingToSelection:(id)sender;
- (void)removeFormattingFromSelection:(id)sender;
- (IBAction)orderFrontListInspector:(id)sender;

- (void)fixUpAttachments;

- (IBAction)removeSmartQuotesFromSelection:(id)sender;

- (void)showEditorForAttachment:(id)attachment plugin:(RWAbstractPlugin *)plugin;

@property (weak) id pluginDelegate;

@end

@interface NSDictionary (RWMarkupDirective)
- (NSString*)tag;
- (NSString*)openTag;
- (NSString*)closeTag;
- (NSString*)name;
- (BOOL)cleartags;
@end

extern NSString* kRWTextViewIgnoreFormattingAttributeName;
extern NSString* kRWTextViewMarkupDirectivesAttributeName;

enum {
	kClearFormattingMenuTag = 6000,
	kIgnoreFormattingMenuTag = 6001,
	kWebSafeFontsMenuTag = 6002,
	kHTMLAttributesMenuTag = 6003,
	kFormatMenuTag = 6004,
	kSmartQuotesMenuTag = 6005,
	kRemoveSmartQuotesMenuTag = 6006,
	kPictureTakerMenuTag = 6050,
	kCheckSpellingWhileTypingMenuTag = 6060,
	kCheckGrammarWithSpellingMenuTag = 6061,
};

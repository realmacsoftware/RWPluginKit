//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************

#import <RWKit/RWLinkPanel.h>

@protocol RWPluginProtocol;

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

- (void)showEditorForAttachment:(id)attachment plugin:(id <RWPluginProtocol>)plugin;

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

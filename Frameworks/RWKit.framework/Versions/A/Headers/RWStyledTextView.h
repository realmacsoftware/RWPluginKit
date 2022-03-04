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

@import Cocoa;

@class RWStyledText;
@class RWTextView;

@interface RWStyledTextView : NSView <NSCoding>

- (id <RWPluginProtocol>)plugin;

// Actions
- (IBAction)onAddLink:(id)sender;
- (IBAction)onRemoveLink:(id)sender;
- (IBAction)onAction:(id)sender;
- (IBAction)onToggleSmartQuotes:(id)sender;
- (IBAction)onUnderline:(id)sender;
- (IBAction)onList:(id)sender;

// NSCoding
- (void)encodeWithCoder:(NSCoder*)aCoder;
- (id)initWithCoder:(NSCoder*)aDecoder;

@property (copy) RWStyledText* styledText;

@property (readonly, strong) RWTextView* textView;

@property (copy) NSAttributedString* attributedString;

/// Returns the current text editing view
@property (readonly, strong) id textEditingView;

/// The delegate for this styled text view.  Note that while the RWStyledTextView object will be the delegate set for the inner RWTextView, all of RWTextView's delegate messages will be forwarded to the main styled text view delegate object.
// @property (assign) NSObject<RWStyledTextViewDelegate>* delegate;
@property (weak) id delegate;

@property BOOL editable;

@end

#pragma mark - RWStyledTextViewDelegate Protocol

@protocol RWStyledTextViewDelegate <NSObject>

- (id <RWPluginProtocol>)pluginForStyledTextView:(RWStyledTextView*)styledTextView;

@end

#pragma mark - RWTextViewDefaultDelegate

@interface RWTextViewDefaultDelegate : NSObject <NSTextViewDelegate>

+ (RWTextViewDefaultDelegate*)textViewDefaultDelegateWithStyledTextView:(RWStyledTextView*)styledTextView;

- (id)initWithStyledTextView:(RWStyledTextView*)styledTextView;

@property (weak) RWStyledTextView* styledTextView;

@end

//***************************************************************************

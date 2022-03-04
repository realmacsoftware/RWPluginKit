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

#import <RWKit/RWAbstractPlugin.h>
#import <RWKit/RWLinkPanel.h>

@class RWTextView;

@protocol RWTextViewPluginClientMedia
- (void)currentMediaAttributesChanged;
@end

@interface RWTextViewPluginClient : RWAbstractPlugin <RWLinkPanelDelegate, RWTextViewPluginClientMedia>

@property (assign) NSRange _linkSelectedRange;
@property (strong) RWTextView *_styledContentTextView;
@property (strong) NSButton *_addButton;
@property (strong) RWLinkPanel *_linkPanel;
@property (strong) NSButton *_removeButton;

- (void)setStyledTextView:(id)view;
- (void)setAdd:(id)add andRemoveLinkButtons:(id)remove;

- (void)textDidChange:(NSNotification *)aNotification;

@end

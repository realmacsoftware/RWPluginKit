//
//  RWTextViewClient.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 18/08/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>

#import <RMKit/RMKit.h>
#import "RWKit.h"

@interface RWTextViewPluginClient : RWAbstractPlugin <RWLinkPanelDelegate>
{
	RWLinkPanel *_linkPanel;
	RWTextView *_styledContentTextView;
	NSButton *_addButton;
	NSButton *_removeButton;
	NSRange _linkSelectedRange;
}

- (void)setStyledTextView:(id)view;
- (void)setAdd:(id)add andRemoveLinkButtons:(id)remove;

- (void)currentMediaAttributesChanged;

- (void)textDidChange:(NSNotification *)aNotification;

@property (strong) RWTextView *_styledContentTextView;
@property (strong) NSButton *_addButton;
@property (strong) RWLinkPanel *_linkPanel;
@property (strong) NSButton *_removeButton;

@end

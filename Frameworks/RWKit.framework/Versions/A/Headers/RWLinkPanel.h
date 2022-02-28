//
//  RWLinkPanel.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 22/05/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>

@class RWLink;

@protocol RWLinkPanelDelegate
- (void)panelCompletedWithLink:(RWLink *)link;
@end

@interface RWLinkPanel : NSWindowController <NSMenuDelegate>
{
	RWLink *_currentLink;
	
	IBOutlet NSTextField *urlField;
	IBOutlet NSPopUpButton *schemePopUp;
	IBOutlet NSView *customAttributesView;
	IBOutlet NSTableView *customAttributesTable;
	IBOutlet NSDictionaryController *linkAttributesController;
}

@property (weak, nonatomic) IBOutlet NSObjectController *bindings;

@property (assign, nonatomic) BOOL showRemoveLinkButton;

+ (RWLinkPanel *)panelWithDelegate:(id <RWLinkPanelDelegate>)delegate plugin:(id)plugin;
+ (RWLinkPanel *)panelWithDelegate:(id <RWLinkPanelDelegate>)delegate document:(id)document;

- (void)presentPanelWithLink:(RWLink *)link parent:(NSWindow *)parent;

- (IBAction)addAttribute:(id)sender;
- (IBAction)onToggleCustomLinkAttributes:(id)sender;

@end

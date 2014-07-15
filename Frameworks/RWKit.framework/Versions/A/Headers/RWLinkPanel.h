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
	
	NSObjectController *bindings;
	
	IBOutlet NSTextField *urlField;
	IBOutlet NSPopUpButton *schemePopUp;
	IBOutlet NSView *customAttributesView;
	IBOutlet NSTableView *customAttributesTable;
	IBOutlet NSDictionaryController *linkAttributesController;
}

@property (nonatomic, readonly) IBOutlet NSObjectController *bindings;

+ (RWLinkPanel *)panelWithDelegate:(id <RWLinkPanelDelegate>)delegate plugin:(id)plugin;

- (void)presentPanelWithLink:(RWLink *)link parent:(NSWindow *)parent;

- (IBAction)addAttribute:(id)sender;
- (IBAction)onToggleCustomLinkAttributes:(id)sender;

@end

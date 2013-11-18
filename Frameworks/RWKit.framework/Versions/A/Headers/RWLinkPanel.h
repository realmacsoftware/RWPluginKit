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
	id _plugin;
	RWLink *_currentLink;
	id<RWLinkPanelDelegate> _delegate;
	
	BOOL _creatingLink;
	
	NSDictionary *savedAttributes;
	NSWindow *parent;
	
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

- (IBAction)addAttribute:(id)aSender;
- (IBAction)onToggleCustomLinkAttributes:(id)sender;

@end

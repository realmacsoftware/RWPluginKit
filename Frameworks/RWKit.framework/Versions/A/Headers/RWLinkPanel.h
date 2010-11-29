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
- (void)panelCompletedWithLink:(RWLink*)link;
@end

@interface RWLinkPanel : NSWindowController
{
	id _plugin;
	RWLink* _currentLink;
	id<RWLinkPanelDelegate> _delegate;
	
	BOOL _creatingLink;
	
	NSDictionary *savedAttributes;
	NSWindow *parent;
	
	NSObjectController *bindings;
	
	IBOutlet NSTextField *urlField;
	IBOutlet NSPopUpButton *schemePopUp;
	IBOutlet NSView* customAttributesView;
	IBOutlet NSTableView* customAttributesTable;
	IBOutlet NSDictionaryController *linkAttributesController;
}

- (IBAction)addAttribute:(id)aSender;
- (IBAction)onToggleCustomLinkAttributes:(id)sender;

- (void)presentPanelWithLink:(RWLink*)link parent:(NSWindow*)parent;

+ (RWLinkPanel*)panelWithDelegate:(id<RWLinkPanelDelegate>)delegate plugin:(id)plugin;

@property (nonatomic, retain) id _plugin;
@property (nonatomic, retain) id<RWLinkPanelDelegate> _delegate;
@property (nonatomic, retain, getter=currentLink) RWLink* _currentLink;
@property (nonatomic, readonly) IBOutlet NSObjectController *bindings;

@end

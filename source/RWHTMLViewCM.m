//***************************************************************************

// Copyright (C) 2009 ~ 2010 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RMSSamplePlugin.h"
#import "RWHTMLViewCM.h"

//***************************************************************************

@implementation RWHTMLViewCM

static NSMenuItem *sQuickInsertMenuItem = nil;
static NSDictionary *sQuickInsertDictionary = nil;

- (IBAction)quickInsert:(id)sender
{
	[self insertText:@"<h1>Banana!</h1>"];
}

- (NSMenu *)menuForEvent:(NSEvent *)anEvent
{
	if (sQuickInsertMenuItem == nil)
	{
		NSMenu *menu = [[[NSMenu alloc] initWithTitle:@"Secret Menu!"] autorelease];
		
		sQuickInsertDictionary = [[NSDictionary alloc] initWithContentsOfFile:
			[[NSBundle bundleForClass:[RMSSamplePlugin class]] pathForResource:@"quickInsertTemplates" ofType:@"plist"]];
		
		for (id key in [sQuickInsertDictionary allKeys])
		{
			NSMenuItem *item = [[[NSMenuItem alloc] initWithTitle:key action:@selector(quickInsert:) keyEquivalent:@""] autorelease];
			[menu addItem:item];
		}
		
		sQuickInsertMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quick Insert" action:nil keyEquivalent:@""];
		[sQuickInsertMenuItem setSubmenu:menu];
	}
	
	NSMenu *menu = [super menuForEvent:anEvent];
	
	if ([menu indexOfItem:sQuickInsertMenuItem] == -1)
	{
		NSMenuItem *sep = [NSMenuItem separatorItem];
		
		[menu insertItem:sep atIndex:0];
		[menu insertItem:sQuickInsertMenuItem atIndex:0];
	}
	
	return menu;
}

@end

//***************************************************************************

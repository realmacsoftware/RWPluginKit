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
#import "RMSSamplePluginContentViewController.h"

@interface RMSSamplePluginContentViewController ()

@property (nonatomic, weak) RMSSamplePlugin *plugin;

@end

//***************************************************************************

@implementation RMSSamplePluginContentViewController

@dynamic content;

- (NSString *)content
{
	return htmlView.string;
}

- (void)textDidChange:(NSNotification *)notification
{
	RMSSamplePlugin *p = self.plugin;
	
	[p broadcastPluginChanged];
}

- (void)awakeFromNib
{
	RMSSamplePlugin *p = self.plugin;
	NSString *string = p.content;
	
	if (string) {
		htmlView.string = string;
	}
	
	[htmlView setHasBorder:NO];
}

- (instancetype)initWithRepresentedObject:(id)object
{
	self = [super initWithNibName:@"RMSSamplePluginContentView" bundle:[RMSSamplePlugin bundle]];
	if (self == nil) {
		return nil;
	}
	
	self.plugin = object;
	
	return self;
}

@end

//***************************************************************************

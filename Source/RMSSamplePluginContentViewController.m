//***************************************************************************

// Copyright (C) 2009 ~ 2022 Realmac Software Ltd
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
@property (nonatomic, weak) IBOutlet RWCodeView *htmlView;

@end

//***************************************************************************

@implementation RMSSamplePluginContentViewController

@dynamic content;

- (NSString *)content
{
	return self.htmlView.string;
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
		self.htmlView.string = string;
	}
	
	[self.htmlView setHasBorder:NO];
    
    self.htmlView.language = RWCodeHighlightingLanguageHTML;
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

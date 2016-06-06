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
#import "RMSSamplePluginOptionsViewController.h"

@interface RMSSamplePluginOptionsViewController ()

@property (nonatomic, weak) RMSSamplePlugin *plugin;

@end

//***************************************************************************

@implementation RMSSamplePluginOptionsViewController

- (instancetype)initWithRepresentedObject:(id)object
{
	self = [super initWithNibName:@"RMSSamplePluginOptionsView" bundle:[RMSSamplePlugin bundle]];
	if (self == nil) {
		return nil;
	}
	
	self.plugin = object;
	
	return self;
}

- (IBAction)chooseFile:(id)sender
{
	NSOpenPanel *openPanel = [NSOpenPanel openPanel];
	[openPanel beginWithCompletionHandler:^(NSInteger result) {
		if (result != NSFileHandlingPanelOKButton) {
			return;
		}
		
		NSError *bookmarkError = nil;
		NSURL *fileURL = openPanel.URL;
		RMSSamplePlugin *pluginInstance = self.plugin;
		NSString *newFileToken = [pluginInstance registerFileURL:fileURL error:&bookmarkError];
		if (newFileToken == nil) {
			NSLog(@"Failed to bookmark file with error: %@", bookmarkError);
			return;
		}
		
		if (pluginInstance.fileToken) {
			[pluginInstance removeFileReferenceForToken:pluginInstance.fileToken];
		}
		
		pluginInstance.fileToken = newFileToken;
	}];
}

- (IBAction)testFileAccess:(id)sender
{
	RMSSamplePlugin *pluginInstance = self.plugin;
	NSLog(@"fileToken: %@", pluginInstance.fileToken);
	if (pluginInstance.fileToken == nil) {
		NSBeep();
		return;
	}
	
	NSError *bookmarkError = nil;
	NSURL *fileURL = [pluginInstance fileURLForToken:pluginInstance.fileToken error:&bookmarkError];
	if (fileURL == nil) {
		NSBeep();
		NSLog(@"Failed to resolve token with error: %@", bookmarkError);
		return;
	}
	
	if ([fileURL startAccessingSecurityScopedResource] == NO) {
		NSBeep();
		NSLog(@"Failed to enable URL access.");
		return;
	}
	
	NSError *fileReadError = nil;
	NSData *fileData = [NSData dataWithContentsOfURL:fileURL options:(NSDataReadingOptions)0 error:&fileReadError];
	if (fileData == nil) {
		NSBeep();
		NSLog(@"Failed to read file with error: %@.", fileReadError);
		return;
	}
	
	[fileURL stopAccessingSecurityScopedResource];
	
	NSLog(@"Read data of %ld bytes.", fileData.length);
}

@end

//***************************************************************************

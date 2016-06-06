//***************************************************************************

// Copyright (C) 2004 ~ 2010 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RMSSamplePlugin.h"
#import "RMSSamplePluginOptionsViewController.h"
#import "RMSSamplePluginContentViewController.h"

//***************************************************************************

@implementation RMSSamplePlugin

//***************************************************************************

#pragma mark Protocol Methods

- (NSView *)optionsAndConfigurationView
{
	if (optionsViewController == nil)
	{
		optionsViewController = [[RMSSamplePluginOptionsViewController alloc] initWithRepresentedObject:self];
	}
	
	return optionsViewController.view;
}

- (NSView *)userInteractionAndEditingView
{
	if (contentViewController == nil)
	{		
		contentViewController = [[RMSSamplePluginContentViewController alloc] initWithRepresentedObject:self];
	}
	
	return contentViewController.view;
}

- (id)contentHTML:(NSDictionary *)params
{
	NSString *string = (contentViewController.content) ?: self.content;
	if (string == nil) {
		string = @"";
	}
	
	if (self.emitRawContent == NO) {
		return [NSString stringWithString:string];
	}
	
	return [self contentOnlySubpageWithEntireHTML:[NSString stringWithString:string] name:nil];
}

- (NSString *)sidebarHTML:(NSDictionary *)params
{
	return nil;
}

- (NSNumber *)normaliseImages
{
	return [NSNumber numberWithUnsignedInt:0];
}

- (NSString *)overrideFileExtension
{
	// Return the extension you'd like to force RapidWeaver to apply to your page.
	
	return @"htm";
}

- (void)pluginWillAutoSave {
	
//	NSLog(@"Called -pluginWillAutoSave. Is main thread: %d", [NSThread isMainThread]);
}

- (void)pluginDidAutoSave {
	
//	NSLog(@"Called -pluginDidAutoSave. Is main thread: %d", [NSThread isMainThread]);
}

//***************************************************************************

#pragma mark KVO Broadcasting

- (NSArray *)visibleKeys
{
	// Add any values here that cause the document to need saving. This allows us to use KVO to catch any changes and do our broadcasting instead of writing the setters manually. Properties and KVO FTW!
	
	return @[@"emitRawContent", @"fileToken"];
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
	if ([[self visibleKeys] containsObject:keyPath])
	{
		[self broadcastPluginChanged];
	}
}

- (void)stopObservingVisibleKeys
{
	NSArray *keys = [self visibleKeys];
	
	for (NSString *key in keys)
	{
		[self removeObserver:self forKeyPath:key];
	}
}

- (void)observeVisibleKeys
{
	NSArray *keys = [self visibleKeys];
	
	for (NSString *key in keys)
	{
		[self addObserver:self forKeyPath:key options:0 context:NULL];
	}
}

//***************************************************************************

#pragma mark Object Lifecycle

- (void)finishSetup
{
	contentViewController = nil;
	optionsViewController = nil;
	
	[self observeVisibleKeys];
}

- (void)encodeWithCoder:(NSCoder *)coder
{
	[super encodeWithCoder:coder];
	
	[coder encodeObject:(contentViewController.content) ?: self.content forKey:@"Content String"];
	[coder encodeObject:[NSNumber numberWithBool:self.emitRawContent] forKey:@"Emit Raw Content"];
	[coder encodeObject:self.fileToken forKey:@"File Token"];
}

- (id)initWithCoder:(NSCoder *)coder
{
	self = [super initWithCoder:coder];
	if (self == nil) {
		return nil;
	}
	
	_content = [[coder decodeObjectForKey:@"Content String"] copy];
	_emitRawContent = [[coder decodeObjectForKey:@"Emit Raw Content"] boolValue];
	_fileToken = [[coder decodeObjectForKey:@"File Token"] copy];
	
	[self finishSetup];
	
	return self;
}

- (id)init
{
	self = [super init];
	if (self == nil) {
		return nil;
	}
	
	[self finishSetup];
	
	return self;
}

- (void)dealloc
{
	[self stopObservingVisibleKeys];
	
	[_content release];
	[_fileToken release];
	
	[contentViewController release];
	[optionsViewController release];
	
    [super dealloc];
}

//***************************************************************************

#pragma mark Class Methods

+ (NSBundle *)bundle
{
	return [NSBundle bundleForClass:[self class]];
}

+ (BOOL)initializeClass:(NSBundle *)aBundle
{
	return YES;
}

+ (NSEnumerator *)pluginsAvailable
{
	id plugin = [[RMSSamplePlugin alloc] init];
	
	if (plugin)
	{
		return [[NSArray arrayWithObject:[plugin autorelease]] objectEnumerator];
	}
	
	return nil;
}

+ (NSString *)pluginName
{
	return NSLocalizedStringFromTableInBundle(@"PluginName", nil, [RMSSamplePlugin bundle], @"Localizable");
}

+ (NSString *)pluginAuthor
{
	return @"My Company Name";
}

+ (NSImage *)pluginIcon
{
	NSBundle *bundle = [RMSSamplePlugin bundle];
	NSString *iconFilename = [bundle objectForInfoDictionaryKey:@"CFBundleIconFile"];
	return [[[NSImage alloc] initWithContentsOfFile:[bundle pathForImageResource:iconFilename]] autorelease];
}

+ (NSString *)pluginDescription;
{
	return NSLocalizedStringFromTableInBundle(@"PluginDescription", nil, [RMSSamplePlugin bundle], @"Localizable");
}

+ (BOOL) canCreateNewPage:(NSError **)errorRef
{
	// Return NO and populate the errorRef's localizedDescription if you want to stop a user from creating a new page.
	return YES;
}

+ (void) willMigrateAddonLocation
{
	// If you'd like to be notified if the user migrates their addon folder to a new location,
	// implement this method and do any necessary work before returning
}

@end

//***************************************************************************

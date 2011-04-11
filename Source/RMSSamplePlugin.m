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
#import "RMSSparkleLoader.h"

//***************************************************************************

@implementation RMSSamplePlugin

@synthesize content, emitRawContent;

//***************************************************************************

- (void)checkForUpdates
{
	static SUUpdater *sUpdater = nil;
	
	if (sUpdater == nil)
	{
		sUpdater = [[RMSSparkleLoader sparkleLoader] updaterForBundle:[NSBundle bundleForClass:[self class]]];
		NSLog(@"Updater: %@", sUpdater);
		
		// Normal Sparkle update logic goes here.
		// Needs to be inside the block so as to avoid happening once
		// per plugin instance.
	}
}

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
		[self checkForUpdates];
		
		contentViewController = [[RMSSamplePluginContentViewController alloc] initWithRepresentedObject:self];
	}
	
	return contentViewController.view;
}

- (id)contentHTML:(NSDictionary *)params
{
	NSString *string = (contentViewController.content) ?: self.content;
	
	id result;
	
	if (self.emitRawContent == NO) result = [NSString stringWithString:string];
	else result = [self contentOnlySubpageWithEntireHTML:[NSString stringWithString:string] name:nil];
	
	return result;
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

//***************************************************************************

#pragma mark KVO Broadcasting

- (NSArray *)visibleKeys
{
	// Add any values here that cause the document to need saving.
	// This allows us to use KVO to catch any changes and do our broadcasting
	// instead of writing the setters manually. Properties and KVO FTW!
	
	return [NSArray arrayWithObjects:@"emitRawContent", nil];
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

- (void)encodeWithCoder:(NSCoder *)aCoder
{
	[super encodeWithCoder:aCoder];
	
	[aCoder encodeObject:(contentViewController.content) ?: self.content forKey:@"Content String"];
	[aCoder encodeObject:[NSNumber numberWithBool:self.emitRawContent] forKey:@"Emit Raw Content"];
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
	[super initWithCoder:aDecoder];
	
	self.content = [aDecoder decodeObjectForKey:@"Content String"];
	self.emitRawContent = [[aDecoder decodeObjectForKey:@"Emit Raw Content"] boolValue];
	
	[self finishSetup];
	
	return self;
}

- (id)init
{
	[super init];
	
	self.content = nil;
	self.emitRawContent = NO;
	
	[self finishSetup];
	
	return self;
}

- (void)dealloc
{
	[self stopObservingVisibleKeys];
	
	self.content = nil;
	
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

@end

//***************************************************************************

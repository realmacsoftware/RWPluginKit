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
#import "RWHTMLViewCM.h"
#import "RMSSamplePluginOptionsViewController.h"
#import "RMSSamplePluginContentViewController.h"

//***************************************************************************

@implementation RMSSamplePlugin

static NSBundle *sPluginBundle = nil;
// static NSDictionary *gQuickInsertDictionary = nil;

@synthesize content, emitRawContent;

//***************************************************************************

#pragma mark Actions

- (IBAction)quickInsert:(id)sender
{
	// [[self documentWindow] makeFirstResponder:htmlContent];
	// 
	// NSString *templateToInsert = [gQuickInsertDictionary objectForKey:[sender titleOfSelectedItem]];
	// 
	// if (templateToInsert)
	// {
	// 	NSArray *templateParts = [templateToInsert componentsSeparatedByString:@"%c"];
	// 	NSRange selectedRange = [htmlContent selectedRange];
	// 	NSTextStorage *storage = [htmlContent textStorage];
	// 	NSString *firstPart = [templateParts objectAtIndex:0];
	// 	if ([htmlContent shouldChangeTextInRange:selectedRange replacementString:[NSString stringWithFormat:@"%@%@%@", firstPart, [[htmlContent string] substringWithRange:selectedRange], [templateParts count] > 1 ? [templateParts objectAtIndex:1] : @""]])
	// 	{
	// 		[storage beginEditing];
	// 		[storage insertAttributedString:[htmlContent colorize:firstPart] atIndex:selectedRange.location];
	// 		if ([templateParts count] > 1 && ![[templateParts objectAtIndex:1] isEqualToString:@""])
	// 		{
	// 			[storage insertAttributedString:[htmlContent colorize:[templateParts objectAtIndex:1]] atIndex:selectedRange.location + selectedRange.length + [firstPart length]];
	// 		}
	// 		[storage endEditing];
	// 		[htmlContent didChangeText];
	// 		[[htmlContent undoManager] setActionName:@"Quick Insert"];
	// 		selectedRange.location += [firstPart length] + selectedRange.length;
	// 		selectedRange.length = 0;
	// 		[htmlContent setSelectedRange:selectedRange];
	// 		[self performSelector:@selector(textDidChange:) withObject:nil afterDelay:0];
	// 	}
	// }
}

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

- (void)encodeWithCoder:(NSCoder *)aCoder
{
	// Dead Code Path
	// This is only hear to show how to load plugins when not using the sandwich based routines.
	
	[aCoder encodeObject:(contentViewController.content) ?: self.content];
	[aCoder encodeObject:[NSNumber numberWithBool:self.emitRawContent]];
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
	// Dead Code Path
	// This has been superseded by the sandwich based routines.
	
	if ((self = [self init]))
	{
		self.content = [aDecoder decodeObject];
		self.emitRawContent = [[aDecoder decodeObject] boolValue];
	}
	
	return self;
}

- (id)init
{
	[super init];
	
	self.content = nil;
	self.emitRawContent = NO;
	
	contentViewController = nil;
	optionsViewController = nil;
	
	[self observeVisibleKeys];
	
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
	return sPluginBundle;
}

+ (BOOL)initializeClass:(NSBundle *)aBundle
{
	if (sPluginBundle) return NO;
	
	sPluginBundle = [aBundle retain];
	// gQuickInsertDictionary = [[NSDictionary alloc] initWithContentsOfFile:[aBundle pathForResource:@"quickInsertTemplates" ofType:@"plist"]];
	
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
	return RMLocalizedStringInSelfBundle(@"PluginName");
}

+ (NSString *)pluginAuthor
{
	return @"My Company Name";
}

+ (NSImage *)pluginIcon
{
	NSString *pathToIcon = [RMSelfBundle() pathForImageResource:[RMSelfBundle() objectForInfoDictionaryKey:@"CFBundleIconFile"]];
	
	return [[[NSImage alloc] initWithContentsOfFile:pathToIcon] autorelease];
}

+ (NSString *)pluginDescription;
{
	return RMLocalizedStringInSelfBundle(@"PluginDescription");
}

@end

//***************************************************************************

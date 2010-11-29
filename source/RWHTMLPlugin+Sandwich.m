//***************************************************************************

// Copyright (C) 2008 ~ 2010 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RWHTMLPlugin+Sandwich.h"
#import "RWHTMLPluginContentViewController.h"

//***************************************************************************

@implementation RWHTMLPlugin (Sandwich)

+ (void)load
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	
	[RMSandwich setFactoryClass:self forType:@"RapidWeaver HTML Code Data"];
	
	[pool drain];
}

+ (id)createWithSandwich:(RMSandwich*)sandwich
{
	RWHTMLPlugin* plugin = [[[RWHTMLPlugin alloc] init] autorelease];
	
	NSDictionary* dictionary = [sandwich sandwichFillingForVersion:0].dictionary;
	NSDictionary* files = [sandwich sandwichFillingForVersion:0].files;
	
	NSString* pathToHTMLContents = [files objectForKey:@"Contents.html"];
	if(pathToHTMLContents)
	{
		plugin.content = [[NSString stringWithContentsOfFile:pathToHTMLContents encoding:NSUTF8StringEncoding error:NULL] retain];
	}
	
	NSNumber* applyThemeToPageNumber = [dictionary objectForKey:@"ApplyThemeToPage"];
	if(applyThemeToPageNumber) [plugin setEmitRawContent:(![applyThemeToPageNumber boolValue])];
	
	return plugin;
}

- (RMSandwich*)sandwich
{
	RMSandwich* sandwich = [RMSandwich sandwichWithType:@"RapidWeaver HTML Code Data"];
	
	NSDictionary* dictionary = [NSDictionary dictionaryWithObjectsAndKeys:
		[NSNumber numberWithBool:(self.emitRawContent == NO)], @"ApplyThemeToPage", nil];
	[sandwich setDictionary:dictionary forVersion:0];
	
	NSString* pathToHTMLContents = [TheFileManager() temporaryFilenameWithPrefix:@"HTMLPageSave" extension:@"html"];
	
	NSString *html = (contentViewController.content) ?: self.content;
	[html writeToFile:pathToHTMLContents atomically:NO encoding:NSUTF8StringEncoding error:NULL];
	
	NSDictionary* files = [NSDictionary dictionaryWithObjectsAndKeys:pathToHTMLContents, @"Contents.html", nil];
	[sandwich setFiles:files forVersion:0];
	
	return sandwich;
}

@end

//***************************************************************************

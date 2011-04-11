//
//  RMSSparkleLoader.m
//  RMSSamplePlugin
//
//  Created by Kevin LaCoste on 11-04-11.
//  Copyright 2011 Realmac Software. All rights reserved.
//

#import "RMSSparkleLoader.h"


@implementation RMSSparkleLoader

- (BOOL)loadSparkle
{
	// Dig into the plugin bundle to get at the framework.
	
	NSBundle *bundle = [NSBundle bundleForClass:[self class]];
	NSString *path = [[bundle sharedFrameworksPath] stringByAppendingPathComponent:@"Sparkle.framework"];
	
	return [[NSBundle bundleWithPath:path] load];
}

- (BOOL)isSparkleLoaded
{
	BOOL result = NO;
	
	if (NSClassFromString(@"SUUpdater"))
	{
		result = YES;
	}
	
	else
	{
		if ([self loadSparkle])
		{
			result = YES;
		}
	}
	
	return result;
}


#pragma mark Public Interface

- (SUUpdater *)updaterForBundle:(NSBundle *)bundle
{
	SUUpdater *updater = nil;
	
	if ([self isSparkleLoaded])
	{
		updater = [SUUpdater updaterForBundle:bundle];
	}
	
	return updater;
}

#pragma mark Object Lifecycle

+ (RMSSparkleLoader *)sparkleLoader
{
	return [[[[self class] alloc] init] autorelease];
}

@end

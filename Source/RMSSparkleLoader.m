//
//  RMSSparkleLoader.m
//  RMSSamplePlugin
//
//  Created by Kevin LaCoste on 11-04-11.
//  Copyright 2011 Realmac Software. All rights reserved.
//

#import "RMSSparkleLoader.h"

@implementation RMSSparkleLoader

- (NSString *)_sparkleFrameworkPath
{
	NSBundle *bundle = [NSBundle bundleForClass:[self class]];
	
	return [[bundle sharedFrameworksPath] stringByAppendingPathComponent:@"Sparkle.framework"];
}

- (BOOL)_loadSparkleAndReturnError:(NSError **)error
{
	// Attempt to load our bundled copy of the framework.
	
	return [[NSBundle bundleWithPath:[self _sparkleFrameworkPath]] loadAndReturnError:error];
}

- (BOOL)_isSparkleLoaded
{
	Class sparkleClass = NSClassFromString(@"SUUpdater");
	if (sparkleClass == nil) {
		return NO;
	}
	
	return YES;
}

#pragma mark - Public Interface

- (SUUpdater *)updaterForBundle:(NSBundle *)bundle error:(NSError **)error
{
	BOOL isLoaded = [self _isSparkleLoaded];
	if (isLoaded == YES) {
		return [SUUpdater updaterForBundle:bundle];
	}
	
	isLoaded = [self _loadSparkleAndReturnError:error];
	if (isLoaded) {
		return [SUUpdater updaterForBundle:bundle];
	}
	
	return nil;
}

- (SUUpdater *)updaterForBundle:(NSBundle *)bundle
{
	return [self updaterForBundle:bundle error:NULL];
}

#pragma mark - Object Lifecycle

+ (RMSSparkleLoader *)sparkleLoader
{
	return [[[[self class] alloc] init] autorelease];
}

@end

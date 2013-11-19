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

- (NSError *)_sparkleError
{
	NSDictionary *errorInfo = @{
		NSLocalizedDescriptionKey : NSLocalizedString(@"Sparkle returned nil for the specified bundle.", nil),
		NSLocalizedRecoverySuggestionErrorKey : NSLocalizedString(@"Time to debug Sparkle!", nil)
	};
	
	return [NSError errorWithDomain:@"RMSSparkleLoaderDomain" code:0 userInfo:errorInfo];
}

- (SUUpdater *)_updaterForBundle:(NSBundle *)bundle error:(NSError **)error
{
	SUUpdater *updater = [SUUpdater updaterForBundle:bundle];
	if (updater != nil) {
		return updater;
	}
	
	// If Sparkle didn't return an SUUpdater, fill out the error object.
	
	if (error != NULL) {
		*error = [self _sparkleError];
	}
	
	return nil;
}

#pragma mark - Public Interface

- (SUUpdater *)updaterForBundle:(NSBundle *)bundle error:(NSError **)error
{
	BOOL isLoaded = [self _isSparkleLoaded];
	if (isLoaded == YES) {
		return [self _updaterForBundle:bundle error:error];
	}
	
	isLoaded = [self _loadSparkleAndReturnError:error];
	if (isLoaded) {
		return [self _updaterForBundle:bundle error:error];
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

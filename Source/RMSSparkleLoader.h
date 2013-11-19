//
//  RMSSparkleLoader.h
//  RMSSamplePlugin
//
//  Created by Kevin LaCoste on 11-04-11.
//  Copyright 2011 Realmac Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Sparkle/Sparkle.h>

@interface RMSSparkleLoader : NSObject

+ (RMSSparkleLoader *)sparkleLoader;

- (SUUpdater *)updaterForBundle:(NSBundle *)bundle DEPRECATED_ATTRIBUTE;
- (SUUpdater *)updaterForBundle:(NSBundle *)bundle error:(NSError **)error;

@end

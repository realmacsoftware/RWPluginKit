//
//  CrashChecker.h
//  RapidWeaver
//
//  Created by Tom Bradley on 03/12/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <WebKit/WebKit.h>

@interface RWCrashChecker : NSObject

+ (NSArray *)recognisedAppLibraries;

+ (NSArray *)perpetratorsForCallStack:(NSArray *)callStack;
+ (NSString *)descriptionForLibrary:(NSString *)library;

@end



//
//  RWErrorReporter.h
//  RapidWeaver
//
//  Copyright 2011 Realmac Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface RWErrorReporter : NSObject
{
	// Nothing to see here.
}

+ (void)reportError:(NSString *)error context:(NSString *)context DEPRECATED_ATTRIBUTE;
+ (void)reportErrorWithTitle:(NSString *)title message:(NSString *)message;

+ (void)reportError:(NSError *)error;
+ (void)reportException:(NSException *)exception;

@end

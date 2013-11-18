//***************************************************************************

// Copyright (C) 2009 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface RWPlugin : NSObject
{
	NSDictionary *attributes;
	NSBundle *bundle;
}

@property (nonatomic, retain) NSDictionary *attributes;
@property (nonatomic, retain) NSBundle *bundle;

// Designated initializer?
// Need to review code that calls these initializers and determine
// what the preferred behaviour is and then clean up the initializers.

- (id)initWithPluginAttributes:(NSDictionary *)attributes;
- (id)initWithPath:(NSString *)path;

// Creates a plugin object and initializes it's bundle property.
// The bundle is not loaded simply by creating a plugin object
// so there shouldn't be any side effects to this.

+ (instancetype)pluginWithPath:(NSString *)path;

- (BOOL)load;
- (BOOL)preflight;
- (BOOL)isVisible;
- (BOOL)isRetired;

- (NSNumber *)bundleAPIVersion;
- (NSString *)bundleIdentifier;

- (NSComparisonResult)nameCompare:(RWPlugin *)inPlugin;

- (NSString *)name;
- (NSString *)buildString;
- (NSString *)version DEPRECATED_ATTRIBUTE;
- (NSString *)versionString;
- (NSString *)path;
- (NSString *)comments;
- (Class)factory;

+ (NSString *)pluginNameAtPath:(NSString *)path;
+ (NSInteger)pluginVersionAtPath:(NSString *)path;

@end

//***************************************************************************

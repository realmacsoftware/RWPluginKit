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

@property (nonatomic, strong) NSDictionary *attributes;
@property (nonatomic, strong) NSBundle *bundle;

@property (nonatomic) BOOL disabled;

+ (instancetype)pluginWithPath:(NSString *)path;
- (id)initWithPath:(NSString *)path;

- (NSError *)load;
- (NSError *)preflight;
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
- (NSString *)author;
- (NSImage *)icon;
- (NSURL *)supportURL;
- (Class)factory;

+ (NSString *)pluginNameAtPath:(NSString *)path;
+ (NSInteger)pluginVersionAtPath:(NSString *)path;

@end

//***************************************************************************

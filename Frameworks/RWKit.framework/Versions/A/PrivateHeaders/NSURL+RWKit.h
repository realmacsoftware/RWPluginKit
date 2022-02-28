//
//  NSURL+RWKit.h
//  RWKit
//
//  Created by Tom Bradley on 09/03/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (Paths)

#pragma mark - Application Support (all versions)

// Location of common RW application group support (group container)
+ (NSURL *)rwApplicationGroupSupportLocation;

#pragma mark - Application Support (specific versions)

// Location of RW6 application support (private container)
+ (NSURL *)rw6ApplicationSupportLocation;

// Location of RW7 application support (private container)
+ (NSURL *)rw7ApplicationSupportLocation;

#pragma mark - Addons (current version)

// Location of current addons folder (group container or custom location)
+ (NSURL *)rwAddonsLocation;

// Location of application group container addons folder
+ (NSURL *)rwManagedAddonsLocation;

// Returns the last stored path to the custom addons folder. Useful if the custom location bookmark fails to decode
+ (NSString *)rwCustomAddonsLocationLastKnownValidPath;

#pragma mark - Addons (specific versions)

// Location of RW6 addons folder (private container)
+ (NSURL *)rw6AddonsLocation;

// Location of RW7 addons folder (private container or custom location)
// Returns nil if custom location is set and didn't resolve
+ (NSURL *)rw7AddonsLocation;

// Location of RW8 addons folder (group container or custom location)
// Can return nil if a custom location is set and the bookmark didn't resolve correctly
+ (NSURL *)rw8AddonsLocation;

// Returns the last stored path to the RW8 custom addons folder. Useful if the custom location bookmark fails to decode
+ (NSString *)rw8CustomAddonsLocationLastKnownValidPath;

#pragma mark - Paths: App Bundle

+ (NSString *)pathToBuiltInPlugIns;
+ (NSString *)pathToBuiltInThemes;

#pragma mark - Plugin Defaults (all versions)

// Location of directory to store plugin defaults
+ (NSURL *)rwPluginDefaultsSupportLocationWithError:(NSError **)error;

#pragma mark - Paths: User Installed Addons

+ (NSURL *)userInstalledThemesLocationWithError:(NSError **)error;
+ (NSURL *)userInstalledThemeVariationsLocationWithError:(NSError **)error;
+ (NSURL *)userInstalledSnippetsLocationWithError:(NSError **)error;
+ (NSURL *)userInstalledStacksLocationWithError:(NSError **)error;
+ (NSURL *)userInstalledPluginsLocationWithError:(NSError **)error;
+ (NSURL *)pluginToBeInstalledLocationWithError:(NSError **)error;

+ (NSURL *)userInstalledThemesLocation;
+ (NSURL *)userInstalledThemeVariationsLocation;
+ (NSURL *)userInstalledSnippetsLocation;
+ (NSURL *)userInstalledStacksLocation;
+ (NSURL *)userInstalledPluginsLocation;
+ (NSURL *)pluginToBeInstalledLocation;

+ (NSString *)pathToUserInstalledThemes;
+ (NSString *)pathToUserInstalledThemeVariations;
+ (NSString *)pathToUserInstalledSnippets;
+ (NSString *)pathToUserInstalledStacks;
+ (NSString *)pathToUserInstalledPlugins;
+ (NSString *)pathToPluginToBeInstalledDirectory;

#pragma mark - Paths: Disabled Addons

+ (NSURL *)disabledPluginsLocationWithError:(NSError **)error;
+ (NSURL *)disabledThemesLocationWithError:(NSError **)error;
+ (NSURL *)disabledStacksLocationWithError:(NSError **)error;

+ (NSURL *)disabledPluginsLocation;
+ (NSURL *)disabledThemesLocation;
+ (NSURL *)disabledStacksLocation;
+ (NSURL *)disabledBuiltInAddonsFileLocation;

+ (NSString *)pathToDisabledPlugins;
+ (NSString *)pathToDisabledThemes;
+ (NSString *)pathToDisabledStacks;
+ (NSString *)pathToDisabledBuiltInAddonsFile;

#pragma mark - Persistence

// Create custom addon location information for storing to user defaults
- (NSDictionary *)locationInfoWithError:(NSError **)error;

#pragma mark - Bookmarks

- (NSData *)appScopedBookmarkDataWithError:(NSError **)error;
- (NSData *)documentScopedBookmarkDataForDocumentURL:(NSURL *)documentURL withError:(NSError **)error;

#pragma mark - iCloud Drive

- (BOOL)isOniCloudDrive;

#pragma mark - MD5

- (NSData *)contentChecksumWithError:(NSError **)outError;

@end

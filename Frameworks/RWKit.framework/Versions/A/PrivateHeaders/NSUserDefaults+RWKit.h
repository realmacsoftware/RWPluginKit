//
//  NSUserDefaults+RWKit.h
//  RWKit
//
//  Created by Tom Bradley on 09/03/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const RWPreferencesGenericPageIconsKey;

@interface NSUserDefaults (RWKit)

#pragma mark - Standard Prefs (Private container)

// RW8 defaults from private container
+ (NSUserDefaults *)rwPrivateDefaults;

#pragma mark - Shared Prefs (Group container)

// App group defaults for current version
+ (NSUserDefaults *)rwGroupDefaults;

// App group defaults for RW7
+ (NSUserDefaults *)rw7GroupDefaults;

// App group defaults for RW8
+ (NSUserDefaults *)rw8GroupDefaults;

#pragma mark - Migration

+ (BOOL)rw8HasPerformedMigration;
+ (void)setRW8HasPerformedMigration:(BOOL)hasPerformedMigration;

#pragma mark - Custom addon location

// Are custom addon locations present in user defaults
+ (BOOL)rw7HasCustomAddonLocation;
+ (BOOL)rw8HasCustomAddonLocation;

// Returns the info dict {bookmarkData:, path:} for the custom addon location
+ (NSDictionary *)rw7CustomAddonLocationInfo;
+ (NSDictionary *)rw8CustomAddonLocationInfo;

// Save custom addon location info to user defaults
+ (void)setRWCustomAddonLocationInfo:(NSDictionary *)locationInfo;

@end

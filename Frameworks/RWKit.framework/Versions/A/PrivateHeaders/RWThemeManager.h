//
//  RWThemeManager.h
//  RapidWeaver
//
//  Created by Mark Davis on Thu Jun 17 2004.
//  Copyright (c) 2004 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RMKit/RMKit.h>
#import "RWKit.h"

@class RWTheme;

extern NSString *const RWThemeManagerWillRemoveThemeNotification;
extern NSString *const RWThemeManagerDidRemoveThemeNotification;
extern NSString *const RWThemeManagerCustomStylesDidChangeNotification;

extern NSString *const RWThemeManagerDidEnableThemeNotification;
extern NSString *const RWThemeManagerDidDisableThemeNotification;

@interface RWThemeManager : NSObject

+ (instancetype)sharedInstance;

// compare version strings
+ (BOOL)version:(NSString *)a greaterThan:(NSString *)b;

// return the version of the object at path
+ (NSString *)getObjectVersion:(NSString *)path;
+ (NSDictionary *)getObjectPlist:(NSString *)path;

// return the version of the object at the given path
+ (NSString *)versionForPath:(NSString*)name;
+ (NSString *)versionStringForPath:(NSString *)path;

+ (BOOL)isApplicationSupportTheme:(RWTheme *)theme;
+ (BOOL)askUserDeleteTheme:(RWTheme *)theme;
+ (BOOL)removeTheme:(RWTheme *)theme;

+ (NSArray *)stackExtensions;

/*
 
 */

// add a theme to the registry; use this once the app is running
// (returns YES if the object replaced an existing object in the list)
- (BOOL)addExternalThemeAtPath:(NSString *)path;

// call this during application startup and the initial scan
// (returns YES if the object replaced an existing object in the list)
- (BOOL)registerObjectAtPath:(NSString *)path external:(BOOL)external;

// Bulk object registration
- (void)registerObjectsAtPaths:(NSArray *)paths;

// Rebuild theme category index
- (void)refreshThemeCategories;

// Removes the cached plist data for a theme.
// Necessary when deleting themes or replacing with
// newer versions during double-click installs.
- (void)removeCachedDataForTheme:(RWTheme *)inTheme;

- (NSArray *)cachedPluginPaths;

- (NSDictionary *)themePropertiesAtPath:(NSString *)path error:(NSError **)error;

- (NSString *)themeNameAtPath:(NSString *)path;
- (BOOL)themeAtPathIsTextBased:(NSString *)path;

- (void)toggleThemeEnabled:(RWTheme *)theme;

/*
 
 */

extern NSString *const RWThemeManagerThemesKey;
@property (readonly, copy, nonatomic) NSArray *themes;
@property (readonly, copy, nonatomic) NSArray *responsiveThemes;
@property (readonly, copy, nonatomic) NSArray *nonClassicThemes;
@property (readonly, strong, nonatomic) NSMutableArray *disabledThemes;

@property (nonatomic, strong) NSArrayController *themesArrayController;

// return the theme matching the given name
- (RWTheme *)themeForName:(NSString*)name;

// remove the theme
- (void)removeTheme:(RWTheme *)theme;

@end

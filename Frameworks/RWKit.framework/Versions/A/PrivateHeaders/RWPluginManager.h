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

@class RWPage;
@class RWPlugin;

//***************************************************************************

#define kPluginCacheBigIcons	0
#define kPluginCacheSmallIcons	1

//***************************************************************************

extern NSString * const RWPluginManagerWillRemovePluginNotification;
extern NSString * const RWPluginManagerDidRemovePluginNotification;
extern NSString * const RWPluginManagerPluginsLoadedNotification;

//***************************************************************************

@interface RWPluginManager : NSObject

@property (nonatomic, strong) NSArrayController *pluginsArrayController;
@property (nonatomic, strong) NSMutableArray *plugins; // only enabled plugins
@property (nonatomic, strong, readonly) NSArray *hiddenPlugins;
@property (nonatomic, strong) NSMutableArray *allPlugins; // all plugins, including disabled plugins
@property (nonatomic) BOOL isStacksInstalled;

+ (NSArray *)pluginExtensions;
+ (BOOL)isPluginExtension:(NSString *)extension;

+ (RWPluginManager *)sharedInstance;

- (NSImage *)iconForClass:(id)inClass size:(BOOL)inSmallIcons;
- (NSImage *)iconForPage:(RWPage *)inPage size:(BOOL)inSmallIcons;
- (NSImage *)iconForPlugin:(RWPlugin *)inPlugin size:(BOOL)inSmallIcons;

- (NSImage *)iconForClass:(id)inClass size:(BOOL)inSmallIcons selected:(BOOL)selected;
- (NSImage *)iconForPage:(RWPage *)inPage size:(BOOL)inSmallIcons selected:(BOOL)selected;
- (NSImage *)iconForPlugin:(RWPlugin *)inPlugin size:(BOOL)inSmallIcons selected:(BOOL)selected;

- (NSImage *)addMenuIconForPlugin:(RWPlugin *)inPlugin selected:(BOOL)selected;

- (RWPlugin *)pluginForIdentifier:(NSString *)identifier;

- (void)registerInstallFailed:(RWPlugin *)plugin;

- (NSArray *)loadPluginsAtPaths:(NSArray *)paths;
- (void)deletePlugin:(RWPlugin *)plugin;

- (void)enablePlugin:(RWPlugin *)plugin;
- (void)disablePlugin:(RWPlugin *)plugin;
- (void)togglePluginEnabled:(RWPlugin *)plugin; // calls one of the above two methods - inverts state

@end

//***************************************************************************

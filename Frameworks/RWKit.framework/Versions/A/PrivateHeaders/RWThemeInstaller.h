/* RWThemeInstaller */

#import <Cocoa/Cocoa.h>

extern NSString *const RWThemeInstallerDidInstallThemeNotification;
extern NSString *const RWThemeInstallerDidUpdateThemeNotification;

@interface RWThemeInstaller : NSObject

+ (NSArray *)installAllObjects;

+ (BOOL)installObjectAtPath:(NSString *)path;

+ (void)uninstallAddons;

// The following methods return the requested path.
// They do not create or check for it's presence.

+ (NSURL *)appSupportDirectoryURL;
+ (NSURL *)addonsUninstallFileURL;
+ (void)chooseAppSupportDirectory;
+ (void)chooseAppSupportDirectoryBypassingConfirmation;
+ (void)clearAppSupportDirectory;
+ (BOOL)hasUserSpecifiedAppSupportDirectory;
+ (NSString *)appSupportPathForNextLaunch;

+ (NSString *)pathToBuiltInThemes;
+ (NSString *)pathToBuiltInPlugIns;

+ (NSString *)pathToApplicationSupport;
+ (NSString *)pathToUserInstalledThemes;
+ (NSString *)pathToUserInstalledThemeVariations;
+ (NSString *)pathToUserInstalledEditorThemes;
+ (NSString *)pathToUserInstalledSnippets;
+ (NSString *)pathToUserInstalledPlugins;

+ (NSString *)pathForItemNamed:(NSString *)filename;
+ (NSDictionary *)pathsForItemsNamed:(NSArray *)filenames;
+ (NSString *)pathForItemWithIdentifier:(NSString *)identifier;
+ (NSDictionary *)pathsForItemsWithIdentifiers:(NSArray *)identifiers;

@end

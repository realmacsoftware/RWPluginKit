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

+ (NSURL *)addonsUninstallFileURL;
+ (void)clearAppSupportDirectory;


+ (NSString *)pathForItemNamed:(NSString *)filename;
+ (NSDictionary *)pathsForItemsNamed:(NSArray *)filenames;
+ (NSString *)pathForItemWithIdentifier:(NSString *)identifier;
+ (NSDictionary *)pathsForItemsWithIdentifiers:(NSArray *)identifiers;

@end

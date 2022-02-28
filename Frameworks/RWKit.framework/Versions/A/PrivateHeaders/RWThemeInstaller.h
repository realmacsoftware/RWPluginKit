/* RWThemeInstaller */

#import <Cocoa/Cocoa.h>

extern NSString *const RWThemeInstallerDidInstallThemeNotification;
extern NSString *const RWThemeInstallerDidUpdateThemeNotification;

@interface RWThemeInstaller : NSObject

+ (void)setShouldLoad3rdPartyThemes:(BOOL)shouldLoad;
+ (void)setShouldLoad3rdPartyPlugins:(BOOL)shouldLoad;

+ (NSArray *)installAllObjects;

+ (void)uninstallAddons;

// The following methods return the requested path.
// They do not create or check for it's presence.

+ (NSURL *)addonsUninstallFileURL;

+ (NSString *)pathForItemNamed:(NSString *)filename;
+ (NSDictionary *)pathsForItemsNamed:(NSArray *)filenames;
+ (NSString *)pathForItemWithIdentifier:(NSString *)identifier;
+ (NSDictionary *)pathsForItemsWithIdentifiers:(NSArray *)identifiers;

@end

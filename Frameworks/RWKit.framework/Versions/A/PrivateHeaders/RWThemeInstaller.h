/* RWThemeInstaller */

#import <Cocoa/Cocoa.h>

@interface RWThemeInstaller : NSObject

+ (void)installAllObjects;

+ (BOOL)installObjectAtPath:(NSString *)path;

// The following methods return the requested path.
// They do not create or check for it's presence.

+ (NSURL *)appSupportDirectoryURL;
+ (void)chooseAppSupportDirectory;
+ (void)clearAppSupportDirectory;
+ (BOOL)hasUserSpecifiedAppSupportDirectory;
+ (NSString *)appSupportPathForNextLaunch;

+ (NSString *)pathToBuiltInThemes;
+ (NSString *)pathToBuiltInPlugIns;

+ (NSString *)pathToApplicationSupport;
+ (NSString *)pathToUserInstalledThemes;
+ (NSString *)pathToUserInstalledThemeVariations;
+ (NSString *)pathToUserInstalledSnippets;
+ (NSString *)pathToUserInstalledPlugins;

+ (NSString *)pathForItemNamed:(NSString *)filename;

@end

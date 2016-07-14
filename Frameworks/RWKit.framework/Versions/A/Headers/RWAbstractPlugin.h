/*
    RWAbstractPlugin.h
    RapidWeaver Plugin Development Kit

    Copyright (c) 2004 Realmac Software Limited. All rights reserved.
*/

#import <Cocoa/Cocoa.h>

#import "RWKit/RWPluginProtocol.h"
#import "RWKit/RWDocumentProtocol.h"

@class RMHTML;
@class RWSharedStorage;

extern NSString *const kRWPluginChangedNotification;
extern NSString *const kRWPluginChangedInvertNotification;
extern NSString *const kRWPluginExportStatusNotification;
extern NSString *const kRWCurrentMediaChangedNotification;
extern NSString *const kRWPluginPageSettingsRequestNotification;
extern NSString *const kRWDoubleClickedMediaNotification;

@interface RWAbstractPlugin : NSObject <RWPlugin, NSCoding>

- (NSDocument <RWDocument> *)document;

- (NSObject <RWPage> *)page;
- (NSString *)uniqueID;

+ (void)clearSharedPluginDataForDocument:(NSDocument<RWDocument> *)document;
+ (RMSandwich *)sharedPluginSandwichForDocument:(NSDocument<RWDocument> *)document;
+ (void)loadSharedPluginDataSandwich:(RMSandwich *)sandwich forDocument:(NSDocument<RWDocument> *)document;

+ (BOOL)canCreateNewPage:(NSError **)errorRef currentPages:(NSArray *)currentPages;
+ (void)willMigrateAddonLocation;

- (BOOL)canPerformExportForMode:(NSString *)mode errorMessage:(NSString **)errorMessage;

+ (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)params;
- (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)params;

- (NSString *)contentHTML:(NSDictionary *)params;
- (NSString *)sidebarHTML:(NSDictionary *)params;
- (NSString *)pageContentHeaders:(NSDictionary *)params;

- (void)broadcastPluginChanged;
- (void)broadcastPluginExportStatus:(NSString *)message progress:(CGFloat)percent;
- (void)broadcastMediaChanged;
- (void)broadcastPluginSettingsRequest;

- (NSArray *)directoryContents:(NSString *)path;

- (NSString *)tempFilesDirectory:(NSString *)name;
+ (NSString *)tempFilesDirectory:(NSString *)name forPlugin:(RWAbstractPlugin *)plugin;
+ (NSString *)tempFilesDirectory:(NSString *)name forUniqueID:(NSString *)unique;

// Return paths for temporary file storage. These calls don't create the folder.
// Return paths of the form:
// --> path/to/tmp/RapidWeaver
// --> path/to/tmp/RapidWeaver/processID

+ (NSString *)pathToTempDirectory;
+ (NSString *)pathToAppTempDirectory; // Process ID version.

- (NSString *)pathToThemeFile:(NSString *)file params:(NSDictionary *)params correction:(NSInteger)depth;

- (NSMutableString *)updatePageTemplate:(NSMutableString *)pageTemplate params:(NSDictionary *)params depth:(NSInteger)depth;

- (NSMutableDictionary *)contentOnlySubpageWithHTML:(NSString *)content name:(NSString *)name;
- (NSMutableDictionary *)contentOnlySubpageWithData:(NSData *)content name:(NSString *)name;
- (NSMutableDictionary *)contentOnlySubpageWithEntireHTML:(NSString *)content name:(NSString *)name;

- (NSMutableDictionary *)customSubpageWithData:(NSData *)content name:(NSString *)name destination:(NSString *)destination;

- (void)cancelExport;

#pragma mark Resource Access & Linking

// Returns a flat list of site resources.

- (NSArray *)resourceInfoList;

// Returns a URL string that takes into account the user's current link setting as specified in the preferences.
// Passing nil will result in an empty string being returned.
// Note: Results are only valid if called during export!

- (NSString *)linkForResourceWithIdentifier:(NSString *)identifier;

#pragma mark NSURL Bookmark Support

- (NSString *)registerFileURL:(NSURL *)fileURL error:(NSError **)error;
- (void)removeFileReferenceForToken:(NSString *)token;
- (NSURL *)fileURLForToken:(NSString *)token error:(NSError **)error;

@end

@interface RWAbstractPlugin (Deprecated)

- (NSMutableDictionary *)pluginDefaults __deprecated;
- (void)setPluginDefaults:(NSDictionary *)defaults __deprecated;

- (void)broadcastPluginChangedInvert __deprecated;
- (NSMutableDictionary *)pluginSettingsValueForDisplay:(NSString *)display value:(id)value __deprecated;
- (RWSharedStorage *)sharedPluginStorage __deprecated;

@end

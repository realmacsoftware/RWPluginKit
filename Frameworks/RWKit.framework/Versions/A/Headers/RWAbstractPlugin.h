/*
    RWAbstractPlugin.h
    RapidWeaver Plugin Development Kit

    Copyright (c) 2004 Realmac Software Limited. All rights reserved.
*/

#import <Cocoa/Cocoa.h>

#import "RWKit/RWPluginProtocol.h"
#import "RWKit/RWDocumentProtocol.h"

@class RMHTML;
@class RWSearchResult;

extern NSString* const kRWPluginStartedLoadingNotification;
extern NSString* const kRWPluginFinishedLoadingNotification;
extern NSString* const kRWPluginStartedMigrationNotification;
extern NSString* const kRWPluginFinishedMigrationNotification;
extern NSString *const kRWPluginChangedNotification;
extern NSString *const kRWPluginChangedInvertNotification;
extern NSString *const kRWPluginExportStatusNotification;
extern NSString *const kRWCurrentMediaChangedNotification;
extern NSString *const kRWPluginPageSettingsRequestNotification;
extern NSString *const kRWDoubleClickedMediaNotification;

extern NSString *const kRWPluginChangedReloadPreviewUserInfoKey;

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
- (void)broadcastPluginChangedReloadingPreviews:(BOOL)reloadPreview;
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

- (NSArray <RWPage> *)allPagesUsingPlugin;

#pragma mark Resource Access & Linking

// Returns a flat list of site resources.

- (NSArray *)resourceInfoList;

// Returns a URL string that takes into account the user's current link setting as specified in the preferences.
// Passing nil will result in an empty string being returned.
// Note: Results are only valid if called during export!

- (NSString *)linkForResourceWithIdentifier:(NSString *)identifier;

#pragma mark File References



#pragma mark NSURL Bookmark Support

- (NSString *)registerFileURL:(NSURL *)fileURL error:(NSError **)error DEPRECATED_ATTRIBUTE;
- (void)removeFileReferenceForToken:(NSString *)token DEPRECATED_ATTRIBUTE;
- (NSURL *)fileURLForToken:(NSString *)token error:(NSError **)error DEPRECATED_ATTRIBUTE;

#pragma mark Search Helper

// A helper method - pass in a large block of text and we'll generate search results and call foundBlock for you
// You can call this as many times as you need - but you're still responsible for calling your completion block
// Pass in a userInfo dictionary to reference model objects across search methods
- (void)searchString:(NSString *)haystack forString:(NSString *)needle foundBlock:(void (^)(RWSearchResult *searchResult))foundBlock userInfo:(NSDictionary *)userInfo;

#pragma mark Plugin Defaults

// Allows you to store a dictionary into RapidWeaver's group container to persist global settings.
// Availability: RW8
- (NSMutableDictionary *)pluginDefaults;
- (void)setPluginDefaults:(NSDictionary *)defaults;

@end

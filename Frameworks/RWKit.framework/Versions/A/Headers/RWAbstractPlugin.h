/*
    RWAbstractPlugin.h
    RapidWeaver Plugin Development Kit

    Copyright (c) 2004 Realmac Software Limited. All rights reserved.
*/

#import <Cocoa/Cocoa.h>
#import "RWPluginInterface.h"

@class RMHTML;

@interface RWAbstractPlugin : NSObject <RWPluginProtocol, NSCoding>
{
    id _unused; // this ivar was named _documentWindow: we're renaming it to _unused rather than deleting it to preserve ABI compatibility
    NSMutableDictionary *_themeSpecificOptionsDictionary;
    NSString *_uniqueID;
    id _unused2; // this ivar was _document and used to keep track of the parent document: we're renaming it to _unused rather than deleting it to preserve ABI compatibility
}

- (id)document;
- (void)setDocument:(id)document;

- (NSWindow *)documentWindow;
- (void)setDocumentWindow:(NSWindow *)documentWindow;

- (NSString*)documentPath;

- (NSString *)uniqueID;
- (void)setUniqueID:(NSString *)uniqueID;

+ (NSArray *)extraFilesNeededInExportFolder:(NSDictionary*)params;
- (NSArray *)extraFilesNeededInExportFolder:(NSDictionary*)params;

- (NSString *)contentHTML:(NSDictionary*)params;
- (NSString *)sidebarHTML:(NSDictionary*)params;
- (NSString *)pageContentHeaders:(NSDictionary*)params;

- (void)broadcastPluginChanged;
- (void)broadcastPluginChangedInvert;
- (void)broadcastPluginExportStatus:(NSString*)message progress:(CGFloat)percent;
- (void)broadcastMediaChanged;
- (void)broadcastPluginSettingsRequest;

- (NSArray*)directoryContents:(NSString*)path;

- (NSString*)tempFilesDirectory:(NSString*)name;
+ (NSString*)tempFilesDirectory:(NSString*)name forPlugin:(RWAbstractPlugin*)plugin;
+ (NSString*)tempFilesDirectory:(NSString*)name forUniqueID:(NSString*)unique;

+ (NSString*)rwTempFilesDirectory;
+ (NSString*)appTempFilesDirectory;

- (RMHTML*)exporterWithParams:(NSDictionary*)params;
- (NSString*)pathToThemeFile:(NSString*)file params:(NSDictionary*)params correction:(NSInteger)depth;

- (NSMutableDictionary*)pluginSettingsValueForDisplay:(NSString*)display value:(id)value;

- (NSMutableString*)updatePageTemplate:(NSMutableString*)pageTemplate params:(NSDictionary*)params depth:(NSInteger)depth;

- (NSMutableDictionary*)contentOnlySubpageWithHTML:(NSString*)content name:(NSString*)name;
- (NSMutableDictionary*)contentOnlySubpageWithData:(NSData*)content name:(NSString*)name;
- (NSMutableDictionary*)contentOnlySubpageWithEntireHTML:(NSString*)content name:(NSString*)name;

- (NSMutableDictionary*)customSubpageWithData:(NSData*)content name:(NSString*)name destination:(NSString*)destination;

- (NSMutableDictionary*)pluginDefaults;
- (void)setPluginDefaults:(NSDictionary*)defaults;

@end

//
//  RWManifestCalculator.h
//  RapidWeaver
//
//  Created by Simon Taylor on 10/04/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWPage;

@interface NSDictionary (RWManifestAdditions)
- (NSArray *)paths;
- (NSDictionary *)pages;
- (NSString *)pageID;
- (BOOL)comparable:(NSDictionary *)manifest;
- (NSDictionary *)entryForKey:(NSString *)path;
- (BOOL)compareEntry:(NSDictionary *)b;
- (BOOL)isDocumentManifest;
@end

@interface RWManifestGenerator : NSObject

+ (NSInteger)version;

- (void)enqueueManifestGenerationNamed:(NSString *)manifestName forPath:(NSString *)path page:(NSString *)pageID siteRoot:(NSString *)siteRoot includeDigests:(BOOL)includeDigests;
- (void)enqueueManifestGenerationNamed:(NSString *)manifestName forPaths:(NSArray *)paths root:(NSString *)root page:(NSString *)pageID siteRoot:(NSString *)siteRoot includeDigests:(BOOL)includeDigests;

- (void)enqueueEntryForManifestNamed:(NSString *)manifestName file:(NSString *)file relativeTo:(NSString *)root;

- (NSDictionary *)manifests;

@end

extern NSString *const kRWPageManifestFilename;
extern NSString *const kRWPageManifestPagesKey;
extern NSString *const kRWPageManifestVersionKey;
extern NSString *const kRWPageManifestPageHashesKey;
extern NSString *const kRWPageManifestHashAlgorithmKey;
extern NSString *const kRWPageManifestGenerationDateKey;
extern NSString *const kRWPageManifestPageDigestsKey;

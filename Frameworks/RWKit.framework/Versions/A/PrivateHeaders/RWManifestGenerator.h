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

+ (RWManifestGenerator *)create;

+ (NSInteger)version;

- (NSMutableDictionary *)generateManifestForPath:(NSString *)path forPage:(NSString *)pageID includingDigests:(BOOL)includingDigests;

- (NSMutableDictionary *)generateManifestWithPaths:(NSArray *)paths fromRoot:(NSString *)root forPage:(NSString *)pageID includingDigests:(BOOL)includingDigests;

- (void)addEntryForFile:(NSString *)file toManifest:(NSMutableDictionary *)manifest relativeTo:(NSString *)root;

- (void)updateManifest:(NSDictionary *)manifest atPath:(NSString *)path;

@end

extern NSString *const kRWPageManifestFilename;
extern NSString *const kRWPageManifestPagesKey;
extern NSString *const kRWPageManifestVersionKey;
extern NSString *const kRWPageManifestPageHashesKey;
extern NSString *const kRWPageManifestHashAlgorithmKey;
extern NSString *const kRWPageManifestGenerationDateKey;
extern NSString *const kRWPageManifestPageDigestsKey;

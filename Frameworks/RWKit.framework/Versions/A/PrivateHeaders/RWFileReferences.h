//
//  RWFileReferences.h
//  RWKit
//
//  Created by Tom Bradley on 18/10/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RWDocument;
@class RWFileReference;

NS_ASSUME_NONNULL_BEGIN

@interface RWFileReferences : NSObject

- (instancetype)initWithDocument:(RWDocument *)document;

#pragma mark - Persistence

- (NSArray <RWFileReference *> *)allInternalFileReferences;

- (NSDictionary *)archivableDictionaryForDocumentAtURL:(NSURL *)url error:(NSError **)error;
- (void)restoreFromArchivedDictionary:(NSDictionary *)dictionary error:(NSError **)error;

#pragma mark - Persistence, legacy

- (void)restoreFromLegacyArchivedDictionary:(NSDictionary *)dictionary error:(NSError **)error;

#pragma mark - Add File References

// Convenience method to create a new file reference. Can return nil in case of error.
- (RWFileReference *)addNewFileReferenceForURL:(NSURL *)url internal:(BOOL)internal error:(NSError **)error;

- (void)addFileReference:(RWFileReference *)fileReference;

#pragma mark - Remove File References

- (void)removeFileReferenceWithIdentifier:(NSString *)identifier;

#pragma mark - Querying

- (RWFileReference *)fileReferenceForIdentifier:(NSString *)identifier;

- (NSArray <RWFileReference *> *)fileReferencesWithChecksum:(NSData *)checksum;

#pragma mark - Validation

- (BOOL)canResolveAllFileReferences;

#pragma mark - Repair

- (BOOL)hasBrokenFileReferences;
- (void)repairBrokenFileReferences;
- (NSArray *)brokenFileReferences;

@end

NS_ASSUME_NONNULL_END

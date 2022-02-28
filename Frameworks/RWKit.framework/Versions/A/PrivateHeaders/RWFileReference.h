//
//  RWFileReference.h
//  RapidWeaver
//
//  Created by Tom Bradley on 18/10/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const RWExternalResourceErrorDomain;
extern NSUInteger const RWExternalResourceErrorDocumentNotFound;

typedef NSString RWFileReferenceAccessToken;
typedef NSString RWFileChangedNotificationToken;
typedef void (^FileChangedBlock)(void);

@class RWDocument, RWStorageVolume;

@interface RWFileReference : NSObject

// The unique resource identifier
@property (nonatomic, readonly) NSString *identifier;

// Content checksum
@property (nonatomic, readonly) NSData *checksum;

// Is this resource stored inside the project file
@property (nonatomic, readonly) BOOL storedInDocument;

// The file is resolvable and accessible
@property (nonatomic, readonly) BOOL fileIsAccessible;

// Last error
@property (atomic, readonly) NSError *error;

// Set to YES if the bookmark couldn't be resolved correctly. Can happen when converting pre RW8.1 docs
@property (nonatomic, readonly) BOOL bookmarkRepairRequired;

// Storage volume information, nil if volume is inaccessible
@property (atomic, readonly) RWStorageVolume *volume;

// Last known storage volume name
@property (atomic, readonly) NSString *lastKnownStorageVolumeName;

// Last known storage volume name
@property (atomic, readonly) NSString *lastResolvablePath;

// Path if file is held inside the document. Can be either
//  - Filename if located within the document resources folder
//  - Full path to tmp folder if resource not yet copied to document
@property (atomic, readonly) NSString *internalFilePath;

#pragma mark - New File References

// Create a new external resource object for a URL, normally chosen via NSOpenPanel
+ (instancetype)fileReferenceWithURL:(NSURL *)url storeInDocument:(BOOL)storeInDocument forDocument:(RWDocument *)document;
- (instancetype)initWithURL:(NSURL *)url storeInDocument:(BOOL)storeInDocument forDocument:(RWDocument *)document;

#pragma mark - Document Archivable Bookmarks

// Initialize from an archived data read from a document
+ (instancetype)fileReferenceWithArchiveDictionary:(NSDictionary *)dictionary forDocument:(RWDocument *)document;
- (instancetype)initWithArchiveDictionary:(NSDictionary *)dictionary forDocument:(RWDocument *)document;

// Create an archive pointing to this resource that can be saved to the document
- (NSDictionary *)archivableDictionaryForDocumentAtURL:(NSURL *)url error:(NSError **)error;

#pragma mark - Legacy Document Archivable Bookmarks

// Initialize from legacy archived data read from a document
+ (instancetype)fileReferenceWithLegacyArchiveDictionary:(NSDictionary *)dictionary forDocument:(RWDocument *)document;
- (instancetype)initWithLegacyArchiveDictionary:(NSDictionary *)dictionary forDocument:(RWDocument *)document;

#pragma mark - Resource Changed Notificaitons

- (RWFileChangedNotificationToken *)registerFileChangedBlock:(FileChangedBlock)fileChangedBlock;
- (void)unregisterFileChangedBlockWithToken:(RWFileChangedNotificationToken *)token;

#pragma mark - Preferred Resource Access

// Convenience method for grabbing the file contents as a string
- (NSString *)stringContentsWithError:(NSError **)error;

// Convenience method for grabbing the file contents
- (NSData *)fileContentsWithError:(NSError **)error;

// Convenience method for reading the file as an image
- (NSImage *)imageWithError:(NSError **)error;

// Convenience method for accessing the file as through a file wrapper
- (NSFileWrapper *)fileWrapperWithError:(NSError **)error;

// Convenience method for obtaining the file modification date
- (NSDate *)fileModificationDateWithError:(NSError **)error;

// Convenience method for obtaining the URL of this file reference
- (NSURL *)urlWithError:(NSError **)error;

#pragma mark - Manual Resource Access

// Add this resource to the app sandbox so it may be accessed. Calls must be balanced with stopAccessingWithToken:
- (RWFileReferenceAccessToken *)startAccessingWithError:(NSError **)outError;

// Should be called to remove access from the app sandbox
- (void)stopAccessingWithToken:(RWFileReferenceAccessToken *)token;

#pragma mark - Reassignment

- (void)reassignToURL:(NSURL *)url storeInDocument:(BOOL)storeInDocument error:(NSError **)error;

#pragma mark - Repair

// Check if this file reference is able to resolve
- (BOOL)isValid;

- (BOOL)attemptToRepairBookmark;
- (void)updateFileAvailability;

@end

NS_ASSUME_NONNULL_END

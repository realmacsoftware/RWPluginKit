//***************************************************************************

// Copyright (C) 2007 Realmac Software Pty Ltd
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//***************************************************************************

#import "RMValueObject.h"

//***************************************************************************

@protocol RMDiscardableContent;
@protocol RMFreezing;

@class RMFilesystemObject;

//***************************************************************************

/// A simple protocol for classes that support content that can be temporarily discarded.  The definition of discarded content is up to the receiver, but typically it is a hint that an object is used infrequently and can be be e.g. archived out to disk to free up memory.
/** This protocol closely mirrors a similarly-named protocol that may be available in a future version of Mac OS X. */
@protocol RMDiscardableContent

/// Tells the receiver that the object should be made available for rapid access until a matching -endContentAccess method is encountered.  Returns YES if the object could be made readily available; NO otherwise.
/** This forces the object to be paged in from disk if the object is not already cached, and forces subsequent -setObject: calls to cache the object in memory. */
- (BOOL)beginContentAccess;

/// Tells the receiver that the object no longer needs to be made available for rapid access.  Note that it is up to the implementation to decide whether to it should actually discard the object contents.
- (void)endContentAccess;

/// Discards the object contents if possible, and also marks the receiver's contents as not readily available for rapid access.
- (void)discardContentIfPossible;

/// Returns YES if the receiver's contents is discarded (not readily available); NO otherwise.
- (BOOL)isContentDiscarded;

@end

//***************************************************************************

/// A proxy class for an object that's serialised to disk, and is deserialised into memory on demand as needed.
/** A "paged object" is an abstract class that serialises and de-serialises its container objects to disk, to keep heap memory usage low.  It is intended to be used with potentially huge objects (e.g. 50MB+) where the working set deals with very few of these huge objects at a time and does not require that all of them reside in memory at once.  Any objects that are not required in-memory memory are "paged" out (i.e. serialised to disk) whenever their reference count drops to zero; however, since the RMPagedObject class for that object is still around, you can easily re-access that object using the object property as usual, and the RMPagedObject will de-serialise that object from disk back into memory.  When a paged object is copied, the on-disk backing store will also be duplicated.  A paged object can also be "cached" in memory for efficient access to the object, which is very useful if the vast majority of paged objects are small but a few extremely large ones need to be paged out to disk.  A subclass can determine whether to cache the object by overriding the +shouldCacheObject: method.
  * 
  * This class is an abstract class: it leaves the actual serialisation of objects to disk to concrete subclasses.  The two standard subclasses you'll probably use are RMArchivedObject, which uses the NSCoding protocol to save and load objects, and RMFrozenObject, which uses the RMFreezing and RMThawing protocols to save and load objets.  If you are implementing a concrete subclass of RMPagedObject, override the -readObjectFromPath: and -writeObject:toPath:error: methods to load and save the object from/to disk, respectively.  You should also provide your own (typed) accessor methods in your subclass; e.g. if you are using this to store an NSImage*, subclass this as a new PagedImage class, and implement your own properties that set and return NSImages.  It is also recommended that you override the +preferredExtension method to give your on-disk representations a particular file extension.  You may also override the -setup method to perform any extra initialisation there.  For an example concrete subclass of RMPagedObject, see the RMFrozenString class (which is in a subclass of RMFrozenObject).
  *
  * Note that the paged object may not be deleted when the application terminates; in particular, a paged object's backing store on disk will not be deleted if the application crashes.  This is intentional, since expert users can then peek around in the paged objects' temporary directory to examine any data.  If you really need to make sure that all your files are deleted when the process exits, it's strongly suggested that you track the paths yourself and use atexit() or a similar handler to register a cleanup function.
  *
  * Also note that if you are loading data from a user's document, the user may delete that document while your application is running, and the user probably expects that the application still has their data!  It's strongly suggested that you use the idiom of "RMPagedObject* myLoadedObject = [[RMPagedObject pagedObjectWithPath:myPath deleteOnDisposal:NO] copy]" if you are loading a user's document data.  This will use a separate disk backing store in a temporary file, so that if the user deletes their document while the application is running, the paged object's data will still be available.
  * 
  * If you are using garbage collection, be aware that an object's backing store is only deleted when -finalize is called, but -finalize isn't guaranteed to be called, and -finalize may be run at unpredictable times on background threads.  If you want to make 100% sure that an object's on-disk backing store is deleted, ensure the garbage collector runs via -[NSGarbageCollector collectExhaustively].
  */
@interface RMPagedObject : NSObject<RMValueObject, RMDiscardableContent>
{
	RMFilesystemObject* _filesystemObject;
	
	id<NSCopying, NSObject> _cachedObject;
	BOOL _diskObjectIsOutdated;
	BOOL _keepObjectInMemory;
	
	NSUInteger _cachedHash;
	BOOL _calculatedCachedHash;
}

/// Convenience class method to allocate a new (autoreleased) paged object; the object is only cached in memory if +shouldCacheObject: returns YES.
+ (id)pagedObjectWithObject:(id<NSCopying, NSObject>)object;

/// Convenience class method to allocate a new (autoreleased) paged object.
+ (id)pagedObjectWithObject:(id<NSCopying, NSObject>)object forceCaching:(BOOL)cacheInitially;

/// Convenience class method to allocate a new (autoreleased) paged object.
+ (id)pagedObjectWithPath:(NSString*)path deleteOnDisposal:(BOOL)willDeleteOnDeallocOrFinalize;

/// Returns a preferred extension for the object archived on disk.
+ (NSString*)preferredExtension;

/// Returns a preferred extension for the object archived on disk.
/** This method is intended to be overridden by subclasses, and is used in preference to the +preferredExtension class method if it exists. */
- (NSString*)preferredExtension;

/// Returns YES if the object being paged to/from disk should remain in memory.  Defaults to NO unless specifically overridden by a subclass.
/** Subclasses should override this method and return YES if the given object should be cached in memory. */
+ (BOOL)shouldCacheObject:(id<NSCopying, NSObject>)newObject;

/// Returns YES if the object being paged to/from disk should remain in memory.  Defaults to NO unless specifically overridden by a subclass.
/** This method is intended to be overridden by subclasses, and is used in preference to the +shouldCacheObject class method if it exists.  Subclasses should override this method and return YES if the given object should be cached in memory. */
- (BOOL)shouldCacheObject:(id<NSCopying, NSObject>)newObject;

/// Initialises a new RMPagedObject with a temporary object.
/** The on-disk object will always be deleted when it's disposed (deallocated/finalized). */
- (id)initWithObject:(id<NSCopying, NSObject>)object;

/// Initialises a new RMPagedObject with a temporary object, forcing it to be cached initially.
/** The on-disk object will always be deleted when it's disposed (deallocated/finalized). */
- (id)initWithObject:(id<NSCopying, NSObject>)object forceCaching:(BOOL)cacheInitially;

/// Initialises a new RMPagedObject with the backing store at the given path.
/** The path itself nor the file residing at the path is not checked for its validity until it's actually retrived with the -object method.  The object will be deleted on deallocation/finalization or application termination only if the deleteOnDisposal: parameter is set to YES. */
- (id)initWithPath:(NSString*)path deleteOnDisposal:(BOOL)willDeleteOnDeallocOrFinalize;

/// This is a method designed to be overridden by subclasses to perform any initialisation before freezing or thawing an object.  (Do _not_ override -init!)
- (void)setup;

/// This will delete the backing store object on disk if it exists; its primary use is if you are running under garbage collection and absolutely require the path on disk to be empty right now.
/** After this function returns, the path property will be set to nil, any cached objects in memory will be released, and this object is effectively a zombie and should probably be released. */
- (void)deleteObject;

/// Compare for equality with another paged object.
/** Two paged objects are equal _only_ if the inodes at both those paths are equal.  This is an intended design decision.  If you want to compare equality of the actual objects represented by the paged objects, use the .object property on both objects and compare them for equality. */
- (BOOL)isEqualToPagedObject:(RMPagedObject*)other;

/// You should override this method in your concrete subclass, to return an object that's deserialised from the given path.
/** Do not call this method directly. */
- (id)readObjectFromPath:(NSString*)path;

/// You should override this method in your concrete subclass, to write the given object to the given path.
/** Do not call this method directly. */
- (BOOL)writeObject:(id)object toPath:(NSString*)path error:(NSError**)outError;

/// Returns the object itself, which will be unarchived from disk.
/** The copied object will normally be deleted when it's disposed (deallocated/finalised). */
@property (copy) id<NSCopying, NSObject> object;

/// Returns the actual path to the object on the disk.
@property (readonly, copy) NSString* path;

/// Delete this object when it's disposed of (deallocated/finalized).
@property BOOL deleteOnDisposal;

/// Returns the cached hash value for the currently paged object.
/** Note that this will force the paged object to be loaded into the memory if it has not already been demanded at least once, which is possible if the paged object was created via -initWithPath:deleteOnDisposal (or +pagedObjectWithPath:deleteOnDisposal:). */
@property (readonly) NSUInteger cachedHash;

/// Attempts to return the object in O(1) time if it does not need to be paged in from disk; returns nil otherwise.
@property (readonly, copy) id<NSCopying, NSObject> cachedObject;

@end

//***************************************************************************

/// This is a concrete subclass of RMPagedObject that saves and loads objects to/from disk via the NSCoding protocol.
@interface RMArchivedObject : RMPagedObject

@property (copy) id<NSCoding, NSCopying, NSObject> object;

@end

//***************************************************************************

/// This is a concrete subclass of RMPagedObject that saves and loads objects to/from disk via the RMFreezing and RMThawing protocols.
@interface RMFrozenObject : RMPagedObject
{
	Class _thawObjectClass;
}

@property (copy) id<RMFreezing, NSCopying, NSObject> object;

/// Since the file's contents cannot determine which class is responsible for thawing a certain file, you may specifically specify which class is unresponsible for thawing the object here.
/** If you do not explicitly set this property, it is automatically determined whenever the object itself is set. */
@property (assign) Class thawObjectClass;

@end

//***************************************************************************

/// This is an example RMPagedObject subclass that implements all the methods and properties necessary to be a full-fledged paged object.
@interface RMFrozenString : RMFrozenObject

/// A typed accessor/property to access the string.
@property (copy, getter=object, setter=setObject:) NSString* string;

@end

//***************************************************************************

/// This is an RMPagedObject subclass that can page an NSData object to/from disk.  The path extension for each individual NSData object can be overriden by the pathExtension property.
@interface RMFrozenData : RMFrozenObject
{
	NSString* _pathExtension;
}

/// A typed accessor/property to access the data.
@property (copy, getter=object, setter=setObject:) NSData* data;

/// You may optionally set this property to use a particular path extension for each individual RMFrozenData object.  If the pathExtension property is not explicitly set, it defaults to "dat".
@property (copy) NSString* pathExtension;

@end

//***************************************************************************


#import <Cocoa/Cocoa.h>

// RWSharedStorage
//
// General bucket for plugins to store commonly used objects in. 
//
// We create one of these on demand per-plugin class.
//
@interface RWSharedStorage : NSObject {
@protected
	NSRecursiveLock* _lock;
	NSMutableDictionary* _storage;
}

- (void)lock;
- (void)unlock;

- (NSMutableDictionary*)storage;

@end

// RWAbstractPlugin (RWAbstractPluginPriv)
//
// Private category - currently just handle the shared storage interface
//
@interface RWAbstractPlugin (RWAbstractPluginPriv)

- (RWSharedStorage*)sharedPluginStorage;

@end

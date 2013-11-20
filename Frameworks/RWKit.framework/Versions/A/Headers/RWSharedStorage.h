
#import <Cocoa/Cocoa.h>

/*!
	\brief
	General bucket for plugins to store commonly used objects in.
	We create one of these on demand per-plugin class.
 */
@interface RWSharedStorage : NSObject <NSLocking>

@property (readonly, nonatomic, strong) NSMutableDictionary *storage;

@end

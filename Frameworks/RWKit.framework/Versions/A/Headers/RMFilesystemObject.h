//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************



//***************************************************************************

/// A class that represents a particular file on disk -- the file on disk is copied and deleted as this object is copied and deleted.
/** This class is used to manage files and directories on disk.  By "manage", this class effectively takes ownership of the file or directory at the given path: when this object is copied, it will likewise make a duplicate of the file or directory on disk in a temporary directory.  When this object is no longer referenced, it can also optionally delete the file or directory on disk.  While this seems like a rather lightweight class, it is incredibly useful when one has to work with files as a temporary store: files and directories can then be represented as standard objects, and are copied and deleted automatically.
  *
  * Files and directories are also normally deleted on standard application termination (i.e. when an NSApplicationWillTerminateNotification is received).  However, the file or directory is not always deleted when the application terminates; in particular, it will not be deleted if the application crashes.  This is intentional, since expert users can then peek around in the system's temporary directory to examine any data.  If you really need to make sure that all your disk objects are deleted when the process exits, it's strongly suggested that you track the paths yourself and use atexit() or a similar handler to register a cleanup function.
 *
 * Copies made of this object (via -copy and -copyWithZone:) will make a copy of the referenced file or directory in a temporary directory, and will be automatically deleted when the copied object is no longer referenced.  To change this behaviour for the copied object, you must manually set the deleteOnDisposal property to NO after copying it.
 *
 * Also note that if you are using this class to load data from a user's document, the user may delete that document while your application is running, and the user probably expects that the application still has their data if this happens!  It's strongly suggested that you use the idiom of "RMFilesystemObject* myObject = [[RMFilesystemObject filesystemObjectWithPath:myPath deleteOnDisposal:NO] copy]" if you are loading a user's document data.  This will create a new temporary file from the original data, so that if the user deletes their document while the application is running, the filesystem's object's path will still be available.
 */
__attribute__((objc_subclassing_restricted))
@interface RMFilesystemObject : NSObject

/// Convenience class method to allocate a new (autoreleased) filesystem object.
+ (id)filesystemObjectWithPath:(NSString*)path deleteOnDisposal:(BOOL)willDeleteOnDealloc;

/// Initialises a new RMFilesystemObject with the backing store at the given path.
/** The object will be deleted on deallocation/finalization or application termination only if the deleteOnDisposal: parameter is set to YES. */
- (id)initWithPath:(NSString*)path deleteOnDisposal:(BOOL)willDeleteOnDealloc;

/// Copies the filesystem object as per copyWithZone:, but copies the file or directory on disk to the specific path given.
- (id)copyWithZone:(NSZone*)zone toPath:(NSString*)newPath;

/// Compare for equality with another filesystem object.
/** Two filesystem objects are equal _only_ if the paths are _actually_ the same.  That is, an instance of an filesystemObject will _not_ be equal to [filesystemObject copy].  This is intentional behaviour. */
- (BOOL)isEqualToFilesystemObject:(RMFilesystemObject*)other;

/// This will delete the filesystem object on disk; its primary use is if you are running under garbage collection and absolutely require the path on disk to be empty right now.
/** After this function returns, the path property will be set to nil, and this object is effectively a zombie and should probably be released. */
- (void)deleteObject;

/// Returns the path to the object on the disk.
@property (nonatomic, strong, readonly) NSString* path;

/// Delete this object when it's disposed of.
@property BOOL deleteOnDisposal;

@end

//***************************************************************************

extern NSOperationQueue* RMFilesystemObjectDuplicationOperationQueue(void);

//***************************************************************************

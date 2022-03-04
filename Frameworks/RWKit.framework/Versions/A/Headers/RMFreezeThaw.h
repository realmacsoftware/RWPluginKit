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

@import Cocoa;

#import <RWKit/RMPagedObject.h>
#import <RWKit/RMSandwich.h>

//***************************************************************************

/// Provides freezing and thawing (saving and loading) of objects to and from disk.

/** The RMFreezing protocol is similar to the NSCoding protocol: it enables
  * objects to be saved to disk ("frozen"), and loaded from disk ("thawed").
  * It differs from NSCoding in two important ways.
  * 
  * First, we have a looser
  * coupling between loading objects from disk and creating objects based on the
  * types.  Whereas NSCoder stores the class name along with the data that's
  * written to disk, the RMFreezing protocol relies on a RMThawFactory
  * class to decide what class should be created based on the file name and/or
  * file contents.  In other words, RMThawFactory is the abstract
  * factory for this class.  This looser coupling enables you to greatly chop
  * and change the class hierarchy for your document.
  *
  * Second, RMFreezing is designed to use little memory during the saving
  * process by asking objects to save directly to paths on disk,
  * whereas NSCoder typically creates data objects in memory during
  * the save.  This becomes impractical for documents that can be hundreds of
  * megabytes large, since the user's physical memory will fill up and
  * thrashing can ensue.  Dealing directly with paths also means that one
  * can use multiple hardlinks to existing content on-disk (e.g. the
  * RMPagedObject class does this.)
  *
  * By default, the NSNumber, NSString, NSData, NSDate, RMPagedObject and
  * RMSandwich classes have RMFreezing support.
  */
@protocol RMFreezing <NSObject>

/// Return a filename extension for this particular receiver.
- (NSString*)frozenPathExtension;

/// Writes the object to the path given on the disk.
/** Return YES if the object was successfully written to disk.  Return NO if
  * the object was not written correctly, and set the error parameter
  * appropriately. */
- (BOOL)freezeToPath:(NSString*)path atomically:(BOOL)saveAtomically error:(NSError**)outError;

@end

//---------------------------------------------------------------------------

@protocol RMThawing <NSObject>

/// Return a set of supported path extensions for this class.
+ (NSSet*)freezeThawDefaultSupportedPathExtensions;

/// Create (an autoreleased) instance of this class from the path given.
+ (id)thawFromPath:(NSString*)path error:(NSError**)outError;

@end

//---------------------------------------------------------------------------

/// An abstract factory of frozen file types to classes.
/** Maintains an association of file extensions, to classes that can thaw
  * those files to create objects. */
@interface RMThawFactory : NSObject

/// Returns the factory class for the given file extension.
+ (Class)thawClassForExtension:(NSString*)pathExtension;

/// Associates a file extension with a given factory class.
/** The class is required to implement the +thawFromPath:error: method. */
+ (void)setThawClass:(Class)aClass forExtension:(NSString*)pathExtension;

/// Creates an object by thawing the contents at the given path on disk.
+ (id)thawFromPath:(NSString*)path error:(NSError**)outError;

@end

//***************************************************************************

/// RMFreezing and RMThawing support for the NSNumber class.
@interface NSNumber (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the NSString class.
@interface NSString (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the NSData class.
@interface NSData (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the NSDate class.
@interface NSDate (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the NSImage class.
@interface NSImage (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the NSImage class.
@interface NSAttributedString (RMFreezeThaw) <RMFreezing, RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing support for the NSArray class.
@interface NSArray (RMFreezeThaw) <RMFreezing>
@end

//---------------------------------------------------------------------------

/// RMFreezing support for the NSDictionary class.
@interface NSDictionary (RMFreezeThaw) <RMFreezing>
@end

//---------------------------------------------------------------------------

/// RMThawing support for property list classes.
@interface NSPropertyListSerialization (RMFreezeThaw) <RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing support for the RMPagedObject class.
@interface RMPagedObject (RMFreezeThaw) <RMFreezing>
@end

//---------------------------------------------------------------------------

/// RMThawing support for the RMArchivedObject class.
@interface RMArchivedObject (RMFreezeThaw) <RMThawing>
@end

//---------------------------------------------------------------------------

/// RMFreezing and RMThawing support for the RMSandwich class.
@interface RMSandwich (RMFreezeThaw) <RMFreezing, RMThawing>

@end

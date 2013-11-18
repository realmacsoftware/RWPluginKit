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

#import <Cocoa/Cocoa.h>

#import "RMValueObject.h"

/// An in-memory representation of a sandwich filling.
/** A Sandwich Filling is the central entity of the Sandwich file format: it is responsible for preserving the user's data.  To do this, you can store three types of data in a sandwich filling: (1) an arbitrary NSDictionary, (2) files, (3) more sandwiches.  The intended use is for the NSDictionary to store small bits of information that would be inefficient to store in a file, due to inefficiency issues with lots of small files.  While files can be very large, they are multiply hard-linked as much as possible for maximum efficiency.  (This is particularly useful in conjunction with the RMPagedObject class; see that class's documentation for more information.)  Currently, files are required to be normal files or directories and cannot be e.g. a symlink, or special character device.  Subsandwiches are simply stored as subdirectories. */
@interface RMSandwichFilling : NSObject<RMValueObject>
{
	NSDictionary* _subsandwiches;	///< A dictionary of (NSString* sandwichFilename => RMSandwich* sandwich).
	NSDictionary* _files;			///< A dictionary of (NSString* preferredFilename => NSString* filePath).
	NSDictionary* _dictionary;		///< A dictionary of arbitrary key-value pairs.
	
	BOOL _deleteFilesOnDisposal;	///< Deletes files referenced by this sandwich when the object is disposed of.
}

/// A convenient class method to create an (autoreleased) empty sandwich filling.
/** Use the sandwich's properties set subsandwiches, fileWrappers, and the dictionary. */
+ (RMSandwichFilling*)sandwichFilling;

/// A convenient class method to create an (autoreleased) sandwich filling.
+ (RMSandwichFilling*)sandwichFillingWithDictionary:(NSDictionary*)dictionary;

/// A convenient class method to create an (autoreleased) sandwich filling.
+ (RMSandwichFilling*)sandwichFillingWithDictionary:(NSDictionary*)dictionary files:(NSDictionary*)files subsandwiches:(NSDictionary*)subsandwiches;

/// Creates a sandwich filling.
/** Designated initialiser. */
- (id)initWithDictionary:(NSDictionary*)dictionary files:(NSDictionary*)files subsandwiches:(NSDictionary*)subsandwiches;

/// Tests for equality with another sandwich filling.
- (BOOL)isEqualToSandwichFilling:(RMSandwichFilling*)other;

/// Copies the sandwich filling like -copy does, but also duplicates any files referenced by the sandwich.
/** The files property will be updated to reflect the new pathnames for the files referenced by this sandwich. */
- (RMSandwichFilling*)copyDuplicatingFiles;

/// Returns a more detailed description than -description, suitable for debugging purposes, poiposes, and tortoises.
- (NSString*)debugDescription;

/// A dictionary of (NSString* sandwichFilename => RMSandwich* sandwich).
/** Note that this method will always return a dictionary; if no subsandwiches exist, an empty dictionary is returned. */
@property (copy) NSDictionary* subsandwiches;

/// A dictionary of (NSString* preferredFilename => NSString* filePath).
/** Two files should not have the same preferred filenames.  The filePaths must refer to regular files, not directories or symbolic
  * links.  Note that this method will always return a dictionary; if no files exist, an empty dictionary is returned. */
@property (copy) NSDictionary* files;

/// An arbitrary key-value dictionary that can be used to store whatever values you like.
/** This dictionary property is useful for storing small bits of information that would be inefficient to store as regular disk
  * files, or metadata about the fileWrappers.  Note that this method will always return a dictionary, though the dictionary may
  * be empty. */
@property (copy) NSDictionary* dictionary;

/// If YES, deletes the files referenced by this sandwich will be deleted on disposal.  Defaults to NO.
@property BOOL deleteFilesOnDisposal;

@end

//---------------------------------------------------------------------------

/// An object to manipulate sandwiches (an on-disk file format).
/** A sandwich is a directory (a.k.a. bundle) on disk with a particular
  * structure.  It only stores three bits of information: a 'Type' string that
  * indicates what type of document it is; an optional 'Creator' string that
  * indicates what application created the sandwich, and an array of
  * 'Sandwich Fillings'.  The real meat of a sandwich (pardon the pun) is
  * really in the Sandwich Fillings, which may actually contain more sandwiches
  * (stored in subdirectories of the root sandwich directory); see the
  * RMSandwichFilling class for more information about them.
  * 
  * Sandwich Fillings have a very simple versioning scheme, with each version
  * number simply determined from its index in the array.  This implies that
  * the versions must start at 0 and increase in an integral manner, so that
  * version 4 cannot exist without versions 0, 1, 2 and 3 also existing.
  * Applications are expected to be able to understand up to a particular
  * version number, so if an application only understands up to version 2,
  * version numbers 3 and 4 will not affect its operation.  Backward
  * compatibility is achieved by simply reading in version numbers that you
  * understand, and ignoring higher version numbers.  Forward compatibility is
  * achieved by saving the sandwich fillings in those higher versions in a
  * temporary store, and then re-including those higher-numbered versions in
  * the final sandwich that's saved back to disk.
  *
  * Sandwiches store their information (type, creator, sandwich fillings) in
  * an Apple Property List file named Contents.plist in the directory.  (See
  * the plist(5) manpage for more information about property list files.)
  * The Contents.plist file is usually saved as an XML plist for maximum
  * interoperability and robustness against corruption, but this can be changed
  * by the programmer to e.g. a binary plist file if the sandwich filling data
  * is not critical (e.g. cache data).
  *
  * Other than the Contents.plist file, other files and directories may (and
  * often will) be present in the directory; these files will usually be
  * referenced by the sandwich fillings.
  *
  * Note that while a sandwich implements the NSCopying protocol, a sandwich
  * copy will still reference the same files on disk; the disk files will not
  * normally be copied.  This is what you probably want for normal behaviour,
  * otherwise referencing a sandwich inside e.g. an NSDictionary will end up
  * copying all the on-disk files as well, which is relatively expensive.
  * However, if you want to make a copy of the sandwich and its entire
  * directory structure on disk, use the -copyDuplicatingFiles method, which
  * will copy the entire sandwich directory structure to a temporary directory.
  * The temporary directory will be deleted on application exit (via
  * the NSApplicationWillTerminateNotification notification name), so you must
  * re-save the sandwich to disk manually if you wish to preserve the copied
  * data.  Note that when you load a document, you should invoke
  * -copyDuplicatingFiles to preserve the sandwich's contents, otherwise the
  * user will probably be rather surprised when he deletes the sandwich
  * directory after loading the file and finds out that things are missing.
  */
@interface RMSandwich : NSObject<RMValueObject>
{
	NSString* _type;
	NSString* _creator;
	
	NSPropertyListFormat _propertyListFormat;
	
	NSMutableArray* _sandwichFillingVersions;		///< An array of RMSandwichFillings
}

/// Convenience factory method to create a sandwich.
+ (RMSandwich*)sandwichWithType:(NSString*)type;

/// Convenience factory method to create a sandwich.
+ (RMSandwich*)sandwichWithType:(NSString*)type creator:(NSString*)creator;

/// Returns an absolute pathname to the sandwich archives for this application.
+ (NSString*)sandwichArchivesPath;

/// Returns the factory class for a given sandwich type.
+ (Class)factoryClassForType:(NSString*)sandwichType;

/// Sets the factory class for a particular sandwich type.
/** The factory class should implement a +createWithSandwich: method. */
+ (void)setFactoryClass:(Class)factoryClass forType:(NSString*)sandwichType;

/// Creates an object based on the sandwich given.
/** The type of object created depends on the sandwich's type.  Use the setFactoryClass: method to set a factory class for a
 * given sandwich type. */
+ (id)createWithSandwich:(RMSandwich*)sandwich;

/// Designated initialiser.
- (RMSandwich*)initWithType:(NSString*)type creator:(NSString*)creator;

/// Returns the given sandwich filling for the particular version number.
/** Returns nil if the version number is invalid. */
- (RMSandwichFilling*)sandwichFillingForVersion:(NSUInteger)version;

/// Sets the given sandwich filling for the particular version number.
/** The version number specified must be the next version.  For example, you cannot set the sandwich filling for version 3 if
  * you have not first set the sandwich fillings for versions 0, 1 and 2.  Returns YES if the sandwich filling was set
  * succesfully, or NO if the version number was specified incorrectly. */
- (BOOL)setSandwichFilling:(RMSandwichFilling*)filling forVersion:(NSUInteger)version;

/// A convenience method to update a sandwich filling version (creating it if necessary), and set its dictionary to the argument specified.
- (BOOL)setDictionary:(NSDictionary*)dictionary forVersion:(NSUInteger)version;

/// A convenience method to update a sandwich filling version (creating it if necessary), and set its files to the argument specified.
- (BOOL)setFiles:(NSDictionary*)files forVersion:(NSUInteger)version;

/// A convenience method to update a sandwich filling version (creating it if necessary), and set its subsandwiches to the argument specified.
- (BOOL)setSubsandwiches:(NSDictionary*)subsandwiches forVersion:(NSUInteger)version;

/// Returns the version number for the next empty version slot.
/** For example, if versions 0, 1 and 2 have been set, this will return 3.  If no versions have been set, this returns 0. */
- (NSUInteger)nextVersionNumber;

/// Tests sandwiches for equality.
- (BOOL)isEqualToSandwich:(RMSandwich*)other;

/// Copies the sandwich like -copy does, but also duplicates any files referenced by sandwich fillings inside this sandwich.
/** The files property inside all sandwich fillings will be updated to reflect the pathnames for the duplicated files. */
- (RMSandwich*)copyDuplicatingFiles;

/// A sandwich's type, which is used to determine the factory class for the sandwich.
@property (copy) NSString* type;

/// The creator of a sandwich, typically the application's human-readable name.  This property is optional.
@property (copy) NSString* creator;

/// Returns an array of sandwich fillings, where the index in the array represents the version number of the filling.
@property (copy, readonly) NSArray* versions;

/// Changes the type of property list format used for the sandwich's Contents.plist file.  Defaults to NSPropertyListXMLFormat_v1_0.
/** It is highly recommended that you use the default XML property list format
  * for highest robustness against corruption and ease of manipulation, but
  * using a binary format is sensible for large (100k+) property lists where
  * data loss is acceptable (e.g. for cached information).  Note that the
  * property list format type is not validated until the sandwich is written,
  * so if you pass in a bogus value here, you won't know about it until you
  * write out the sandwich. */
@property NSPropertyListFormat propertyListFormat;

/// Cleans up the sandwich archives directory.  This method may not return for a very long time (seconds or minutes).
+ (void)clearSandwichArchives:(NSNotification*)note;

@end

//***************************************************************************

/// Similar to NSCoder, but transforms the object to and from a sandwich.
@protocol RMSandwichMaking <NSObject>

/// Returns a sandwiched version of the receiver's contents.
- (RMSandwich *)sandwich;

@end

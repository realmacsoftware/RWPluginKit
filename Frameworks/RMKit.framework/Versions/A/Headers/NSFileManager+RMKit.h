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

//***************************************************************************

@class RWTuple;

//***************************************************************************

@interface NSFileManager (DuplicateFile)

/// Like -duplicateItemAtPath:toPath:error:, except that it's named to better represent what it does.
/** A regular copy is performed if the hard-link fails. */
- (BOOL)linkOrCopyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)outError;

/// This is similar to -copyItemAtPath:toPath:error:, except that it attempts to hard-link the file first.
/** A regular copy is performed if the hard-link fails. */
- (BOOL)duplicateItemAtPath:(NSString*)srcPath toPath:(NSString*)dstPath error:(NSError**)outError;

/// This does exactly same thing as -[NSFileManager duplicateItemAtPath:toPath:error:], except that it has a different method signature which makes it easier to use with NSInvocationOperations.  It returns a nil NSError on success.
- (NSError*)duplicateItemWithPathsInTuple:(RWTuple*)tuple;

@end

//***************************************************************************

@interface NSFileManager (RMExtendedAttributesSupport)

/// Returns an NSDictionary containing the extended attributes of the item at a given path.  The keys of the dictionary are the the names of the POSIX extended attributes the file has.  The corresponding values are NSData objects representing the attribute contents.  If there are no extended attributes for the item, this method returns an empty NSDictionary.  If an error occurred, thie method turns nil and sets the error given in the outError parameter.
- (NSDictionary*)extendedAttributesOfItemAtPath:(NSString*)path traverseLink:(BOOL)followSymbolicLinks error:(NSError**)error;

/// Sets the extended attributes on the file at the given path.  Returns YES if successful, and returns NO and sets the outError parameter if unsuccessful.
- (BOOL)setExtendedAttributes:(NSDictionary*)attributes ofItemAtPath:(NSString*)path error:(NSError**)outError;

@end

//***************************************************************************

@interface NSFileManager (IsDirectory)

- (BOOL)isDirectory:(NSString*)path;

@end

//***************************************************************************

@interface NSFileManager (TemporaryFilenames)

/// Returns the host-local cache directory for the application's CFBundleIdentifier.
- (NSString*)applicationCacheDirectory;

/// Returns a standardised temporary path, which will be the application bundle identifier name and process ID appended to the path returned by NSTemporaryDirectory().  The path does not contain a trailing slash.  The temporary directory path will be deleted on application exit, so do not rely on files persisting there after the application quits!  (You should be using NSCachesDirectory for that.)
/** An example path would be /var/folders/4K/4KPl0EDa2RW0Rk+1YwSRB++++TI/-Tmp-/com.realmacsoftware.rapidweaverpro/25673. */
- (NSString*)applicationTemporaryDirectoryRootPath;

#pragma mark - Files

/// Returns a temporary path name.
/** This function is safe from race conditions, unlike mktemp(3). */
- (NSString*)temporaryFilename;

/// Trailing XXXX characters on the end of the path template are replaced with random characters, similarly to mktemp(3).
/** Note that this function is safe since it will proceed to open(2) the file with O_EXCL, as described in the mktemp(3) manpage.  The file will be created with mode 0700 and zero bytes. */
- (NSString*)temporaryFilenameWithTemplate:(NSString*)pathTemplate;

/// Trailing XXXX characters on the end of the path template are replaced with random characters, similarly to mktemp(3).  The path extension, if any is given, will be appended to the resulting temporary filename.
/** Note that this function is safe since it will proceed to open(2) the file with O_EXCL, as described in the mktemp(3) manpage.  The file will be created with mode 0700 and zero bytes. */
- (NSString*)temporaryFilenameWithTemplate:(NSString*)pathTemplate extension:(NSString*)pathExtension;

/// Returns a temporary filename in a temporary directory that contains the specified "prefix" name in its filename (which can be useful if the user's trawling the temporary directory looking for things).
/** Note that this function is safe since it will proceed to open(2) the file with O_EXCL, as described in the mktemp(3) manpage.  The file will be created with mode 0700 and zero bytes. */
- (NSString*)temporaryFilenameWithPrefix:(NSString*)prefix;

/// Returns a temporary filename in a temporary directory that contains the specified "prefix" name in its filename, and the specified extension for its path extension (which can be useful if the user's trawling the temporary directory looking for things).
/** Note that this function is safe since it will proceed to open(2) the file with O_EXCL, as described in the mktemp(3) manpage.  The file will be created with mode 0700 and zero bytes. */
- (NSString*)temporaryFilenameWithPrefix:(NSString*)prefix extension:(NSString*)pathExtension;

#pragma mark - Directories

/// Returns a temporary directory name.
/** The resulting returned path will be created as a directory, with a mode of 0700. */
- (NSString*)temporaryDirectory;

/// Trailing XXXX characters on the end are replaced with random characters, similarly to mkdtemp(3).
/** The resulting returned path will be created as a directory, with a mode of 0700. */
- (NSString*)temporaryDirectoryWithTemplate:(NSString*)pathTemplate;

/// Trailing XXXX characters on the end are replaced with random characters, similarly to mkdtemp(3).
/** The resulting returned path will be created as a directory, with a mode of 0700. */
- (NSString*)temporaryDirectoryWithTemplate:(NSString*)pathTemplate extension:(NSString*)pathExtension;

/// Returns a temporary directory name that contains the specified "prefix" name in its filename (which can be useful if the user's trawling the temporary directory looking for things).
/** The resulting returned path will be created as a directory, with a mode of 0700.  If the prefix name is nil, the current process name is used as the prefix instead. */
- (NSString*)temporaryDirectoryWithPrefix:(NSString*)prefix;

/// Returns a temporary directory name that contains the specified "prefix" name in its filename (which can be useful if the user's trawling the temporary directory looking for things).
/** The resulting returned path will be created as a directory, with a mode of 0700.  If the prefix name is nil, the current process name is used as the prefix instead. */
- (NSString*)temporaryDirectoryWithPrefix:(NSString*)prefix extension:(NSString*)pathExtension;

#pragma mark - Paths

/// Returns a temporary pathname.
/** Warning: a possible race condition can exist when a filename is obtained and you creating the file, since another process can create the file with the same name before you do.  It is strongly recommended you use the -temporaryDirectory or -temporaryFilename methods instead.  The filename is guaranteed not to exist at the time the method is called. */
- (NSString*)temporaryPathname;

/// Trailing XXXX characters on the end are replaced with random characters, similarly to mktemp(3).
/** Warning: a possible race condition can exist when a filename is obtained and you creating the file, since another process can create the file with the same name before you do.  It is strongly recommended you use the -temporaryDirectoryWithTemplate or -temporaryFilenameWithTemplate methods instead.  The filename is guaranteed not to exist at the time the method is called. */
- (NSString*)temporaryPathnameWithTemplate:(NSString*)pathTemplate;

/// Trailing XXXX characters on the end are replaced with random characters, similarly to mktemp(3).  The path extension, if any is given, will be appended to the resulting temporary filename.
/** Warning: a possible race condition can exist when a filename is obtained and you creating the file, since another process can create the file with the same name before you do.  It is strongly recommended you use the -temporaryDirectoryWithTemplate or -temporaryFilenameWithTemplate methods instead.  The filename is guaranteed not to exist at the time the method is called. */
- (NSString*)temporaryPathnameWithTemplate:(NSString*)pathTemplate extension:(NSString*)pathExtension;

/// Returns a temporary pathname that contains the specified "prefix" name in its filename (which can be useful if the user's trawling the temporary directory looking for things).  Trailing XXXX characters on the end are replaced with random characters, similarly to mktemp(3).  The path extension, if any is given, will be appended to the resulting temporary filename.
/** Warning: a possible race condition can exist when a filename is obtained and you creating the file, since another process can create the file with the same name before you do.  It is strongly recommended you use the -temporaryDirectoryWithTemplate or -temporaryFilenameWithTemplate methods instead.  The filename is guaranteed not to exist at the time the method is called. */
- (NSString*)temporaryPathnameWithPrefix:(NSString*)prefix extension:(NSString*)pathExtension;

@end

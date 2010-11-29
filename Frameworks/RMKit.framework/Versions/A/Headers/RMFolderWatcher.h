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

#include <CoreServices/CoreServices.h>

#import <Cocoa/Cocoa.h>

//***************************************************************************

@class RMFolderWatcher;

//***************************************************************************

@protocol RMFolderWatcherDelegate <NSObject>

/// This method is called whenever any files or directories inside the path changes.
- (void)folderWatcher:(RMFolderWatcher*)folderWatcher pathChanged:(NSString*)fullPath;

/// This method is called whenever any of the files you specifically ask to be watched changes.
/** This method is called before -folderWatcher:pathChanged:. */
- (void)folderWatcher:(RMFolderWatcher*)folderWatcher fileInsidePathChanged:(NSString*)fullPathFilename;

@end

//***************************************************************************

/// A class that watches a particular path on disk and notifies a delegate object of any changes inside that path.
/** You may optionally pass an array of files to watch inside the folder.  If
  * you do this, your delegate object will receive a
  * -folderWatcher:fileInsidePathChanged: message when any of the files in the
  * array changes.  Filenames to be watched must be relative to the path
  * to be watched, though they may contain filenames in subdirectories
  * underneath that path.  For example, you may specify to watch /var/tmp, and
  * pass in an array of two files: "mydirectory/foo" and "bar".  This results
  * in the -folderWatcher:pathChanged: method being called on your delegate
  * whenever /var/tmp/ changes, and -folderWatcher:fileInsidePathChanged:
  * being called whenever /var/tmp/mydirectory/foo or /var/tmp/bar changes. */
@interface RMFolderWatcher : NSObject
{
	FSEventStreamRef _eventStream;
	NSString* _path;
	NSMutableDictionary* _filesToWatch;
	id<RMFolderWatcherDelegate> _delegate;
}

/// The path to watch.
/** Note that this is a read-only property.  If you wish to change the path to
  * watch, you must create a new RMFolderWatcher instance. */
@property (copy, readonly) NSString* path;

/// The delegate object for this folder watcher.
@property (assign) id<RMFolderWatcherDelegate> delegate;

/// Initialises a new folder watcher for the specified path.
/** If you do not wish to watch any specific files inside the folder, pass nil
  * or an empty array in for the filenames. */
- (id)initWithDirectoryAtPath:(NSString*)path filenamesToWatchInsideDirectory:(NSArray*)filenames;

@end

//***************************************************************************

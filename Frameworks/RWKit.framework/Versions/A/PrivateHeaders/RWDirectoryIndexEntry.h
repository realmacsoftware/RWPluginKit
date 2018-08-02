//***************************************************************************

// Copyright (C) 2008 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

/*!
	\brief
	This is a very simple class that only holds a filename.  It's not really necessary, but was required when I was fooling around with creating a UI to edit the directory index filenames.  (Binding an NSTableColumn to an array _requires_ that the array items have a key, so you can't simply have an NSArray of NSStrings, for example; you need to have an NSArray of RWDirectoryIndexEntry objects instead.)
 */
@interface RWDirectoryIndexEntry : NSObject

+ (NSSet *)standardIndexDirectoryEntries;

+ (RWDirectoryIndexEntry*)directoryIndexEntryWithFilename:(NSString*)filename;
- (id)initWithFilename:(NSString*)filename;

@property (copy) NSString *filename;

@end

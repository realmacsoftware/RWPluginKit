//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

/// This is the public API for a RapidWeaver 4.0 document.
@protocol RW40Document <NSObject>

/// Returns a universally unique identifier for this document.
- (NSString*)UUIDString;

/// Returns the window for the document
- (NSWindow*)window;

@end

/// This is the public API for a RapidWeaver document.
@protocol RWDocument <RW40Document>

@end

//***************************************************************************

//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RWKit/RWDocumentProtocol.h"

/// This is the public API for a RapidWeaver page.
@protocol RWPage <NSObject>

/// Returns the document that this page is part of.
- (NSDocument <RWDocument> *)document;

/// Returns an NSString that is used as a unique identifier for this page.
- (NSString *)uniqueID;

/// Returns the page title as specified in the page inspector.
- (NSString *)title;
- (BOOL)enabled;
- (BOOL)hidden;
- (NSArray *)children;

// Marks this page as changed.
- (void)markAsChanged;

@end

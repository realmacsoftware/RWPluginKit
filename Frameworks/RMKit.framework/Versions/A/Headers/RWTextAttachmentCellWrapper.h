//***************************************************************************

// Copyright (C) 2005-2007 Mako Technology
// Copyright (C) 2005-2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface RWTextAttachmentCellWrapper : NSObject /* : NSObject<NSTextAttachmentCell> */
{
	id <NSTextAttachmentCell> _cell;
	
	// These ivars really belongs to RWImageTextAttachmentCellWrapper (since 
	// only it will use it), but putting it there causes RapidWeaver to crash on
	// startup immediately due to weird +poseAsClass: issues.
	NSDictionary *cachedMediaAttributes;
	NSImage *cachedTransformImage;
}

enum {
	kImageAttachmentType = 1,
	kMovieAttachmentType,
	kPDFAttachmentType,
    kSVGAttachmentType,
    kSiteResourceAttachmentType
};

@property (assign) CGImageRef cachedTransformImageRef;
@property (retain) id <NSTextAttachmentCell> cell;
@property (retain) NSDictionary *cachedMediaAttributes;

- (NSInteger)attachmentType;
- (void)setUnderlyingCell:(id <NSTextAttachmentCell>)cell;
- (void)setAttachment:(NSTextAttachment *)anAttachment;

@end

//---------------------------------------------------------------------------

@interface RWSiteResourceTextAttachmentCellWrapper : RWTextAttachmentCellWrapper

@end

//---------------------------------------------------------------------------

@interface RWImageTextAttachmentCellWrapper : RWTextAttachmentCellWrapper

@end

//---------------------------------------------------------------------------

@interface RWMovieTextAttachmentCellWrapper : RWTextAttachmentCellWrapper

@end

//---------------------------------------------------------------------------

@interface RWPDFTextAttachmentCellWrapper : RWTextAttachmentCellWrapper

@end

//---------------------------------------------------------------------------

@interface RWSVGTextAttachmentCellWrapper : RWImageTextAttachmentCellWrapper

@end

//***************************************************************************

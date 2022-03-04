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

@interface RWTextAttachmentCellWrapper : NSObject <NSTextAttachmentCell>

typedef NS_ENUM(NSUInteger, RWTextAttachmentType) {
    kImageAttachmentType = 1,
    kMovieAttachmentType,
    kPDFAttachmentType,
    kSVGAttachmentType,
    kSiteResourceAttachmentType
};

@property (strong) id cachedTransformImageRef;
@property (strong) id <NSTextAttachmentCell> cell;
@property (strong) NSDictionary *cachedMediaAttributes;
@property (assign) CGSize cachedImageSize;

- (RWTextAttachmentType)attachmentType;
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

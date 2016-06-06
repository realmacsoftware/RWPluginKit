//***************************************************************************

// Copyright (C) 2012 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RMKit/RMKit.h"

#import "RWDocumentModel.h"

#import "RWKit/RMHTML.h"

// RWDocumentOptionsSnapshot; represents a snapshot of the editable model state that appears in the Site Setup sheet
// Upon opening the sheet a snapshot is taken and any edits performed on that, when the sheet is dismissed the edits
// are pushed back to the document triggering any appropriate saved state and site export state changes
@interface RWDocumentOptionsSnapshot : RMModelObject

@property BOOL useSiteLogo;
@property (copy) NSString* siteTitle;
@property BOOL useSiteTitle;
@property (copy) NSString* siteLogoAltText;
@property (copy) NSString* siteBannerAltText;
@property BOOL showBreadcrumbTrail;
@property BOOL useSiteSlogan;
@property (copy) NSString* siteBaseURL;
@property BOOL addCopyrightMailto;
@property BOOL useSiteCopyright;
@property (copy) NSString* siteEmail;
@property (copy) NSString* siteContactText;
@property BOOL useWebClipIcon;
@property BOOL useFavicon;
@property (copy) NSString* siteSlogan;
@property (copy) NSString* siteCopyright;
@property (assign) RWLinkStyle commonFileConsolidationMode;
@property BOOL obfuscateSiteEmailAddress;
@property BOOL wantsXMLSiteMap;
@property BOOL cruftlessLinks;

- (void)copyFromModel:(NSObject*)model;
- (void)copyToModel:(NSObject*)model;

@end


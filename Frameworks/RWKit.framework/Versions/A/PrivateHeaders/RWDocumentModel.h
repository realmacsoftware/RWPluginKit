//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RMKit/RMKit.h"
#import "RWKit/RMHTML.h"

@class RWPageTree;
@class RWPageAttributes;
@class RWBookmark;

@interface RWDocumentModel : RMModelObject

// Some of these properties should arguably be read-only
@property (retain) NSMutableArray *publishingDestinations;
@property (retain) RWBookmark *temporaryPublishingDestination;
@property (retain) RWBookmark *selectedPublishingDestination;
@property (copy) NSString *siteTitle;
@property (copy) NSString *siteLogoAltText;
@property (copy) NSString *siteCopyright;
@property (copy) NSString *siteEmail;
@property (copy) NSString *siteSlogan;
@property (copy) NSString *siteLogoFilename;
@property (copy) NSData *siteLogoData;
@property (copy) NSString *siteContactText;
@property (copy) NSString *siteThemeName;
@property (copy) NSString *globalCSS;
@property (copy) NSString *globalJavascript;
@property (copy) NSString *globalHeader;
@property (copy) NSString *globalBody;
@property (copy) NSString *globalPrefix;
@property (copy) NSString *mostRecentlySelectedThemeStyle;

extern NSString *const RWDocumentModelTreeKey;
@property (readonly, retain) RWPageTree *tree;

@property (copy) NSString *siteDefaultExportDestination;
@property (copy) NSData *siteDefaultExportDestinationBookmark;
@property (retain) RWPageAttributes *defaultPageAttributes;
@property (copy) NSString *siteBaseURL;
@property (retain) NSMutableDictionary *imageExportSettings;
@property (copy) NSData *faviconData;
@property (copy) NSData *webClipIconData;
@property (copy) NSData *bannerData;
@property (copy) NSString *bannerFilename;
@property (copy) NSString *siteBannerAltText;
@property (retain) NSMutableDictionary *documentManifests;

@property (assign) RWLinkStyle commonFileConsolidationMode;

@property (assign) BOOL useSiteTitle;
@property (assign) BOOL useSiteCopyright;
@property (assign) BOOL useSiteSlogan;
@property (assign) BOOL addCopyrightMailto;
@property (assign) BOOL obfuscateSiteEmailAddress;
@property (assign) BOOL useSiteLogo;
@property (assign) BOOL showBreadcrumbTrail;
@property (assign) BOOL useFavicon;
@property (assign) BOOL useWebClipIcon;
@property (assign) BOOL useBanner;
@property (assign) BOOL loadingDocument;
@property (assign) BOOL publishSettingsConfigured;
@property (assign) BOOL wantsXMLSiteMap;
@property (assign) BOOL cruftlessLinks;
@property (assign) BOOL hasChangedGlobalCSS;
@property (assign) BOOL hasChangedGlobalJavascript;
@property (assign) BOOL hasChangedGlobalHeader;
@property (assign) BOOL hasChangedGlobalBody;
@property (assign) BOOL hasChangedGlobalPrefix;
@property (assign) BOOL consolidateCSSFiles;
@property (assign) BOOL useCacheBusting;
@property (copy) NSString *cacheBustingString;
@property (assign) BOOL useDocumentPortability;
@property (assign) BOOL minifyExtraFiles;

@property (assign) NSInteger userAgentResizingPreset;

@property (copy) NSArray *directoryIndexEntries;

@property (copy) NSString *projectNotes;

@property (copy) NSString *uniqueBackupName;

@end

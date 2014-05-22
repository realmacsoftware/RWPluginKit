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

@class RWTheme;
@class RWPageTree;
@class RWPageAttributes;

@interface RWDocumentModel : RMModelObject

// Some of these properties should arguably be read-only
@property (copy) NSDictionary *publishingSettings;
@property (copy) NSString* siteTitle;
@property (copy) NSString* siteGoogleAnalyticsCode;
@property (copy) NSString* siteLiveStatsCode;
@property (copy) NSString* siteCopyright;
@property (copy) NSString* siteEmail;
@property (copy) NSString* siteSlogan;
@property (copy) NSString* siteLogoFilename;
@property (copy) NSData* siteLogoData;
@property (copy) NSString* siteContactText;
@property (retain) RWTheme* siteTheme;
@property (copy) NSString *globalCSS;
@property (copy) NSString *globalJavascript;
@property (copy) NSString *globalHeader;
@property (copy) NSString *globalPrefix;

extern NSString *const RWDocumentModelTreeKey;
@property (readonly, retain) RWPageTree *tree;

@property (copy) NSString* siteDefaultExportDestination;
@property (retain) RWPageAttributes* defaultPageAttributes;
@property (copy) NSString* siteBaseURL;
@property (retain) NSMutableDictionary* imageExportSettings;
@property (copy) NSData* faviconData;
@property (copy) NSData* webClipIconData;
@property (retain) NSMutableDictionary* documentManifests;

@property (assign) RWLinkStyle commonFileConsolidationMode;

@property (assign) BOOL useSiteTitle;
@property (assign) BOOL useSiteCopyright;
@property (assign) BOOL useSiteSlogan;
@property (assign) BOOL addCopyrightMailto;
@property (assign) BOOL obfuscateSiteEmailAddress;
@property (assign) BOOL useSiteLogo;
@property (assign) BOOL showBreadcrumbTrail;
@property (assign) BOOL previewAfterExportRelativeToBaseURL;
@property (assign) BOOL useFavicon;
@property (assign) BOOL useWebClipIcon;
@property (assign) BOOL showTidiedCode;
@property (assign) BOOL loadingDocument;
@property (assign) BOOL forcedDocumentModification;
@property (assign) BOOL forcedThemeSelectionChange;
@property (assign) BOOL publishSettingsConfigured;
@property (assign) BOOL wantsXMLSiteMap;
@property (assign) BOOL putGoogleAnalyticsInHead;
@property (assign) BOOL cruftlessLinks;
@property (assign) BOOL hasChangedGlobalCSS;
@property (assign) BOOL hasChangedGlobalJavascript;
@property (assign) BOOL hasChangedGlobalHeader;
@property (assign) BOOL hasChangedGlobalPrefix;
@property (assign) BOOL consolidateCSSFiles;

@property (copy) NSArray *directoryIndexEntries;

@end

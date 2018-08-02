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
@class WebIconPackage;

@interface RWDocumentModel : NSObject

// Some of these properties should arguably be read-only
@property (strong) NSMutableArray *publishingDestinations;
@property (strong) RWBookmark *temporaryPublishingDestination;
@property (strong) RWBookmark *selectedPublishingDestination;
@property (copy) NSString *siteTitle;
@property (copy) NSString *siteLogoAltText;
@property (copy) NSString *siteCopyright;
@property (copy) NSString *siteEmail;
@property (copy) NSString *siteSlogan;
@property (copy) NSString *siteContactText;
@property (copy) NSString *siteThemeName;
@property (copy) NSString *globalCSS;
@property (copy) NSString *globalJavascript;
@property (copy) NSString *globalHeader;
@property (copy) NSString *globalBody;
@property (copy) NSString *globalPrefix;
@property (copy) NSString *mostRecentlySelectedThemeStyle;

extern NSString *const RWDocumentModelTreeKey;
@property (readonly, strong) RWPageTree *tree;

@property (copy) NSString *siteDefaultExportDestination;
@property (copy) NSData *siteDefaultExportDestinationBookmark;
@property (strong) RWPageAttributes *defaultPageAttributes;
@property (copy) NSString *siteBaseURL;
@property (strong) NSMutableDictionary *imageExportSettings;
@property (copy) NSString *siteBannerAltText;
@property (copy) NSColor *pinnedTabIconColor;
@property (strong) NSMutableDictionary *documentManifests;

@property (assign) RWLinkStyle commonFileConsolidationMode;

@property (assign) BOOL useSiteTitle;
@property (assign) BOOL useSiteCopyright;
@property (assign) BOOL useSiteSlogan;
@property (assign) BOOL useSocialTags;
@property (copy) NSString *twitterAccount;
@property (assign) BOOL addCopyrightMailto;
@property (assign) BOOL obfuscateSiteEmailAddress;
@property (assign) BOOL showBreadcrumbTrail;
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
@property (copy) NSNumber *overrideWebServerPort;
@property (assign) BOOL autoStartWebServer;
@property (assign) BOOL minifyExtraFiles;

@property (copy) NSString *siteLogoIdentifier;
@property (copy) NSString *webClipIconIdentifier;
@property (copy) NSString *faviconIdentifier;
@property (copy) NSString *pinnedTabIconIdentifier;
@property (copy) NSString *bannerIdentifier;
@property (strong) WebIconPackage *iconPackage;

@property (assign) BOOL anonymiseThirdPartyRequests;
@property (assign) BOOL showPrivacyMessage;
@property (assign) BOOL rememberPrivacyMessageDismissed;
@property (copy) NSAttributedString *privacyMessage;

@property (copy) NSArray *directoryIndexEntries;

@property (copy) NSString *projectNotes;

@property (copy) NSString *uniqueBackupName;

@property (copy) NSString *siteLanguage;
@property (copy) NSString *siteDirection;

@end

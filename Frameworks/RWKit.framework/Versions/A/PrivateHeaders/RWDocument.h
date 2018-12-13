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

#import "RWKit/RWDocumentProtocol.h"
#import "RWKit/RMHTML.h"

@class RWDocumentModel;
@class RWPage;
@class RWPageAttributes;
@class RWTheme;
@class RWSiteFolder;
@class RWDocumentOptionsSnapshot;
@class WebIconPackage;
@class RWFileReferences;

extern NSString *const RWDocumentWillRemoveResourceNotification;
extern NSString *const RWDocumentDidRemoveResourceNotification;

/// RWDocument is the shiny new replacement for the old MyDocument class.
/** If you are defining any new methods that should belong to the document class, define them here instead of in MyDocument.  Over time, I'd like to eventually refactor all the methods in MyDocument and gradually move them here once it's decided that those methods are clean enough to make it through. */
@interface RWDocument : NSDocument <RWDocument, RMObjectPathing>

extern NSString *const RWDocumentPagesKey;
@property (nonatomic, readonly, strong) NSArray *pages;
- (void)reparent:(RWPage *)page parent:(RWPage *)parent clearManifest:(BOOL)clearManifest;
- (void)markAllPagesAsChanged:(BOOL)changed;

extern NSString *const RWDocumentAllPagesKey;
@property (weak, readonly, nonatomic) NSArray *allPages;

@property (strong) RWPage *index;

@property (nonatomic, strong) NSMutableDictionary *missingPagesInfo;
@property (nonatomic, strong) NSMutableDictionary *corruptPagesInfo;

- (RWPage *)pageFromUniqueID:(NSString *)identifier topLevelOnly:(BOOL)top;
- (RWPage *)pageFromUniqueID:(NSString *)uniqueID;
- (NSString *)pageFilesFolderName:(id)pageID;

- (NSString *)pathFromPage:(id)params;
- (NSString *)pathFromPage:(id)pageID to:(id)pageID2;
- (NSString *)pathFromPage:(id)params cruftlessLinks:(NSNumber *)cruftlessLinksNumber;

- (void)addResource:(RWSiteResource *)resource;
- (void)addResources:(NSArray <RWSiteResource *> *)resources;

@property (assign, nonatomic) BOOL wantsXMLSiteMap;

- (NSString *)siteIndexFilenameOverriddenForPage:(RWPage *)page;
- (NSString *)siteIndexFilename;
- (NSString *)siteBaseURLEscaped;

- (RWDocumentOptionsSnapshot *)createOptionsSnapshot;
- (void)applyOptionsSnapshot:(RWDocumentOptionsSnapshot *)options;

//

@property (nonatomic, strong) RWSiteFolder *resourcesNode;

@property (nonatomic, strong) NSMutableArray *settingsPlugins;

@property (nonatomic, assign) BOOL publishSettingsConfigured;
@property (nonatomic, strong) NSMutableArray *publishingDestinations;

@property (strong) NSString *imageExportFormat;
@property (strong) NSString *imageExportQuality;

@property (copy) NSString *siteTitle;
@property (assign) BOOL useSiteTitle;

@property (copy) NSString *siteLogoAltText;

@property (copy) NSString *siteCopyright;
@property (assign) BOOL useSiteCopyright;

@property (copy) NSString *siteEmail;
@property (assign) BOOL addCopyrightMailto;

@property (copy) NSString *siteContactText;
@property (assign) BOOL obfuscateSiteEmailAddress;

@property (assign) BOOL showBreadcrumbTrail;

@property (copy) NSString *siteSlogan;
@property (assign) BOOL useSiteSlogan;

@property (assign) BOOL useSocialTags;
@property (copy) NSString *twitterAccount;

@property (copy) NSString *siteLanguage;
@property (copy) NSString *siteDirection;

@property (strong) RWPageAttributes *defaultPageAttributes;

@property (assign) RWLinkStyle commonFileConsolidationMode;

extern NSString *const RWDocumentSiteBaseURLKey;
@property (copy) NSString *siteBaseURL;

@property (copy) NSString *siteBannerAltText;

@property (copy) NSColor *pinnedTabIconColor;

@property (nonatomic, strong) RWTheme *theme;
- (void)startWatchingTheme:(RWTheme *)theme;
- (void)stopCurrentThemeWatcher;

@property (copy) NSString *mostRecentlySelectedThemeStyle;

@property (copy) NSString *siteDefaultExportDestination;
@property (weak, readonly) NSData *siteDefaultExportDestinationBookmark;

@property (copy) NSString *globalCSS;
@property (copy) NSAttributedString *attributedGlobalCSS;
@property (readonly) BOOL useGlobalCSS;
@property (assign) BOOL hasChangedGlobalCSS;

@property (assign) BOOL consolidateCSSFiles;

@property (copy) NSString *globalJavascript;
@property (copy) NSAttributedString *attributedGlobalJavascript;
@property (readonly) BOOL useGlobalJavascript;
@property (assign) BOOL hasChangedGlobalJavascript;

@property (copy) NSString *globalHeader;
@property (copy) NSString *globalBody;
@property (copy) NSAttributedString *attributedGlobalHeader;
@property (readonly) BOOL useGlobalHeader;
@property (assign) BOOL hasChangedGlobalHeader;
@property (assign) BOOL hasChangedGlobalBody;

@property (copy) NSString *globalPrefix;
@property (copy) NSAttributedString *attributedGlobalPrefix;
@property (readonly) BOOL useGlobalPrefix;
@property (assign) BOOL hasChangedGlobalPrefix;

@property (copy) NSString *projectNotes;

@property (copy) NSString *uniqueBackupName;

@property (assign) BOOL useCacheBusting;

@property (assign) BOOL minifyExtraFiles;

@property (assign) BOOL useDocumentPortability;
@property (copy) NSNumber *overrideWebServerPort;
@property (assign) BOOL autoStartWebServer;

@property (nonatomic, strong) RWSiteResource *siteLogo;
@property (nonatomic, strong) RWSiteResource *webClipIcon;
@property (nonatomic, strong) RWSiteResource *favicon;
@property (nonatomic, strong) RWSiteResource *pinnedTabIcon;
@property (nonatomic, strong) RWSiteResource *banner;
@property (nonatomic, strong) WebIconPackage *iconPackage;

@property (assign) BOOL anonymiseThirdPartyRequests;
@property (assign) BOOL showPrivacyMessage;
@property (assign) BOOL rememberPrivacyMessageDismissed;
@property (copy) NSAttributedString *privacyMessage;
@property (copy) NSString *privacyMessageDismissButtonTitle;

- (BOOL)com_rwrp_checkAndWarnIfTIFF:(NSData *)data extendedWarning:(BOOL)warning;

- (BOOL)hasChangedGlobalFiles;
- (void)resetGlobalFilesChangedFlags;


@property (nonatomic, strong) RWFileReferences *fileReferences;


@end

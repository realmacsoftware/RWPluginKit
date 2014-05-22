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

@class RMFolderWatcher;
@class RWDocumentModel;
@class RWPage;
@class RWPageAttributes;
@class RWResourceDatabase;
@class RWTheme;
@class RWSourceListNode;
@class RWDocumentOptionsSnapshot;

extern NSString *const RWDocumentWillRemoveResourceNotification;
extern NSString *const RWDocumentDidRemoveResourceNotification;
extern NSString *const RWDocumentDidUpdateStatsConfigNotification;

/// RWDocument is the shiny new replacement for the old MyDocument class.
/** If you are defining any new methods that should belong to the document class, define them here instead of in MyDocument.  Over time, I'd like to eventually refactor all the methods in MyDocument and gradually move them here once it's decided that those methods are clean enough to make it through. */
@interface RWDocument : NSDocument <RWDocument, RMObjectPathing>

@property (nonatomic, retain) IBOutlet NSWindow *window;

extern NSString *const RWDocumentPagesKey;
@property (nonatomic, readonly, retain) NSArray *pages;
- (void)reparent:(RWPage *)page parent:(RWPage *)parent clearManifest:(BOOL)clearManifest;
- (void)markAllPagesAsChanged:(BOOL)changed;

extern NSString *const RWDocumentAllPagesKey;
@property (readonly, nonatomic) NSArray *allPages;

@property (retain) RWPage *index;

@property (nonatomic, retain) NSMutableDictionary *missingPagesInfo;

- (RWPage *)pageFromUniqueID:(NSString *)identifier topLevelOnly:(BOOL)top;
- (RWPage *)pageFromUniqueID:(NSString *)uniqueID;
- (NSString *)pageFilesFolderName:(id)pageID;

- (NSString *)pathFromPage:(id)params;
- (NSString *)pathFromPage:(id)pageID to:(id)pageID2;
- (NSString *)pathFromPage:(id)params cruftlessLinks:(NSNumber *)cruftlessLinksNumber;

- (void)addResources:(NSArray *)inResourceArray toNode:(RWSourceListNode *)inFolderNode atIndex:(NSInteger)inIndex;
- (void)removeResourceNode:(RWSourceListNode *)inNode;

@property (assign, nonatomic) BOOL wantsXMLSiteMap;

- (NSString *)siteIndexFilenameOverriddenForPage:(RWPage *)page;
- (NSString *)siteIndexFilename;
- (NSString *)siteBaseURLEscaped;

- (RWDocumentOptionsSnapshot *)createOptionsSnapshot;
- (void)applyOptionsSnapshot:(RWDocumentOptionsSnapshot *)options;

//

@property (nonatomic, retain) RWSourceListNode *resourcesNode;
@property (nonatomic, retain) RWResourceDatabase *resourceDB;

@property (nonatomic, assign) BOOL publishSettingsConfigured;
@property (nonatomic, retain) NSDictionary *publishingSettings;

@property (assign) BOOL useSiteLogo;
@property (copy) NSData *siteLogoData;

@property (retain) NSString *imageExportFormat;
@property (retain) NSString *imageExportQuality;

@property (copy) NSString *siteLogoFilename;

@property (copy) NSString *siteGoogleAnalyticsCode;
@property (assign) BOOL putGoogleAnalyticsInHead;

@property (copy) NSString *siteLiveStatsCode;

@property (copy) NSString *siteTitle;
@property (assign) BOOL useSiteTitle;

@property (copy) NSString *siteCopyright;
@property (assign) BOOL useSiteCopyright;

@property (copy) NSString *siteEmail;
@property (assign) BOOL addCopyrightMailto;

@property (copy) NSString *siteContactText;
@property (assign) BOOL obfuscateSiteEmailAddress;

@property (assign) BOOL showBreadcrumbTrail;

@property (copy) NSString *siteSlogan;
@property (assign) BOOL useSiteSlogan;

@property (retain) RWPageAttributes *defaultPageAttributes;

@property (assign) RWLinkStyle commonFileConsolidationMode;

@property (assign) BOOL previewAfterExportRelativeToBaseURL;

@property (assign) BOOL showTidiedCode;

extern NSString *const RWDocumentSiteBaseURLKey;
@property (copy) NSString *siteBaseURL;

@property (assign) BOOL useWebClipIcon;
@property (copy) NSData *webClipIconData;

@property (assign) BOOL useFavicon;
@property (copy) NSData *faviconData;

@property (nonatomic, retain) RWTheme *theme;
@property (nonatomic, retain) RMFolderWatcher *currentThemeFileWatcher;

@property (copy) NSString *siteDefaultExportDestination;

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
@property (copy) NSAttributedString *attributedGlobalHeader;
@property (readonly) BOOL useGlobalHeader;
@property (assign) BOOL hasChangedGlobalHeader;

@property (copy) NSString *globalPrefix;
@property (copy) NSAttributedString *attributedGlobalPrefix;
@property (readonly) BOOL useGlobalPrefix;
@property (assign) BOOL hasChangedGlobalPrefix;

- (BOOL)com_rwrp_checkAndWarnIfTIFF:(NSData *)data extendedWarning:(BOOL)warning;

- (BOOL)hasChangedGlobalFiles;
- (void)resetGlobalFilesChangedFlags;

@property (nonatomic, retain) NSMutableArray *fileReferences;
- (NSString *)registerFileURL:(NSURL *)fileURL withIdentifier:(NSString *)clientIdentifier error:(NSError **)error;
- (void)removeFileReferenceForToken:(NSString *)token;
- (BOOL)hasFileReferenceForToken:(NSString *)token;
- (NSURL *)fileURLForToken:(NSString *)token error:(NSError **)error;
- (NSArray *)fileTokensForPage:(RWPage *)page;

@end

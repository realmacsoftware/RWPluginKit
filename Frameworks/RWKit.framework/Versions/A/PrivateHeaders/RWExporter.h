
#import <Foundation/Foundation.h>

#import "RWKit/RWKit+Private.h"

@class RWDocument;
@class RWManifestGenerator;
@class RWPage;
@class RWSiteResource;
@class RWExporter;

extern NSString *const kRWExporterExportMode;
extern NSString *const kRWExporterPublishMode;
extern NSString *const kRWExporterPreviewMode;
extern NSString *const kRWExporterQuickLookMode;
extern NSString *const kRWExporterMasterStylePreviewMode;
extern NSString *const kRWExporterViewSourceCodeMode;
extern NSString *const kRWExporterConvertingForWebViewDOM;

/*
	These notifications ARE NOT posted on the main thread, this is a significant API change from RapidWeaver 5
	
	You MUST NOT wait on the main thread inside their handlers, doing so WILL deadlock RapidWeaver
 */

extern NSString *const kRWExporterSiteBackupDidStart;
extern NSString *const kRWExporterSiteBackupDidEnd;
extern NSString *const kRWExporterSiteBackupError;

extern NSString *const kRWExporterSiteExportDidStart;
extern NSString *const kRWExporterSiteExportDidEnd;
extern NSString *const kRWExporterSiteExportError;

extern NSString *const kRWExporterPageExportDidStart;
extern NSString *const kRWExporterPageExportDidEnd;
extern NSString *const kRWExporterPageExportError;

@protocol RWExporterDelegate <NSObject>

- (void)exporter:(RWExporter *)exporter didExportResource:(RWSiteResource *)resource;

@end

#pragma mark -

@interface RWExporter : NSObject

/*
	Configure
 */

- (id)initWithDocument:(RWDocument *)document;

@property (nonatomic, assign) id <RWExporterDelegate> delegate;

@property (nonatomic, assign) BOOL mergeFolders;

@property (nonatomic) RWLinkStyle consolidatedPathsStyle;

@property (nonatomic, copy) NSString *mode;

@property (nonatomic, copy) NSString *path;

@property (nonatomic, retain) NSMutableArray *exportedResourceURLs;

/*
	Start
 */

// Used to export a single page.

- (BOOL)exportPage:(RWPage *)page toPath:(NSString *)path inRoot:(NSString *)root usingName:(NSString *)name includingChildren:(BOOL)includingChildren;

// Used to export a site or group of pages.

- (BOOL)exportPages:(NSArray *)pages;

@property (nonatomic, readonly, assign, getter=isCancelled) BOOL cancelled;
- (void)cancel;

- (BOOL)exportSiteBackup;

/*
	Output
 */

@property (nonatomic) BOOL success;

@property (nonatomic, readonly) NSDictionary *manifests;

@end


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
extern NSString *const kRWExporterMasterStylePreviewMode;
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

extern NSString *const kRWExporterChecksumGenerationDidStart;
extern NSString *const kRWExporterChecksumGenerationDidEnd;

extern NSString *const kRWExporterPageExportDidStart;
extern NSString *const kRWExporterPageExportDidEnd;
extern NSString *const kRWExporterPageExportUpdateMessage;

#pragma mark -

@interface RWExporter : NSObject

/*
	Configure
 */

- (id)initWithDocument:(RWDocument *)document;

@property (nonatomic) RWLinkStyle consolidatedPathsStyle;

@property (nonatomic, copy) NSString *mode;

@property (nonatomic, copy) NSString *path;

@property (nonatomic, copy) NSString *overriddenSiteBaseURL;

/*
	Start
 */

// Used to export a single page.

- (BOOL)exportPage:(RWPage *)page subPagePath:(NSString *)subPagePath toPath:(NSString *)path inRoot:(NSString *)root usingName:(NSString *)name includingChildren:(BOOL)includingChildren;

// Used to export a site or group of pages.

- (void)exportPages:(NSArray *)pages completion:(void (^)(BOOL successful, NSError *error))completionBlock;

@property (nonatomic, readonly, assign, getter=isCancelled) BOOL cancelled;
- (void)cancel;

- (BOOL)exportSiteBackup;

- (void)parseHTMLString:(NSString *)htmlString forElementNames:(NSArray *)elementNames usingBlock:(void (^)(NSXMLElement *node, BOOL *stop))block;

/*
	Output
 */

@property (nonatomic) BOOL success;

@property (nonatomic, readonly) NSDictionary *manifests;

@end

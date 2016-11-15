//
//  RWSiteLayout.h
//  RapidWeaver
//
//  Created by Simon Taylor on 04/01/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWDocument;
@class RWPage;

@interface RWSiteLayout : NSObject

+ (instancetype)siteLayoutWithDocument:(RWDocument *)document;
- (id)initWithDocument:(RWDocument *)document;

@property (readonly, nonatomic, weak) RWDocument *document;

- (NSString *)pageName:(RWPage *)page;

// Now that we're owned by the document, this could be an instance variable.
- (NSString *)pathToPage:(RWPage *)page fromPage:(RWPage *)page2 inDocument:(RWDocument *)document relative:(BOOL)relative;
- (NSString *)pathToPage:(RWPage *)page fromPage:(RWPage *)page2 inDocument:(RWDocument *)document relative:(BOOL)relative cruftlessLinks:(BOOL)useCruftlessLinks;

- (NSString *)pathToPage:(RWPage *)page fromPage:(RWPage *)page2 inDocument:(RWDocument *)document relative:(BOOL)relative depthCorrection:(const NSInteger)depthCorrection;

// Applies to the from page.
- (NSString *)pathToPage:(RWPage *)page fromPage:(RWPage *)page2 inDocument:(RWDocument *)document relative:(BOOL)relative depthCorrection:(const NSInteger)depthCorrection cruftlessLinks:(BOOL)useCruftlessLinks;

/*
 
 */

- (NSString *)pathToRootFromPage:(RWPage *)page inDocument:(RWDocument *)document;

- (RWPage *)pageFromIndexFilePath:(NSString *)pagePath relativeTo:(NSString *)siteRoot inDocument:(RWDocument *)document;

- (RWPage *)pageFromPath:(NSString *)pagePath relativeTo:(NSString *)siteRoot inDocument:(RWDocument *)document;

- (BOOL)pageOccupiesSharedFolder:(RWPage *)page inDocument:(RWDocument *)document;

+ (BOOL)isReservedFolderName:(NSString *)name;

- (NSString *)decruftLinkIfEnabled:(NSString *)link;

+ (NSString *)pageImagesFolderName;
+ (NSString *)pageFilesFolderName;
+ (NSString *)pageAssetsFolderName;

+ (NSString *)commonFilesFolderName;
+ (NSString *)commonThemesFilesFolderPath;
+ (NSString *)commonPluginsFilesFolderPath;
+ (NSString *)commonAssetsFolderPath;
+ (NSString *)commonImagesFolderPath;

@end

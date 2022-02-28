//
//  RWPage.h
//  RapidWeaver
//
//  Created by Daniel Counsell on Wed Jun 16 2004.
//  Copyright (c) 2004 Realmac Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <RMKit/RMKit.h>
#import "RWKit.h"

@class MyDocument;
@class RWPageAttributes;
@class RWPageStyles;
@class RWTheme;
@class RWBookmark;
@class RWSearchResult;

@protocol RWPlugin;

@interface RWPage : NSObject <NSCoding, RWPage>

- (id)initWithPluginClass:(Class)pluginClass document:(MyDocument *)document;
- (id)initWithPlugin:(id <RWPlugin>)plugin document:(MyDocument*)document;

@property (nonatomic, weak) MyDocument *document;
@property (nonatomic, copy) NSString *uniqueID;

@property (nonatomic, weak) RWPage *parent;
@property (nonatomic, readonly, strong) NSMutableArray *children;

@property (nonatomic, readonly) BOOL pluginIsLoaded;
@property (nonatomic, strong) id <RWPlugin> plugin;
@property (nonatomic, strong) RMSandwich *pluginDataSandwich;
@property (nonatomic, strong) RMSandwich *pageSandwich;
@property (nonatomic, strong) NSDictionary* pluginClassInfo;
@property (nonatomic, readonly) Class pluginClass;
@property (nonatomic, strong) RWPageStyles *styles;
@property (nonatomic, strong) NSMutableDictionary *manifests;
@property (nonatomic, copy) NSDate *createdDate;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *buttonName;
@property (nonatomic, copy) NSString *themeName;
@property (nonatomic, copy) NSString *mostRecentlySelectedStyleName;
@property (nonatomic, readonly) NSURL *supportURL;

@property (nonatomic, assign) NSInteger savedIndex;

@property (nonatomic, strong) RWSiteResource *banner;
@property (nonatomic, copy) NSString *bannerAltText;

- (NSString *)path;
- (NSString *)type;

- (NSView *)view;
- (NSViewController *)viewController;

- (RWTheme *)theme;

- (BOOL)pageUsesDefaultSiteTheme;

@property (nonatomic, strong) RWPageAttributes *attributes;

- (void)addChild:(RWPage *)child;
- (void)removeChild:(RWPage *)child andChildren:(BOOL)removeChildren;

- (NSArray *)allChildren;

- (NSInteger)countChildren;

- (NSInteger)childIndex:(RWPage *)child;
- (void)setChildIndex:(RWPage *)child index:(NSUInteger)index;

- (RWPage *)pageFromUniqueID:(NSString *)uniqueID;
- (BOOL)containsPage:(RWPage *)page;

- (BOOL)isDescendedFrom:(RWPage *)page;
- (BOOL)isIndex;

- (NSString*)position;
- (NSInteger)hierarchyDepth;
- (NSInteger)pathDepth;

@property (copy, nonatomic) NSString *tidiedHTML;

- (BOOL)isExternalPage;
- (NSString*)externalPageURL;
- (NSString*)externalPageTarget;

- (BOOL)enabled;
- (BOOL)hidden;

- (NSMutableSet *)currentVariationsFlags:(BOOL *)siteFlags;
- (NSMutableDictionary *)currentColourVariations;

- (BOOL)hasOptionsAndConfigurationView;

- (NSImage *)icon;

- (void)notifyWasSelected;
- (void)notifyWasDeselected;

- (NSDictionary *)manifestForBookmark:(RWBookmark *)bookmark;
- (void)setManifest:(NSDictionary *)manifest forBookmark:(RWBookmark *)bookmark;
- (void)clearManifests;


- (void)repairFilePathsWithURL:(NSURL *)url;

- (void)searchForString:(NSString *)searchString foundResult:(void (^)(RWSearchResult *searchResult))foundBlock completion:(void (^)(void))completion;

@end

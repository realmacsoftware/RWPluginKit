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

@protocol RWPlugin;

@interface RWPage : NSObject <NSCoding, RWPage>

- (id)initWithPluginClass:(Class)pluginClass document:(MyDocument *)document;
- (id)initWithPlugin:(id <RWPlugin>)plugin document:(MyDocument*)document;

@property (nonatomic, assign) MyDocument *document;
@property (nonatomic, copy) NSString *uniqueID;

@property (nonatomic, assign) RWPage *parent;
@property (nonatomic, readonly, retain) NSMutableArray *children;

@property (nonatomic, retain) id <RWPlugin> plugin;
@property (nonatomic, retain) RWPageStyles *styles;
@property (nonatomic, retain) NSDictionary *manifest;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *buttonName;
@property (nonatomic, copy) NSString *themeName;
@property (nonatomic, copy) NSString *mostRecentlySelectedStyleName;

@property (nonatomic, assign) NSInteger savedIndex;

- (NSString *)path;
- (NSString *)type;

- (NSView *)view;

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

@property (strong, nonatomic) NSArray *errorsAndWarnings;
- (void)resetErrorsAndWarnings;
- (void)appendErrorsAndWarnings:(NSArray *)errors;

- (void)resetErrorsAndWarningsNoNotify;
- (void)appendErrorsAndWarningsNoNotify:(NSArray *)errors;

@property (copy, nonatomic) NSString *untidiedHTML;
- (void)setUntidiedHTMLNoNotify:(NSString *)untidiedHTML;

@property (copy, nonatomic) NSString *tidiedHTML;
- (void)setTidiedHTMLNoNotify:(NSString *)tidiedHTML;

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

@end

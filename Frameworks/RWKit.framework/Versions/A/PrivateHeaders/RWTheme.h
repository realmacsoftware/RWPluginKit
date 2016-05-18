/* RWTheme */

#import <Cocoa/Cocoa.h>

@interface RWTheme : NSObject

+ (instancetype)themeWithPath:(NSString *)path;

@property (readonly, retain) NSArray *colourTagFiles;
@property (readonly, retain) NSArray *files;
@property (readonly, retain) NSArray *keywords;

@property (readonly, retain) NSImage *largePreview;
@property (readonly, retain) NSImage *smallPreview;

@property (readonly, copy) NSString *themeAuthor;
@property (readonly, copy) NSString *themeName;
@property (readonly, copy) NSString *themeTitle;
@property (readonly, copy) NSString *shortName;
@property (readonly, copy) NSString *html;
@property (readonly) BOOL themeIsResponsive;

@property (readonly) NSString *path;
@property (readonly) NSString *version;
@property (readonly) NSString *versionString;
@property (readonly) NSURL *supportURL;

// RWTextToolbar plist values.
@property (readonly) BOOL toolbarAlwaysDisplayFullNavigation;
@property (readonly) BOOL toolbarDisplayFullSubNavigation;
@property (readonly) NSString *toolbarItemCurrent;
@property (readonly) NSString *toolbarItemCurrentParent;
@property (readonly) NSString *toolbarItemCurrentAncestor;
@property (readonly) NSString *toolbarItemCurrentAncestorParent;
@property (readonly) NSString *toolbarItemNormal;
@property (readonly) NSString *toolbarItemNormalParent;
@property (readonly) NSString *toolbarSubItem;
@property (readonly) NSString *toolbarList;
@property (readonly) NSString *toolbarBreadCrumb;
@property (readonly) NSString *toolbarBreadCrumbItem;
@property (readonly) NSString *toolbarBreadCrumbSeparator;

// RWBannerOptions
@property (readonly) CGSize bannerImageRecommendedSize;
@property (readonly) NSString *bannerImageRecommendedSizeString;
@property (readonly) NSString *pathToFallbackBannerRelativeToTheme;

// RWThemeCapabilities plist values.
@property (readonly) BOOL supportsToolbarRelTag;
@property (readonly) BOOL supportsPathTo;
@property (readonly) BOOL supportsPathToInFiles;
@property (readonly) BOOL supportsContentOnlySubPages;
@property (readonly) BOOL supportsBannerImages;

@property (readonly) BOOL themeIsClassic;

// RMStoreKit-style bundle identifier, nil for any incompatible themes.
@property (readonly) NSString *bundleIdentifier;

- (void)setupTheme;

// Style variations.
- (NSArray *)styleVariationGroups;
- (NSMutableSet *)styleVariationEnabledPaths;
- (NSString *)variationPathForMember:(id)member;
- (NSDictionary *)defaultColourVariations;

// Partial to full path utility.
- (NSString *)themeElementNameToFullPath:(NSString *)name;

+ (NSArray *)themeExtensions;
+ (BOOL)isThemeExtension:(NSString *)extension;

@end

/* RWTheme */

#import <Cocoa/Cocoa.h>

@interface RWTheme : NSObject

+ (instancetype)themeWithPath:(NSString *)path;

@property (readonly, strong) NSArray *colourTagFiles;
@property (readonly, strong) NSArray *files;
@property (readonly, strong) NSArray *keywords;

@property (readonly, strong) NSImage *largePreview;
@property (readonly, strong) NSImage *smallPreview;

@property (readonly, copy) NSString *themeAuthor;
@property (readonly, copy) NSString *themeName;
@property (readonly, copy) NSString *themeTitle;
@property (readonly, copy) NSString *shortName;
@property (readonly, copy) NSString *html;
@property (readonly) BOOL themeIsResponsive;

@property (weak, readonly) NSString *path;
@property (weak, readonly) NSString *version;
@property (weak, readonly) NSString *versionString;
@property (weak, readonly) NSURL *supportURL;

// RWTextToolbar plist values.
@property (readonly) BOOL toolbarAlwaysDisplayFullNavigation;
@property (readonly) BOOL toolbarDisplayFullSubNavigation;
@property (weak, readonly) NSString *toolbarItemCurrent;
@property (weak, readonly) NSString *toolbarItemCurrentParent;
@property (weak, readonly) NSString *toolbarItemCurrentAncestor;
@property (weak, readonly) NSString *toolbarItemCurrentAncestorParent;
@property (weak, readonly) NSString *toolbarItemNormal;
@property (weak, readonly) NSString *toolbarItemNormalParent;
@property (weak, readonly) NSString *toolbarSubItem;
@property (weak, readonly) NSString *toolbarList;
@property (weak, readonly) NSString *toolbarBreadCrumb;
@property (weak, readonly) NSString *toolbarBreadCrumbItem;
@property (weak, readonly) NSString *toolbarBreadCrumbSeparator;

// RWBannerOptions
@property (readonly) CGSize bannerImageRecommendedSize;
@property (weak, readonly) NSString *bannerImageRecommendedSizeString;
@property (weak, readonly) NSString *pathToFallbackBannerRelativeToTheme;

// RWThemeCapabilities plist values.
@property (readonly) BOOL supportsToolbarRelTag;
@property (readonly) BOOL supportsPathTo;
@property (readonly) BOOL supportsPathToInFiles;
@property (readonly) BOOL supportsContentOnlySubPages;
@property (readonly) BOOL supportsBannerImages;
@property (readonly) BOOL supportsAlphaInColours;

@property (readonly) BOOL themeIsClassic;

// RMStoreKit-style bundle identifier, nil for any incompatible themes.
@property (weak, readonly) NSString *bundleIdentifier;

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

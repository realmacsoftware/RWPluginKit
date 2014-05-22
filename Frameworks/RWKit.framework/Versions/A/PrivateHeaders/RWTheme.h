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

@property (readonly) NSString *path;
@property (readonly) NSString *version;
@property (readonly) NSURL *supportURL;

// RWTextToolbar plist values.
@property (readonly) BOOL toolbarAlwaysDisplayFullNavigation;
@property (readonly) NSString *toolbarItemCurrent;
@property (readonly) NSString *toolbarItemCurrentAncestor;
@property (readonly) NSString *toolbarItemNormal;
@property (readonly) NSString *toolbarList;
@property (readonly) NSString *toolbarBreadCrumb;
@property (readonly) NSString *toolbarBreadCrumbItem;
@property (readonly) NSString *toolbarBreadCrumbSeparator;

// RWThemeCapabilities plist values.
@property (readonly) BOOL supportsToolbarRelTag;
@property (readonly) BOOL supportsPathTo;
@property (readonly) BOOL supportsContentOnlySubPages;

// RMStoreKit-style bundle identifier, nil for any incompatible themes.
@property (readonly) NSString *bundleIdentifier;

- (void)setupTheme;

// Style variations.
- (NSArray *)styleVariationGroups;
- (NSMutableSet *)styleVariationEnabledPaths;
- (NSString *)variationPathForMember:(id)member;

// Partial to full path utility.
- (NSString *)themeElementNameToFullPath:(NSString *)name;

+ (NSArray *)themeExtensions;
+ (BOOL)isThemeExtension:(NSString *)extension;

@end

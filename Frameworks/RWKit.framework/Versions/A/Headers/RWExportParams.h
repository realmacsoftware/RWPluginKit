//***************************************************************************

// Copyright (C) 2005-2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import <RMKit/RMKit.h>
#import <RMKit/RMModelObject.h>

//***************************************************************************

@class RWPageAttributes;
@class RWTheme;

//***************************************************************************

typedef enum
{
	/// This page has its own customised page style
	/** This does _not_ indicate that the page has its own customised _theme_, only the theme style!  Note that this is the same as the kRWPageStyleVariationsPageMode value declared in RWPageAttributes.h (but we can't import RWPageAttributes.h since that's part of RapidWeaver and not part of RWKit yet). */
	RWPageStyleModePage = 0,
	
	/// This page uses the default site style for its current theme
	/** Note that this is the same as the kRWPageStyleVariationsSiteMode value declared in RWPageAttributes.h (but we can't import RWPageAttributes.h since that's part of RapidWeaver and not part of RWKit yet). */
	RWPageStyleModeSite
}
RWPageStyleMode;

typedef enum
{
	RWExportModeExport,
	RWExportModePublish,
	RWExportModePreview,
	RWExportModeViewSourceCode,
	RWExportModeConvertingForWebViewDOM,
}
RWExportMode;

typedef enum
{
	RWCommonFilesPathModeAbsolute,
	RWCommonFilesPathModeRelative,
}
RWCommonFilesPathMode;

//***************************************************************************

extern NSString* RWExportModeStringFromExportModeEnum(RWExportMode exportMode);
extern RWExportMode RWExportModeEnumFromExportModeString(NSString* exportMode);

//***************************************************************************

@interface RWExportParameters : RMModelObject

/// Creates an (autoreleased) export parameters object from the given parameters dictionary.
+ (RWExportParameters*)exportParametersWithDictionary:(NSDictionary*)paramsDictionary;

/// Initialises an export parameters object from the given parameters dictionary.
- (RWExportParameters*)initWithDictionary:(NSDictionary*)paramsDictionary;

/// Returns the export settings in dictionary format, suitable used for the 'params' or 'exportParameters' in RapidWeaver's old -export functions.
- (NSMutableDictionary*)dictionary;

// e.g. "html"
@property (copy) NSString* filenameExtension;

// e.g. "assets"
@property (copy) NSString* assetsFolderName;

@property (retain) RWPageAttributes* pageAttributes;

// e.g. "http://web.me.com/foobar/MyWebsite"
@property (copy) NSURL* baseURL;

@property RWCommonFilesPathMode commonFilesPathMode;

// e.g. 0
@property BOOL contentOnlySubpages;

// e.g. ""
@property (copy) NSString* customCSSPath; 

// e.g. ""
@property (copy) NSString* customHeader;

// e.g. ""
@property (copy) NSString* customJavaScript;

// e.g. "files"
@property (copy) NSString* filesFolderName;

// e.g. "images"
@property (copy) NSString* imagesFolderName;

// e.g. "index.html"
@property (copy) NSString* indexFilename;

// e.g. ""
@property (copy) NSString* location;

// e.g. RWExportModePublish
@property RWExportMode exportMode;

// e.g. "index.html"
@property (copy) NSString* name;

// e.g. "utf-8"
@property (copy) NSString* encoding; 

/// The filesystem path that the export should be performed to.  
// e.g. "/private/var/folders/4K/4KPl0EDa2RW0Rk+1YwSRB++++TI/TemporaryItems/RapidWeaver/70086/document-8055824/RWDocumentPagePreview"
@property (copy) NSString* exportPath;

// e.g. ""
@property (copy) NSString* pluginCommonPath;

// e.g. "Theme Default"
@property (copy) NSString* styleName;

@property RWPageStyleMode pageStyleMode;

@property (retain) RWTheme* theme;

// e.g. ""
@property (copy) NSString* themeCommonPath;

// e.g. "Untitled Page"
@property (copy) NSString* title;

@property (copy) NSDictionary* styles; 

@end

//***************************************************************************

/// The following category is provided for backward ABI compatibility with RapidWeaver 3.x only.
/** Please do _not_ use _any_ of the methods here, so that we can deprecate these evil category methods as quickly as possible.  Use the actual -object:forKey: method of NSDictionary to access the parameters dictionary instad.  This dictionary will eventually be replaced by the RWExportParameters class. */
@interface NSDictionary (RWExportParams)

/// The dictionary key for this method is @"mode"
- (NSString*)exportMode DEPRECATED_ATTRIBUTE;

/// Replace this method with [[dictionary objectForKey:@"mode"] isEqual:@"preview"]
- (BOOL)isPreviewExportMode DEPRECATED_ATTRIBUTE;

/// Replace this method with [[dictionary objectForKey:@"mode"] isEqual:@"export"]
- (BOOL)isExportExportMode DEPRECATED_ATTRIBUTE;

/// Replace this method with [[dictionary objectForKey:@"mode"] isEqual:@"publish"]
- (BOOL)isPublishExportMode DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"name"
- (NSString*)exportFilename DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"FilenameExt"
- (NSString*)exportFilenameExtension DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"title"
- (NSString*)exportPageTitle DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"path"
- (NSString*)exportPagePath DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"location"
- (NSString*)exportPageLocation DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"filesfoldername"
- (NSString*)exportFilesFolderName DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"imagesfoldername"
- (NSString*)exportImagesFolderName DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"assetsfoldername"
- (NSString*)exportAssetsFolderName DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"attributes"
- (NSDictionary*)exportPageAttributes DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"index"
- (NSString*)exportSiteIndexFilename DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"themecommonpath"
- (NSString*)exportPathToCommonThemeFiles DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"plugincommonpath"
- (NSString*)exportPathToCommonPluginFiles DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"commonpathsrelative"
- (BOOL)exportCommonPathsAreRelatve DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"commonpathsabsolute"
- (BOOL)exportCommonPathsAreAbsolute DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"base"
- (NSString*)exportSiteBaseURL DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"contentonlysubpages"
- (BOOL)contentOnlySubpagesEnabled DEPRECATED_ATTRIBUTE;

/// The dictionary key for this method is @"subpage"
- (BOOL)emitContentForSubpage DEPRECATED_ATTRIBUTE;

// The dictionary key for the page encoding is @"pagecharset"

@end

//***************************************************************************

//***************************************************************************

// Copyright (C) 2005-2010 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RMKit/RMKit.h"

@class RWPageAttributes;
@class RWTheme;

typedef enum {
	/// This page has its own customised page style
	/** This does _not_ indicate that the page has its own customised _theme_, only the theme style!  Note that this is the same as the kRWPageStyleVariationsPageMode value declared in RWPageAttributes.h (but we can't import RWPageAttributes.h since that's part of RapidWeaver and not part of RWKit yet). */
	RWPageStyleModePage = 0,
	
	/// This page uses the default site style for its current theme
	/** Note that this is the same as the kRWPageStyleVariationsSiteMode value declared in RWPageAttributes.h (but we can't import RWPageAttributes.h since that's part of RapidWeaver and not part of RWKit yet). */
	RWPageStyleModeSite
}
RWPageStyleMode;

typedef enum {
	RWExportModeExport,
	RWExportModePublish,
	RWExportModePreview,
	RWExportModeMasterStyle,
	RWExportModeViewSourceCode,
	RWExportModeConvertingForWebViewDOM,
	RWExportModeQuickLook,
    RWExportModeSearch
} RWExportMode;

typedef enum {
	RWCommonFilesPathModeAbsolute,
	RWCommonFilesPathModeRelative,
} RWCommonFilesPathMode;

extern NSString* RWExportModeStringFromExportModeEnum(RWExportMode exportMode);
extern RWExportMode RWExportModeEnumFromExportModeString(NSString* exportMode);

@interface RWExportParameters : NSObject

/// Creates an (autoreleased) export parameters object from the given parameters dictionary.
+ (RWExportParameters*)exportParametersWithDictionary:(NSDictionary*)paramsDictionary;

/// Initialises an export parameters object from the given parameters dictionary.
- (RWExportParameters*)initWithDictionary:(NSDictionary*)paramsDictionary;

/// Returns the export settings in dictionary format, suitable used for the 'params' or 'exportParameters' in RapidWeaver's old -export functions.
- (NSMutableDictionary*)dictionary;

// e.g. "html"
@property (copy) NSString* filenameExtension;

@property (copy) NSString *resourcesFolderName;

@property (strong) RWPageAttributes* pageAttributes;

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

@property (strong) RWTheme* theme;

// e.g. ""
@property (copy) NSString* themeCommonPath;

// e.g. "Untitled Page"
@property (copy) NSString* title;

@property (copy) NSDictionary* styles;

@end

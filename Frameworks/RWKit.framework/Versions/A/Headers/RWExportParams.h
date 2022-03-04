//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************

@import Cocoa;

#import <RWKit/RWKit-Constants.h>

/// Useful for accessing export parameters while using pre RW9 export methods
/// See RWPluginPublishingProtocol interface for improved RW9 export
__attribute__((objc_subclassing_restricted))
@interface RWExportParameters : NSObject

/// Creates an export parameters object from the given parameters dictionary.
+ (RWExportParameters *)exportParametersWithDictionary:(NSDictionary *)paramsDictionary;

/// Initialises an export parameters object from the given parameters dictionary.
- (RWExportParameters *)initWithDictionary:(NSDictionary *)paramsDictionary;

/// Returns the export settings in dictionary format, suitable used for the 'params' or 'exportParameters' in RapidWeaver's old -export functions.
- (NSMutableDictionary *)dictionary;

/// Filename extension this page will use e.g. "html"
@property (nonatomic, readonly) NSString *filenameExtension;

/// Always "Resources"
@property (nonatomic, readonly) NSString *resourcesFolderName;

/// Website address where this page will be published e.g. "http://web.me.com/foobar/MyWebsite"
@property (nonatomic, readonly) NSURL *baseURL;

/// Link style used when referencing resources or other pages
@property (nonatomic, readonly) RWKitLinkStyle commonFilesPathMode;

/// Custom CSS to be applied to each page
@property (nonatomic, readonly) NSString *customCSS;

/// Custom headers to be applied to each page
@property (nonatomic, readonly) NSString *customHeader;

/// Custom Javascript to be applied to each page
@property (nonatomic, readonly) NSString *customJavaScript;

/// Name of the folder containing page files e.g. "files"
@property (nonatomic, readonly) NSString *filesFolderName;

/// Name of the folder containing page images e.g. "images"
@property (nonatomic, readonly) NSString *imagesFolderName;

/// Filename of the site index page e.g. "index.html"
@property (nonatomic, readonly) NSString *indexFilename;

/// Location of this page when published e.g. "products/books"
@property (nonatomic, readonly) NSString *location;

/// Export mode, see RWExportMode for more information
@property (nonatomic, readonly) RWExportMode exportMode;

/// Filename of this page e.g. "index.html"
@property (nonatomic, readonly) NSString *name;

/// Page encoding e.g. "utf-8"
@property (nonatomic, readonly) NSString *encoding;

/// Path where exported files should be written
@property (nonatomic, readonly) NSString *exportPath;

/// Path to the plugin's common files e.g. "rw_common/plugins/styledtext"
@property (nonatomic, readonly) NSString *pluginCommonPath;

/// Path to the theme's files  e.g. "rw_common/themes/offroad"
@property (nonatomic, readonly) NSString *themeCommonPath;

/// Browser Title e.g. "Untitled Page"
@property (nonatomic, readonly) NSString *title;

/// Theme style to apply e.g. "Theme Default"
@property (nonatomic, readonly) NSString *styleName;

/// Dictionary of theme style variations
@property (nonatomic, readonly) NSDictionary *styles;

@end

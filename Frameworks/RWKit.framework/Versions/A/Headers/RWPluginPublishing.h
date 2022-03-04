//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2020 Realmac Software. All rights reserved.
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

@import Foundation;

@protocol RWPluginPublishingContext;
@protocol RWPluginPublishChildPage;


#pragma mark - Publish Parameters

@protocol RWPluginPublishingParams <NSObject>

@property (nonatomic, readonly) NSString * _Nonnull path;
@property (nonatomic, readonly) NSString * _Nonnull subPagePath;
@property (nonatomic, readonly) NSString * _Nonnull name;
@property (nonatomic, readonly) NSString * _Nonnull title;
@property (nonatomic, readonly) NSString * _Nonnull browserTitle;
@property (nonatomic, readonly) NSString * _Nonnull location;
@property (nonatomic, readonly) NSString * _Nonnull filesFolderName;
@property (nonatomic, readonly) NSString * _Nonnull imagesFolderName;
@property (nonatomic, readonly) NSString * _Nonnull index;
@property (nonatomic, readonly) NSString * _Nonnull themeCommonPath;
@property (nonatomic, readonly) NSString * _Nonnull pluginCommonPath;
@property (nonatomic, readonly) BOOL commonPathsRelative;
@property (nonatomic, readonly) BOOL commonPathsAbsolute;
@property (nonatomic, readonly) NSArray * _Nonnull variations;
@property (nonatomic, readonly) BOOL styleVariationMode;
@property (nonatomic, readonly) NSString * _Nonnull customCSS;
@property (nonatomic, readonly) NSString * _Nonnull customJavaScript;
@property (nonatomic, readonly) NSString * _Nonnull customHeader;
@property (nonatomic, readonly) NSString * _Nonnull customBody;
@property (nonatomic, readonly) NSString * _Nonnull globalCSSPath;
@property (nonatomic, readonly) NSString * _Nonnull globalJavaScriptPath;
@property (nonatomic, readonly) NSString * _Nonnull pageCharset;
@property (nonatomic, readonly) NSString * _Nonnull filenameExt;
@property (nonatomic, readonly) NSString * _Nonnull styleName;
@property (nonatomic, readonly) NSString * _Nonnull webSiteURL;
@property (nonatomic, readonly) NSString * _Nonnull pageIdentifier;
@property (nonatomic, readonly) BOOL consolidateCSSFiles;
@property (nonatomic, readonly) BOOL isPreviewMode;
@property (nonatomic, readonly) BOOL isSearchMode;

@end



#pragma mark - Publishing

@protocol RWPluginPublishing

// May be called on any thread
- (void)publishPageWithContext:(id <RWPluginPublishingContext> _Nonnull)context;

@end

#pragma mark - Page

typedef NS_OPTIONS(NSInteger, AttributedStringExportOption) {
    AttributedStringExportOptionStripPath = 1 << 0,
    AttributedStringExportOptionAbsolutePath = 1 << 1
};

@protocol RWPluginPublishingContext <NSObject>


#pragma mark - Inputs

// Contains all parameters to apply during this export
@property (atomic, readonly) id <RWPluginPublishingParams> _Nonnull params;

// Check periodically, if YES the export has been cancelled
@property (atomic, readonly) BOOL exportAborted;


#pragma mark - Outputs
// EXPORT DATA

// Apply the theme to this page's content. If NO, contentHTML will be exported as raw HTML
@property (nonatomic, assign) BOOL applyTheme;

// Preferred filename for this page
@property (nonatomic, strong) NSString * _Nullable preferredFilename;

// HTML to be placed in the '%content%' area
@property (nonatomic, strong) NSString * _Nullable contentHTML;

@property (nonatomic, strong) NSString * _Nullable sidebarHTML;
@property (nonatomic, strong) NSString * _Nullable extraHeadHTML;
@property (nonatomic, strong) NSString * _Nullable extraBodyHTML;
@property (nonatomic, strong) NSString * _Nullable prefix;

// Files exported to the page's "files" folder
- (void)addFileWrapper:(NSFileWrapper * _Nonnull)wrapper;

// Add a child page, applying substitutions. Resulting content will be stored in the page's "files" folder
- (void)addChildPage:(id <RWPluginPublishChildPage> _Nonnull)page;

#pragma mark - Utility

// Returns HTML suitable for inclusion into this page, any required assets are stored in the page's "files" folder
- (NSString * _Nonnull)htmlForAttributedString:(NSAttributedString * _Nonnull)attributedString;
- (NSString * _Nonnull)htmlForAttributedString:(NSAttributedString * _Nonnull)attributedString options:(AttributedStringExportOption)options;

@end


#pragma mark - Child Page

@protocol RWPluginPublishChildPage <NSObject>

// Preferred filename for this page
@property (nonatomic, strong) NSString * _Nonnull preferredFilename;

// Title for the page
@property (nonatomic, strong) NSString * _Nonnull title;

// HTML to be placed in the '%content%' area
@property (nonatomic, strong) NSString * _Nonnull contentHTML;

// Sidebar for the child page
@property (nonatomic, strong) NSString * _Nullable sidebarHTML;

// Override the open graph title header
@property (nonatomic, strong) NSString * _Nullable ogTitle;

// Override the open graph description header
@property (nonatomic, strong) NSString * _Nullable ogDescription;

// Override the open graph description image
@property (nonatomic, strong) id <RWResourceProtocol> _Nullable ogImage;



//- (void)setApplyTheme:(BOOL)applyTheme;
//- (void)setExtraHeadHTML:(NSString *)extraHeadHTML;
//- (void)setExtraBodyHTML:(NSString *)extraBodyHTML;
//- (void)setPagePrefix:(NSString *)prefix;
//- (void)setHeader:(NSString *)name value:(NSString *)value;
//
//- (void)setFilesWrapper:(NSFileWrapper *)wrapper;

@end

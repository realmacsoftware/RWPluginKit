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

@import Foundation;

@protocol RWPluginExportContextPage;
@protocol RWPluginExportContextChildPage;

/// Traditional export methods available in previous versions of RW
/// See RWPluginPublishingProtocol interface for improved RW9+ export
@protocol RWPluginExport

/// This notification is posted when a site export begins
/// Posted from a background thread
extern NSString * _Nonnull const kRWExporterSiteExportDidStart;

/// This notification is posted when a site export finishes
/// Posted from a background thread
extern NSString * _Nonnull const kRWExporterSiteExportDidEnd;

/// Notification posted when page export starts. Notification object is a dictionary containing the page (id<RWPageProtocol>) being exported
/// Posted from a background thread
extern NSString * _Nonnull const kRWExporterPageExportDidStart;

/// Notification posted when page export ends. Notification object is a dictionary containing the page (id<RWPageProtocol>) being exported
/// Posted from a background thread
extern NSString * _Nonnull const kRWExporterPageExportDidEnd;

// This method has the same use as its instance counterpart below, except this class version should be used for copying files specific to the plugin itself, rather than the plugin instance. For example, the - (NSArray *)extraFilesNeededInExportFolder: should return the user's photos, and  + (NSArray *)extraFilesNeededInExportFolder: should return a picture frame graphic.
+ (NSArray * _Nullable)extraFilesNeededInExportFolder:(NSDictionary * _Nonnull)parameters;

// This should return an NSArray of NSString file paths if your plugin needs any files (such as images, audio, style sheets, and others) copied into the export folder when the user exports a site for publishing. The files should be located in some sort of temporary directory. Pass an array with no objects if you don't need any extra files copied.
- (NSArray * _Nullable)extraFilesNeededInExportFolder:(NSDictionary * _Nonnull)parameters;

#pragma mark - Page Content

/// This should return all HTML code suitable to be placed inside the page's content area
- (NSString * _Nullable)contentHTML:(NSDictionary * _Nonnull)parameters;

/// This should return all HTML code suitable to be placed inside the page's sidebar area
- (NSString * _Nullable)sidebarHTML:(NSDictionary * _Nonnull)parameters;

/// This should return any HTML to be inserted immediately before the closing body tag
- (NSString * _Nullable)extraBodyHTML:(NSDictionary * _Nonnull)parameters;

/// Defaults to YES. Return NO to opt out of asynchronous exporting
- (BOOL)allowsAsynchronousExport;

/// This method is invoked by RapidWeaver to inform your plugin to cancel the export.
/** When you receive this message, it is recommended that you toggle a BOOL
  * property inside your plugin that you frequently check; when you detect that
  * the BOOL has been toggled, tidy up any temporary storage and return as soon
  * as possible. */
- (void)cancelExport;

 @optional

/// If implemented, should return a string to be placed into the theme's %plugin_header% area (usually inside the <head> tag of the HTML)
- (NSString * _Nullable)pageContentHeaders:(NSDictionary * _Nonnull)parameters;

/// If implemented, should return a string to be placed before the HTML DOCTYPE header on the page
- (NSString * _Nonnull)pageContentPrefix:(NSDictionary * _Nonnull)parameters;

/// If implemented, should return an array of strings (urls) to be placed in the sitemap.xml file
- (NSArray <NSString *> * _Nonnull)pagesForSiteMap:(NSDictionary * _Nonnull)parameters;

#pragma mark - External URLs

/// Defaults to NO. YES indicates this page points to an external URL
- (BOOL)isExternalPage;

/// If isExternalPage returns YES, this method should be implemented and return the external URL
- (NSURL * _Nullable)externalPageURL;

#pragma mark - Export Progress

// Call this method during export to update RW's progress window with a message and percent completion
- (void)broadcastPluginExportStatus:(NSString * _Nonnull)message progress:(CGFloat)percent;


@end

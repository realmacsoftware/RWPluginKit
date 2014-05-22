//***************************************************************************

// Copyright (C) 2004-2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RWKit/RWDocumentProtocol.h"
#import "RWKit/RWPageProtocol.h"

@class RMHTMLPackage;
@class RMSandwich;
@class RWExportParameters;

/*!
	\brief
	These methods will be removed and the data will be loaded from a file inside the plug-in bundle which RapidWeaver will read instead of loading the bundle
 */
@protocol RWPluginMetadata <NSObject>

/// Returns a localised name of the plugin.
/** The localised name will be displayed in RapidWeaver's plugin listing.  For
 * example, you may return "Photo Album" in English, or "Album de photos" for
 * French. */
+ (NSString *)pluginName;

/// Returns the author of the plugin.
/** For example: "Realmac Software Ltd". */
+ (NSString *)pluginAuthor;

/// Returns a resolution-independent icon of the plugin, which will used in RapidWeaver's page list.  The icon will usually be displayed at a size of 128x128 pixels.
+ (NSImage *)pluginIcon;

/// Returns a very small version of the icon for the plugin, which is used in RapidWeaver's page list. The icon will usually be displayed at a size of 16x16px
+ (NSImage *)smallPluginIcon;

/// Returns a localised description of the plugin, to be displayed to the user.
/** For example: "The Photo Album plugin enables you to publish your iPhoto
 * galleries and other images from your local hard disk to the Web." */
+ (NSString *)pluginDescription;

// This should return YES if you provide an HTML description for your plugin (rather than an NSString*)
+ (BOOL)hasHTMLDescription;

@end

@protocol RWPluginExport <NSObject>

/*
	These notifications ARE NOT posted on the main thread, this is a significant API change from RapidWeaver 5
	
	You MUST NOT wait on the main thread inside their handlers, doing so WILL deadlock RapidWeaver
 */

/// This notification name is sent just as a site export has been started.
/** The notification object will be the RWDocument that is being exported. */
extern NSString *const kRWExporterSiteExportDidStart;

/// This notification name is sent just as a site export has been finished.
/** The notification object will be the RWDocument that is being exported. */
extern NSString *const kRWExporterSiteExportDidEnd;

/// This notification name is sent just after a page export has been started.
/** The notification object will be the RWPage that is being exported. */
extern NSString *const kRWExporterPageExportDidStart;

/// This notification name is sent just after a page export has been finished.
/** The notification object will be the RWPage that is being exported. */
extern NSString *const kRWExporterPageExportDidEnd;

// This method has the same use as its instance counterpart below, except this class version should be used for copying files specific to the plugin itself, rather than the plugin instance. For example, the - (NSArray *)extraFilesNeededInExportFolder should return the user's photos, and  + (NSArray *)extraFilesNeededInExportFolder should return a picture frame graphic.
+ (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)parameters;

// This should return an NSArray of NSString file paths if your plugin needs any files (such as images, audio, style sheets, and others) copied into the export folder when the user exports a site for publishing. The files should be located in some sort of temporary directory. Pass an array with no objects if you don't need any extra files copied.
- (NSArray *)extraFilesNeededInExportFolder:(NSDictionary *)parameters;

// This should return all HTML code resulting from user-interaction. The code should be suitable to be placed inside RapidWeaver's content area.
- (NSString *)contentHTML:(NSDictionary *)parameters;

// This should return all HTML code generated by the plugin. The code should be suitable to be placed inside RapidWeaver's sidebar area.
- (NSString *)sidebarHTML:(NSDictionary *)parameters;

 @optional

// If implemented, it should return a string that will be substituted into the theme's %plugin_header% area (usually inside the <head> tag of the HTML).
- (NSString *)pageContentHeaders:(NSDictionary *)parameters;

// This method should return a string, which will be placed before the HTML DOCTYPE header on the page.  This method is optional; if you don't define it, no extra content will be placed before the DOCTYPE header.
- (NSString *)pageContentPrefix:(NSDictionary*)parameters;

/// If you implement this method, the HTML returned in -renderForPage: or -contentHTML: is used as the entire page contents' HTML, rather than being placed in the %content% tag inside the page.
/** The name parameter is ignored. */
- (NSMutableDictionary *)contentOnlySubpageWithEntireHTML:(NSString *)content name:(NSString *)name;

/// Returns an HTML package that is placed into the webpage's main content area.
/** Normally, the main resource of the HTML package is substituted directly into the %content% area of the theme file, unless you implement the -contentOnlySubpageWithEntireHTML:name: method.  If you wish to publish extra files besides the main HTML resource, put those extra files inside the HTML package with the same directory name as the exportParameters.filesFolderName property. */
- (RMHTMLPackage *)renderForPage:(RWExportParameters *)exportParameters;

 @required

/// This method is invoked by RapidWeaver to inform your plugin to cancel the export.
/** When you receive this message, it is recommended that you toggle a BOOL
  * property inside your plugin that you frequently check; when you detect that
  * the BOOL has been toggled, tidy up any temporary storage and return as soon
  * as possible. */
- (void)cancelExport;

 @optional

- (NSArray *)pagesForSiteMap:(NSDictionary *)info;

- (NSString *)defaultFolderName;

@end

@protocol RWPluginSettings <NSObject>

// return a dirctionary describing the plugin and its exportable settings
// TODO: Need to document this more
- (NSDictionary *)pluginSettings;

// apply the settings as returned from -pluginSettings to this plugin
// TODO: Need to document this more
- (void)setPluginSettings:(NSDictionary *)settings;

// return YES if this plugin will accept 'settings'
// TODO: Need to document this more
- (BOOL)acceptsPluginSettings:(NSDictionary *)settings;

// return YES if this plugin can provide settings (default is NO)
// TODO: Need to document this more
- (BOOL)providesPluginSettings;

@end

@protocol RWPluginArchiving <NSObject>

 @optional

/// Creates a new plugin instance with the given sandwich.
+ (id)createWithSandwich:(RMSandwich *)sandwich;

/// Returns a sandwich that will be saved to disk, as part of the user's RapidWeaver document.
- (RMSandwich *)sandwich;

/// This is similar to the +pluginName method, but is used in preference to +pluginName when saving a document.
/** This is mostly designed for the RWPluginPlaceholder class, which is used
 * when RapidWeaver loads a document that uses a plugin not currently
 * installed on the system.  RWPluginPlaceholder's +pluginName method returns
 * "Placeholder", but its -archivingName implementation returns the name of
 * the plugin it's standing in place for (such as "Blocks").  This enables the
 * plugin placeholder to communicate to the saving code the real name of the
 * plugin.  Note that this is an instance method, unlike +pluginName, which
 * is a class method.  If you do not implement this method, the saving
 * code will use the result of +pluginName instead. */
- (NSString *)archivingName;

/// This is similar to +pluginAuthor, but is used in preference to +pluginAuthor when saving a document.
/** See the documentation for -archivingName for more information. */
- (NSString *)archivingAuthor;

/// Returns the homepage for the plugin, which the user may visit to find out more information about your plugin.
/** You may return nil if your plugin does not have a real homepage (though I
 * guess a better solution would be to create a homepage... RapidWeaver may be
 * useful for doing that :).  For example:
 * [NSURL URLWithString:@"http://www.myrapidweaverplugins.com/myplugin/"]
 * See the documentation for -archivingName for more information. */
- (NSURL *)archivingHomepageURL;

/// The class name for the plugin that will be used when saving a document.
/** You may override this method to enable a different class name to be used
 * as the factory class.  This method is intended mostly to be used by
 * RWPluginPlaceholder (which returns the class name of the plugin that it's
 * standing in for, such as "YHBlocks"), but may be useful in other bizarre
 * circumstances.  If you do not implement this method, the receiver's
 * -className method will be used instead.  Note that this is an instance
 * method, not a class method. */
- (NSString *)archivingClassName;

/// Returns an NSData object that will be written when saving a document.
/** This method is only called if -sandwich returns nil.  You will usually
 * never need to implement this method: this method is mostly for the benefit
 * of the RWPluginPlaceholder class, which must be able to preserve
 * non-sandwiched plugin data archives exactly in their original state.  If
 * you implement this method, the data returned in this method will be used
 * to create the plugin from a saved document if your plugin's
 * +createWithSandwich: method doesn't exist or returns nil. */
- (NSData *)archivingData;

 @optional

/*!
	\brief
	Invoked on the main thread after `document` returns non nil
 */
- (void)documentWasLoaded;

@end

@protocol RWPluginEditing <NSObject>

/*!
	\brief
	Return result is not retained by RW
	This should return the view to be shown inside RapidWeaver for editing the attributes and content associated with your plugin. For example, for a blog plugin, this would be a view showing a table view of blog entries and text views for editing each entry.
 */
- (NSView *)userInteractionAndEditingView;

/*!
	\bief
	Return result is not retained by RW
	This should return the view that will appear in the Page Inspector's Page Settings tab
 */
- (NSView *)optionsAndConfigurationView;

 @optional

/*!
	\brief
	Returns an array of menu items to be added to the view.
	The view, in this case, is an RWTextView. Normally this would
	just be overriden as part of the normal sub-classing via
	-menuForEvent: but since we hide the RWTextView in a RWStyledTextView
	that's not currently possible. ie: You can't override RWTextView
	when using an RWStyledTextView in your NIB/XIBs. Instead, test
	your view here and provide any items as necessary.
	if (view == myStyledTextView.textView) {// do something...}
 */
- (NSArray *)contextualMenuAdditionsForView:(id)view;

// This method should rescale all images that are saved in the document to their final output size on the web page.  The return value is the number of images normalised.  As an example, let's say a user has three images in their page: one image is 350x350 pixels at 100% scaling; another image is 1000x1000 with a final output size of 600x300 (set in the media inspector or because your plugin enforces it), and the third image is 5000x5000 rescaled to 10% of its original size.  After image normalisation, the first image should remain unchanged at 350x350 pixels due to it having a scale factor of 100%; the second image will be 600x300; the third image will be 500x500.  If you have any NSMutableAttributedString instance variables in your plugin, you may call a method named -[RWTextView normaliseImageAttachments], which returned an unsigned int.  That method will normalise any images in the styled text view for you.  Note that you must implement this method to avoid a warning when the image normalisation information sheet appears to the user.  If you do not store any images in your plugin or do need not to normalise any images, simply return [NSNumber numberWithUnsignedInt:0].  Note the British spelling of this method!
- (NSNumber *)normaliseImages;

/*!
	\brief
	This notification name is sent just after the user switches between the Edit/Preview modes.
	The notification object is the RWDocument in which the user switched mode, while the userInfo dictionary contains one key named RWDocumentViewDidSwitchTabsUserInfoKeyMode
 */
extern NSString *const RWDocumentViewDidSwitchTabs;
	extern NSString *const RWDocumentViewDidSwitchTabsUserInfoKeyMode; // @(RWDocumentViewTab)

typedef NS_ENUM(NSUInteger, RWDocumentViewTab) {
	RWDocumentViewTabEdit = 0,
	RWDocumentViewTabPreview = 1,
	RWDocumentViewTabSource = 2,
};

/// This method will be called when your plugin has been selected by the user in the page list.
/** You can use this method to prepare the plugin to be displayed to the user.  For example, if you need to load any data off disk before the plugin's UI can be displayed properly, you can do it here.  Note that this method is _not_ called before the start of an export or publish. */
- (void)pluginWasSelected;

/// This method will be called when your plugin has been unselected (because the user has selected another page in the page list).
/** You can use this method to page out any in-memory data to disk, to keep RapidWeaver's memory usage small.  For example, the Styled Text plugin will save the data for the main text view out to disk and release all the memory used by the text (which may be hundreds of megabytes, in the case of very large documents). */
- (void)pluginWasDeselected;

//// Theme-Specific Options

// This method should return the stored value for a given theme-specific option key. See below for further information on these values and their use.
- (id)valueForThemeSpecificOptionKey:(NSString *)key;

// This method is called by RapidWeaver if your plugin has any theme-specific options available. These options are for customizing your plugin's output content-wise from theme to theme. For example, if you made a photo album plugin, this concept makes it possible for different themes to use custom picture frame graphics for the same plugin. The custom picture frame graphic would be specified in the theme's file format, where it might acknowledge certain plugins and specify options for them. If you have theme options, and your plugin does not get any input from the theme on how it should look, you should have defaults ready for use.
- (void)setValue:(id)value forThemeSpecificOptionKey:(NSString *)key;

@end

/*!
	\brief
	Root protocol for RapidWeaver 6
 */
@protocol RWPlugin <NSObject, RWPluginMetadata, RWPluginExport, RWPluginSettings, RWPluginArchiving, RWPluginEditing>

// This method is called when the plugin is loaded, and the plugin's bundle is passed as an argument. If initialization fails, return NO, and if it goes alright, return YES.
+ (BOOL)initializeClass:(NSBundle *)theBundle;

@end

/*!
	\brief
	You may call this function to gain access to the RapidWeaver document that contains your plugin.
	Pass your own plugin instance (i.e. self) as the parameter to this function.
	
	This function is marked as a weak import so that you may
	continue to develop plugins that are backward-compatible with RapidWeaver
	3.x: if you are doing that, be sure to check for the existence of this
	function (via "if(RWDocumentForPlugin == NULL)" before calling it in your
	code.  (If you are developing >=4.0 only plugins, please continue, nothing
	to see here.)
	
	If you call this function in one of your plugin's initialisers, realise
	that the document may not be finished loading yet, so don't be surprised if
	some document property or method returns nil (or worse...)
  */
extern NSDocument <RWDocument> *RWDocumentForPlugin(id <RWPlugin> plugin) WEAK_IMPORT_ATTRIBUTE;

/*!
	\brief
	You may call this function to gain access to the RapidWeaver page that contains your plugin.
	Pass your own plugin instance (i.e. self) as the parameter to this
	function.  Note that this function will return you the page that hosts
	your plugin, not the currently selected page.
	
	This function is marked as a weak import so that you may
	continue to develop plugins that are backward-compatible with RapidWeaver
	3.x: if you are doing that, be sure to check for the existence of this
	function (via "if(RWPageForPlugin == NULL)" before calling it in your
	code.  (If you are developing >=4.0 only plugins, please continue, nothing
	to see here.)
	
	If you call this function in one of your plugin's initialisers, realise
	that the page may not be finished loading yet, so don't be surprised if
	some page property or method returns nil (or worse...)
 */
extern NSObject <RWPage> *RWPageForPlugin(id <RWPlugin> plugin) WEAK_IMPORT_ATTRIBUTE;

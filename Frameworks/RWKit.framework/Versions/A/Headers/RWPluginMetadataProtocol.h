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

/*!
    \brief
    These methods will be removed and the data will be loaded from a file inside the plug-in bundle which RapidWeaver will read instead of loading the bundle
 */
@protocol RWPluginMetadata <NSObject>

/// Returns a localised name of the plugin.
/** The localised name will be displayed in RapidWeaver's plugin listing.  For
 * example, you may return "Photo Album" in English, or "Album de photos" for
 * French. */
+ (NSString * _Nonnull)pluginName;

/// Returns the author of the plugin.
/** For example: "Realmac Software Ltd". */
+ (NSString * _Nonnull)pluginAuthor;

/// Returns a resolution-independent icon of the plugin, which will used in RapidWeaver's page list.  The icon will usually be displayed at a size of 128x128 pixels.
+ (NSImage * _Nonnull)pluginIcon;

/// Returns a localised description of the plugin, to be displayed to the user.
/** For example: "The Photo Album plugin enables you to publish your iPhoto
 * galleries and other images from your local hard disk to the Web." */
+ (NSString * _Nonnull)pluginDescription;

// This should return YES if you provide an HTML description for your plugin (rather than an NSString*)
+ (BOOL)hasHTMLDescription;

@optional

// Return YES if this page should be initially hidden from the site menu's when created
+ (BOOL)initiallyHiddenFromNavigation;

// Return a specific file extension if your plugin requires it
- (NSString * _Nonnull)overrideFileExtension;

@end

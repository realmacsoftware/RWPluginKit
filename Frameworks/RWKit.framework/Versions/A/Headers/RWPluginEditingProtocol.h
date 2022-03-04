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
@import Cocoa;

@protocol RWPluginEditing <NSObject>

@optional

/*!
    \brief
    Return result is not retained by RW
    This should return the view to be shown inside RapidWeaver for editing the attributes and content associated with your plugin. For example, for a blog plugin, this would be a view showing a table view of blog entries and text views for editing each entry.
 */
- (NSView * _Nonnull)userInteractionAndEditingView;

/*!
    \bief
    Return result is not retained by RW
    This should return the view that will appear in the Page Inspector's Page Settings tab
 */
- (NSView * _Nullable)optionsAndConfigurationView;

/*!
    \brief
    This notification name is sent just after the user switches between the Edit/Preview modes.
    The notification object is the RWDocument in which the user switched mode, while the userInfo dictionary contains one key named RWDocumentViewDidSwitchTabsUserInfoKeyMode
 */
extern NSString * _Nonnull const RWDocumentViewDidSwitchTabs;
extern NSString * _Nonnull const RWDocumentViewDidSwitchTabsUserInfoKeyMode;

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

@end

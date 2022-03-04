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

#import <RWKit/RWPluginArchivingProtocol.h>
#import <RWKit/RWPluginEditingProtocol.h>
#import <RWKit/RWPluginExportProtocol.h>
#import <RWKit/RWPluginMetadataProtocol.h>
#import <RWKit/RWSharedPluginDataProtocol.h>

@protocol RWPageProtocol;


@protocol RWPluginProtocol <NSObject, RWPluginArchiving, RWPluginEditing, RWPluginExport, RWPluginMetadata, RWSharedPluginData>

// Called when the plugin is loaded, passing the plugin's bundle as an argument. Return a BOOL indicating if initialization was successful.
+ (BOOL)initializeClass:(NSBundle * _Nonnull)bundle;

- (instancetype _Nonnull)init;

/// Return YES if a new page can be created. The currentPages parameter contains all existing pages in this project using this plugin.
+ (BOOL)canCreateNewPage:(NSError * _Nullable * _Nullable)errorRef currentPages:(NSArray <RWPageProtocol> * _Nonnull)currentPages;

/// Defaults to YES. Return No if only 1 page is allowed per project
/// Availability: RW9+
+ (BOOL)allowsMultiplePages;


+ (void)willMigrateAddonLocation;

/// Return YES if export is allowed for the mode
- (BOOL)canPerformExportForMode:(NSString * _Nonnull)mode errorMessage:(NSString * _Nullable * _Nullable)errorMessage;

/// Notify RW that this plugin's content has changed
- (void)broadcastPluginChanged;

@optional

/// Return a preferred folder name used when creating pages, defaults to 'page'
- (NSString * _Nullable)defaultFolderName;

@end

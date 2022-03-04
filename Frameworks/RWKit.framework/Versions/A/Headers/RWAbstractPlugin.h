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

#import <RWKit/RWPluginProtocol.h>

@protocol RWDocumentProtocol;
@protocol RWPageProtocol;

@interface RWAbstractPlugin : NSObject <RWPluginProtocol, NSCoding>

@property (nonatomic, readonly) id <RWDocumentProtocol> document;
@property (nonatomic, readonly) id <RWPageProtocol> page;

- (NSString *)uniqueID;

/// Returns an array of <RWPageProtocol> instances using this plugin
- (NSArray <RWPageProtocol> *)allPagesUsingPlugin;

#pragma mark URLs

/// Returns the url to the addons directory
+ (NSURL *)rwAddonsLocation;

#pragma mark Temporary Data

/// Returns the full path to a temporary directory ending with the provided name. Useful for storing any temporary files your plugin needs to generate. The directory is automatically cleared the next time RapidWeaver is launched
- (NSString *)tempFilesDirectory:(NSString *)name;


#pragma mark Plugin Defaults

/// Allows you to store a dictionary into RapidWeaver's group container to persist global settings.
/// Availability: RW8
- (void)setPluginDefaults:(NSDictionary *)defaults;

/// Allows you to retrieve a dictionary from RapidWeaver's group container containing global settings.
/// Availability: RW8
- (NSMutableDictionary *)pluginDefaults;


#pragma mark Markdown Support

/// Returns HTML for the given markdown string
/// Availability: RW9+
+ (NSString *)htmlForMarkdownString:(NSString *)markdownString;

/// Returns
/// Availability: RW9+
+ (NSDictionary *)metadataForMarkdownString:(NSString *)markdownString;


#pragma mark Relaunch

/// Request that RapidWeaver should relaunch. Useful after installing updates or changing settings that could affect the entire project.
/// Availability: RW9+
- (void)requestApplicationRelaunchWithReason:(NSString *)reason;


#pragma mark Deprecations

/// Returns an array of dictionaries [{name:identifier}, ...] describing all site resources.
- (NSArray <NSDictionary *> *)resourceInfoList DEPRECATED_MSG_ATTRIBUTE("This method is deprecated and will be removed. Use self.document.rootResource");

/// Returns a URL string that takes into account the user's current link setting as specified in the preferences.
/// Passing nil will result in an empty string being returned.
/// Note: Results are only valid if called during export!
- (NSString *)linkForResourceWithIdentifier:(NSString *)identifier DEPRECATED_MSG_ATTRIBUTE("Use methods defined on RWResourceProtocol");

@end

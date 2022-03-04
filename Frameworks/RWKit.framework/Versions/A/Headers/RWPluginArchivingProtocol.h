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

#import <RWKit/RMSandwich.h>

@protocol RWPluginArchiving <NSObject>

@optional

/// Return a fully qualified domain name to be used for idenitifying the plugin during project load/save
+ (NSString * _Nonnull)pluginIdentifier;

/// Creates a new plugin instance with the given sandwich.
+ (id _Nullable)createWithSandwich:(RMSandwich * _Nonnull)sandwich;

/// Returns a sandwich that will be saved to disk, as part of the user's RapidWeaver document.
- (RMSandwich * _Nullable)sandwich;

 @optional

/*!
    \brief
    Invoked on the main thread after `document` returns non nil
 */
- (void)documentWasLoaded;

@end

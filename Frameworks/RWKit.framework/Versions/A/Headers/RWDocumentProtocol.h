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

@protocol RWPageProtocol;
@protocol RWResourceProtocol;

/// This is the public API for a RapidWeaver document
@protocol RWDocumentProtocol

/// Controls the visibility of the page inspector
@property (nonatomic, getter=isPluginInspectorVisible) BOOL pluginInspectorVisible;

/// Returns the window for the document
@property (nonatomic, readonly) NSWindow * _Nullable window;

/// Returns the undo manager for the document
@property (nonatomic, readonly) NSUndoManager * _Nullable undoManager;

/// Returns the current link style for the document
@property (nonatomic, readonly) RWKitLinkStyle linkStyle;

/// Returns the top level pages in the document
@property (nonatomic, readonly) NSArray <id <RWPageProtocol>> * _Nonnull topLevelPages;

/// Returns every page in the document
@property (nonatomic, readonly) NSArray <id <RWPageProtocol>> * _Nonnull allPages;

/// Returns the index page
@property (nonatomic, readonly) id <RWPageProtocol> _Nullable indexPage;

/// Retrieve a page with the specified unique Id, may return nil
- (id <RWPageProtocol> _Nullable)pageWithUniqueId:(NSString * _Nonnull)uniqueId;

/// Returns the root resource folder containing all other site resources
@property (nonatomic, readonly) id <RWResourceProtocol> _Nonnull rootResource;

/// Returns the resource for the given identifier if it exists
- (id <RWResourceProtocol> _Nullable)resourceWithIdentifier:(NSString * _Nonnull)identifier;

/// Show the resource browser
- (void)showResourceBrowser;

@end




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

@protocol RWDocumentProtocol;

/// Public API for a RapidWeaver page
@protocol RWPageProtocol

/// Returns YES if links to this page open in a new window
@property (nonatomic, readonly) BOOL linkOpensInNewWindow;

/// Returns the document this page belongs to
@property (nonatomic, readonly) id <RWDocumentProtocol> _Nullable document;

/// Returns an NSString that is used as a unique identifier for this page
@property (nonatomic, readonly) NSString * _Nonnull uniqueID;

/// Returns the page title as specified in the page inspector
@property (nonatomic, readonly) NSString * _Nonnull title;

/// Returns YES if this page will be exported during a publish. Specified via 'draft' checkbox in the page inspector
@property (nonatomic, readonly) BOOL enabled;

/// Returns YES if this page is hidden from the navigation bar
@property (nonatomic, readonly) BOOL hidden;

/// Returns YES if this page references a page not contiained within this document
@property (nonatomic, readonly) BOOL isExternalPage;

/// Returns the URL to an external page if there is one
@property (nonatomic, readonly) NSURL * _Nullable externalPageURL;

/// Returns the path depth of this page when published
@property (nonatomic, readonly) NSInteger pageHierarchyDepth;

/// Returns an array of direct descendent pages
@property (nonatomic, readonly) NSArray <id <RWPageProtocol>> * _Nonnull childPages;

/// Returns a link to pointing to the given page, applying a depth correction if necessary
- (NSString * _Nullable)generateLinkToPage:(id <RWPageProtocol> _Nonnull)page depthCorrection:(NSInteger)depthCorrection;

/// Mark this page's content as changed so it's exported during the next publish. Handy for plugins like the Offsite Page that can use a redirect page.
- (void)markAsChanged;

@end


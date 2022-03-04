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

@protocol RWSearchResultProtocol;

/// An object conforming to this protocol will be passed to your plugin when the user performs a project wide search
@protocol RWSearchContextProtocol

/// Check periodically, will be YES if user cancelled the search
@property (nonatomic, readonly) BOOL searchCancelled;

/// Directly append a search result to the list
- (void)appendResult:(id <RWSearchResultProtocol> _Nonnull)searchResult;

/// Ask the context to search a block of text and automatically add results
- (void)searchString:(NSString * _Nonnull)string;

/// Ask the context to search a block of text and automatically add results, assigning userInfo - useful when navigating to a search result
- (void)searchString:(NSString * _Nonnull)string userInfo:(id _Nullable)userInfo;

/// Notify RapidWeaver that search has completed
- (void)finalizeSearch;

@end

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

@protocol RWSearchContextProtocol;
@protocol RWSearchResultProtocol;

/// You plugin should implement this protocol to support project wide search
@protocol RWPluginSearchProtocol

@required

/// Called when a user searches their entire project for a string. Add a result for each occurrence via the context
/// You must call the finalizeSearch on the context when you've finished searching your plugin
/// Threading: background
- (void)searchForString:(NSString * _Nonnull)searchString context:(id <RWSearchContextProtocol> _Nonnull)context;

/// Called when a user selects your search result in the search window. Allows you to direct the user to the instance that they selected.
/// Threading: main thread
- (void)navigateToSearchResult:(id <RWSearchResultProtocol> _Nonnull)result;

@end

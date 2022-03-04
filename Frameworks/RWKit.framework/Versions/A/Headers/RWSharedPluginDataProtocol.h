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

@protocol RWDocumentProtocol;

@protocol RWSharedPluginData

@required

/// Load the passed in sandwich for the specified document. This will be called on document load if the plugin has stored shared plugin data
+ (void)loadSharedPluginDataSandwich:(RMSandwich * _Nonnull)sandwich forDocument:(id <RWDocumentProtocol> _Nonnull)document;

/// Return a sandwich containing shared data to be stored in the specified document.
+ (RMSandwich * _Nullable)sharedPluginSandwichForDocument:(id <RWDocumentProtocol> _Nonnull)document;

/// Clear any shared data for the specified document
+ (void)clearSharedPluginDataForDocument:(id <RWDocumentProtocol> _Nonnull)document;

@end

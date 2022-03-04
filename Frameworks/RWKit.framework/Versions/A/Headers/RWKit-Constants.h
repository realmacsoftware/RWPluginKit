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

extern NSString *const RWKitBundleIdentifier;

#pragma mark - Links

typedef NS_ENUM(NSInteger, RWKitLinkStyle) {
    /// Links are relative to the current page
    RWKitLinkStyleRelative,
    
    /// Links include the full path from the site root
    RWKitLinkStyleAbsolutePath,
    
    /// Links are fully qualified and include the site domain name
    RWKitLinkStyleAbsolute,
};

#pragma mark - Export

typedef NS_ENUM(NSInteger, RWExportMode) {
    RWExportModePublish = 1,
    RWExportModePreview = 2,
    RWExportModeSearch = 7
};

#pragma mark - Document Resources

/// Identifier of resource placed on the pasteboard. Use document API to retrieve the resource
extern NSString * const RWSiteResourceIdentifierType;

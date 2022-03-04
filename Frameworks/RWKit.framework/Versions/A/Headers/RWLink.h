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

enum {
	kRWLinkNotAnAsset = 0,
	kRWLinkPageAsset = 1,
	kRWLinkSiteAsset = 2
};

__attribute__((objc_subclassing_restricted))
@interface RWLink : NSObject <NSCoding, NSCopying>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *subpageID;
@property (nonatomic, strong) NSString *anchor;

@property (nonatomic, strong) NSMutableDictionary <NSString *, NSString *> *attributes;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *rel;
@property (nonatomic, strong) NSString *href;
@property (nonatomic, strong) NSString *target;

@property (nonatomic) BOOL internal;
@property (nonatomic) BOOL opensNewWindow;
@property (nonatomic) NSInteger asset;

- (id)initWithHREF:(NSString *)link internal:(BOOL)internal;

@end

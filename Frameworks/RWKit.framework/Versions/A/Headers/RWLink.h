//
//  RWLink.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 20/02/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Foundation/Foundation.h>

enum {
	kRWLinkNotAnAsset = 0,
	kRWLinkPageAsset = 1,
	kRWLinkSiteAsset = 2
};

@interface RWLink : NSObject <NSCoding, NSCopying>
{
	NSString *_name;
	NSString *_subpageID;
	NSString *_anchor;
	
	NSMutableDictionary *_attributes;
	
	BOOL _internal;
	NSInteger _asset;
}

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *subpageID;
@property (nonatomic, copy) NSString *anchor;

@property (nonatomic, retain) NSMutableDictionary *attributes;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *rel;
@property (nonatomic, copy) NSString *href;
@property (nonatomic, copy) NSString *target;

@property BOOL internal;
@property BOOL opensNewWindow;
@property NSInteger asset;

- (id)initWithHREF:(NSString *)link internal:(BOOL)internal;

/// The -setHREF: method is for backwards compatibility only (you should be using -setHref: instead)
- (void)setHREF:(NSString *)href;

@end

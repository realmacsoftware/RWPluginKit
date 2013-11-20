//
//  RWPageTree.h
//  RapidWeaver
//
//  Created by Simon Taylor on 05/02/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWPage;

@interface RWPageTree : NSObject

extern NSString *const RWPageTreePagesKey;

@property (nonatomic, retain) NSArray *pages;

- (void)addPage:(RWPage *)page after:(RWPage *)sibling;
- (void)removePage:(RWPage *)page andChildren:(BOOL)removeChildren;
- (void)replacePage:(RWPage *)page withPage:(RWPage *)replacementPage;
- (void)reparent:(RWPage *)page parent:(RWPage *)parent;

- (void)setChildIndex:(RWPage *)child index:(NSUInteger)index;

@property (nonatomic, retain) RWPage *index;

extern NSString *const RWPageTreeAllPagesKey;
/*!
	\brief
	Full depth aggregation of all pages
	
	\details
	Observation is only triggered for mutations made via this object, not direct manipulations of the pages
 */
@property (nonatomic, readonly) NSArray *allPages;

@property (nonatomic, readonly) NSMenu *pageMenu;

@end

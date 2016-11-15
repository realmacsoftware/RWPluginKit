//***************************************************************************

// Copyright (C) 2009 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//  Created by Kevin LaCoste on 09-10-18.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RWKit/RWSourceList.h"

@interface RWSourceListNode : NSObject <NSCoding, RWSourceList>

+ (instancetype)node;

- (id)init;
- (id)initWithRepresentedObject:(id)anObject;

@property (weak, nonatomic, readonly) NSString *name; // comes from the represented object
@property (nonatomic, strong) id representedObject;
@property (nonatomic, weak) RWSourceListNode *parent;
@property (nonatomic, strong) NSMutableArray *children; // shouldn't be exposing this
@property (weak, nonatomic, readonly) NSString *path; // all enclosing nodes to the root of the tree

- (void)addChild:(RWSourceListNode *)aChild;
- (void)insertChild:(RWSourceListNode *)aChild atIndex:(NSUInteger)anIndex;
- (void)removeChild:(RWSourceListNode *)aChild;

- (NSArray *)allChildren;

@end

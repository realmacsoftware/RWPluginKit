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

@class RWSiteFolder;
@class RWSiteResource;

extern NSString *const RWSiteFolderDidChangeNotification;

@interface RWSiteFolder : NSObject

@property (nonatomic, weak) RWSiteFolder *parent;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, readonly) NSArray *children;
@property (nonatomic, readonly) NSArray *items;
@property (nonatomic, readonly) NSString *path; // returns the path of this node in the tree

@property (nonatomic, readonly) NSArray *allChildFolders;

- (id)initWithName:(NSString *)name;

#pragma mark - Items Array Getters

- (NSUInteger)countOfItems;
- (id)objectInItemsAtIndex:(NSUInteger)index;
- (void)getItems:(id __unsafe_unretained *)buffer range:(NSRange)inRange;

#pragma mark - Items Array Mutators

- (void)insertItems:(NSArray *)array atIndexes:(NSIndexSet *)indexes;
- (void)removeItemsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceItemsAtIndexes:(NSIndexSet *)indexes withItems:(NSArray *)array;

- (void)insertObject:(id)object inItemsAtIndex:(NSUInteger)index;
- (void)removeObjectFromItemsAtIndex:(NSUInteger)index;
- (void)replaceObjectInItemsAtIndex:(NSUInteger)index withObject:(id)object;

- (void)addItem:(id)object;
- (void)addItems:(NSArray *)objects;

- (void)removeItem:(RWSiteResource *)resource;

#pragma mark - Children Array Getters

- (NSUInteger)countOfChildren;
- (id)objectInChildrenAtIndex:(NSUInteger)index;
- (void)getChildren:(id __unsafe_unretained *)buffer range:(NSRange)inRange;

#pragma mark - Children Array Mutators

- (void)insertChildren:(NSArray *)array atIndexes:(NSIndexSet *)indexes;
- (void)removeChildrenAtIndexes:(NSIndexSet *)indexes;
- (void)replaceChildrenAtIndexes:(NSIndexSet *)indexes withChildren:(NSArray *)array;

- (void)insertObject:(id)object inChildrenAtIndex:(NSUInteger)index;
- (void)removeObjectFromChildrenAtIndex:(NSUInteger)index;
- (void)replaceObjectInChildrenAtIndex:(NSUInteger)index withObject:(id)object;

- (void)addChild:(id)object;

- (void)removeFromParent;
- (void)removeChild:(RWSiteFolder *)childFolder;

#pragma mark - Methods

- (RWSiteResource *)resourceWithIdentifier:(NSString *)identifier;
- (NSArray <RWSiteResource *> *)allResources;

- (void)markAllResourcesAsChanged:(BOOL)changed;

@end

//
//  RWResourceDatabase.h
//  RapidWeaver
//
//  Created by Kevin LaCoste on 10-03-08.
//  Copyright 2010 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RWSiteResource;
@class RWSourceListNode;

@interface RWResourceDatabase : NSObject <NSCoding>

@property (weak, readonly, nonatomic) NSSet *resources;

@property (weak, readonly, nonatomic) NSDictionary *identifierMap;
@property (weak, readonly, nonatomic) NSDictionary *nodeMap;
@property (weak, readonly, nonatomic) NSDictionary *pageMap;

- (void)addResource:(RWSiteResource *)resource node:(RWSourceListNode *)node;
- (void)removeResources:(NSSet *)resources;

@end

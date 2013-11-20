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

@property (readonly, nonatomic) NSSet *resources;

@property (readonly, nonatomic) NSDictionary *identifierMap;
@property (readonly, nonatomic) NSDictionary *nodeMap;
@property (readonly, nonatomic) NSDictionary *pageMap;

- (void)addResource:(RWSiteResource *)resource node:(RWSourceListNode *)node;
- (void)removeResources:(NSSet *)resources;

@end

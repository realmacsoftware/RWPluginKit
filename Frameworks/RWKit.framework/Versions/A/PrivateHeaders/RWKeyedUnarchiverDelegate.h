//
//  RWKeyedUnarchiverDelegate.h
//  RapidWeaver
//
//  Created by Kevin LaCoste on 2013-04-08.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RWKeyedUnarchiverDelegate : NSObject <NSKeyedUnarchiverDelegate>

/// Returns a set with the names of any missing plugin classes encountered during the load.
@property (nonatomic, readonly, retain) NSMutableSet *missing;

@end

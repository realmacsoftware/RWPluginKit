//
//  NSFileManager+RWKit.h
//  RWKit
//
//  Created by Tom Bradley on 09/03/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (RWKit)

// Check if rw6 addons can be found
+ (BOOL)rw6AddonsExist;

// Check if rw7 addons can be found
+ (BOOL)rw7AddonsExist;

// Check if rw8 addons can be found
+ (BOOL)rw8AddonsExist;

// YES if previous version addons have found in a managed location
+ (BOOL)addonsRequireMigration;

@end

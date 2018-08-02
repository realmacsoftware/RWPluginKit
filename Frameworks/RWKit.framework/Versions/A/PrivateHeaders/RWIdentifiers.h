//
//  RWIdentifiers.h
//  RWKit
//
//  Created by Tom Bradley on 09/03/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RWIdentifiers : NSObject

#pragma mark - Application Groups

+ (NSString *)rwGroupIdentifier;
+ (NSString *)rw7GroupIdentifier;
+ (NSString *)rw8GroupIdentifier;

#pragma mark - Bundle Identifiers

+ (NSString *)rw7BundleIdentifier;
+ (NSString *)rw8BundleIdentifier;

@end

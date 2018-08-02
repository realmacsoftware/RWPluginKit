//
//  RWAppSettings.h
//  RWKit
//
//  Created by Tom Bradley on 02/08/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RWAppSettings : NSObject

+ (RWAppSettings *)sharedAppSettings;

- (id)valueForKey:(NSString *)key;
- (void)setValue:(id)value forKey:(NSString *)key;

@end

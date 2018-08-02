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

// Retrieve a value for the specified key from User Defaults.
// Using this method is preferable over [NSUserDefaults standardUserDefaults] as it also searches old versions of RapidWeaver
- (id)valueForKey:(NSString *)key;

// Please migrate to an application group container to store your preferences.
// You'll need to add an App Group in your entitlements file. Then you can access preferences using the following code.
// The advantage of this approach is that you're free to change your bundle id while retaining access to your preferences. Also, the
// same preferences easily are accessable from different versions of RapidWeaver.

// Set a value
/*
NSUserDefaults *appGroupDefaults = [[NSUserDefaults alloc] initWithSuiteName:@"[DEVELOPERID].com.domain.appgroupname"];
[appGroupDefaults setValue:@"myValue" forKey:@"myKey"];
[appGroupDefaults synchronize];
*/

// Get a value
/*
[appGroupDefaults valueForKey:@"myKey"];
*/

@end

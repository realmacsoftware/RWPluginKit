//
//  RWStorageVolume.h
//  RWKit
//
//  Created by Tom Bradley on 02/11/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const RWStorageVolumesDidChangeNotification;

@class RWStorageVolume;

NS_ASSUME_NONNULL_BEGIN

@interface RWStorageVolumes : NSObject

+ (instancetype)sharedStorageVolumes;

- (RWStorageVolume *)volumeForURL:(NSURL *)url;
- (RWStorageVolume *)volumeWithName:(NSString *)volumeName;

@end

NS_ASSUME_NONNULL_END

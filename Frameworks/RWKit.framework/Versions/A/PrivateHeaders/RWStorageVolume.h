//
//  RWStorageVolume.h
//  RWKit
//
//  Created by Tom Bradley on 02/11/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RWStorageVolume : NSObject

// Last error that occurred
@property (nonatomic, readonly) NSError *error;

// Name of the volume
@property (nonatomic, readonly) NSString *name;

// URL where the volume is mounted
@property (nonatomic, readonly) NSURL *volumeURL;

// Is the volume external, i.e. not an internal, non ejectable drive
@property (nonatomic, readonly) BOOL external;

// Is this volume currently accessible
@property (nonatomic, readonly) BOOL available;

+ (RWStorageVolume *)volumeForURL:(NSURL *)url;
+ (RWStorageVolume *)volumeWithName:(NSString *)volumeName;

- (void)updateVolumeAvailablility;

@end

NS_ASSUME_NONNULL_END

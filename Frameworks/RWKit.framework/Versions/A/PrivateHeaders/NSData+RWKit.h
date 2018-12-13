//
//  NSData+RWKit.h
//  RapidWeaver
//
//  Created by Tom Bradley on 09/11/2018.
//  Copyright © 2018 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RWStorageVolume;

NS_ASSUME_NONNULL_BEGIN

@interface NSData (RWKit)

// Returns one of the following
// - URL with security
// - URL without security (bookmark invalid)
// - nil (bookmark invalid or volume missing)
- (NSURL *)decodedURLWithError:(NSError **)error;
- (NSURL *)decodedURLWithError:(NSError **)error documentURL:(nullable NSURL *)documentURL;

// Returns volume information for this bookmark if it's resolvable
- (RWStorageVolume *)bookmarkVolumeInformation;
- (RWStorageVolume *)bookmarkVolumeInformationForDocumentURL:(nullable NSURL *)documentURL;

@end

NS_ASSUME_NONNULL_END

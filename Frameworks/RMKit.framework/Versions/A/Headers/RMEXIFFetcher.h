//
//  RMEXIFFetcher.h
//  RMKit
//
//  Created by Kevin LaCoste on 2013-02-23.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RMEXIFFetcher : NSObject

// Use ImageIO to grab the EXIF attributes of the image at the provided path.

+ (NSDictionary *)EXIFAttributesForImageAtPath:(NSString *)path;

@end

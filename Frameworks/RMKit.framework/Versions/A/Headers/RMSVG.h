//
//  RMSVG.h
//  RMKit
//
//  Created by Simon Maddox on 09/03/2017.
//  Copyright © 2017 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RMSVG : NSObject

+ (NSImage *)imageFromSVGString:(NSString *)SVGString;
+ (NSImage *)imageFromSVGStringData:(NSData *)SVGStringData;
+ (NSImage *)imageFromFilePath:(NSString *)filePath;
+ (NSImage *)imageFromURL:(NSURL *)fileURL;

+ (NSImage *)imageFromSVGString:(NSString *)SVGString size:(NSSize)size;
+ (NSImage *)imageFromSVGStringData:(NSData *)SVGStringData size:(NSSize)size;
+ (NSImage *)imageFromFilePath:(NSString *)filePath size:(NSSize)size;
+ (NSImage *)imageFromURL:(NSURL *)fileURL size:(NSSize)size;

@end

//
//  RWPageEncodings.h
//  RapidWeaver
//
//  Created by Simon Taylor on 19/02/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface RWPageEncodings : NSObject

+ (NSArray*)availableEncodingDisplayStrings;
+ (NSString*)displayStringForCharset:(NSString*)charset;
+ (NSString*)charsetForDisplayString:(NSString*)display;
+ (NSString*)supportedCharset:(NSString*)charset;

@end

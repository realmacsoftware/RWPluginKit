//
//  RWPageError.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 11/05/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface RWPageError : NSObject {

}

// placeholder for content generation errors e.g. tidy warnings, photo export failures

enum {
	kRWPageError_InfoLevel = 1,
	kRWPageError_WarningLevel,
	kRWPageError_ErrorLevel
};

- (NSInteger)level;
- (NSString*)reason;

@end

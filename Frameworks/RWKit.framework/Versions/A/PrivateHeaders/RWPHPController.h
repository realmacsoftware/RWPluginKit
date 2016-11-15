//
//  RWPHPController.h
//  RapidWeaver
//
//  Created by Simon Taylor on 27/07/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

__deprecated

@interface RWPHPController : NSObject

@property (nonatomic, strong) NSData *result;
@property (nonatomic, assign) NSInteger status;

+ (RWPHPController *)create;

- (NSArray *)errors;
- (NSArray *)lineAndItemDictionaryOfErrors:(NSInteger)outputMode;
- (NSData *)pipeDataToPHP:(NSData *)inputData;

@end

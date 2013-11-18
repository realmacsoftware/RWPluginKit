//
//  NSMutableString+StyleSheet.h
//  RapidWeaver
//
//  Created by Josh Ferguson on 9/10/10.
//  Copyright 2010 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableString (RWStyleSheet) 

- (NSRange)removeStyleTag:(NSString *)cssFilename;

@end

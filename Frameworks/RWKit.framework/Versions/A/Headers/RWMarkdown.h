//
//  RWMarkdown.h
//  RapidWeaver
//
//  Created by Simon Maddox on 04/12/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RWMarkdown : NSObject

+ (instancetype) MarkdownExporter;

- (NSString *) exportMarkdownString:(NSString *)markdownString;
- (NSDictionary *) metadataForMarkdownString:(NSString *)markdownString;

@end

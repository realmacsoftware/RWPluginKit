//
//  RWSearchResult.h
//  RapidWeaver
//
//  Created by Simon Maddox on 25/01/2017.
//  Copyright © 2017 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RWPageProtocol.h"

@interface RWSearchResult : NSObject

/// Used to provide more context to a search result - you can choose to show, for example, a few words before and after the search result.
/// We'll use this in the search window, and make the search query inside the string bold
@property (nonatomic, copy) NSString *surroundingText;

/// The range of this specific result in the surrounding text. If there are multiple instances of the search query in the surrounding text,
/// this is how we know which one to highlight.
@property (nonatomic) NSRange rangeInSurroundingText;

/// Used for your reference, so you can navigate back to results if they're selected
@property (nonatomic) NSRange range;
@property (nonatomic, strong) NSDictionary *userInfo;

@end

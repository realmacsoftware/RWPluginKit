//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RWKit/RWPage.h"

#import "RMKit/RMKit.h"

@class MyDocument;

@interface RWPage (Sandwich) <RMSandwichMaking>

+ (id)createWithSandwich:(RMSandwich *)sandwich pageIndex:(NSUInteger)pageIndex document:(MyDocument *)document missingPages:(NSMutableDictionary *)missingPages;

- (RMSandwich *)sandwich;

@end

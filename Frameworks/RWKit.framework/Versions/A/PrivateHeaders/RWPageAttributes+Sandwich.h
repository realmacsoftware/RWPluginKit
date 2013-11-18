//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RWKit/RWPageAttributes.h"

@class RMSandwich;
@class RWPage;
@class RWDocument;
@class RWPageStyles;

@interface RWPageAttributes (Sandwich)

+ (id)createWithSandwich:(RMSandwich*)sandwich page:(RWPage*)page document:(RWDocument*)document;
- (RMSandwich*)sandwichWithPageStyles:(RWPageStyles*)pageStyles;

@end

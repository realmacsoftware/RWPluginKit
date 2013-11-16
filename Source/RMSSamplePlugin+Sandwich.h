//***************************************************************************

// Copyright (C) 2008 ~ 2010 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import "RMSSamplePlugin.h"

//***************************************************************************

@class RMSandwich;

//***************************************************************************

@interface RMSSamplePlugin (Sandwich)

// Note: This code is not actually included in the project. It's just here
// to demonstrate how the API is used. The sample plugin uses NSCoding
// to read/write it's data to disk.

+ (id)createWithSandwich:(RMSandwich *)sandwich;
- (RMSandwich *)sandwich;

@end

//***************************************************************************

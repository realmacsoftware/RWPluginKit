//***************************************************************************

// Copyright (C) 2009 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//  Created by Kevin LaCoste on 09-10-08.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RWSourceList.h"

@interface RWSourceListGroup : NSObject

+ (id)groupWithName:(NSString *)name object:(NSObject *)object keyPath:(NSString *)keyPath;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, readonly) NSArray *items;

@end

//***************************************************************************

// Copyright (C) 2004 ~ 2022 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

@class RMSSamplePluginOptionsViewController;
@class RMSSamplePluginContentViewController;

#import <RWKit/RWKit.h>

//***************************************************************************

@interface RMSSamplePlugin : RWAbstractPlugin

@property (nonatomic, copy) NSString *content;
@property (nonatomic, assign) BOOL emitRawContent;
@property (nonatomic, copy) NSString *fileToken;

+ (NSBundle *)bundle;

@end

//***************************************************************************

//***************************************************************************

// Copyright (C) 2006-2007 Mako Technology
// Copyright (C) 2006-2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import "RWKit/RWKit.h"

@class RWPluginPlaceholderView;

@interface RWPluginPlaceholder : RWAbstractPlugin <RWPlugin> {
 @protected
	NSData *archive;
	NSString *missingClassName;
	NSDictionary *missingClassInfo;
	RWPluginPlaceholderView *view;
	RMSandwich *sandwich;
}

@property (nonatomic, retain) NSData *archive;
@property (nonatomic, copy) NSString *missingClassName;
@property (nonatomic, retain) NSDictionary *missingClassInfo;

@end

//***************************************************************************

// Copyright (C) 2009 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

@class RWPage;

@interface RMXMLSiteMapEntry : NSObject

- (id)initWithBaseURL:(NSString *)baseURL page:(RWPage *)page exportParameters:(NSDictionary *)exportParameters;

- (NSString *)xml;

@end

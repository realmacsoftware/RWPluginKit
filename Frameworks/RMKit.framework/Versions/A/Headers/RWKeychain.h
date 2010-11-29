//***************************************************************************

// Copyright (C) 2008 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>
#import <Security/Security.h>

//***************************************************************************

@interface RWKeychain : NSObject
{
	
}

+ (OSStatus)addInternetPassword:(NSString *)password forServer:(NSString *)server andAccount:(NSString *)account protocol:(SecProtocolType)protocol;

+ (void)deleteInternetPasswordForAccount:(NSString*)account forServer:(NSString*)server protocol:(SecProtocolType)protocol;

+ (NSString*)findInternetPasswordForAccount:(NSString*)account forServer:(NSString*)server protocol:(SecProtocolType)protocol;

@end

//***************************************************************************

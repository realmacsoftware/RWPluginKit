//
//  NSURL+RWKitAdditions.h
//  RapidWeaver
//
//  Created by Keith Duncan on 23/07/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (RWKitAdditions)

/*!
	\brief
	Callers don't need to branch whether to call `rw_startAccessingSecurityScopedResource:` based on this return value, `rw_startAccessingSecurityScopedResource:` already does so
	Exposed for testing purposes
 */
- (BOOL)rw_isSecurityScopedResource;

- (BOOL)rw_startAccessingSecurityScopedResource:(NSError **)errorRef;
- (void)rw_stopAccessingSecurityScopedResource;

@end

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

#import <Foundation/Foundation.h>

@class RWBookmark;

@interface RWSiteResource : NSObject

@property (nonatomic, copy) NSString *fileToken;

- (id)initWithFileIdentifier:(NSString *)fileIdentifier name:(NSString *)name;
+ (instancetype)siteResourceWithFileIdentifier:(NSString *)fileIdentifier name:(NSString *)name;

extern NSString *const RWSiteResourceIdentifierKey;
/*!
	\brief
	Immutable, the same between launches
 */
@property (nonatomic, readonly, copy) NSString *identifier;

extern NSString *const RWSiteResourceNameKey;
/*!
	\brief
	User provided name
 */
@property (nonatomic, copy) NSString *name;

- (BOOL)validateName:(inout NSString **)nameRef error:(out NSError **)errorRef;

@property (nonatomic, copy) NSURL *publishedURL;
@property (nonatomic, strong) NSDate *publishedDate;
@property (nonatomic, strong) NSDate *timeStamp;

@property (nonatomic, copy) NSString *fullPath;

- (void)setChanged:(BOOL)changed;
- (void)setChanged:(BOOL)changed forBookmark:(RWBookmark *)bookmark;
- (BOOL)changedStatusForBookmark:(RWBookmark *)bookmark;

@end

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

@class RWSiteFolder;
@class RWBookmark;

extern NSString *const RWSiteResourceIdentifierKey;
extern NSString *const RWSiteResourceNameKey;

@interface RWSiteResource : NSObject

@property (nonatomic, weak) RWSiteFolder *parent;

@property (nonatomic, readonly) NSString *identifier;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *fileToken;

@property (nonatomic, strong) NSURL *publishedURL;
@property (nonatomic, strong) NSDate *publishedDate;
@property (nonatomic, assign) BOOL isRemoteResource;
@property (nonatomic, strong) NSDate *timeStamp;

@property (nonatomic, strong) NSString *fullPath;
@property (nonatomic, strong) NSURL *originalURL;

@property (nonatomic, readonly) NSString *path; // returns the path of this node in the tree

- (id)initWithFileIdentifier:(NSString *)fileIdentifier name:(NSString *)name;
+ (instancetype)siteResourceWithFileIdentifier:(NSString *)fileIdentifier name:(NSString *)name;

- (void)setChanged:(BOOL)changed;
- (void)setChanged:(BOOL)changed forBookmark:(RWBookmark *)bookmark;
- (BOOL)changedStatusForBookmark:(RWBookmark *)bookmark;

- (void)removeFromParent;

@end

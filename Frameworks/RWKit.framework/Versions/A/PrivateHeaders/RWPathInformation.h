//
//  RWPathInformation.h
//  RWKit
//
//  Created by Tom Bradley on 01/04/2019.
//  Copyright © 2019 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RWDocument;
@class RWPage;

NS_ASSUME_NONNULL_BEGIN

@interface RWPathInformation : NSObject

@property (nonatomic, readonly) BOOL pageFound;
@property (nonatomic, readonly) RWPage *page;
@property (nonatomic, readonly) BOOL isSubPage;
@property (nonatomic, readonly) NSString *subPagePath;

@property (nonatomic, readonly) NSString *preferedFilename;
@property (nonatomic, readonly) BOOL pageChangedSinceLastPreview;
@property (nonatomic, readonly) NSString *pageFolder;

// Some files like woff or jpg are exported as part of the page. These are not individually exportable
@property (nonatomic, readonly) BOOL isExportableType;

+ (instancetype)pathInformationWithDocument:(RWDocument *)document relativePath:(NSString *)relativePath;
- (instancetype)initWithDocument:(RWDocument *)document relativePath:(NSString *)relativePath;

@end

NS_ASSUME_NONNULL_END

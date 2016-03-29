//
//  RWPluginHealthCheckProtocol.h
//  RapidWeaver
//
//  Created by Tom Bradley on 27/01/2016.
//  Copyright © 2016 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RWPluginHealthCheckProtocol <NSObject>

@optional

// Perform standard health checks on NSAttributedStrings
- (NSArray *)attributedStringsRequiringStandardHealthChecks;
- (void)showEditorForAttributedString:(id)attributedString attachment:(id)attachment;

// Perform custom health checks
- (void)performHealthCheckWithErrorReportingBlock:(void(^)(NSString *errorTitle, NSString *errorDescription, void(^repairBlock)()))errorBlock;

@end

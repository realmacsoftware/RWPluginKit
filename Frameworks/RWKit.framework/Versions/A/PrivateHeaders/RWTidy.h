//
//  RWTidy.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 21/01/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>


@interface RWTidy : NSObject {

}

extern NSString* kRWTidyTidiedDataKey;
extern NSString* kRWTidyTidiedStringKey;
extern NSString* kRWTidyDiagnosticsKey;

enum {
	kTidyInsertXMLDecl = 1
};

+ (NSDictionary*)tidy:(NSString*)html encoding:(CFStringEncoding)encoding optimise:(BOOL)optimise options:(NSInteger)options;

@end

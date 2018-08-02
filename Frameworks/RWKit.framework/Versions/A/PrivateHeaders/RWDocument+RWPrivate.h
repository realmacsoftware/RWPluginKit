//
//  RWDocument+RWPrivate.h
//  RapidWeaver
//
//  Created by Keith Duncan on 09/07/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import "RWDocument.h"

@class RWDocumentModel;
@class RWPage;

@interface RWDocument ()

@property (nonatomic, assign) BOOL watchCurrentThemeFiles;

@end

@interface RWDocument (RWPrivate)

/*!
	\brief
	Should be called before reading from a URL. Safely resets properties which are filled from disk back to their original state.
 */
- (void)_initialiseEmptyModel;

- (BOOL)validateSiteBaseURL:(NSString **)ioValue error:(NSError **)outError;

@property (readonly, nonatomic, strong) RWDocumentModel *model;

@end

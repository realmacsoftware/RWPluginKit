//
//  NSMutableAttributedString+RWKitAdditions.h
//  RapidWeaver
//
//  Created by Keith Duncan on 11/07/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableAttributedString (RWKitAdditions)

/*!
	\brief
	This method will normalise all the image attachments in the attributed string; see the description for the -normaliseImages for more information.
 */
- (NSUInteger)normaliseImageAttachments;

@end

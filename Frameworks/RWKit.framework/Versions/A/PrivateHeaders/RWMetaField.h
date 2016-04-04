//***************************************************************************

// Copyright (C) 2005-2007 Mako Technology
// Copyright (C) 2005-2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface RWMetaField : NSObject
{
	NSString *_type;	// name, http-equiv
	NSString *_name;
	NSString *_content;
	NSString *_language;
	NSString *_metaTemplate;
}

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *language;
@property (nonatomic, copy) NSString *metaTemplate;

+ (RWMetaField *)metaFieldWithDictionary:(NSDictionary *)dictionary;

// Returns the object as an NSMutableDictionary for use in plist saving.
- (id)propertyList;

// Returns the object as an NSString useful for inclusion in HTML.
- (NSString *)text;

@end

//***************************************************************************

//
//  RWPageAttributes.h
//  RapidWeaver
//
//  Created by Simon Taylor on 15/02/2005.
//  Copyright 2005 Mako Technology. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWPage;
@class RWDocument;
@class RWBookmark;

@interface RWPageAttributes : NSObject {
	NSMutableDictionary *_attributes;
	RWPage *_page;
	RWDocument *_document;
	
	BOOL _changedSinceLastPreview;
}

- (id)initWithPage:(RWPage*)page;

- (BOOL)enabled;
- (void)setEnabled:(BOOL)enabled;

- (NSString*)filename;
- (NSString*)filenameNoExt;
- (void)setFilename:(NSString*)filename;

- (NSString*)filenameExt;
- (void)setFilenameExt:(NSString*)filename;

- (NSString*)foldername;
- (void)setFoldername:(NSString*)foldername;
- (BOOL)foldernameIsAbsolute;

- (NSString*)charset;
- (CFStringEncoding)charsetEncoding;

- (NSString*)encoding;
- (void)setEncoding:(NSString*)encoding;

- (NSArray*)encodings;

- (NSString*)output;
- (void)setOutput:(NSString*)output;
- (NSArray*)outputs;
- (NSArray*)localisedOutputs;
- (NSUInteger)outputIndex;
- (void)setOutputIndex:(NSUInteger)index;

enum {
	kRWPageOutputDefault,
	kRWPageOutputTidied,
	kRWPageOutputOptimised
};
- (NSInteger)outputFromOutput:(NSString*)output;
- (BOOL)outputModeIsTidied;

- (NSArray*)headers;
- (void)setHeaders:(NSMutableArray*)headers;
- (NSString*)headersText;

- (NSString*)sidebar;
- (void)setSidebar:(NSString*)sidebar;
- (void)_setSidebar:(NSString*)sidebar;

- (NSAttributedString*)sidebarStyled;
- (void)setSidebarStyled:(NSAttributedString*)sidebar;
- (void)_setSidebarStyled:(NSAttributedString*)sidebar;

typedef NS_ENUM(NSInteger, RWPageAttributesSidebarMode) {
	RWPageAttributesSidebarModeHTML = 0,
	RWPageAttributesSidebarModeStyledText,
};
- (RWPageAttributesSidebarMode)sidebarMode;
- (void)setSidebarMode:(RWPageAttributesSidebarMode)sidebarMode;

- (NSString*)sidebarTitle;
- (void)setSidebarTitle:(NSString*)sidebarTitle;

- (BOOL)credit;
- (void)setCredit:(BOOL)credit;

- (BOOL)expires;
- (void)setExpires:(BOOL)expires;

- (NSInteger)expiryQuantity;
- (void)setExpiryQuantity:(NSInteger)quantity;

- (NSString*)expiryUnit;
- (void)setExpiryUnit:(NSString*)units;
- (NSArray*)expiryUnits;
- (NSArray*)localisedExpiryUnits;
- (NSInteger)expiryUnitInSeconds:(NSString*)unit;
- (NSUInteger)expiryUnitIndex;
- (void)setExpiryUnitIndex:(NSUInteger)index;

- (void)setChanged:(BOOL)changed;
- (void)setChanged:(BOOL)changed forBookmark:(RWBookmark *)bookmark;
- (BOOL)changedStatusForBookmark:(RWBookmark *)bookmark;

- (NSDate*)lastExported;
- (void)setLastExported:(NSDate*)date;

- (BOOL)hidden;
- (void)setHidden:(BOOL)hidden;

- (BOOL)xmlDecl;
- (void)setXmlDecl:(BOOL)xmlDecl;

- (NSString*)imageFormat;
- (void)setImageFormat:(NSString*)format;
- (NSArray*)imageFormats;
- (NSArray*)localisedImageFormats;
- (NSUInteger)imageFormatIndex;
- (void)setImageFormatIndex:(NSUInteger)index;

- (NSString*)imageQuality;
- (void)setImageQuality:(NSString*)quality;
- (NSArray*)imageQualities;
- (NSArray*)localisedImageQualities;
- (NSUInteger)imageQualityIndex;
- (void)setImageQualityIndex:(NSUInteger)index;

- (BOOL)linkOpensInNewWindow;
- (void)setLinkOpensInNewWindow:(BOOL)flag;

- (void)updatePageAttributes:(NSDictionary*)attributes;

- (NSArray*)externalPageAssets;
- (void)setExternalPageAssets:(NSArray*)assets;

- (NSMutableDictionary*)styleVariations;
- (void)setStyleVariations:(NSMutableDictionary*)variations;
- (NSMutableDictionary*)styleVariationsForMode;

- (NSMutableDictionary*)colourVariations;
- (void)setColourVariations:(NSMutableDictionary*)variations;
- (NSMutableDictionary*)colourVariationsForMode;

enum {
	kRWPageStyleVariationsPageMode = 0,
	kRWPageStyleVariationsSiteMode
};
- (NSInteger)styleVariationsMode;
- (void)setStyleVariationsMode:(NSInteger)mode;

+ (void)setDefaultPageAttributes:(NSDictionary*)attributes;
+ (NSMutableDictionary*)defaultPageAttributes;
+ (RWPageAttributes*)defaultPageAttributesObject;

- (NSArray*)pageAttributeSelection;
- (void)setPageAttributeSelection:(NSArray*)selection;

- (NSMutableDictionary*)filterAttributes:(NSMutableDictionary*)attributes with:(NSArray*)selection;

- (NSString*)pagePrefix;
- (void)setPagePrefix:(NSString*)prefix;

- (NSString*)pageSuffix;
- (void)setPageSuffix:(NSString*)suffix;

+ (NSArray *)localisedStringArray:(NSArray *)arrayToLocalise;
+ (NSString *)localizedCustomStyleName;

@property (assign) RWPage *page;
@property (assign) RWDocument *document;
@property (nonatomic, retain) NSMutableDictionary *attributes;

@property (assign) BOOL changedSinceLastPreview;

@end

// Notifications
/*
extern NSString* kRWPageTitleDidChangeNotification;
extern NSString* kRWPageFilenameDidChangeNotification;
extern NSString* kRWPageEncodingDidChangeNotification;
extern NSString* kRWPageOutputDidChangeNotification;
extern NSString* kRWPageHeadersDidChangeNotification;
extern NSString* kRWPageCreditDidChangeNotification;
extern NSString* kRWPageSidebarDidChangeNotification;
extern NSString* kRWPageExpiryDidChangeNotification;
extern NSString* kRWPageChangedDidChangeNotification;
extern NSString* kRWPageLastExportedDidChangeNotification;
extern NSString* kRWPageHiddenDidChangeNotification;
*/
extern NSString* kRWPageAttributeDidChangeNotification;
extern NSString* kRWPageExternalAttributeDidChangeNotification;
extern NSString* kRWPageChangedDidChangeNotification;

// Common Keys
extern NSString* kRWPageIDKey;

// Attributes
extern NSString* kRWPageChangedStatusesKey;
extern NSString* kRWPageColourVariationsKey;
extern NSString* kRWPageCreditKey;
extern NSString* kRWPageEnabledKey;
extern NSString* kRWPageEncodingKey;
extern NSString* kRWPageExpiresKey;
extern NSString* kRWPageExpiryQuantityKey;
extern NSString* kRWPageExpiryUnitKey;
extern NSString* kRWPageFilenameExtKey;
extern NSString* kRWPageFilenameKey;
extern NSString* kRWPageFoldernameKey;
extern NSString* kRWPageHeadersKey;
extern NSString* kRWPageHiddenKey;
extern NSString* kRWPageImageFormatKey;
extern NSString* kRWPageImageQualityKey;
extern NSString* kRWPageLastExportedKey;
extern NSString* kRWPageLinkTargetKey;
extern NSString* kRWPageMetaFieldsKey;
extern NSString* kRWPageOutputKey;
extern NSString* kRWPageSidebarKey;
extern NSString* kRWPageSidebarModeKey;
extern NSString* kRWPageSidebarStyledKey;
extern NSString* kRWPageSidebarTitleKey;
extern NSString* kRWPageStyleVariationsKey;
extern NSString* kRWPageStyleVariationsModeKey;
extern NSString* kRWPageXMLDeclKey;
extern NSString* kRWPagePagePrefixKey;

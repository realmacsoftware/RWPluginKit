//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>

#import <RMKit/RMKit.h>

// We don't _need_ to import this header, but if we don't, clients that only import RWStyledText.h will get very strange RMHTMLPackage class errors, so it's probably better to just import all our dependencies.
#import <RMKit/RMKit.h>
#import "RWHTMLRendering.h"

//***************************************************************************

@protocol RWPage;

//***************************************************************************

/// A class that stores either an NSAttributedString or RMHTMLPackage object, and provides a common interface to access the contents.
/** To ease RapidWeaver 4.0's transition from a attributed strings to full-blown HTML editing, we provide this RWStyledText class as a (hopefully) helpful class that abstracts away the details of exactly whether you're dealing with an attributed string or an HTML package.  While this class is somewhat useful on its own, it is intended to be used in conjunction with an RWStyledTextView, in which case it becomes far more powerful since it will automatically synchronise its contents with the RWStyledTextView. */
@interface RWStyledText : NSObject<RMFreezing, RMThawing, RMValueObject, RWHTMLRendering, RMDiscardableContent>

/// Creates a new (autoreleased) styled text instance with the given attributed string.
+ (RWStyledText*)styledTextWithAttributedString:(NSAttributedString*)attributedString;

/// Creates a new (autoreleased) styled text instance with the given HTML package.
+ (RWStyledText*)styledTextWithHTMLPackage:(RMHTMLPackage*)htmlPackage;

/// Initialises a styled text instance with the given attributed string.
- (RWStyledText*)initWithAttributedString:(NSAttributedString*)attributedString;

/// Initialises a styled text instance with the given HTML package.
- (RWStyledText*)initWithHTMLPackage:(RMHTMLPackage*)htmlPackage;

/// Returns the textual length of the receiver (i.e. without any attachments or frozzberries).
- (NSUInteger)length;

/// Returns YES if the receiver can determine in O(1) time whether it is either a zero-length NSAttributedString or RMHTMLPackage.
/** If the receiver is a zerolength NSAttributedString or RMHTMLPackage, it will still return NO if this cannot be determined in O(1) time (e.g. if the string must be paged in off disk. */
- (BOOL)isEmpty;

/// Converts the text to an HTML package.  Returns YES if the conversion was successful or if the text is already an HTML package, or NO if the conversion was unsuccessful.
/** You need to pass this method the RWPage that hosts the styled text for a correct conversion.  See the documentation for +[RWHTMLRendering renderAttributedStringToHTMLPackage:page:] for more information. */
- (BOOL)convertToHTMLPackageWithPage:(id<RWPage>)page;

/// Returns YES if the receiver is equal to the given styled text object.
- (BOOL)isEqualToStyledText:(RWStyledText*)other;

// RMFreezing protocol
- (NSString*)frozenPathExtension;
- (BOOL)freezeToPath:(NSString*)path atomically:(BOOL)saveAtomically error:(NSError**)outError;

// RMThawing protocol
+ (NSSet*)freezeThawDefaultSupportedPathExtensions;
+ (id)thawFromPath:(NSString*)path error:(NSError**)outError;

// RWHTMLRendering protocol
- (RMHTMLPackage*)renderWithPage:(id<RWPage>)page exportParameters:(RWExportParameters*)exportParameters;

// RMDiscardableContent protocol
- (BOOL)beginContentAccess __deprecated;
- (void)endContentAccess __deprecated;
- (void)discardContentIfPossible __deprecated;
- (BOOL)isContentDiscarded __deprecated;

//---------------------------------------------------------------------------

/// Returns an attributed string.  If the styled text is storing an HTML package rather than an attributed string, this will return nil.
@property (copy) NSAttributedString* attributedString;

/// Returns YES if the styled text is storing an attributed string; NO if the styled text is storing an HTML package.
@property (readonly) BOOL isAttributedString;

/// Returns an HTML package.  If the styled text is storing an attributed string rather than an HTML package, this will return nil.
@property (copy) RMHTMLPackage* htmlPackage;

/// Returns YES if the styled text is storing an HTML package; NO if the styled text is storing an attributed string.
@property (readonly) BOOL isHTMLPackage;

/// Returns the on-disk path to either the attributed string or the HTML package.
/** Note that if the receiver is storing an attributed string, the given path will be a file; if the receiver is storing an HTML package, the given path will be a directory. */
@property (copy, readonly) NSString* path;

@end

//***************************************************************************

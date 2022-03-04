//************************************************************************
//
//  RapidWeaver Plugin Development Kit
//  Copyright © 2022 Realmac Software. All rights reserved.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished proprietary information of Realmac Software Ltd
//  and are protected by copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or
//  in part, without the prior written consent of Realmac Software Ltd.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//  ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
//  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//
//************************************************************************

@import Cocoa;
#import <RWKit/RMFreezeThaw.h>

@class RWStyledText;

/// A class that stores either an NSAttributedString object, and provides an interface to access the contents.
__attribute__((objc_subclassing_restricted))
@interface RWStyledText : NSObject <RMFreezing, RMThawing>

/// Returns an attributed string.  If the styled text is storing an HTML package rather than an attributed string, this will return nil.
@property (copy) NSAttributedString *attributedString;

/// Creates a new (autoreleased) styled text instance with the given attributed string.
+ (RWStyledText *)styledTextWithAttributedString:(NSAttributedString*)attributedString;

/// Initialises a styled text instance with the given attributed string.
- (RWStyledText *)initWithAttributedString:(NSAttributedString*)attributedString;

/// Returns the textual length of the receiver (i.e. without any attachments or frozzberries).
- (NSUInteger)length;

/// Returns YES if the receiver can determine whether it is either a zero-length NSAttributedString.
- (BOOL)isEmpty;

/// Returns YES if the receiver is equal to the given styled text object.
- (BOOL)isEqualToStyledText:(RWStyledText *)other;

// RMFreezing protocol
- (NSString *)frozenPathExtension;
- (BOOL)freezeToPath:(NSString *)path atomically:(BOOL)saveAtomically error:(NSError**)outError;

// RMThawing protocol
+ (NSSet *)freezeThawDefaultSupportedPathExtensions;
+ (id)thawFromPath:(NSString *)path error:(NSError **)outError;

@end

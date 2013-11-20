//***************************************************************************

// Portions Copyright (C) 2004, Keith Anderson
// Portions Copyright (C) 2005-2008 Realmac Software Pty Ltd

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject
// to the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

//***************************************************************************

//***************************************************************************

// Copyright (C) 2005-2008 Realmac Software Pty Ltd

//***************************************************************************

#import <Cocoa/Cocoa.h>

@interface NSString (UTI)

+ (NSString *)pathExtensionForUTI:(NSString*)uniformTypeIdentifier;

@end

//***************************************************************************

@interface NSString (RWStringUtilities)
- (NSMutableString*)stripRepeatedPathSeparators;
- (NSString*)stringByRemovingSuffix:(NSString*)suffix;

// Similar to -stringByAppendingPathComponent:, but this doesn't strip double-slashes in e.g. "http://foo/bar/baz/"
- (NSString*)stringByAppendingURLPathComponent:(NSString*)aString;

/// Similar to -stringByDeletingLastPathComponent:, but this doesn't strip double-slashes in e.g. "http://foo/bar/baz/"
- (NSString*)stringByDeletingLastURLPathComponent;

- (BOOL)validWebFilename;
- (NSString*)convertToEntities;
- (NSString*)convertToNumericalReferences:(BOOL)everything;
- (NSString*)summarizeToSentences:(UInt32*)sentences;

- (NSString*)stringEscapedForXMLElementText;
- (NSString*)stringEscapedForXMLElementTextWithCharactersToLeaveUnescaped:(NSArray *)characters;

- (NSString*)stringEscapedForHTMLElementText;
- (NSString*)stringEscapedForHTMLElementTextWithCharactersToLeaveUnescaped:(NSArray *)characters;

- (NSString*)stringEscapedForHTMLAttribute;
- (NSString*)stringEscapedForHTMLAttributeWithCharactersToLeaveUnescaped:(NSArray *)characters;


- (NSString*)stringEscapedForFilename;
- (NSString*)stringEscapedForLowercaseFilename;
- (NSString*)stringEscapedForFriendlyFilename;
- (NSString*)stringEscapedForLowercaseFriendlyFilename;
- (NSString*)stringEscapedForMacFriendlyFilename;
- (NSString*)stringEscapedForInclusionInSingleQuotedPHPString;
- (NSData*)dataUsingHTMLEscapesWithCFStringEncoding:(CFStringEncoding)encoding;
- (NSData*)dataUsingHTMLEscapesWithNSStringEncoding:(NSStringEncoding)encoding;
+ (NSString*)formatStringZeroPaddedForUnsignedInteger:(NSUInteger)anInteger;
@end

@interface NSMutableString (RWStringUtilities)
- (void)appendForwardSlash;
- (NSUInteger)replaceOccurrencesOfString:(NSString *)target withString:(NSString *)replacement;
@end

@interface NSString (RWPathUtilities)
- (NSString*)resolveAliases;
- (OSStatus)pathToFSRef:(FSRef*)fsRef;
- (OSStatus)pathToFSSpec:(FSSpec*)spec;
- (NSMutableData*)aliasForPathRelativeTo:(NSString*)pathB;
@end

@interface NSString (MD5_Checksum)
- (NSData*)md5Checksum;
@end

@interface NSString (CRC_Checksum)
- (NSData*)crcChecksum;
@end

@interface NSMutableData (RWPathUtilities)
- (NSString*)resolveAliasRelativeTo:(NSString*)pathB withoutUI:(BOOL)flag;
@end

@interface NSAttributedString (Attachments)
- (NSArray*)attachments;
- (NSArray*)attachmentsForRange:(NSRange)maxRange;
- (NSUInteger)normaliseImageAttachments;
@end

//***************************************************************************

@interface RWCharacterConverter : NSObject

+ (NSString*)encodeUnicodeForHTML:(NSString*)html skipTags:(BOOL)skipTags;

@end

//***************************************************************************

@interface NSString (RWCharacterConverter)

+ (NSString*)XMLEntityStringForString:(NSString*)string;
- (NSString*)stringByReplacingXMLEntities;

@end

//***************************************************************************

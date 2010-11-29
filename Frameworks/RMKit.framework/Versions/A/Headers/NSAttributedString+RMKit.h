//***************************************************************************

#import <Cocoa/Cocoa.h>

//***************************************************************************

@interface NSAttributedString (NSStringOperations)

- (NSArray*)componentsSeparatedByString:(NSString*)separator;
- (NSAttributedString*)attributedStringWithoutOutermostTextList;

@end

//***************************************************************************

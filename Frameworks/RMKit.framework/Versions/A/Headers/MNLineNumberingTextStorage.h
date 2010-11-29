
#import <Cocoa/Cocoa.h>



extern NSString* const MarkerAttributeName;

@interface MNLineNumberingTextStorage : NSTextStorage
{
	NSMutableAttributedString *m_attributedString;
	
	
	
	
}

-(BOOL)hasBookmarkAtIndex:(NSUInteger)index inTextView:(NSTextView*)textView;
	// Check if the paragraph contains index is bookmarked.

-(void)setBookmarkAtIndex:(NSUInteger)index flag:(BOOL)flag  inTextView:(NSTextView*)textView;
	// Set bookmark to the paragraph contains index.

	// ** note **  
	// Bookmarks are added to paragraphs, not characters.
	// A bookmark is stored as an attribute 'MarkerAttributeName' embedded to return code. 


-(NSUInteger)paragraphNumberAtIndex:(NSUInteger)index;
	// return paragraph number contains index




@property (retain) NSMutableAttributedString *m_attributedString;
@end

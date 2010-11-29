#import <Cocoa/Cocoa.h>

#import "RWExportParams.h"

@interface RMHTML : NSObject {
	
	BOOL _allowWebUnsafeFonts;
	NSDictionary* _currentMarkupAttribute;
	NSString* _filesFolderName;
	NSString* _imagesFolderName;
	NSString* _assetsFolderName;
}

typedef enum RWLinkStyle
{
	RWLinkStyleRelative,
	RWLinkStyleAbsolutePath,
	RWLinkStyleAbsolute,
}
RWLinkStyle;

- (BOOL)allowWebUnsafeFonts;
- (void)setAllowWebUnsafeFonts:(BOOL)flag;

- (NSString *)exportAttributedString:(NSAttributedString *)str
							  toPath:(NSString *)path
						 imagePrefix:(NSString *)imagePrefix;

- (NSString *)exportAttributedString:(NSAttributedString *)str
							  toPath:(NSString *)path
						imagesFolder:(NSString *)imagesFolder
						 imagePrefix:(NSString *)imagePrefix
						HTMLTemplate:(NSString *)theTemplate
						  contentTag:(NSString *)contentTag;

- (NSString *)exportAttributedString:(NSAttributedString *)str
							  toPath:(NSString *)path
						imagesFolder:(NSString *)imagesFolder
						 imagePrefix:(NSString *)imagePrefix
						HTMLTemplate:(NSString *)theTemplate
						  contentTag:(NSString *)contentTag
							fromPage:(id)thePage;

- (NSString *)exportAttributedString:(NSAttributedString *)str
							  toPath:(NSString *)path
						imagesFolder:(NSString *)imagesFolder
						 imagePrefix:(NSString *)imagePrefix
						HTMLTemplate:(NSString *)theTemplate
						  contentTag:(NSString *)contentTag
							fromPage:(id)thePage
					 depthCorrection:(NSInteger)depthCorrection;

- (NSString *)exportAttributedString:(NSAttributedString *)str
							  toPath:(NSString *)path
						imagesFolder:(NSString *)imagesFolder
						 imagePrefix:(NSString *)imagePrefix
						HTMLTemplate:(NSString *)theTemplate
						  contentTag:(NSString *)contentTag
							fromPage:(id)thePage
					 depthCorrection:(NSInteger)depthCorrection
						  exportMode:(RWExportMode)exportMode;

- (NSString*)exportAttributedString:(NSAttributedString*)str
							 toPath:(NSString*)path
					   imagesFolder:(NSString*)imagesFolder
						imagePrefix:(NSString*)imagePrefix
					   HTMLTemplate:(NSString*)theTemplate
						 contentTag:(NSString*)contentTag
						   fromPage:(id)thePage
					depthCorrection:(NSInteger)depthCorrection
						 exportMode:(RWExportMode)exportMode
						  linkStyle:(RWLinkStyle)linkStyle;

- (void)processLink:(id)link 
			   page:(NSObject*)thePage
	depthCorrection:(NSInteger)depthCorrection 
			 toHTML:(NSMutableString*)html
	filesFolderName:(NSString*)filesFolderName
		  linkStyle:(RWLinkStyle)linkStyle;

- (NSString*)filesFolderName;
- (void)setFilesFolderName:(NSString*)name;
- (NSString*)imagesFolderName;
- (void)setImagesFolderName:(NSString*)name;
- (NSString*)assetsFolderName;
- (void)setAssetsFolderName:(NSString*)name;

- (BOOL)supportsConvertingToWebViewDOM;

@end

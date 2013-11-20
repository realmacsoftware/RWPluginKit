
#import <Cocoa/Cocoa.h>

#import "RWKit/RWPageProtocol.h"
#import "RWKit/RWExportParams.h"

typedef NS_ENUM(NSInteger, RWLinkStyle) {
	RWLinkStyleRelative,
	RWLinkStyleAbsolutePath,
	RWLinkStyleAbsolute,
};

@interface RMHTML : NSObject {
	BOOL _allowWebUnsafeFonts;
	
	NSDictionary *_currentMarkupAttribute;
	
	NSString *_filesFolderName;
	NSString *_imagesFolderName;
	NSString *_assetsFolderName;
	
	// The mode property is used during link processing to determine if a link needs to
	// handle depth correction (export) or top-level (preview).
	
	NSString *_mode;
}

@property (nonatomic, assign) BOOL allowWebUnsafeFonts;
@property (nonatomic, copy) NSString *assetsFolderName;
@property (nonatomic, copy) NSString *filesFolderName;
@property (nonatomic, copy) NSString *imagesFolderName;
@property (nonatomic, copy) NSString *mode;

// Returns an autoreleased RMHTML object.
// Pass the parameter dictionary as received from the host during API calls.

+ (id)HTMLExporterWithParameterDictionary:(NSDictionary *)parameters;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagePrefix:(NSString *)imagePrefix;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(NSObject <RWPage> *)thePage;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(NSObject <RWPage> *)thePage depthCorrection:(NSInteger)depthCorrection;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(NSObject <RWPage> *)thePage depthCorrection:(NSInteger)depthCorrection exportMode:(RWExportMode)exportMode;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(NSObject <RWPage> *)thePage depthCorrection:(NSInteger)depthCorrection exportMode:(RWExportMode)exportMode linkStyle:(RWLinkStyle)linkStyle;

- (void)processLink:(id)link  page:(NSObject *)thePage depthCorrection:(NSInteger)depthCorrection toHTML:(NSMutableString *)html filesFolderName:(NSString *)filesFolderName linkStyle:(RWLinkStyle)linkStyle;

- (BOOL)supportsConvertingToWebViewDOM;

@end

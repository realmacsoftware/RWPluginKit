
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

#import <RWKit/RWKit-Constants.h>

@protocol RWPageProtocol;
@protocol RWPluginPublishingParams;

__attribute__((objc_subclassing_restricted))
@interface RMHTML : NSObject

@property (nonatomic, assign) BOOL allowWebUnsafeFonts;
@property (nonatomic, copy) NSString *assetsFolderName;
@property (nonatomic, copy) NSString *filesFolderName;
@property (nonatomic, copy) NSString *imagesFolderName;

// The mode property is used during link processing to determine if a link needs to
// handle depth correction (export) or top-level (preview).
@property (nonatomic, copy) NSString *mode;

// Returns an autoreleased RMHTML object.
// Pass the parameter dictionary as received from the host during API calls.

+ (id)HTMLExporterWithParameterDictionary:(NSDictionary *)parameters;
+ (id)HTMLExporterWithPublishingParams:(id <RWPluginPublishingParams>)params;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagePrefix:(NSString *)imagePrefix;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(id <RWPageProtocol>)thePage;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(id <RWPageProtocol>)thePage depthCorrection:(NSInteger)depthCorrection;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(id <RWPageProtocol>)thePage depthCorrection:(NSInteger)depthCorrection exportMode:(RWExportMode)exportMode;

- (NSString *)exportAttributedString:(NSAttributedString *)str toPath:(NSString *)path imagesFolder:(NSString *)imagesFolder imagePrefix:(NSString *)imagePrefix HTMLTemplate:(NSString *)theTemplate contentTag:(NSString *)contentTag fromPage:(id <RWPageProtocol>)thePage depthCorrection:(NSInteger)depthCorrection exportMode:(RWExportMode)exportMode linkStyle:(RWKitLinkStyle)linkStyle;

- (void)processLink:(id)link page:(id <RWPageProtocol>)thePage depthCorrection:(NSInteger)depthCorrection toHTML:(NSMutableString *)html filesFolderName:(NSString *)filesFolderName linkStyle:(RWKitLinkStyle)linkStyle;

- (BOOL)supportsConvertingToWebViewDOM;

@end

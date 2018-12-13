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

#import "RWKit/RWPageProtocol.h"
#import "RWKit/RWExportParams.h"

/// This class provides a simple interface to render an NSAttributedString or a RapidWeaver page as HTML.
/** If you are familiar with the RMHTML class and the (undocumented and private) RWExporter class, this is essentially a public facade class to those two classes. */
@interface RWHTMLRendering : NSObject

/// Renders (exports) the attributed string as HTML to the specified directory.
/** The index filename must not be nil.  If the page parameter is nil, no links will be resolved, and images will be exported in their original file format with high quality.  The folder name for auxiliary files (images etc) and the image prefix will be randomly named. */
+ (void)renderAttributedString:(NSAttributedString *)attributedString toDirectory:(NSString *)path indexFilename:(NSString *)indexFilename page:(id <RWPage>)page exportMode:(RWExportMode)exportMode;

/// Renders (exports) the attributed string as an HTML package, and returns an HTML package.
/* If the page parameter is nil, no links will be resolved, and images will be exported in their original file format with high quality.  The folder name for auxiliary files (images etc) and the image prefix will be randomly named. */
+ (RMHTMLPackage *)renderAttributedStringToHTMLPackage:(NSAttributedString *)attributedString page:(id <RWPage>)page exportMode:(RWExportMode)exportMode;

@end

@protocol RWHTMLRendering <NSObject>

/// Renders (exports) the receiver as an HTML package.
/* If the page parameter is nil, no links will be resolved, and images will be exported in their original file format with high quality.  The folder name for auxiliary files (images etc) and the image prefix will be randomly named. */
- (RMHTMLPackage*)renderWithPage:(id<RWPage>)page exportParameters:(RWExportParameters*)exportParameters;

@end

@interface NSAttributedString (RWHTMLRenderingSupport) <RWHTMLRendering>

@end

@interface RMHTMLPackage (RWHTMLRenderingSupport) <RWHTMLRendering>

@end

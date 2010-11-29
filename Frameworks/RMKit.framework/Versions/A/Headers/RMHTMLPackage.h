//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
// 
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

#import <Cocoa/Cocoa.h>

#import "RMFreezeThaw.h"
#import "RMValueObject.h"

#import <WebKit/WebKit.h>

//***************************************************************************

@class RMFilesystemObject;
@class RMUUID;
@class WebDataSource;

//***************************************************************************

@interface RMHTMLPackage : NSObject<RMFreezing, RMThawing, RMValueObject>
{
	RMFilesystemObject* _resourcesDirectory;
	RMUUID* _UUID;
}

+ (RMHTMLPackage*)HTMLPackageWithHTMLDirectoryAtPath:(NSString*)path;
+ (RMHTMLPackage*)HTMLPackageWithWebFrame:(WebFrame*)webFrame;
+ (RMHTMLPackage*)emptyHTMLPackage;

- (RMHTMLPackage*)initWithHTMLDirectoryAtPath:(NSString*)path;
- (RMHTMLPackage*)initWithWebFrame:(WebFrame*)webFrame;
- (RMHTMLPackage*)initWithFilesystemObject:(RMFilesystemObject*)filesystemObject;

- (NSString*)HTMLForMainResource;
- (NSData*)dataForResourceAtPath:(NSString*)path;

- (NSArray*)subresourcesFullPathFilenames;

// RMFreezing
- (NSString*)frozenPathExtension;
- (BOOL)freezeToPath:(NSString*)path atomically:(BOOL)saveAtomically error:(NSError**)outError;

// RMThawing
+ (NSSet*)freezeThawDefaultSupportedPathExtensions;
+ (id)thawFromPath:(NSString*)path error:(NSError**)outError;

// RMValueObject
- (BOOL)isEqualToHTMLPackage:(RMHTMLPackage*)other;

@property (readonly, copy) RMUUID* UUID;
@property (readonly) NSURL* baseURL;
@property (readonly) NSString* path;

@end

//***************************************************************************

@interface RMHTMLPackageURLProtocol : NSURLProtocol
{
}

@end

//***************************************************************************

@interface WebFrame (RMHTMLPackageSupport)

- (void)loadHTMLPackage:(RMHTMLPackage*)HTMLPackage;
- (NSString*)innerHTMLString;

@end

//***************************************************************************

@interface WebView (RMHTMLPackageSupport)

- (RMHTMLPackage*)HTMLPackage;

@end

//***************************************************************************

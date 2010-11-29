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

//***************************************************************************

/// Represents a Mac OS X version number.
typedef struct
{
	NSUInteger major;	//< e.g. If the system version is 10.5.2, this would be 10
	NSUInteger minor;	//< e.g. If the system version is 10.5.2, this would be 5
	NSUInteger bugFix;	//< e.g. If the system version is 10.5.2, this would be 2
}
MacOSXVersion;

//***************************************************************************

/// A class that provides information about the entire system (e.g. the current Mac OS X version number).
@interface RMSystem : NSObject
{
}

/// Returns the current Mac OS X system version.
+ (MacOSXVersion)systemVersion;

/// Returns YES if we're running Mac OS X 10.4.0 or later; NO otherwise.
+ (BOOL)isMacOSX1040OrLater;

/// Returns the amount of physical memory this system has (in megabytes).
+ (NSUInteger)physicalRAMSizeInMegabytes;

@end

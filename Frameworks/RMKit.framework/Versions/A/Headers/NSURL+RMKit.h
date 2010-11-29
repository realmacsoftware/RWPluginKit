//***************************************************************************

// Copyright (C) 2008 Realmac Software Ltd
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

@interface NSURL (FullPath)

/// This method is similar to -path, but keeps trailing slashes on the end of the path if there is one present.
/** For example, for the URLs "file:///foo/bar/" and "http://foo.com/bar/", -[NSURL path] will return "/bar", whereas -[NSURL fullPath] (this method) will return "/bar/".  This method therefore gives similar behaviour to CFURLCopyPath(), but will also replace percent-escapes in the string with their unescaped, raw equivalents (like -[NSURL path]). */
- (NSString*)fullPath;

@end

//***************************************************************************

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

@interface NSData (SHA1Digest)

/// Returns a SHA-1 digest of the receiver.
- (NSData*)SHA1Digest;

/// Returns a SHA-1 digest of the receiver as a hexadecimal string, with all letters uppercased (e.g. @"8B8B1E0C820C07FA0D1D97D3D94CC08755B81D59").
- (NSString*)SHA1DigestHexString;

@end

//***************************************************************************

@interface NSData (WriteToTemporaryFile)

/// Writes the receiver to a temporary file on disk.  Returns nil if the write failed, or the full pathname to the temporary file if the write succeeds.
- (NSString*)writeToTemporaryFileWithOptions:(NSUInteger)writeOptionsMask error:(NSError**)outError;

@end

//***************************************************************************

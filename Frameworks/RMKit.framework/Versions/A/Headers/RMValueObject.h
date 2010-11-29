//***************************************************************************

// Copyright (C) 2007 Realmac Software Pty Ltd
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

/** A very simple protocol so that I remember to implement all these methods when creating a "value" object (one whose value determines whether it is equal or not to another object.) */
@protocol RMValueObject <NSObject, NSCopying>

- (BOOL)isEqual:(id)other;
- (NSUInteger)hash;

@end

/// A convenience method to compare if two objects are equal: this takes into account whether both objects have the same address.
/** This function is also useful when implementing -isEqual:. */
static inline BOOL RMEqualObjects(id lhs, id rhs)
{
	if(lhs == rhs) return YES;
	
	return [lhs isEqual:rhs];
}

//***************************************************************************

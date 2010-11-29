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

#import <Cocoa/Cocoa.h>

//***************************************************************************

/// This is a simple pair class, similar to std::pair in the C++ STL, or a two-tuple from functional programming languages such as Haskell and Erlang.
/** Note that the objects stored here are retained, not copied, so RWTuple
  * can work with objects that do not implement value semantics.  This enables
  * us to store things such as NSWindows and NSTextViews in a tuple. */
@interface RWTuple : NSObject
{
	id _first;
	id _second;
}

+ (RWTuple*)tupleWithFirstElement:(id)first secondElement:(id)second;

- (RWTuple*)initWithFirstElement:(id)first secondElement:(id)second;
- (BOOL)isEqualToTuple:(RWTuple*)other;
- (NSComparisonResult)compare:(RWTuple*)tuple;

@property (retain) id first;
@property (retain) id second;

@end

//---------------------------------------------------------------------------

/// Convenience function to make an RWTuple (since it's syntactically brief).
extern RWTuple* RWTupleMake(id first, id second);

//***************************************************************************

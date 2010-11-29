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

/// Implement this protocol for your object to support "object paths".
/** An object path is similar to a key (key as in "Key/Value" coding), but can descend into sub-objects by separating path components with a slash (/) character.  Each object defines its own semantics for path components in the object path; for example, an NSDictionary may interpret a path component as a string used to looked up a value in the dictionary, whereas an NSArray may interpret a path component as an integer that is an index into the array.
 * 
 * As an example, [foo objectForPath:@"key1/key2"] is equivalent to first performing [foo objectForKey:@"key1"], then calling objectForKey:@"key2" on the result of that.
 */
@protocol RMObjectPathing

@optional

/// Returns the given object for the object path string.  If you do not implement this method (which is the normal case), a default implementation will be used.
/** As an example, [foo objectForPath:@"key1/key2"] is equivalent to first performing [foo objectForKey:@"key1"], then calling objectForKey:@"key2" on the result of that. */
- (id)objectForPath:(NSString*)objectPath;

@required

/// Returns the object for a given path component.
/** You are guaranteed that the path component passed to this method will not have a slash character (/) in it.  It is up to your individual object to define how the path component should be interpreted; for example, if your object uses array-like indexing, you may choose to interpret path components as integer strings that represent the object index. */
- (id)objectForPathComponent:(NSString*)pathComponent;

@end

//***************************************************************************

@interface NSArray (ObjectPathSupport) <RMObjectPathing>

/// Implements object paths for an NSArray.
/** The path component will be parsed as an unsigned integer and be used as an index into the array.  If the number fails to parse or is out-of-bounds, this returns nil. */
- (id)objectForPathComponent:(NSString*)pathComponent;

@end

//---------------------------------------------------------------------------

@interface NSDictionary (ObjectPathSupport) <RMObjectPathing>

/// Implements object paths for an NSDictionary.
/** The path component will be parsed as a dictionary key, and is passed directly to -objectForKey. */
- (id)objectForPathComponent:(NSString*)pathComponent;

@end

//***************************************************************************

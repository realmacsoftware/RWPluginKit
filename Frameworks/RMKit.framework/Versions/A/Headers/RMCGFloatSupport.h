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

/// Like round(3), but takes a CGFloat parameter rather than a double.
static inline CGFloat CGFloatRound(CGFloat x)
{
#if defined(__LP64__)
	return round(x);
#else
	return roundf(x);
#endif
}

/// Like floor(3), but takes a CGFloat parameter rather than a double.
static inline CGFloat CGFloatFloor(CGFloat x)
{
#if defined(__LP64__)
	return floor(x);
#else
	return floorf(x);
#endif
}

/// Like ceil(3), but takes a CGFloat parameter rather than a double.
static inline CGFloat CGFloatCeil(CGFloat x)
{
#if defined(__LP64__)
	return ceil(x);
#else
	return ceilf(x);
#endif
}

/// Like lrint(3), but takes a CGFloat parameter rather than a double.
static inline long CGFloatLrint(CGFloat x)
{
#if defined(__LP64__)
	return lrint(x);
#else
	return lrintf(x);
#endif
}

/// Like modf(3), but takes a CGFloat parameter rather than a double.
static inline long CGFloatModf(CGFloat value, CGFloat* iptr)
{
#if defined(__LP64__)
	return modf(value, iptr);
#else
	return modff(value, iptr);
#endif
}

//***************************************************************************

@interface NSNumber (CGFloat)

/// Returns a number with the CGFloat value.
+ (NSNumber*)numberWithCGFloat:(CGFloat)value;

/// Returns a CGFloat from the receiver.
- (CGFloat)CGFloatValue;

@end

//***************************************************************************

@interface NSString (CGFloatValue)

/// Returns a CGFloat from the receiver.
- (CGFloat)CGFloatValue;

@end

//***************************************************************************

@interface NSControl (CGFloatSupport)

- (CGFloat)CGFloatValue;
- (void)setCGFloatValue:(CGFloat)value;

@end

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

@interface NSError (RMErrorCreation)

/*
	Returns an NSError object derived from the given POSIX errno, given as the
	errorNumber parameter. The error domain set to NSPOSIXErrorDomain, error code
	set to the given errorNumber (errno), and userInfo dictionary's
	NSLocalizedDescriptionKey key set to strerror(errorNumber).
*/
extern NSError* RMErrorWithPOSIXErrno(const int errorNumber);

/*
	Sets the given "out" NSError** parameter to an NSError object created from
	the POSIX errno given as the errorNumber parameter.
*/
extern BOOL RMErrorSetErrorParameterWithWithPOSIXErrno(const int errorNumber, NSError** outError);

/*
	Deprecated in RW 5.2.1. Use RMErrorSetErrorParameterWithWithPOSIXErrno() instead.
	Internally this function just calls that directly.
*/
extern BOOL RMErrorFailureWithPOSIXErrno(const int errorNumber, NSError** outError) DEPRECATED_ATTRIBUTE;

@end

//***************************************************************************

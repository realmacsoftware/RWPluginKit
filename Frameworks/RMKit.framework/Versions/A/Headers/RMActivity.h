//***************************************************************************

// Copyright (C) 2007-2008 Realmac Software Ltd
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

#import "RMActivityView.h"

//***************************************************************************

typedef enum
{
	RMActivityProgressRunning,
	RMActivityProgressFinished,
}
RMActivityProgressState;

//***************************************************************************

@interface RMAnnotatedOperation : NSOperation<RMActivityViewing>
{
	NSString* _localizedDescription;
	NSImage* _imageDescription;
}

+ (NSString*)localisedStateForActivity:(RMAnnotatedOperation*)activity;

- (NSString*)localisedState;

@property (copy) id localizedDescription;
@property (retain) NSImage* imageDescription;

@end

//***************************************************************************

typedef enum
{
	RWFakeOperationStateReady,
	RWFakeOperationStateExecuting,
	RWFakeOperationStateFinished,
}
RWFakeOperationState;

//---------------------------------------------------------------------------

@interface RMFakeOperation : RMAnnotatedOperation
{
	RWFakeOperationState _fakeOperationState;
}

+ (RMFakeOperation*)fakeOperationWithLocalizedDescription:(id)localizedDescription;

- (RMFakeOperation*)initWithLocalizedDescription:(id)localizedDescription;

- (void)finish;

@end

//***************************************************************************

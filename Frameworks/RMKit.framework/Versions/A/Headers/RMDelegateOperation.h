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

#import "RMActivity.h"

//***************************************************************************

@interface RMDelegateOperation : RMAnnotatedOperation
{
	id _delegate;
	SEL _action;
	NSArray* _actionArguments;
}

// TODO: Make this thing take an RMMessage* or NSInvocation* parameter

+ (RMDelegateOperation*)operationWithDelegate:(id)delegate;
+ (RMDelegateOperation*)operationWithDelegate:(id)delegate action:(SEL)selector;
+ (RMDelegateOperation*)operationWithDelegate:(id)delegate action:(SEL)selector withObject:(id)argument1;
+ (RMDelegateOperation*)operationWithDelegate:(id)delegate action:(SEL)selector withObject:(id)argument1 withObject:(id)argument2;

- (RMDelegateOperation*)initWithDelegate:(id)delegate;
- (RMDelegateOperation*)initWithDelegate:(id)delegate action:(SEL)selector;
- (RMDelegateOperation*)initWithDelegate:(id)delegate action:(SEL)selector withObject:(id)argument1;
- (RMDelegateOperation*)initWithDelegate:(id)delegate action:(SEL)selector withObject:(id)argument1 withObject:(id)argument2;

- (void)setDelegate:(id)delegate action:(SEL)selector;
- (void)setDelegate:(id)delegate action:(SEL)selector firstArgument:(id)argument1 secondArgument:(id)argument2;

@property (assign) id delegate;
@property SEL action;
@property (copy) NSArray* actionArguments;

@end

//***************************************************************************

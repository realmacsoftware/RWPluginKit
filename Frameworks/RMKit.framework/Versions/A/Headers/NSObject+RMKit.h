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

@interface NSObject (PerformOnMainThread)

/// Similar to performSelectorOnMainThread:withObject:waitUntilDone:, but also permits including a second argument in the performed message.
- (void)performSelectorOnMainThread:(SEL)aSelector
						  withObject:(id)argument1
						  withObject:(id)argument2
					   waitUntilDone:(BOOL)wait;

/// Similar to performSelectorOnMainThread:withObject:waitUntilDone:, but also returns the result from the performed method.
/** Methods with a void return type will have an NSNull object returned, and methods with a BOOL or char return type with have an NSNumber object returned.  No other return types are currently supported at the moment! */
- (id)performSelectorOnMainThread:(SEL)aSelector
					   withObject:(id)argument1;

/// Similar to performSelectorOnMainThread:withObject:waitUntilDone:, but also returns the result from the performed method.
/** Methods with a void return type will have an NSNull object returned, and methods with a BOOL or char return type with have an NSNumber object returned.  No other return types are currently supported at the moment! */
+ (id)performSelectorOnMainThread:(SEL)aSelector
					   withObject:(id)argument1;

/// Similar to performSelectorOnMainThread:withObject:withObject:waitUntilDone:, but also returns the result from the performed method.
/** Methods with a void return type will have an NSNull object returned, and methods with a BOOL or char return type with have an NSNumber object returned.  No other return types are currently supported at the moment! */
- (id)performSelectorOnMainThread:(SEL)aSelector
					   withObject:(id)argument1
					   withObject:(id)argument2;

/// Performs the selector on a new background thread, and runs the default run loop run until the method call returns.
/// Deprecated because it blocks until the background thread completes, making it somewhat pointless to run the selector in the background
/// Instead use NSOperation and NSOperationQueue
- (id)performSelectorOnBackgroundThread:(SEL)aSelector
							 withObject:(id)argument1
							 withObject:(id)argument2 __attribute__((deprecated));

/// Invokes the given invocation with the target set to the receiver.
- (void)performInvocation:(NSInvocation*)anInvocation;

@end

//***************************************************************************

@interface NSObject (SetValueForKeyAdditions)

- (BOOL)setValueIfNotNil:(id)value forKey:(NSString*)key;
- (BOOL)setValueIfNotNil:(id)value viaSelector:(SEL)selector;
- (BOOL)setValue:(id)value forKey:(NSString*)key defaultValue:(id)defaultValue;
- (BOOL)setValue:(id)value viaSelector:(SEL)selector;
- (BOOL)setValue:(id)value viaSelector:(SEL)selector defaultValue:(id)defaultValue;
- (BOOL)setBoolNumber:(NSNumber*)number viaSelector:(SEL)selector;
- (BOOL)setBoolNumber:(NSNumber*)number viaSelector:(SEL)selector defaultValue:(const BOOL)defaultBoolValue;
- (BOOL)setFloatNumber:(NSNumber*)number viaSelector:(SEL)selector;
- (BOOL)setIntNumber:(NSNumber*)number viaSelector:(SEL)selector;
- (BOOL)setIntNumber:(NSNumber*)number viaSelector:(SEL)selector defaultValue:(const int)defaultIntValue;
- (BOOL)setIntegerNumber:(NSNumber*)number viaSelector:(SEL)selector defaultValue:(const NSInteger)defaultIntegerValue;

@end

//***************************************************************************

@interface NSObject (ValueChangedForKey)

- (void)valueChangedForKey:(NSString*)key;

@end

//***************************************************************************

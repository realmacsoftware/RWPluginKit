//***************************************************************************

// Copyright (C) 2007 Sigil Studios Pty Ltd
// Copyright (C) 2007 Ofri Wolfus
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

#import <Foundation/NSArray.h>

//***************************************************************************

// Note: Pretty much all the important concepts in this code is taken from
// dPompa's HigherOrderMessaging framework <http://www.dpompa.com/?cat=4>;
// I merely simplified it a bit for my own use.
//
// Sample usage:
//
// NSArray* strings = [@"Foo Bar Baz" componentsSeparatedByString:@" "];
//
// NSArray* collectedArray = [array collect:MSG(stringByAppendingString:@"Quux")];
// NSArray* selectedArray = [array select:MSG(hasPrefix:@"Ba")];

//***************************************************************************

@class RMMessage;

//***************************************************************************

@interface NSArray (CollectSelectHigherOrderMessaging)

- (id)collect:(RMMessage*)message;
- (id)parallelCollect:(RMMessage*)message;
- (id)select:(RMMessage*)message;

@end

//***************************************************************************

@interface NSObject (PerformOnMainThreadHigherOrderMessaging)

- (id)performMessage:(RMMessage*)message;

- (id)performOnMainThread:(RMMessage*)message;
+ (id)performOnMainThread:(RMMessage*)message;

- (void)performOnMainThread:(RMMessage*)message waitUntilDone:(BOOL)wait;

/** Note: This method is not hugely efficient: it wakes up every 1/10th of a second to check whether the background thread has finished executing.  If you're using this method, I'm presuming that you're after convenience over performance (otherwise you'd be using NSOperation and the like); if this is unacceptable to you, initiate the background thread yourself.  Of course, on modern systems, 1/10th of a second is a reasonably long time, too... */
- (id)performOnBackgroundThread:(RMMessage*)message;

- (void)detachNewThreadSelector:(RMMessage*)message;

@end

//***************************************************************************

#define RMMESSAGE_ARGUMENT_BUFFER_SIZE 1024

@interface RMMessage : NSObject
{
@public
	SEL selector;
	id captureObject;
	
	// This is actually statically allocated memory space to hold a marg_list
	__strong char arguments[RMMESSAGE_ARGUMENT_BUFFER_SIZE];
	
	unsigned argumentSize;
}

@end

//***************************************************************************

@interface RMPerformOnMainThreadAssistant : NSObject
{
@public
	id returnValue;
}

@end

//***************************************************************************

/*!
 * @defined ID()
 * @abstract Enables any message (or function) to return an object even if the compiler doesn't think it should.
 */
#if defined(__ppc__) || defined(__ppc64__)
#if defined (__ppc64__)
#warning Support for PPC-64 is untested
#endif
// PPC uses r3 for integer return values
#define ID(X...) ({ volatile id __o = nil; X; asm volatile ("stw r3, %0": "=m" (__o)); __o; })

#elif defined(__i386__)
// i386 returns integer values in %eax
#define ID(X...) ({ volatile id __o = nil; X; asm volatile ("mov %%eax, %0": "=m" (__o)); __o; })

#elif defined(__x86_64__)
#warning Support for x86-64 has been removed until it is fixed up
// According to the x86-64 ABI, integer return values are returned using the next available register of the
// sequence %rax, %rdx, so this may not be the right register.
// I'd really appreciate comments about this from someone with more knowledge in the subject.
#define ID(X...) ({ volatile id __o = nil; X; asm volatile ("mov %%rax, %0": "=m" (__o)); __o; })

#else
#error Unknown Architecture
#endif

//---------------------------------------------------------------------------

#define MSG(x) (RMMessage*) ID([[[RMMessage alloc] autorelease] x])

//***************************************************************************

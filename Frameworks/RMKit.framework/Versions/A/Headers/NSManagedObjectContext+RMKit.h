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

@interface NSManagedObjectContext (RMKit)

/// This is a safer version of -save:, which has potential deadlocks when a background thread is using -performSelectorOnMainThread:withObject:waitUntilDone: with the 'wait' flag set to YES.  If any errors occured, an application-modal alert will be presented with the save error, or simply logged to the console if the main run loop is not active (which can happen if, for example, -safeSave is called while NSApp is posting a notification that it's terminating).  See the detailed description for more details.
/** -[NSManagedObjectContext save:] has a very nasty deadlock.  If you run it from the main thread while a background thread is blocked on -performSelectorOnMainThread:withObject:waitUntilDone: as it's waiting for the main thread's runloop to fire its selector, something inside -save: is getting blocked.  The stack trace of the main thread will look something like this:

	 Thread 1 (process 23190 thread 0x10b):
	 #0  0x967004ee in semaphore_wait_signal_trap ()
	 #1  0x96707fc5 in pthread_mutex_lock ()
	 #2  0x91e93df5 in -[_PFLock lock] ()
	 #3  0x91e9d731 in -[NSManagedObjectContext(_NSInternalAdditions) lockObjectStore] ()
	 #4  0x91eb0676 in -[NSManagedObjectContext save:] ()

 while the stack trace of the background thread will look something like this:
 
	 Thread 8 (process 23190 thread 0x7003):
	 #0  0x9670768e in __semwait_signal ()
	 #1  0x96732986 in _pthread_cond_wait ()
	 #2  0x9673236d in pthread_cond_wait$UNIX2003 ()
	 #3  0x906dc692 in -[NSCondition wait] ()
	 #4  0x9069502a in -[NSObject(NSThreadPerformAdditions) performSelector:onThread:withObject:waitUntilDone:modes:] ()
	 #5  0x90715b2c in -[NSObject(NSThreadPerformAdditions) performSelectorOnMainThread:withObject:waitUntilDone:modes:] ()
	 #6  0x944b6c25 in -[_IKIRLMainProxy forwardInvocation:] ()
	 #7  0x91ae29aa in ___forwarding___ ()
	 #8  0x91ae2a12 in __forwarding_prep_0___ ()
	 #9  0x944d3470 in -[IKImageBrowserView(ImageBrowserImport) startImportVisibleCells] ()
	 #10 0x9458416f in -[IKTaskManager taskLoop] ()
	 #11 0x90694bad in -[NSThread main] ()
	 #12 0x90694754 in __NSThread__main__ ()
	 #13 0x967316f5 in _pthread_start ()
	 #14 0x967315b2 in thread_start ()
 
 In this example, we have a IKImageBrowserView instance somewhere.  As of Mac OS X 10.5.6, IKImageBrowserView uses a background thread to load images into its browser view, and uses -performSelector:onThread:withObject:waitUntilDone:modes: to execute some methods on the main thread.  The IKImageBrowserView background thread is blocked while it waits for the main run loop perform its selector, and for whatever reason, -[NSManagedObjectContext save:] is also blocked attempting to lock something.
 
 See the implementation of this method for the workaround. */
- (void)safeSave;

/// This is similar to -objectRegisteredForID:, except that (1) you pass it an NSURL instead of an NSManagedObjectID, and (2) this method will force Core Data to load the object into memory if it's a fault, whereas -objectRegisteredForID: will return nil if the object exists in the managed object context but is a fault.
/** Or, another way to view this method is that it's similar to -objectWithID:, except that -objectWithID: will throw an exception if the URL doesn't exist (and catching the exception doesn't seem to help either, for some unknown reason). */
- (NSManagedObject*)objectWithURIRepresentation:(NSURL*)URL;

@end

//***************************************************************************

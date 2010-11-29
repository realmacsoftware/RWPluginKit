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

#import <AppKit/AppKit.h>
#import <QuartzCore/CoreAnimation.h>

//***************************************************************************

@class CALayer, CATextLayer, CAScrollLayer, RMActivityView;

//***************************************************************************

@protocol RMActivityViewing<NSObject>

/// Returns YES if the operation is currently being executed; NO otherwise
- (BOOL)isExecuting;

/// Returns YES if the operation is finished (with or without errors); NO otherwise
- (BOOL)isFinished;

@optional

// Returns a thumbnail image that will be displayed in the user interface, which should look decent at 512x512.  Note that while this method is, strictly speaking, optional, you really want to implement it, otherwise things in RMActivityView will end up looking rather ugly...
- (NSImage*)imageDescription;

// Should return a either than NSString* or an NSAttributedString* which is a localized description of the activity.  The returned string will be displayed directly in the user interface.
/** If you do not implement this method, -description will be used instead. */
- (id)localizedDescription;

// Should return an NSAttributedString* or an NSString*, which will be displayed in the "detailed" part of the user interface.
- (id)localizedDetailedDescription;

// Should return an NSArray of id<RMActivityViewing>
- (NSArray*)dependencies;

@end

//***************************************************************************

@protocol RMActivityViewDelegate<NSObject>

@optional

/// Called back when 
- (void)activityView:(RMActivityView*)activityView didClickOnOperation:(NSOperation*)operation;

/// Return a value bounded between [0.0, 1.0].
- (double)activityViewProgressIndicatorValue:(RMActivityView*)activityView;

/// Return an NSString* or NSAttributedString*.
- (id)activityViewProgressText:(RMActivityView*)activityView;

// Add -finishedSound to RMOperation protocol

@end

//***************************************************************************

@interface RMActivityView : NSView
{
	CALayer* _rootLayer;
	NSMapTable* _CGImageCache;	//< Cache of an operation's NSImage -> CGImageRef
	
	NSMapTable* _layerDictionary;	//< Operation -> Layer
	
	id<RMActivityViewDelegate> _delegate;

	CAScrollLayer* _bodyLayer;					// Assignment semantics (owned by _rootLayer)
	CATextLayer* _localizedDescriptionLayer;	// Assignment semantics (owned by _rootLayer)
	CATextLayer* _progressTextLayer;			// Assignment semantics (owned by _rootLayer)
	CALayer* _progressIndicatorLayer;			// Assignment semantics (owned by _rootLayer)

	NSMutableSet*	_observedOperations;
}

@property (assign) id<RMActivityViewDelegate> delegate;

@property (readonly, retain) NSMutableSet* observedOperations;

+ (id)defaultProgressTextForActivityView:(RMActivityView*)activityView finishedTasks:(NSUInteger)numberOfFinishedTasks totalTasks:(NSUInteger)totalNumberOfTasks;

- (void)scrollToOperation:(NSOperation*)operation;

- (void)observeOperation:(NSOperation*)operation;
- (void)observeOperations:(NSArray*)operations;

@end

//***************************************************************************


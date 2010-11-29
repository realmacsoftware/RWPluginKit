//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// This software is supplied to you by Realmac Software Ltd ("Realmac").
// in consideration of your agreement to the following terms, and your use,
// installation, modification or redistribution of this Realmac software
// constitutes acceptance of these terms.  If you do not agree with these
// terms, please do not use, install, modify or redistribute this Realmac
// software.
//
// In consideration of your agreement to abide by the following terms, and
// subject to these terms, Realmac grants you a personal, non-exclusive
// license, under Realmac's copyrights in this original Realmac software (the
// "Software"), to use, reproduce, modify and redistribute the Software, with
// or without modifications, in source and/or binary forms; provided that if
// you redistribute the Software in its entirety and without modifications,
// you must retain this notice and the following text and disclaimers in all
// such redistributions of the Software.
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

#import <RMKit/RMKit.h>

//***************************************************************************

@protocol RWWebResource

@required

/// This should return an NSData object that is the raw data passed to a Web browser for the given resource.
- (NSData*)webResourceData;

@optional

/// This should return a fully-qualified filesystem path for the resource.
- (NSString*)webResourcePath;

/// This should return an array of objects that conform to the RWWebResource protocol.
- (NSArray*)linkableWebResources;

@end

//***************************************************************************

/// RWWebResource support for the RMFrozenData class.
@interface RMFrozenData (RWWebResourceSupport)

- (NSData*)webResourceData;

@end

//***************************************************************************

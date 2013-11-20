//***************************************************************************

// Copyright (C) 2007 Realmac Software Ltd
//
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information of Realmac Software Ltd
// and are protected by copyright law. They may not be disclosed
// to third parties or copied or duplicated in any form, in whole or
// in part, without the prior written consent of Realmac Software Ltd.

//***************************************************************************

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

//***************************************************************************

/// A RapidWeaver-specific subclass of WebView.
/** This is simply for defensive programming: if we need to add any methods
  * to a WebView in the future, we can do it by adding it to this class instead
  * of re-jiggering all the existing code we've written.  Please subclass from
  * this class rather than WebView. */
@interface RWWebView : WebView
{
	
}

@end

//***************************************************************************

@interface RWWebEditView : RWWebView

@end

//***************************************************************************

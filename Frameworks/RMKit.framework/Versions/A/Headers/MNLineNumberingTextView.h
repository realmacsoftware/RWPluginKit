//
//  MNLineNumberingRulerView.h
//  
//
//  Created by Masatoshi Nishikata on 29/10/05.
//  Copyright 2005 Masatoshi Nishikata. All rights reserved.
//	http://homepage.mac.com/mnishikata/iblog/

//ORIGINAL
//
//  MyTextView.m
//  LineNumbering
//
//  Created by Koen van der Drift on Sat May 01 2004.
//  Copyright (c) 2004 Koen van der Drift. All rights reserved.
//

/*
 
 
	LineNumberingRulerView shows paragraph number, line number and character number.
	Furthermore, it can handle bookmarks like debug marker in Xcode.
 
	Bookmarks are embedded to return code as an attribute 'MarkerAttributeName' (Bool value YES as NSNumber).
	As a default text view saving process using RTFFromRange... , the bookmark attribute is not saved. 
	If you want to save them, extract that attribute and save separatory.
	
 
 */


#import <Cocoa/Cocoa.h>
#import "MNLineNumberingRulerView.h"
#import "MNLineNumberingTextStorage.h"



@interface MNLineNumberingTextView : NSTextView {

}

-(void)toggleGutterVisiblity;
// Show and Hide gutter (ruler view).

-(void)jumpTo;
// Show 'Jump To...' sheet

@end

//
//  RWCodeView.h
//  RapidWeaver
//
//  Created by Simon Maddox on 05/12/2013.
//  Copyright (c) 2013 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE
//

#import <Cocoa/Cocoa.h>

#import "RWCodeHighlightingController.h"

@interface RWCodeView : NSView

@property (nonatomic, strong) NSString *string;
@property (unsafe_unretained, nonatomic, readonly) IBOutlet NSTextView *textView;
@property (nonatomic, unsafe_unretained) IBOutlet id delegate;

@property (nonatomic) BOOL showLineNumbers;
@property (nonatomic, copy) NSString *language;
@property (nonatomic) BOOL hasBorder;
@property (nonatomic) BOOL editable;
@property (nonatomic) BOOL autocompleteEnabled;
@property (nonatomic) CGFloat fontSize;

@end

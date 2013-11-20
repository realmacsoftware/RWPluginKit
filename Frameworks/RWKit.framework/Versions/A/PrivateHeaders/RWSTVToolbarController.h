//
//  RWSTVToolbarController.h
//  RapidWeaver
//
//  Created by Kevin LaCoste on 10-09-22.
//  Copyright 2010 Realmac Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RWTextView;

@interface RWSTVToolbarController : NSViewController
{
	NSButton *addLinkButton;
	NSButton *removeLinkButton;
	
	NSButton *alignLeftButton;
	NSButton *alignCenterButton;
	NSButton *alignRightButton;
	
	NSButton *boldButton;
	NSButton *italicsButton;
	NSButton *underlineButton;
}

@property (nonatomic, assign) IBOutlet NSButton *addLinkButton;
@property (nonatomic, assign) IBOutlet NSButton *removeLinkButton;
@property (nonatomic, assign) IBOutlet NSButton *alignLeftButton;
@property (nonatomic, assign) IBOutlet NSButton *alignCenterButton;
@property (nonatomic, assign) IBOutlet NSButton *alignRightButton;
@property (nonatomic, assign) IBOutlet NSButton *boldButton;
@property (nonatomic, assign) IBOutlet NSButton *italicsButton;
@property (nonatomic, assign) IBOutlet NSButton *underlineButton;

+ (id)controllerWithRepresentedObject:(id)object;

- (void)updateTextToolbarForTextView:(RWTextView *)textView;

- (IBAction)onAddLink:(id)sender;
- (IBAction)onRemoveLink:(id)sender;
- (IBAction)onList:(id)sender;
- (IBAction)onColorPicker:(id)sender;
- (IBAction)onWebSafeFontsMenu:(id)sender;
- (IBAction)onHTMLFormatMenu:(id)sender;
- (IBAction)onToggleBoldText:(id)sender;
- (IBAction)onToggleItalicText:(id)sender;
- (IBAction)onToggleUnderlineText:(id)sender;
- (IBAction)alignLeft:(id)sender;
- (IBAction)alignCenter:(id)sender;
- (IBAction)alignRight:(id)sender;

@end

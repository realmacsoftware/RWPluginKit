//
//  RWAlert.h
//  RWPluginUtilities
//
//  Created by Simon Taylor on 08/05/2005.
//  Copyright (c) 2005 Realmac Software. All rights reserved.
//
//  THIS IS A RAPIDWEAVER INTERNAL HEADER FILE AND THE INTERFACES
//  DESCRIBED HERE COULD CHANGE WITHOUT NOTICE 
//

#import <Cocoa/Cocoa.h>

@interface RWAlert : NSObject

+ (void)runAlert:(NSString *)title message:(NSString *)message;
+ (NSInteger)runAlert:(NSString *)title message:(NSString *)message defaultChoice:(NSString *)defaultButtonText alternateChoice:(NSString *)alternateButtonText;

+ (NSInteger)runInfoAlert:(NSString*)title message:(NSString*)message;
+ (NSInteger)runInfoAlert:(NSString*)title message:(NSString*)message defaultButton:(NSString*)defaultButton alternateButton:(NSString*)otherButton;
+ (NSInteger)runInfoAlertOKCancel:(NSString*)title message:(NSString*)message;
+ (NSInteger)runInfoAlertOKCancelAlternate:(NSString*)title message:(NSString*)message alternate:(NSString*)alternate;

@end

@interface NWAlert : NSAlert

// Convenience class. Allows slightly simpler setup of alerts.

+ (id)alertWithTitle:(NSString *)title message:(NSString *)message;

+ (NSString *)localizedDefaultButtonText;
+ (NSString *)localizedCancelButtonText;

- (void)setDefaultButtonText:(NSString *)buttonText;
- (void)setCancelButtonText:(NSString *)buttonText;

@end

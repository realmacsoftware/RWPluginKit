//
//  RWThemePresenter.h
//  RapidWeaver
//
//  Created by Tom Bradley on 20/09/2017.
//  Copyright © 2017 Realmac Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RWThemePresenter;

@protocol RWThemePresenterDelegate <NSObject>

- (void)themePresenter:(RWThemePresenter*)themePresenter urlChanged:(NSURL *)url;

@end

@interface RWThemePresenter : NSObject

@property (nonatomic, strong) id <RWThemePresenterDelegate> delegate;

- (instancetype)initWithURL:(NSURL *)url;

@end

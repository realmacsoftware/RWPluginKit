//
//  RWTiledImageView.h
//  RapidWeaver
//
//  Created by Kevin LaCoste on 10-10-01.
//  Copyright 2010 Realmac Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface RWTiledImageView : NSView
{
	NSImage *image;
}

- (void)setBackgroundTileFromNSImage:(NSImage *)anImage;

@end

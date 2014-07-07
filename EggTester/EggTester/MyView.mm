//
//  MyView.m
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//
// https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/EventOverview/HandlingMouseEvents/HandlingMouseEvents.html

#import "MyView.h"

@implementation MyView

@synthesize widgetMaster;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
    }
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    NSRect thisViewSize = [self bounds];
    
    NSGradient *backgroundGradient = [[NSGradient alloc] initWithStartingColor:[NSColor blackColor] endingColor:[NSColor blackColor]];
	[backgroundGradient drawInRect:dirtyRect angle:90];

    /*
    NSString *fontFilePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"/fonts"];
    NSURL * fontsURL = [NSURL fileURLWithPath:fontFilePath];
    if(fontsURL != nil)
    {
        OSStatus status;
        FSRef fsRef;
        CFURLGetFSRef((CFURLRef)fontsURL, &fsRef);
        status = ATSFontActivateFromFileReference(&fsRef, kATSFontContextLocal, kATSFontFormatUnspecified, NULL, kATSOptionFlagsDefault, NULL);
        if (status != noErr)
        {
            return;
        }
    }
     */

	NSMutableDictionary *drawStringAttributes = [[NSMutableDictionary alloc] init];
	[drawStringAttributes setValue:[NSColor redColor] forKey:NSForegroundColorAttributeName];
    
    NSString *fontname = @"digital-7";
	[drawStringAttributes setValue:[NSFont fontWithName:fontname size:15] forKey:NSFontAttributeName];
	
    /*
    NSShadow *stringShadow = [[NSShadow alloc] init];
	[stringShadow setShadowColor:[NSColor whiteColor]];
	NSSize shadowSize;
	shadowSize.width = 2;
	shadowSize.height = -2;
	[stringShadow setShadowOffset:shadowSize];
	[stringShadow setShadowBlurRadius:6];
	[drawStringAttributes setValue:stringShadow forKey:NSShadowAttributeName];
	*/
    
	NSString *budgetString = @"ABCDEFGHIJKLMONOPQRSTUVWXYZ0123456789";
	NSSize stringSize = [budgetString sizeWithAttributes:drawStringAttributes];
	NSPoint centerPoint;
	centerPoint.x = (dirtyRect.size.width / 2) - (stringSize.width / 2);
	centerPoint.y = dirtyRect.size.height / 2 - (stringSize.height / 2);
	//[budgetString drawAtPoint:centerPoint withAttributes:drawStringAttributes];
    
    if(widgetMaster==0)
    {
        widgetMaster = new WidgetMaster();
    }
    widgetMaster->draw();
    
    NSRect r = NSMakeRect(0, 0, 1000, 621);
    NSBezierPath *bp = [NSBezierPath bezierPathWithRect:r];
    NSColor *color = [NSColor blueColor];
    [color set];
    [bp stroke];
}

- (void)mouseDown:(NSEvent *)theEvent {
    NSPoint mouseLoc = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    widgetMaster->mouseDown(mouseLoc.x, mouseLoc.y);
}

- (void)mouseUp:(NSEvent *)theEvent {
    NSPoint mouseLoc = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    widgetMaster->mouseUp(mouseLoc.x, mouseLoc.y);
}

- (void)mouseDragged:(NSEvent *)theEvent {
    NSPoint mouseLoc = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    widgetMaster->mouseMove(mouseLoc.x, mouseLoc.y);
}


@end

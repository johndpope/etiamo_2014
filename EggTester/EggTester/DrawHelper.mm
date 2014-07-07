//
//  DrawHelper.mm
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include <stdio.h>
#import "DrawHelper.h"


void setColor(int colorId)
{
    float red = 255.0;
    float green = 255.0;
    float blue = 255.0;
    switch(colorId)
    {
        case 0:
            red = 0;
            green = 0;
            blue = 0;
            break;
            
        case 1:
            green = 20;
            blue = 20;
            break;
    }
    
    [[NSColor colorWithDeviceRed: red/ 255.0
                           green:(green/255.0)
                            blue:(blue/255.0)
                           alpha:1] set];
}

void drawImage(int imgId, int x, int y)
{
    NSImage* img;
    switch(imgId)
    {
        case 0:
            img = [NSImage imageNamed:@"poti0"];
            break;
    }

    NSPoint centerPoint;
	centerPoint.x = x;
	centerPoint.y = y;
    [img drawAtPoint:centerPoint fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1];
}

void drawTextCentered(int colorId, int size, int widthAvailable, int x, int y, string text)
{
    NSFont *font = [NSFont fontWithName:MYFONT size:size];
	NSMutableDictionary *drawStringAttributes = [[NSMutableDictionary alloc] init];
	[drawStringAttributes setValue:[NSColor redColor] forKey:NSForegroundColorAttributeName];
    
    NSString * mystr = [NSString stringWithUTF8String: text.c_str()];
    NSDictionary *attributes = [NSDictionary dictionaryWithObjectsAndKeys: font, NSFontAttributeName, nil];
    int textWidth =  [[[NSAttributedString alloc] initWithString:mystr attributes:attributes] size].width;
    
   	NSPoint centerPoint;
	centerPoint.x = x + (widthAvailable-textWidth ) / 2.0;
	centerPoint.y = y;
	[mystr drawAtPoint:centerPoint withAttributes:drawStringAttributes];
}

void drawText(int colorId, int size, int fromX, int fromY, string text)
{
	NSMutableDictionary *drawStringAttributes = [[NSMutableDictionary alloc] init];
	[drawStringAttributes setValue:[NSColor redColor] forKey:NSForegroundColorAttributeName];
    
    NSString *fontname = MYFONT;
	[drawStringAttributes setValue:[NSFont fontWithName:fontname size:size] forKey:NSFontAttributeName];

    NSString* budgetString = [NSString stringWithUTF8String: text.c_str()];
	NSPoint centerPoint;
	centerPoint.x = fromX;
	centerPoint.y = fromY;
	[budgetString drawAtPoint:centerPoint withAttributes:drawStringAttributes];
    
}

void drawLine(int colorId, int fromX, int fromY, int toX, int toY)
{
    setColor(colorId);
    
    NSPoint startPoint;
    startPoint.x = fromX;
    startPoint.y = fromY;
    
    NSPoint endPoint;
    endPoint.x = toX;
    endPoint.y = toY;
    
    NSBezierPath * verticalLinePath = [NSBezierPath bezierPath];
    [verticalLinePath setLineWidth:1.5];
    [verticalLinePath moveToPoint:startPoint];
    [verticalLinePath lineToPoint:endPoint];
    [verticalLinePath stroke];
}

extern void fillRect(int colorId, int x, int y, int width, int height)
{
    setColor(colorId);
    NSRect r = NSMakeRect(x, y, width, height);
    NSRectFill(r);
}

extern void drawRect(int colorId, int x, int y, int width, int height)
{
    setColor(colorId);
    NSRect r = NSMakeRect(x, y, width, height);
    NSBezierPath *bp = [NSBezierPath bezierPathWithRect:r];
    [bp stroke];
}

extern void draw7Char(int colorId, int x, int y, char c)
{
    switch(c)
    {
        case '0':
            draw7Segment(colorId, x, y, 1|2|4|8|16|32);
            break;
        case '1':
            draw7Segment(colorId, x, y, 2|4);
            break;
        case '2':
            draw7Segment(colorId, x, y, 1|2|8|16|64);
            break;
        case '3':
            draw7Segment(colorId, x, y, 1|2|4|8|64);
            break;
        case '4':
            draw7Segment(colorId, x, y, 2|4|32|64); // BCFG
            break;
        case '5':
            draw7Segment(colorId, x, y, 1|4|8|32|64);
            break;
        case '6':
            draw7Segment(colorId, x, y, 1|4|8|16|32|64);
            break;
        case '7':
            draw7Segment(colorId, x, y, 1|2|4);
            break;
        case '8':
            draw7Segment(colorId, x, y, 1|2|4|8|16|32|64);
            break;
        case '9':
            draw7Segment(colorId, x, y, 1|2|4|8|32|64);
            break;
    }
}

void draw7Segment(int colorId, int x, int y, char bitmask)
{
    if(bitmask & 1)
        drawLine(colorId, x+3,y+9, x+6, y+9); //top A
    
    if(bitmask & 2)
        drawLine(colorId, x+5,y+5, x+6, y+8); // B
    
    if(bitmask & 4)
        drawLine(colorId, x+4,y+1, x+5, y+4); // C
    
    if(bitmask & 8)
        drawLine(colorId, x+1,y, x+4, y); //base D
    
    if(bitmask & 16)
        drawLine(colorId, x+1,y+1, x+2, y+4);// E
    
    if(bitmask & 32)
        drawLine(colorId, x+2,y+5, x+3, y+8);// F
    
    if(bitmask & 64)
        drawLine(colorId, x+2,y+4, x+5, y+4);// G
}


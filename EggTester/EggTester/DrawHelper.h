//
//  DrawHelper.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef EggTester_DrawHelper_h
#define EggTester_DrawHelper_h

#include <iostream>
#include <string>

#import <Cocoa/Cocoa.h>

//#define MYFONT @"digital-7"
#define MYFONT @"courier"

using namespace std;

extern void drawLine(int colorId, int fromX, int fromY, int toX, int toY);
extern void fillRect(int colorId, int x, int y, int width, int height);
extern void drawRect(int colorId, int x, int y, int width, int height);
extern void draw7Segment(int colorId, int x, int y, char bitmask);
extern void draw7Char(int colorId, int x, int y, char c);
extern void setColor(int id);
extern void drawTextCentered(int colorId, int size, int widthAvailable, int fromX, int fromY, string text);
extern void drawText(int colorId, int size, int fromX, int fromY, string text);
extern void drawImage(int imgId, int x, int y);

#endif

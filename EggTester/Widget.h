//
//  IWidget.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__IWidget__
#define __EggTester__IWidget__

#include <iostream>
#include <list>
#include "Param.h"
#include "Global.h"

using namespace std;

struct WidgetSize
{
    int width;
    int height;
};

class Widget
{
    public:
    
    Widget()
    {

    }
    
    // move into base class and just inform about action?
    void mouseUp(int x, int y)
    {
        printf("up");
    }
    
    void mouseMove(int x, int y)
    {
        float deltax =  (x - mouseDownX) / 100.0;
        float deltay =  (y - mouseDownY) / 100.0;
        float v = valOrg + deltax +deltay;
        //printf("the new vlaue is %f", v);
        if(v<0)
        {
            v = 0;
            mouseDownX = x;
            mouseDownY = y;
            valOrg = 0;
        }
        if(v>1)
        {
            v = 1;
            valOrg = 1;
            mouseDownX = x;
            mouseDownY = y;
        }
        param[param0->id] = v;
    }
    
    bool test(int x, int y);
   
    int width;
    int height;
    Param * param0;
    Param * param1;
    void addChild(Widget * widget);
    virtual void draw() = 0;
    virtual WidgetSize getSize() = 0;
    int x;
    int y;
    
    float valOrg;
    int mouseDownX;
    int mouseDownY;
    
    list<Widget*> widgets;
};


#endif /* defined(__EggTester__IWidget__) */

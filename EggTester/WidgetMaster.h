//
//  WidgetMaster.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__WidgetMaster__
#define __EggTester__WidgetMaster__

#include <iostream>
#include <list>

#include "Widget.h"
#include "DrawHelper.h"
#include "Poti0.h"
#include "Global.h"

using namespace std;

class WidgetMaster
{
    
public:
    WidgetMaster();
    void mouseDown(int x, int y);
    void mouseUp(int x, int y);
    void mouseMove(int x, int y);
    void draw();
    
    list<Widget*> widgets;
    
    Widget * widgetFocus;
    
};
#endif /* defined(__EggTester__WidgetMaster__) */

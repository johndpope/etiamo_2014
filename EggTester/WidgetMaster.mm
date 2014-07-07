//
//  WidgetMaster.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "WidgetMaster.h"

WidgetMaster::WidgetMaster()
{
    Poti0 *poti0 = new Poti0();
    poti0->x = 100;
    poti0->y = 100;
    poti0->param0 = &Params[0];
    widgets.push_back(poti0);
    
    Poti0 *poti1 = new Poti0();
    poti1->x = 200;
    poti1->y = 100;
    poti1->param0 = &Params[1];
    widgets.push_back(poti1);
}

void WidgetMaster::mouseDown(int x, int y)
{
    std::list<Widget*>::const_iterator iterator;
    for (iterator = widgets.begin(); iterator != widgets.end(); ++iterator) {
        Widget * widget = *iterator;
        if(widget->test(x, y))
        {
            widgetFocus = widget;
            return;
        }
    }
}

void WidgetMaster::mouseUp(int x, int y)
{
    if(widgetFocus !=0)
    {
        widgetFocus->mouseUp(x,y);
    }
    widgetFocus = 0;
}

void WidgetMaster::mouseMove(int x, int y)
{
    if(widgetFocus !=0)
    {
        widgetFocus->mouseMove(x,y);
    }
}

void WidgetMaster::draw()
{
    std::list<Widget*>::const_iterator iterator;
    for (iterator = widgets.begin(); iterator != widgets.end(); ++iterator) {
        Widget * widget = *iterator;
        widget->draw();
    }
}

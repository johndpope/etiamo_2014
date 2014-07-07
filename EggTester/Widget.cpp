//
//  IWidget.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "Widget.h"

bool Widget::test(int xTest, int yTest)
{
    WidgetSize s = getSize();
    if(xTest >=x && xTest <= x+s.width && yTest >= y && yTest <= y+s.height)
    {
        mouseDownX = xTest;
        mouseDownY = yTest;
        valOrg = param[param0->id];
        return true;
    }
    return false;
}


void Widget::addChild(Widget *widget)
{
    widgets.push_back(widget);
}

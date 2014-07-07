//
//  Poti0.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Poti0__
#define __EggTester__Poti0__

#include <iostream>
#include <sstream>
#include "Widget.h"
#include "DrawHelper.h"

using namespace std;

class Poti0 : public Widget
{
public:
    
    Poti0();
    int param0Id;
    int param1Id;
    void draw();
    

    
    WidgetSize getSize()
    {
        WidgetSize r = {118,118};
        return r;
    }
    
};


#endif /* defined(__EggTester__Poti0__) */

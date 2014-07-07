//
//  Filter.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/3/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "Filter.h"

Filter:: Filter()
{
    mode = 0;
    modEnvelope = 0;
    modVelocity = 0;
    modKeytrack = 0;
    modLfo = 0;
    modModWheel = 0;
    modDistortion = 0;
    
    filter_4 = new Filter_4();
    filter_4->setup();
}

float Filter::process(float val)
{
    return filter_4->process(val);
}

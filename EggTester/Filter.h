//
//  Filter.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/3/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Filter__
#define __EggTester__Filter__

#include <iostream>

#include "Filter_4.h"

#define Pole6 0;

class Filter {
    
public:
    Filter();
    
    float cutoff;
    float res;
    int mode;
    
    float modEnvelope;
    float modVelocity;
    float modKeytrack;
    float modLfo;
    float modModWheel;
    float modDistortion;
    
    float process(float val);
    
private:
    Filter_4 *filter_4;
};

#endif /* defined(__EggTester__Filter__) */

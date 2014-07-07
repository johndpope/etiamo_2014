//
//  LFO.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__LFO__
#define __EggTester__LFO__

#include <iostream>

using namespace std;

class LFO {
    
public:
    LFO();
    
    void init(int waveType, float freq);
    void tick();
    
    float level;
    float freq;
    int waveType;
    float phase;
    
    
private:
};


#endif /* defined(__EggTester__LFO__) */

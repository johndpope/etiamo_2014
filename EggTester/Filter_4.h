//
//  Filter_4.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//
// http://www.musicdsp.org/archive.php?classid=3#181

#ifndef __EggTester__Filter_4__
#define __EggTester__Filter_4__

#include <iostream>
#include "math.h"
#include "Global.h"

#define NPOLES 4
#define GAIN   5.429577679e+03
#define NZEROS 4

class Filter_4 {
    
public:
    Filter_4();
    void setup();
    float process(float val);
    
    
    float cutoff;
    float resonance;
    int mode;
    
    float modEnvelope;
    float modVelocity;
    float modKeytrack;
    float modLfo;
    float modModWheel;
    float modDistortion;
    
    float f, p, q;             //filter coefficients
    float b0, b1, b2, b3, b4;  //filter buffers (beware denormals!)
    float t1, t2;              //temporary buffers
    
    
private:
};

#endif /* defined(__EggTester__Filter_4__) */

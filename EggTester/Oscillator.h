//
//  Oscillator.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Oscillator__
#define __EggTester__Oscillator__

#include <iostream>
#include "Global.h"
#include "WaveTable.h"
#include "ADSR.h"

using namespace std;

class Oscillator {
    
public:
    Oscillator(int oscId);
    int oscId;
    float detune;
    WaveTable *waveTable;
    
    float get(float freq);
    float phase;
    

    bool sync;
    float symetrie;
    float pwm;
    float pwmspeed;
    float sub;
    float spread;
    float freqMod;
    
    float * octaves;
};

#endif /* defined(__EggTester__Oscillator__) */

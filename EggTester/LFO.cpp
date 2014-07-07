//
//  LFO.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "LFO.h"
#include "Global.h"
#include "WaveTable.h"

LFO::LFO()
{
    level = 1.0;
}

void LFO::init(int waveType, float freq)
{
    this->waveType = waveType;
    this->freq = freq;
    phase = 0;
}

void LFO::tick()
{
    float t = waveTable[(int) (waveType * sampleFreq + phase)];
    if(t<0)
    {
        t = t * -1.0;
    }
    level = t;

    // phase
    phase +=  freq;
    if(phase  >= sampleFreq)
    {
        phase -= sampleFreq;
    }
}

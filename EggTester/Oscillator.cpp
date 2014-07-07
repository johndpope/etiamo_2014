//
//  Oscillator.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "Oscillator.h"


Oscillator::Oscillator(int oscId)
{
    this->oscId = oscId;
    waveTable = WaveTable::of();
    
    detune = 1.0;

    sync = false;
    symetrie = 0.5;
    pwm = 0;
    pwmspeed = 2;
    sub = 0;
    spread = 0;
    freqMod = 0;
    octaves = new float[9];
    octaves[0] = 0.125 / 4.0;
    octaves[1] = 0.125 / 2.0;
    octaves[2] = 0.125;
    octaves[3] = 0.25;
    octaves[4] = 0.5;
    octaves[5] = 1.0;
    octaves[6] = 2.0;
    octaves[7] = 4.0;
    octaves[8] = 8.0;
}

float Oscillator::get(float freq)
{
    float res = 0;

    // voice->freq = (10 * param[1] + 430.0) * freqTable[b];
    res = waveTable->getWave(param[oscId + 5])[(int)phase] ;
    
    phase +=  freq * (param[oscId + 11]  + 0.5) * octaves[(int)param[oscId + 8]];
    if(phase  >= sampleFreq)
    {
        phase -= sampleFreq;
    }
    return res;
}



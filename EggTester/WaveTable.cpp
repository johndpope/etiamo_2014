//
//  WaveTable.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "WaveTable.h"
#include "Math.h"

WaveTable* WaveTable::instance = NULL;
WaveTable* WaveTable::of()
{
    if(instance == NULL)
    {
        instance = new WaveTable();
        return instance;
    }
    else
    {
        return instance;
    }
}

WaveTable::WaveTable()
{
    
}

void WaveTable::init()
{
    // populate
    
    // sin
    for(int i=0; i < sampleFreq; i++)
    {
        waveTable[i] = sin( DPI * i / ((float)sampleFreq) ) ;
    }
    
    // square
    for(int i=0; i < sampleFreq; i++)
    {
        if(i < sampleFreq / 2)
        {
            waveTable[i + WAVE_SQUARE * sampleFreq] = 1.0;
        }
        else
        {
             waveTable[i + WAVE_SQUARE * sampleFreq] = -1.0;
        }
    }
    
    // triangle
    for(int i=0; i < sampleFreq ; i++)
    {
        waveTable[i + WAVE_TRIANGLE * sampleFreq ] = -1 + i / ((float)sampleFreq) * 2.0;
    }

    // saw
    for(int i=0; i < sampleFreq / 4; i++)
    {
        waveTable[i + WAVE_SAW * sampleFreq ] = i / ((float)sampleFreq) * 4.0;
    }
    for(int i=sampleFreq/4; i < sampleFreq *3/4; i++)
    {
        waveTable[i + WAVE_SAW * sampleFreq ] = 1- i / ((float)sampleFreq) * 2.0;
    }
    for(int i=sampleFreq * 3/4; i < sampleFreq; i++)
    {
        waveTable[i + WAVE_SAW * sampleFreq ] = -1 + i / ((float)sampleFreq) * 4.0;
    }
    
    // white noise
    for(int i=0; i < sampleFreq ; i++)
    {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) * 2.0 - 1.0;
        waveTable[i + WAVE_WHITENOISE * sampleFreq ] = r;
    }
}

float * WaveTable::getWave(int waveId)
{
    return &waveTable[waveId * sampleFreq];
}



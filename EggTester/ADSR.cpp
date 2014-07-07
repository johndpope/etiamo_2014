//
//  ADSR.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//
// http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/

// http://www.cockos.com/wdl/
// https://github.com/olilarkin/wdl-ol
// http://cr.yp.to/djbfft.html
// http://www.martin-finke.de/blog/articles/audio-plugins-004-vst-and-au/


#include "ADSR.h"

ADSR::ADSR(int id)
{
    this->id = id;
    level = 0;
    released = false;
   // attackTime = sampleFreq / 10.0 ;
}

float ADSR::get()
{
    return level;
}

void ADSR::attack()
{
    released = false;
    level = 0;
    time = 0;
}

void ADSR::release()
{
    released = true;
    releaseRelTime = 0;
    sustainLevelArrived = level;
}

bool ADSR::tick()
{
    if(released)
    {
        // released
        ++releaseRelTime;
        float releaseTime = sampleFreq * param[20] / 1000.0;
        if(releaseRelTime >releaseTime)
        {
            return true;
        }
        
        level = sustainLevelArrived * (1.0 - releaseRelTime / releaseTime );
        return false;
    }
    else
    {
        ++time;
        //printf("%f",param[17]);
        
        float a = sampleFreq * ((int)param[17]) ;
        float decayTime = sampleFreq *  param[18] / 1000.0;
        // sustain
        float fade = (param[20] - 0.5) * 2.0 / sampleFreq;
        if(time > (a + decayTime))
        {
            level += fade;
            
            if(level >1)
            {
                level = 1;
            }
            if(level < 0)
            {
                level = 0;
            }
            return false;
        }
        if(time > a )
        {
            // decay
            float delta = 1.0 - param[19];
            float t = time - a;
            level = 1.0 - delta * t / decayTime ;
            return false;
        }
        else
        {
            // attack
            level = time / a;
            return false;
        }
    }
}

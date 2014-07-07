//
//  Filter_4.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//
// http://www.iowegian.com/fir/tutorial/design/highpass
// http://www.musicdsp.org/archive.php?classid=3#229

// http://www.musicdsp.org/archive.php?classid=3#229

#include "Filter_4.h"

Filter_4::Filter_4()
{
    b0 = b1 = b2 = b3 = b4 = 0;
}

// Lowpass  output:  b4
// Highpass output:  in - b4;
// Bandpass output:  3.0f * (b3 - b4);

float Filter_4::process(float in)
{
    setup();
    in -= q * b4;                          //feedback
    t1 = b1;  b1 = (in + b0) * p - b1 * f;
    t2 = b2;  b2 = (b1 + t1) * p - b2 * f;
    t1 = b3;  b3 = (b2 + t2) * p - b3 * f;
    b4 = (b3 + t1) * p - b4 * f;
    b4 = b4 - b4 * b4 * b4 * 0.166667f;    //clipping
    b0 = in;
    return  b4;
}

void  Filter_4::setup()
{
    cutoff = nlog(60, param[22]+1.0) ;
   // printf("\n%f", cutoff);
    
    resonance = param[23];
    
    q = 1.0f - cutoff;
    p = cutoff + 0.8f * cutoff * q;
    f = p + p - 1.0f;
    q = resonance * (1.0f + 0.5f * q * (1.0f - q + 5.6f * q * q));
    

}





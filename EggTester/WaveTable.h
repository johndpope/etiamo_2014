//
//  WaveTable.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__WaveTable__
#define __EggTester__WaveTable__

#include <iostream>
#include "Global.h"

#define WAVE_SIN 0
#define WAVE_SQUARE 1
#define WAVE_TRIANGLE 2
#define WAVE_SAW 3
#define WAVE_WHITENOISE 4
#define WAVE_PINKNOISE 5

using namespace std;

class WaveTable {
    
public:
     static WaveTable* of( );
   
    void init();
    float * getWave(int waveId);
    
private:
     WaveTable();
    static WaveTable *instance;
};

#endif /* defined(__EggTester__WaveTable__) */

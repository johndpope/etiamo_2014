//
//  Engine.h
//  EggTester
//
//  Created by Mathias Dietrich on 6/30/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Engine__
#define __EggTester__Engine__

#include <iostream>
#include <string>
#include <math.h>
#include "VoicePool.h"
#include "ADSR.h"
#include "Voice.h"
#include "Oscillator.h"
#include "math.h"
#include "WaveTable.h"
#include "Global.h"
#include "LFO.h"
#include "Filter.h"
#include <stdlib.h>

#define NUM_BUFFERS 3
#define BUFFER_SIZE 4096
#define SAMPLE_TYPE float
#define BYTESPERSAMPLE 4
#define MAXVOICES 16

using namespace std;

class Engine {
    
public:
     static Engine* of( );
    ~Engine();
    
    void init();
    float * getParams();
    void setMidi(Byte a, Byte b, Byte c);
    void setOsc(string msg);
    void render( float * buffer, int sampleCount);
    float * freqTable;
    Filter * filter0;
    
    int logCounter; 

    
private:
    Engine();
    static Engine *instance;
    VoicePool * _voicePool;
    LFO * lfoA;
};

#endif /* defined(__EggTester__Engine__) */

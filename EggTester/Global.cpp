//
//  Global.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/3/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
// Admin Location:
// http://wiki.etiamo.com/

// Username:
// admin

// Password:
// 9mANhD8D
//

#include "Global.h"

#define PARAMCOUNT 129 * 128
#define PATCHCOUNT 128

#define CURVESAMPLES 1024
#define CURVECOUNT 16

#define LFOSAMPLES 100
#define LFOCOUNT 8
#define LFOSAMPLEFREQ 20

#define WAVESAMPLES 96000
#define WAVECOUNT 128
#define WAVESAMPLEFREQ 96000
#define PATCHNAMEMAXLENGTH 16
#define SUMPLEBUFFER WAVESAMPLEFREQ * 60 * 4

int sampleFreq;
char program;
int bank;
float morph;
int midiChannel;

float * param;
float * paramPatch;
float * curveTable;
float * lfoTable;
float * waveTable;
char * patchNames;
char * samples;
float tuning;
UInt64 absTime;
int version;

Param * Params;
float generatedLevel;

Global::Global()
{
    Params = new Param[256];
    for(int i=0;i < 256;i++)
    {
        Params[i].id = i;
    }
    version = 1;
}


void Global::init(int sampleFrequenze)
{
    
    sampleFreq = sampleFrequenze;
    bank = 0;
    program = 0;
    morph = 0;
    param = new float[PARAMCOUNT];
    paramPatch = new float[PARAMCOUNT * PATCHCOUNT];
    curveTable = new float[CURVESAMPLES * CURVECOUNT];
    lfoTable = new float[LFOSAMPLES * LFOCOUNT ];
    waveTable = new float[WAVESAMPLES * WAVECOUNT];
    patchNames = new char[PATCHCOUNT * PATCHNAMEMAXLENGTH ];
    samples = new char[SUMPLEBUFFER];
    
    // default parameter
    for(int i=0;i < 64;i++)
    {
        param[i] = 0.78;
    }
    param[0] = 0.79; // masterVol
    param[1] = 0.5; // masterTune
    
    param[2] = 0.5; //oscVol0
    param[3] = 0.5; //oscVol1
    param[4] = 0.5; //oscVol2
    
    param[5] = 0 ; //oscType0
    param[6] = 1 ; //oscType1
    param[7] = 2 ; //oscType2
    
    param[8] = 5 ; //oscOct0
    param[9] = 5 ; //oscOct1
    param[10] = 5 ; //oscOct2
    
    param[11] = 0.5 ; // oscDetune0
    param[12] = 0.5 ; // oscDetune1
    param[13] = 0.5 ; // oscDetune2
    
    param[14] = 0 ; // oscSemtone0
    param[15] = 0 ; // oscSemtone1
    param[16] = 0 ; // oscSemtone2
    
    // 1, 50, 0.5, 0.5, 900)
    param[17] = 2 ; // adsr0 attack ms
    param[18] = 50 ; // adsr0 decay ms
    param[19] = 0.5 ; // adsr0 sustain level
    param[20] = 0.5 ; // adsr0 fade %
    param[21] = 900 ; // adsr0 release ms
}


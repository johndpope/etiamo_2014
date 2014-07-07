//
//  Global.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/3/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Global__
#define __EggTester__Global__

#include <iostream>
#include "Type.h"
#include "Param.h"
#include "math.h"

extern int sampleFreq;
extern char program;
extern int bank;
extern float morph;

extern float * param;
extern float * paramPatch;
extern float * curveTable;
extern float * lfoTable;
extern float * waveTable;
extern char * patchNames;
extern char * samples;

extern int fx0;
extern int fx1;
extern int fx2;

extern int midiChannel;
extern UInt64 absTime;

extern Param * Params;
extern int version;

extern float generatedLevel;

static float nlog (float base, float x)
{
    if(base == 0)
    {
        return 0;
    }
    return log (x) / log (base);
}

class Global {
    
    
public:
    Global();
    void init(int sampleFreq);
    
private:
};

#endif /* defined(__EggTester__Global__) */

//
//  ADSR.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/2/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__ADSR__
#define __EggTester__ADSR__

#include <iostream>

#include "Global.h"

using namespace std;

class ADSR {
    
public:
    
    ADSR(int id);
    
    int id;
    
    // output
    float level;
    
    // attack Setting
    
    // decay Setting
   // float decayTime;
    
    // release Setting
  //  float releaseTime;
    
    // sustain Setting
    //float sustainLevel;
    
    float sustainLevelArrived;
    
    // Fade Setting
  // float fade;
    
    // clocks
    float time;
    int releaseRelTime;
    
    // mode
    bool released;
    
    // Mido Note on
    void attack();
    
    // Midi note off
    void release();
    
    // returns true when the voice should be recycled
    bool tick();
    
    // gets output
    float get();

private:
   
};

#endif /* defined(__EggTester__ADSR__) */

//
//  Voice.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef EggTester_Voice_h
#define EggTester_Voice_h

#include "stdint.h"
#include "Oscillator.h"
#include "Type.h"
#include "ADSR.h"

class Voice
{
public:
    
    Oscillator * osc0;
    Oscillator * osc1;
    Oscillator * osc2;
    
    ADSR * adsrVCA;
    
    Voice()
    {
        osc0 = new Oscillator(0);
        osc1 = new Oscillator(1);
        osc2 = new Oscillator(2);
        
        adsrVCA = new ADSR(0);
        

        osc1->detune = 1.0;
        osc1->detune = 1.0;
        osc2->detune = 1.0;
    }
    
    void release()
    {
        adsrVCA->release();
    }
    
    void attack()
    {
        adsrVCA->attack();
        free = false;
    }
    
    UInt64 startTimeAbs;
    UInt64 startTimeRel;
    UInt64 releaseTimeRel;
    
    int midiNote;
    num freq0;
    num freq1;
    num freq2;
    
    int velocity;
    float volume;
    
    int group;
    
    bool free;
    bool released;
    bool sustainPedal;

};

#endif

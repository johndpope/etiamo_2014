//
//  Param.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/4/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Param__
#define __EggTester__Param__

#include <iostream>
#include "Type.h"

struct Param {
    int id;
    float val;
    float valScaled;
    
    char * name;
    bool type;
    
    float minHard;
    float maxHard;
    float minSoft;
    float maxSoft;
    float step;
    
    Byte midiMax;
    Byte unit;
    Byte usage;
    Byte widget;
    Byte deviders;
    Byte curve;
    Byte midiValue;
    
    Byte midiController;
    
    void setMidiVal(Byte midiVal)
    {
        midiValue = val;
        float delta = maxSoft - minSoft;
        setLevel( minSoft + midiVal * delta / 127.0 );
    }

    
    void setLevel(float val)
    {
        if(val < minSoft)
        {
            val = minSoft;
        }
        if(val > maxSoft)
        {
            val = maxSoft;
        }
        this->val = val;
        if(curve!=0)
        {
            //scale
            valScaled = val;
        }
        else
        {
            valScaled = val;
        }
    }
};
#endif /* defined(__EggTester__Param__) */

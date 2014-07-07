//
//  VoicePool.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__VoicePool__
#define __EggTester__VoicePool__

#include <iostream>
#include "Voice.h"

using namespace std;

class VoicePool
{
    public:

    VoicePool(int maxVoices);
    
    Voice * get();
    Voice * get(int midiNote);

    Voice * _voices;
    int _maxVoices;
    
    private:
    
};
#endif /* defined(__EggTester__VoicePool__) */

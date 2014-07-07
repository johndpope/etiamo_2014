//
//  VoicePool.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "VoicePool.h"

VoicePool::VoicePool(int maxVoices)
{
    _maxVoices = maxVoices;
    _voices = new Voice[maxVoices];
    for(int i=0;i<_maxVoices;++i)
    {
        _voices[i].free = true;
    }
}

Voice * VoicePool::get(){
    for(int i=0;i<_maxVoices;++i)
    {
        if(_voices[i].free)
        {
            _voices[i].attack();
            return &_voices[i];
        }
    }
    return &_voices[0];
}

Voice * VoicePool::get(int midiNote){
    Voice *v = 0;
    for(int i=0; i<_maxVoices; ++i)
    {
        if(_voices[i].midiNote == midiNote)
        {
            if(v==0) // return the first found and free all others
            {
                v = &_voices[i];
            }
            else
            {
                _voices[i].release();
            }
        }
    }
    return v;
}

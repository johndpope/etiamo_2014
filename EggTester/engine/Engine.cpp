//
//  Engine.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 6/30/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "Engine.h"

Engine* Engine::instance = NULL;

Engine* Engine::of()
{
    if(instance == NULL)
    {
        instance = new Engine();
        return instance;
    }
    else
    {
        return instance;
    }
}

Engine::Engine()
{
    lfoA = new LFO();
    filter0 = new Filter();
    generatedLevel = 0;
    logCounter = sampleFreq;
}

Engine::~Engine()
{
    
}

void Engine::init()
{
    _voicePool = new VoicePool(MAXVOICES);
    absTime = 0;
    
    freqTable = new float[127];
    for(int i=0; i < 127; ++i)
    {
        freqTable[i] =  pow(2, (i - 57) / 12.0);
    }
    
    lfoA->init(0, 3);
}

void Engine::setMidi(Byte a, Byte b, Byte c)
{
    if(a == 8) // NOTE OFF
    {
        Voice * voice = _voicePool->get(b);
        if(voice==0)
        {
            return; // voice not found
        }
        voice->release();
    }
    if(a == 9) // NOTE ON
    {
        Voice * voice = _voicePool->get();
        
        // velocity
        voice->velocity = c;
        voice->volume = c / 127.0;
        
        // tuning - pitch
        voice->midiNote = b;
        voice->freq0 = (10 * param[1] + 430.0) * freqTable[b + (int)param[14]];
        voice->freq1 = (10 * param[1] + 430.0) * freqTable[b + (int)param[15]];;
        voice->freq2 = (10 * param[1] + 430.0) * freqTable[b + (int)param[16]];
        
        voice->startTimeRel = 0;
        voice->startTimeAbs = absTime;
        voice->released = false;
        voice->sustainPedal = false;

        voice->osc0->phase = 0;
        voice->osc1->phase = 0;
        voice->osc2->phase = 0;

        voice->attack();
    }
}

void Engine::setOsc(string msg)
{
    
}

void Engine::render( float * buffer, int sampleCount)
{
    for (int i = 0; i < sampleCount ; i++)
    {
        buffer[i] = 0;
        
        for(int j=0; j<MAXVOICES; ++j)
        {
            Voice * voice = &_voicePool->_voices[j];
            
            if(!voice->free)
            {
                if(voice->adsrVCA->tick())
                {
                    voice->free = true;
                    continue;
                }
                
                buffer[i] +=
                
                // mix
                (  param[2] * voice->osc0->get(voice->freq0)
                +  param[3] * voice->osc1->get(voice->freq1)
                +  param[4] * voice->osc2->get(voice->freq2)  )
                
                // volume
                * param[0]
                
                // adsr
                * voice->adsrVCA->get();
            }
        }
        
        // filter
        buffer[i] =  filter0->process(buffer[i]);
        
        // mod
        lfoA->tick();
        float lfoMod = lfoA->level ;
        
        
        buffer[i] =  buffer[i] * lfoMod;
        float test = buffer[i];
        if(test < 0)
        {
            test =test * -1;
        }
        if(test > generatedLevel)
        {
            generatedLevel = test;
        }
       
        ++absTime;
        --logCounter;
        if(logCounter < 0)
        {
            logCounter = sampleFreq;
        }
    }
}

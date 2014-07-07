//
//  BankLoader.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/4/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__BankLoader__
#define __EggTester__BankLoader__

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Global.h"

#define DEFALTBANK "default.eti"

#define ETIAMOMIME .eti
#define BANKFILETYPE 1
#define MAGIC etia

#define BANK_MAGIC 0
#define BANK_VERSION 4
#define BANK_TYPE 6
#define BANK_PROGRAMLAST 7
#define BANK_LICENSE 8
#define BANK_COMPRESSION 12
#define BANK_LENGTH 16
#define BANK_CHECKSUM 20
#define BANK_PATCHDATA 24
#define BANK_TITLE 128 * 128 + BANK_PATCHDATA
#define BANK_INFO 128 * 16 + BANK_TITLE
#define BANK_WAVETABLE 8 * 16 + BANK_INFO

using namespace std;
/*
enum kAudioUnitParameterUnit {
    kAudioUnitParameterUnit_Generic             = 0,
    kAudioUnitParameterUnit_Indexed             = 1,
    kAudioUnitParameterUnit_Boolean             = 2,
    kAudioUnitParameterUnit_Percent             = 3,
    kAudioUnitParameterUnit_Seconds             = 4,
    kAudioUnitParameterUnit_SampleFrames        = 5,
    kAudioUnitParameterUnit_Phase               = 6,
    kAudioUnitParameterUnit_Rate                = 7,
    kAudioUnitParameterUnit_Hertz               = 8,
    kAudioUnitParameterUnit_Cents               = 9,
    kAudioUnitParameterUnit_RelativeSemiTones   = 10,
    kAudioUnitParameterUnit_MIDINoteNumber      = 11,
    kAudioUnitParameterUnit_MIDIController      = 12,
    kAudioUnitParameterUnit_Decibels            = 13,
    kAudioUnitParameterUnit_LinearGain          = 14,
    kAudioUnitParameterUnit_Degrees             = 15,
    kAudioUnitParameterUnit_EqualPowerCrossfade = 16,
    kAudioUnitParameterUnit_MixerFaderCurve1    = 17,
    kAudioUnitParameterUnit_Pan                 = 18,
    kAudioUnitParameterUnit_Meters              = 19,
    kAudioUnitParameterUnit_AbsoluteCents       = 20,
    kAudioUnitParameterUnit_Octaves             = 21,
    kAudioUnitParameterUnit_BPM                 = 22,
    kAudioUnitParameterUnit_Beats               = 23,
    kAudioUnitParameterUnit_Milliseconds        = 24,
    kAudioUnitParameterUnit_Ratio               = 25,
    kAudioUnitParameterUnit_CustomUnit          = 26
};
*/

/*
enum unitTypes
{
    UnitPercent,UnitSeconds,UnitPhase,UnitHertz,UnitDecibels,UnitDegrees,UnitMeters,UnitBPM,UnitMilliseconds
};
 */

const string units[] = {"%", "s", "°", "Hz", "dB", "°" , "m", "BPM", "ms"};

class BankLoader {
    
public:
    BankLoader(string path);
    void load(string name);
    void save(string name);
    string find();
    
    void loadPatch();
    void savePatch();
    
   

    
private:
    string synthRoot;
};

#endif /* defined(__EggTester__BankLoader__) */

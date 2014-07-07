//
//  Patch.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/3/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef __EggTester__Patch__
#define __EggTester__Patch__

#include <iostream>

#define PATCH_VOLUME 0
#define PATCH_TUNING 1
#define PATCH_BENDMIN 2
#define PATCH_BENDMAX 2

#define PATCH_OSC_WAVEFORM 10
#define PATCH_OSC_REGISTER 11
#define PATCH_OSC_SEMITONE 12
#define PATCH_OSC_FINETUNING 13
#define PATCH_OSC_SYMETRIE 14
#define PATCH_OSC_PULEMOD 15
#define PATCH_OSC_PULSEMODSPEED 16
#define PATCH_OSC_SUB 17
#define PATCH_OSC_SPREAD 18
#define PATCH_OSC_SYNC 19
#define PATCH_OSC_KEYFOLLOW 20
#define PATCH_OSC_FM 21
#define PATCH_OSC_LFO 22
#define PATCH_OSC_LFOSPEED 23

class Patch {
    
public:
    Patch();

    
private:
};
#endif /* defined(__EggTester__Patch__) */

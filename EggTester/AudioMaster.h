//
//  AudioMaster.c
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef EggTester_AudioMaster_h
#define EggTester_AudioMaster_h

#include <stdio.h>

#include <stdlib.h>
#include <math.h>

#include <AudioToolbox/AudioQueue.h>
#include <CoreAudio/CoreAudioTypes.h>
#include <CoreFoundation/CFRunLoop.h>
#include <ApplicationServices/ApplicationServices.h>
#include "Engine.h"


#define NUM_BUFFERS 3
#define BUFFER_SIZE 4096
#define SAMPLE_TYPE float
#define SAMPLE_RATE 44100
#define BYTESPERSAMPLE 4


extern Engine *_engine;


#pragma mark - forward declarations
void callback(void *custom_data, AudioQueueRef queue, AudioQueueBufferRef buffer);
int startAudio();


#endif



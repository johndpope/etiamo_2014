//
//  AudioMaster.mm
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "AudioMaster.h"

int bytesPerSample;
Engine * _engine;

int startAudio()
{
    _engine = Engine::of();
    _engine->init();
    
    bytesPerSample = sizeof(float);
    
    AudioStreamBasicDescription format = {0};
    AudioQueueRef queue;
    AudioQueueBufferRef buffers[NUM_BUFFERS];
    
    format.mSampleRate       = 44100;
    format.mFormatID         = kAudioFormatLinearPCM;
    format.mFormatFlags      = kAudioFormatFlagIsFloat | kAudioFormatFlagIsPacked;
    format.mBitsPerChannel = 8 * sizeof(float);
    format.mFramesPerPacket = 1;
    format.mChannelsPerFrame = 1;
    format.mBytesPerPacket = sizeof(float) * format.mFramesPerPacket;
    format.mBytesPerFrame = sizeof(float) * format.mChannelsPerFrame;
    format.mSampleRate = SAMPLE_RATE;
    
    AudioQueueNewOutput(&format, callback, NULL, CFRunLoopGetCurrent(), kCFRunLoopCommonModes, 0, &queue);
    
    for (int i = 0; i < NUM_BUFFERS; i++)
    {
        AudioQueueAllocateBuffer(queue, BUFFER_SIZE, &buffers[i]);
        buffers[i]->mAudioDataByteSize = BUFFER_SIZE;
        callback(NULL, queue, buffers[i]);
    }
	
    AudioQueueStart(queue, NULL);
    return 0;
}


// ------------------------------------------------------------------------------------------
void callback(void *custom_data, AudioQueueRef queue, AudioQueueBufferRef buffer)
{
    
    float *casted_buffer = (float *)buffer->mAudioData;
    int sampleCount = BUFFER_SIZE / bytesPerSample;
    _engine->render(casted_buffer, sampleCount);
    
    AudioQueueEnqueueBuffer(queue, buffer, 0, NULL);
    
}


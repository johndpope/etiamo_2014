//
//  MidiListener.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#ifndef EggTester_MidiListener_h
#define EggTester_MidiListener_h

#import <CoreMIDI/CoreMIDI.h>
#import <AudioUnit/AudioUnit.h>
#import <AudioToolbox/AudioToolbox.h>
#import "Model.h"
#import "AudioMaster.h"
#import "Engine.h"

#pragma mark - state struct
typedef struct MyMIDIPlayer {
	AUGraph		graph;
	AudioUnit	instrumentUnit;
} MyMIDIPlayer;

#pragma mark - forward declarations
void setupMIDI(MyMIDIPlayer *player);
void setupAUGraph(MyMIDIPlayer *player);
static void	MyMIDIReadProc(const MIDIPacketList *pktlist, void *refCon, void *connRefCon);
void MyMIDINotifyProc (const MIDINotification  *message, void *refCon);



#endif

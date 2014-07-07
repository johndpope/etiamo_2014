//
//  MidiListener.mm
//  EggTester
//
//  Created by Mathias Dietrich on 7/1/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "MidiListener.h"

#pragma mark utility functions
static void CheckError(OSStatus error, const char *operation)
{
	if (error == noErr) return;
	
	char str[20];
	// see if it appears to be a 4-char-code
	*(UInt32 *)(str + 1) = CFSwapInt32HostToBig(error);
	if (isprint(str[1]) && isprint(str[2]) && isprint(str[3]) && isprint(str[4])) {
		str[0] = str[5] = '\'';
		str[6] = '\0';
	} else
		// no, format it as an integer
		sprintf(str, "%d", (int)error);
	
	fprintf(stderr, "Error: %s (%s)\n", operation, str);
	
	exit(1);
}

void MyMIDINotifyProc (const MIDINotification  *message, void *refCon) {
	printf("MIDI Notify, messageId=%d,", message->messageID);
}

#pragma mark - callbacks
static void	MyMIDIReadProc(const MIDIPacketList *pktlist, void *refCon, void *connRefCon) {
    
	//MyMIDIPlayer *player = (MyMIDIPlayer*) refCon;
    
	MIDIPacket *packet = (MIDIPacket *)pktlist->packet;
	for (int i=0; i < pktlist->numPackets; i++) {
		Byte midiStatus = packet->data[0];
		Byte midiCommand = midiStatus >> 4;
        
		// is it a note-on or note-off
		if ((midiCommand == 0x09) || (midiCommand == 0x08)) {
			Byte note = packet->data[1] & 0x7F;
			Byte velocity = packet->data[2] & 0x7F;
            Engine::of()->setMidi(midiCommand, note, velocity);
            
			printf("MidiCommand=%d. Note=%d, Velocity=%d\n", midiCommand, note, velocity);
            NSString *msg = [NSString stringWithFormat:@"\nMidi: Cmd:%i,Nodte:%i,Vel:%i", midiCommand, note, velocity];
            
            // debug print midi note
            Model *model = Model.of;
            model.debugStr  = [model.debugStr stringByAppendingString: msg];
		}
		packet = MIDIPacketNext(packet);
	}
}

#pragma mark - midi
void setupMIDI(MyMIDIPlayer *player) {
	
	MIDIClientRef client;
	CheckError (MIDIClientCreate(CFSTR("Core MIDI to System Sounds Demo"), MyMIDINotifyProc, player, &client),
				"Couldn't create MIDI client");
	
	MIDIPortRef inPort;
	CheckError (MIDIInputPortCreate(client, CFSTR("Input port"), MyMIDIReadProc, player, &inPort),
				"Couldn't create MIDI input port");
	
	unsigned long sourceCount = MIDIGetNumberOfSources();
	printf ("%ld sources\n", sourceCount);
    
    NSMutableString* m0 = [[NSMutableString alloc] init];
    [m0 appendString: @"\nMidi device connected: "];
    
	for (int i = 0; i < sourceCount; ++i) {
		MIDIEndpointRef src = MIDIGetSource(i);
		CFStringRef endpointName = NULL;
        
		CheckError(MIDIObjectGetStringProperty(src, kMIDIPropertyName, &endpointName),
				   "Couldn't get endpoint name");
        
		char endpointNameC[255];
		CFStringGetCString(endpointName, endpointNameC,
                           255, kCFStringEncodingUTF8);
        
		printf("  source %d: %s\n", i, endpointNameC);
        
        
        NSString *m1 = [NSString stringWithCString:endpointNameC encoding:NSASCIIStringEncoding];
        
        [m0 appendString: m1];
        
    
		CheckError (MIDIPortConnectSource(inPort, src, NULL),
					"Couldn't connect MIDI port");
	}
    
    Model *model = Model.of;
    [model.debugStr  appendString: m0];
}




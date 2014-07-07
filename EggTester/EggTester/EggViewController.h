//
//  EggViewController.h
//  EggTester
//
//  Created by Mathias Dietrich on 6/29/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Model.h"
#import "AUGraphController.h"
#import "Engine.h"
#import "MidiListener.h"
#include "BankLoader.h"
#include <string>
#import "MyView.h"

@interface EggViewController : NSViewController<NSTabViewDelegate> {

    IBOutlet NSBox *transport;
    IBOutlet MyView * myView;
    IBOutlet AUGraphController *graphController;
    IBOutlet NSTextView *debugView;
    IBOutlet NSButton *btnStartGraph;
    IBOutlet NSSlider *volOut;
    IBOutlet NSTextField *lblVolOut;
    IBOutlet NSLevelIndicator *levelOut;
    
    IBOutlet NSSlider *slider0;
    IBOutlet NSSlider *slider1;
    IBOutlet NSSlider *slider2;
    IBOutlet NSSlider *slider3;
    IBOutlet NSSlider *slider4;
    IBOutlet NSSlider *slider5;
    IBOutlet NSSlider *slider6;
    IBOutlet NSSlider *slider7;
    IBOutlet NSSlider *slider8;
    IBOutlet NSSlider *slider9;
    IBOutlet NSSlider *slider10;
    IBOutlet NSSlider *slider11;
    IBOutlet NSSlider *slider12;
    IBOutlet NSSlider *slider13;
    IBOutlet NSSlider *slider14;
    IBOutlet NSSlider *slider15;
    IBOutlet NSSlider *slider16;
    IBOutlet NSSlider *slider17;
    IBOutlet NSSlider *slider18;
    IBOutlet NSSlider *slider19;
    IBOutlet NSSlider *slider20;
    IBOutlet NSSlider *slider21;
    IBOutlet NSSlider *slider22;
    IBOutlet NSSlider *slider23;
    IBOutlet NSSlider *slider24;
    IBOutlet NSSlider *slider25;
    IBOutlet NSSlider *slider26;
    IBOutlet NSSlider *slider27;
    IBOutlet NSSlider *slider28;
    IBOutlet NSSlider *slider29;
    IBOutlet NSSlider *slider30;
    IBOutlet NSSlider *slider31;
    IBOutlet NSSlider *slider32;
    IBOutlet NSSlider *slider33;
    IBOutlet NSSlider *slider34;
    IBOutlet NSSlider *slider35;
    IBOutlet NSSlider *slider36;
    IBOutlet NSSlider *slider37;
    IBOutlet NSSlider *slider38;
    IBOutlet NSSlider *slider39;
    IBOutlet NSSlider *slider40;
    IBOutlet NSSlider *slider41;
    IBOutlet NSSlider *slider42;
    IBOutlet NSSlider *slider43;
    IBOutlet NSSlider *slider44;
    IBOutlet NSSlider *slider45;
    IBOutlet NSSlider *slider46;
    IBOutlet NSSlider *slider47;

    IBOutlet NSTextField *label0;
    IBOutlet NSTextField *label1;
    IBOutlet NSTextField *label2;
    IBOutlet NSTextField *label3;
    IBOutlet NSTextField *label4;
    IBOutlet NSTextField *label5;
    IBOutlet NSTextField *label6;
    IBOutlet NSTextField *label7;
    IBOutlet NSTextField *label8;
    IBOutlet NSTextField *label9;
    IBOutlet NSTextField *label10;
    IBOutlet NSTextField *label11;
    IBOutlet NSTextField *label12;
    IBOutlet NSTextField *label13;
    IBOutlet NSTextField *label14;
    IBOutlet NSTextField *label15;
    IBOutlet NSTextField *label16;
    IBOutlet NSTextField *label17;
    IBOutlet NSTextField *label18;
    IBOutlet NSTextField *label19;
    IBOutlet NSTextField *label20;
    IBOutlet NSTextField *label21;
    IBOutlet NSTextField *label22;
    IBOutlet NSTextField *label23;
    IBOutlet NSTextField *label24;
    IBOutlet NSTextField *label25;
    IBOutlet NSTextField *label26;
    IBOutlet NSTextField *label27;
    IBOutlet NSTextField *label28;
    IBOutlet NSTextField *label29;
    IBOutlet NSTextField *label30;
    IBOutlet NSTextField *label31;
    IBOutlet NSTextField *label32;
    IBOutlet NSTextField *label33;
    IBOutlet NSTextField *label34;
    IBOutlet NSTextField *label35;
    IBOutlet NSTextField *label36;
    IBOutlet NSTextField *label37;
    IBOutlet NSTextField *label38;
    IBOutlet NSTextField *label39;
    IBOutlet NSTextField *label40;
    IBOutlet NSTextField *label41;
    IBOutlet NSTextField *label42;
    IBOutlet NSTextField *label43;
    IBOutlet NSTextField *label44;
    IBOutlet NSTextField *label45;
    IBOutlet NSTextField *label46;
    IBOutlet NSTextField *label47;
    IBOutlet NSTextField *labelPatch;
    IBOutlet NSButton *btnUp;
    IBOutlet NSButton *btnDown;
    
    IBOutlet NSLevelIndicator *genLevel;
    
    IBOutlet NSTabView *tabView;
    
    NSTimer *timer;
    Engine *engine;
    BankLoader *bankLoader;
}

@property (nonatomic, assign)   NSBox *transport;
@property (nonatomic, assign)  MyView * myView;
@property (nonatomic, assign) AUGraphController *graphController;
@property (nonatomic, assign) NSTextView *debugView;
@property (nonatomic, assign) NSButton *btnStartGraph;
@property (nonatomic, assign) NSSlider *volOut;
@property (nonatomic, assign) NSTextField *lblVolOut;
@property (nonatomic, assign) NSLevelIndicator *levelOut;
@property (nonatomic, assign) Engine *engine;
@property (nonatomic, assign) BankLoader *bankLoader;

@property (nonatomic, assign) NSSlider *slider0;
@property (nonatomic, assign) NSSlider *slider1;
@property (nonatomic, assign) NSSlider *slider2;
@property (nonatomic, assign) NSSlider *slider3;
@property (nonatomic, assign) NSSlider *slider4;
@property (nonatomic, assign) NSSlider *slider5;
@property (nonatomic, assign) NSSlider *slider6;
@property (nonatomic, assign) NSSlider *slider7;
@property (nonatomic, assign) NSSlider *slider8;
@property (nonatomic, assign) NSSlider *slider9;
@property (nonatomic, assign) NSSlider *slider10;
@property (nonatomic, assign) NSSlider *slider11;
@property (nonatomic, assign) NSSlider *slider12;
@property (nonatomic, assign) NSSlider *slider13;
@property (nonatomic, assign) NSSlider *slider14;
@property (nonatomic, assign) NSSlider *slider15;
@property (nonatomic, assign) NSSlider *slider16;
@property (nonatomic, assign) NSSlider *slider17;
@property (nonatomic, assign) NSSlider *slider18;
@property (nonatomic, assign) NSSlider *slider19;
@property (nonatomic, assign) NSSlider *slider20;
@property (nonatomic, assign) NSSlider *slider21;
@property (nonatomic, assign) NSSlider *slider22;
@property (nonatomic, assign) NSSlider *slider23;
@property (nonatomic, assign) NSSlider *slider24;
@property (nonatomic, assign) NSSlider *slider25;
@property (nonatomic, assign) NSSlider *slider26;
@property (nonatomic, assign) NSSlider *slider27;
@property (nonatomic, assign) NSSlider *slider28;
@property (nonatomic, assign) NSSlider *slider29;
@property (nonatomic, assign) NSSlider *slider30;
@property (nonatomic, assign) NSSlider *slider31;
@property (nonatomic, assign) NSSlider *slider32;
@property (nonatomic, assign) NSSlider *slider33;
@property (nonatomic, assign) NSSlider *slider34;
@property (nonatomic, assign) NSSlider *slider35;
@property (nonatomic, assign) NSSlider *slider36;
@property (nonatomic, assign) NSSlider *slider37;
@property (nonatomic, assign) NSSlider *slider38;
@property (nonatomic, assign) NSSlider *slider39;
@property (nonatomic, assign) NSSlider *slider40;
@property (nonatomic, assign) NSSlider *slider41;
@property (nonatomic, assign) NSSlider *slider42;
@property (nonatomic, assign) NSSlider *slider43;
@property (nonatomic, assign) NSSlider *slider44;
@property (nonatomic, assign) NSSlider *slider45;
@property (nonatomic, assign) NSSlider *slider46;
@property (nonatomic, assign) NSSlider *slider47;

@property (nonatomic, assign) NSTextField *label0;
@property (nonatomic, assign) NSTextField *label1;
@property (nonatomic, assign) NSTextField *label2;
@property (nonatomic, assign) NSTextField *label3;
@property (nonatomic, assign) NSTextField *label4;
@property (nonatomic, assign) NSTextField *label5;
@property (nonatomic, assign) NSTextField *label6;
@property (nonatomic, assign) NSTextField *label7;
@property (nonatomic, assign) NSTextField *label8;
@property (nonatomic, assign) NSTextField *label9;
@property (nonatomic, assign) NSTextField *label10;
@property (nonatomic, assign) NSTextField *label11;
@property (nonatomic, assign) NSTextField *label12;
@property (nonatomic, assign) NSTextField *label13;
@property (nonatomic, assign) NSTextField *label14;
@property (nonatomic, assign) NSTextField *label15;
@property (nonatomic, assign) NSTextField *label16;
@property (nonatomic, assign) NSTextField *label17;
@property (nonatomic, assign) NSTextField *label18;
@property (nonatomic, assign) NSTextField *label19;
@property (nonatomic, assign) NSTextField *label20;
@property (nonatomic, assign) NSTextField *label21;
@property (nonatomic, assign) NSTextField *label22;
@property (nonatomic, assign) NSTextField *label23;
@property (nonatomic, assign) NSTextField *label24;
@property (nonatomic, assign) NSTextField *label25;
@property (nonatomic, assign) NSTextField *label26;
@property (nonatomic, assign) NSTextField *label27;
@property (nonatomic, assign) NSTextField *label28;
@property (nonatomic, assign) NSTextField *label29;
@property (nonatomic, assign) NSTextField *label30;
@property (nonatomic, assign) NSTextField *label31;
@property (nonatomic, assign) NSTextField *label32;
@property (nonatomic, assign) NSTextField *label33;
@property (nonatomic, assign) NSTextField *label34;
@property (nonatomic, assign) NSTextField *label35;
@property (nonatomic, assign) NSTextField *label36;
@property (nonatomic, assign) NSTextField *label37;
@property (nonatomic, assign) NSTextField *label38;
@property (nonatomic, assign) NSTextField *label39;
@property (nonatomic, assign) NSTextField *label40;
@property (nonatomic, assign) NSTextField *label41;
@property (nonatomic, assign) NSTextField *label42;
@property (nonatomic, assign) NSTextField *label43;
@property (nonatomic, assign) NSTextField *label44;
@property (nonatomic, assign) NSTextField *label45;
@property (nonatomic, assign) NSTextField *label46;
@property (nonatomic, assign) NSTextField *label47;
@property (nonatomic, assign) NSTextField *labelPatch;
@property (nonatomic, assign) NSButton *btnUp;
@property (nonatomic, assign) NSButton *btnDown;
@property (nonatomic, assign) NSLevelIndicator *genLevel;
@property (nonatomic, assign)  NSTabView *tabView;

- (IBAction) startGraph : (id) sender;
- (IBAction) clearDebug : (id) sender;
- (IBAction) setMeter: (id) sender;

- (IBAction)volumeValueChanged:(NSSlider *)sender;

- (IBAction) slider0:(NSSlider *)sender;
- (IBAction) slider1:(NSSlider *)sender;
- (IBAction) slider2:(NSSlider *)sender;
- (IBAction) slider3:(NSSlider *)sender;
- (IBAction) slider4:(NSSlider *)sender;
- (IBAction) slider5:(NSSlider *)sender;
- (IBAction) slider6:(NSSlider *)sender;
- (IBAction) slider7:(NSSlider *)sender;
- (IBAction) slider8:(NSSlider *)sender;
- (IBAction) slider9:(NSSlider *)sender;
- (IBAction) slider10:(NSSlider *)sender;
- (IBAction) slider11:(NSSlider *)sender;
- (IBAction) slider12:(NSSlider *)sender;
- (IBAction) slider13:(NSSlider *)sender;
- (IBAction) slider14:(NSSlider *)sender;
- (IBAction) slider15:(NSSlider *)sender;
- (IBAction) slider16:(NSSlider *)sender;
- (IBAction) slider17:(NSSlider *)sender;
- (IBAction) slider18:(NSSlider *)sender;
- (IBAction) slider19:(NSSlider *)sender;
- (IBAction) slider20:(NSSlider *)sender;
- (IBAction) slider21:(NSSlider *)sender;
- (IBAction) slider22:(NSSlider *)sender;
- (IBAction) slider23:(NSSlider *)sender;
- (IBAction) slider24:(NSSlider *)sender;
- (IBAction) slider25:(NSSlider *)sender;
- (IBAction) slider26:(NSSlider *)sender;
- (IBAction) slider27:(NSSlider *)sender;
- (IBAction) slider28:(NSSlider *)sender;
- (IBAction) slider29:(NSSlider *)sender;
- (IBAction) slider30:(NSSlider *)sender;
- (IBAction) slider31:(NSSlider *)sender;
- (IBAction) slider32:(NSSlider *)sender;
- (IBAction) slider33:(NSSlider *)sender;
- (IBAction) slider34:(NSSlider *)sender;
- (IBAction) slider35:(NSSlider *)sender;
- (IBAction) slider36:(NSSlider *)sender;
- (IBAction) slider37:(NSSlider *)sender;
- (IBAction) slider38:(NSSlider *)sender;
- (IBAction) slider39:(NSSlider *)sender;
- (IBAction) slider40:(NSSlider *)sender;
- (IBAction) slider41:(NSSlider *)sender;
- (IBAction) slider42:(NSSlider *)sender;
- (IBAction) slider43:(NSSlider *)sender;
- (IBAction) slider44:(NSSlider *)sender;
- (IBAction) slider45:(NSSlider *)sender;
- (IBAction) slider46:(NSSlider *)sender;
- (IBAction) slider47:(NSSlider *)sender;

- (IBAction) save:(NSButton *)sender;
- (IBAction) load:(NSButton *)sender;

- (IBAction) up:(NSButton *)sender;
- (IBAction) down:(NSButton *)sender;

- (IBAction) playA:(NSButton *)sender;
- (IBAction) playC:(NSButton *)sender;
- (IBAction) playA2:(NSButton *)sender;
- (IBAction) playC2:(NSButton *)sender;

-(void) setFader;
- (BOOL)tabView:(NSTabView *)tabView shouldSelectTabViewItem:(NSTabViewItem *)tabViewItem;
@end



//
//  EggViewController.m
//  EggTester
//
//  Created by Mathias Dietrich on 6/29/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import "EggViewController.h"
#import "AudioMaster.h"

@implementation EggViewController;

@synthesize transport;
@synthesize myView;
@synthesize graphController;
@synthesize debugView;
@synthesize btnStartGraph;
@synthesize volOut;
@synthesize lblVolOut;
@synthesize levelOut;
@synthesize engine;
@synthesize bankLoader;

@synthesize slider0;
@synthesize slider1;
@synthesize slider2;
@synthesize slider3;
@synthesize slider4;
@synthesize slider5;
@synthesize slider6;
@synthesize slider7;
@synthesize slider8;
@synthesize slider9;
@synthesize slider10;
@synthesize slider11;
@synthesize slider12;
@synthesize slider13;
@synthesize slider14;
@synthesize slider15;
@synthesize slider16;
@synthesize slider17;
@synthesize slider18;
@synthesize slider19;
@synthesize slider20;
@synthesize slider21;
@synthesize slider22;
@synthesize slider23;
@synthesize slider24;
@synthesize slider25;
@synthesize slider26;
@synthesize slider27;
@synthesize slider28;
@synthesize slider29;
@synthesize slider30;
@synthesize slider31;
@synthesize slider32;
@synthesize slider33;
@synthesize slider34;
@synthesize slider35;
@synthesize slider36;
@synthesize slider37;
@synthesize slider38;
@synthesize slider39;
@synthesize slider40;
@synthesize slider41;
@synthesize slider42;
@synthesize slider43;
@synthesize slider44;
@synthesize slider45;
@synthesize slider46;
@synthesize slider47;

@synthesize label0;
@synthesize label1;
@synthesize label2;
@synthesize label3;
@synthesize label4;
@synthesize label5;
@synthesize label6;
@synthesize label7;
@synthesize label8;
@synthesize label9;
@synthesize label10;
@synthesize label11;
@synthesize label12;
@synthesize label13;
@synthesize label14;
@synthesize label15;
@synthesize label16;
@synthesize label17;
@synthesize label18;
@synthesize label19;
@synthesize label20;
@synthesize label21;
@synthesize label22;
@synthesize label23;
@synthesize label24;
@synthesize label25;
@synthesize label26;
@synthesize label27;
@synthesize label28;
@synthesize label29;
@synthesize label30;
@synthesize label31;
@synthesize label32;
@synthesize label33;
@synthesize label34;
@synthesize label35;
@synthesize label36;
@synthesize label37;
@synthesize label38;
@synthesize label39;
@synthesize label40;
@synthesize label41;
@synthesize label42;
@synthesize label43;
@synthesize label44;
@synthesize label45;
@synthesize label46;
@synthesize label47;
@synthesize labelPatch;
@synthesize btnUp;
@synthesize btnDown;
@synthesize genLevel;
@synthesize tabView;
// UI Refresh
-(void) tick
{
    Model *model = Model.of;
    [debugView setString:  [NSString stringWithString: model.debugStr]];
    [genLevel setFloatValue: generatedLevel];
    
    // peek meter release
    generatedLevel *= 0.9;
    if(generatedLevel <0.000000001)
    {
        generatedLevel = 0;
    }
    [self setFader];
    [myView setNeedsDisplay:YES];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {

    }
    return self;
}

+(void) addDebug: (NSString *)msg
{
    Model *model = Model.of;
    [model.debugStr stringByAppendingString:msg];
}

- (void)awakeFromNib
{
    [tabView setDelegate: self];
    
    Global *g = new Global();
    g->init(44100);
    
    WaveTable::of()->init();
    
    Model *model = Model.of;
    [debugView insertText:model.debugStr ];
    
    //NSString *appFolderPath = [[NSBundle mainBundle] resourcePath];
   // std::string *path = new std::string([appFolderPath UTF8String]);
    string root = "/Users/mathiasdietrich/etiamo/";
    bankLoader = new BankLoader(root);
    bankLoader->load(DEFALTBANK);
    
    engine = Engine::of();
    engine->init();
    
    [self setFader];
    
    MyMIDIPlayer player;
	setupMIDI(&player);
   
    startAudio();
    [NSThread setThreadPriority:0.1];
    
    timer = [NSTimer scheduledTimerWithTimeInterval:0.1
                                             target:self
                                           selector:@selector(tick)
                                           userInfo:NULL
                                            repeats:YES];
}

-(void) setFader
{
    slider0.intValue =  param[0] * 127;
    [label0 setIntegerValue: param[0] * 127];
    
    slider1.intValue =  param[1] * 127;
    [label1 setIntegerValue: param[1] * 127];
    
    slider2.intValue =  param[2] * 127;
    [label2 setIntegerValue: param[2] * 127];
    
    slider3.intValue =  param[3] * 127;
    [label3 setIntegerValue: param[3] * 127];
    
    slider4.intValue =  param[4] * 127;
    [label4 setIntegerValue: param[4] * 127];
    
    slider5.intValue =  param[5] ;
    [label5 setIntegerValue: param[5]];
    
    slider6.intValue =  param[6] ;
    [label6 setIntegerValue: param[6]];
    
    slider7.intValue =  param[7] ;
    [label7 setIntegerValue: param[7]];
    
    slider8.intValue =  param[8] ;
    [label8 setIntegerValue: param[8]];
    
    slider9.intValue =  param[9] ;
    [label9 setIntegerValue: param[9] ];
    
    slider10.intValue =  param[10] ;
    [label10 setIntegerValue: param[10]];
    
    slider11.floatValue =  param[11] ;
    [label11 setFloatValue: param[11] ];
    
    slider12.floatValue =  param[12] ;
    [label12 setFloatValue: param[12] ];
    
    slider13.floatValue =  param[13] ;
    [label13 setFloatValue: param[13] ];
    
    slider14.intValue =  param[14] * 127;
    [label14 setIntegerValue: param[14] * 127];
    
    slider15.intValue =  param[15] * 127;
    [label15 setIntegerValue: param[15] * 127];
    
    slider16.intValue =  param[16] * 127;
    [label16 setIntegerValue: param[16] * 127];
    
    slider17.intValue =  param[17] * 127;
    [label17 setIntegerValue: param[17] * 127];
    
    slider18.intValue =  param[18] * 127;
    [label18 setIntegerValue: param[18] * 127];
    
    slider19.floatValue =  param[19];
    [label19 setFloatValue: param[19]];
    
    slider20.floatValue =  param[20] ;
    [label20 setFloatValue: param[20] ];
    
    slider21.intValue =  param[21] * 127;
    [label21 setIntegerValue: param[21] * 127];
    
    slider22.intValue =  param[22] * 127;
    [label22 setIntegerValue: param[22] * 127];
    
    slider23.intValue =  param[23] * 127;
    [label23 setIntegerValue: param[23] * 127];
    
    slider24.intValue =  param[24] * 127;
    [label24 setIntegerValue: param[24] * 127];
    
    slider25.intValue =  param[25] * 127;
    [label25 setIntegerValue: param[25] * 127];
    
    slider26.intValue =  param[26] * 127;
    [label26 setIntegerValue: param[26] * 127];
    
    slider27.intValue =  param[27] * 127;
    [label27 setIntegerValue: param[27] * 127];
    
    slider28.intValue =  param[28] * 127;
    [label28 setIntegerValue: param[28] * 127];
    
    slider29.intValue =  param[29] * 127;
    [label29 setIntegerValue: param[29] * 127];
    
    slider30.intValue =  param[30] * 127;
    [label30 setIntegerValue: param[30] * 127];
    
    slider31.intValue =  param[31] * 127;
    [label31 setIntegerValue: param[31] * 127];
    
    slider32.intValue =  param[32] * 127;
    [label32 setIntegerValue: param[32] * 127];
    
    slider33.intValue =  param[33] * 127;
    [label33 setIntegerValue: param[33] * 127];
    
    slider34.intValue =  param[34] * 127;
    [label34 setIntegerValue: param[34] * 127];
    
    slider35.intValue =  param[35] * 127;
    [label35 setIntegerValue: param[35] * 127];
    
    slider36.intValue =  param[36] * 127;
    [label36 setIntegerValue: param[36] * 127];
    
    slider37.intValue =  param[37] * 127;
    [label37 setIntegerValue: param[37] * 127];
    
    slider38.intValue =  param[38] * 127;
    [label38 setIntegerValue: param[38] * 127];
    
    slider39.intValue =  param[39] * 127;
    [label39 setIntegerValue: param[39] * 127];
    
    slider40.intValue =  param[04] * 127;
    [label40 setIntegerValue: param[40] * 127];
    
    slider41.intValue =  param[41] * 127;
    [label41 setIntegerValue: param[41] * 127];
    
    slider42.intValue =  param[42] * 127;
    [label42 setIntegerValue: param[42] * 127];
    
    slider43.intValue =  param[43] * 127;
    [label43 setIntegerValue: param[43] * 127];
    
    slider44.intValue =  param[44] * 127;
    [label44 setIntegerValue: param[44] * 127];
    
    slider45.intValue =  param[45] * 127;
    [label45 setIntegerValue: param[45] * 127];
    
    slider46.intValue =  param[46] * 127;
    [label46 setIntegerValue: param[46] * 127];
    
    slider47.intValue =  param[47] * 127;
    [label47 setIntegerValue: param[47] * 127];
    
    [labelPatch setIntegerValue:program];
}

- (IBAction)volumeValueChanged:(NSSlider *)sender {
    
    int  val = [sender intValue];
    [graphController setOutputVolume: ( (float)val) / 127.0f];
    [lblVolOut setStringValue: [NSString stringWithFormat:@"%d", val]];
}

- (IBAction)setMeter: (id) sender
{
    Float32 v =  [graphController getMeterLevel];
    [levelOut setFloatValue: v];
}

- (IBAction) startGraph : (id) sender
{
    //Model *model = Model.of;
    /*
    model.isGrapRunning = ! model.isGrapRunning;
    
    model.debugStr = @"Graph stopped";
    if( model.isGrapRunning)
    {
        [graphController initializeAUGraph:kGraphSampleRate];
        
        [graphController enableInput:0 isOn:1];
        
        [graphController setInputVolume: 0 value:0.5f];
        [graphController setOutputVolume: 0.5f];
        
        [graphController runAUGraph];
        
         model.debugStr = @"Graph started";
        [btnStartGraph setTitle:@"Stop Graph"];
    }
    else
    {
         [graphController stopAUGraph];
         [btnStartGraph setTitle:@"Start Graph"];
    }
    
    [debugView insertText: @"\n"];
    [debugView insertText:model.debugStr ];
     */
}

- (IBAction) clearDebug : (id) sender
{
    Model *model = Model.of;
    [model.debugStr setString:@""];
    [debugView setString: @"\n"];
}

- (IBAction) slider0:(NSSlider *)sender
{
    param[0] = sender.intValue / 127.0;
    [label0 setIntegerValue: sender.intValue];
}
- (IBAction) slider1:(NSSlider *)sender
{
    param[1] = sender.intValue / 127.0;
    [label1 setIntegerValue: sender.intValue];
}
- (IBAction) slider2:(NSSlider *)sender
{
    param[2] = sender.intValue / 127.0;
    [label2 setIntegerValue: sender.intValue];
}
- (IBAction) slider3:(NSSlider *)sender
{
    param[3] = sender.intValue / 127.0;
    [label3 setIntegerValue: sender.intValue];
}
- (IBAction) slider4:(NSSlider *)sender
{
    param[4] = sender.intValue / 127.0;
    [label4 setIntegerValue: sender.intValue];
}
- (IBAction) slider5:(NSSlider *)sender
{
    param[5] = sender.intValue ;
    [label5 setIntegerValue: sender.intValue];
}
- (IBAction) slider6:(NSSlider *)sender
{
    param[6] = sender.intValue ;
    [label6 setIntegerValue: sender.intValue];
}
- (IBAction) slider7:(NSSlider *)sender
{
    param[7] = sender.intValue ;
    [label7 setIntegerValue: sender.intValue];
}
- (IBAction) slider8:(NSSlider *)sender
{
    param[8] = sender.intValue;
    [label8 setIntegerValue: sender.intValue];
}
- (IBAction) slider9:(NSSlider *)sender
{
    param[9] = sender.intValue;
    [label9 setIntegerValue: sender.intValue];
}
- (IBAction) slider10:(NSSlider *)sender
{
    param[10] = sender.intValue ;
    [label10 setIntegerValue: sender.intValue];
}
- (IBAction) slider11:(NSSlider *)sender
{
    param[11] = sender.floatValue ;
    [label11 setFloatValue: sender.floatValue];
}
- (IBAction) slider12:(NSSlider *)sender
{
    param[12] = sender.floatValue ;
    [label12 setFloatValue: sender.floatValue];
}
- (IBAction) slider13:(NSSlider *)sender
{
    param[13] = sender.floatValue ;
    [label13 setFloatValue: sender.floatValue];
}
- (IBAction) slider14:(NSSlider *)sender
{
    param[14] = sender.intValue ;
    [label14 setIntegerValue: sender.intValue];
}
- (IBAction) slider15:(NSSlider *)sender
{
    param[15] = sender.intValue ;
    [label15 setIntegerValue: sender.intValue];
}
- (IBAction) slider16:(NSSlider *)sender
{
    param[16] = sender.intValue ;
    [label16 setIntegerValue: sender.intValue];
}
- (IBAction) slider17:(NSSlider *)sender
{
    param[17] = sender.intValue / 127.0;
    [label17 setIntegerValue: sender.intValue];
}
- (IBAction) slider18:(NSSlider *)sender
{
    param[18] = sender.intValue / 127.0;
    [label18 setIntegerValue: sender.intValue];
}
- (IBAction) slider19:(NSSlider *)sender
{
    param[19] = sender.floatValue;
    [label19 setFloatValue: sender.floatValue];
}
- (IBAction) slider20:(NSSlider *)sender
{
    param[20] = sender.floatValue;
    [label20 setFloatValue: sender.floatValue];
}
- (IBAction) slider21:(NSSlider *)sender
{
    param[21] = sender.intValue / 127.0;
    [label21 setIntegerValue: sender.intValue];
}
- (IBAction) slider22:(NSSlider *)sender
{
    param[22] = sender.intValue / 127.0;
    [label22 setIntegerValue: sender.intValue];
}
- (IBAction) slider23:(NSSlider *)sender
{
    param[23] = sender.intValue / 127.0;
    [label23 setIntegerValue: sender.intValue];
}
- (IBAction) slider24:(NSSlider *)sender
{
    param[24] = sender.intValue / 127.0;
    [label24 setIntegerValue: sender.intValue];
}
- (IBAction) slider25:(NSSlider *)sender
{
    param[25] = sender.intValue / 127.0;
    [label25 setIntegerValue: sender.intValue];
}
- (IBAction) slider26:(NSSlider *)sender
{
    param[26] = sender.intValue / 127.0;
    [label26 setIntegerValue: sender.intValue];
}
- (IBAction) slider27:(NSSlider *)sender
{
    param[27] = sender.intValue / 127.0;
    [label27 setIntegerValue: sender.intValue];
}
- (IBAction) slider28:(NSSlider *)sender
{
    param[28] = sender.intValue / 127.0;
    [label28 setIntegerValue: sender.intValue];
}
- (IBAction) slider29:(NSSlider *)sender
{
    param[29] = sender.intValue / 127.0;
    [label29 setIntegerValue: sender.intValue];
}
- (IBAction) slider30:(NSSlider *)sender
{
    param[30] = sender.intValue / 127.0;
    [label30 setIntegerValue: sender.intValue];
}
- (IBAction) slider31:(NSSlider *)sender
{
    param[31] = sender.intValue / 127.0;
    [label31 setIntegerValue: sender.intValue];
}
- (IBAction) slider32:(NSSlider *)sender
{
    param[32] = sender.intValue / 127.0;
    [label32 setIntegerValue: sender.intValue];
}
- (IBAction) slider33:(NSSlider *)sender
{
    param[33] = sender.intValue / 127.0;
    [label33 setIntegerValue: sender.intValue];
}
- (IBAction) slider34:(NSSlider *)sender
{
    param[34] = sender.intValue / 127.0;
    [label34 setIntegerValue: sender.intValue];
}
- (IBAction) slider35:(NSSlider *)sender
{
    param[35] = sender.intValue / 127.0;
    [label35 setIntegerValue: sender.intValue];
}
- (IBAction) slider36:(NSSlider *)sender
{
    param[36] = sender.intValue / 127.0;
    [label36 setIntegerValue: sender.intValue];
}
- (IBAction) slider37:(NSSlider *)sender
{
    param[37] = sender.intValue / 127.0;
    [label37 setIntegerValue: sender.intValue];
}
- (IBAction) slider38:(NSSlider *)sender
{
    param[38] = sender.intValue / 127.0;
    [label38 setIntegerValue: sender.intValue];
}
- (IBAction) slider39:(NSSlider *)sender
{
    param[39] = sender.intValue / 127.0;
    [label39 setIntegerValue: sender.intValue];
}
- (IBAction) slider40:(NSSlider *)sender
{
    param[40] = sender.intValue / 127.0;
    [label40 setIntegerValue: sender.intValue];
}
- (IBAction) slider41:(NSSlider *)sender
{
    param[41] = sender.intValue / 127.0;
    [label41 setIntegerValue: sender.intValue];
}
- (IBAction) slider42:(NSSlider *)sender
{
    param[42] = sender.intValue / 127.0;
    [label42 setIntegerValue: sender.intValue];
}
- (IBAction) slider43:(NSSlider *)sender
{
    param[43] = sender.intValue / 127.0;
    [label43 setIntegerValue: sender.intValue];
}
- (IBAction) slider44:(NSSlider *)sender
{
    param[44] = sender.intValue / 127.0;
    [label44 setIntegerValue: sender.intValue];
}
- (IBAction) slider45:(NSSlider *)sender
{
    param[45] = sender.intValue / 127.0;
    [label45 setIntegerValue: sender.intValue];
}
- (IBAction) slider46:(NSSlider *)sender
{
    param[46] = sender.intValue / 127.0;
    [label46 setIntegerValue: sender.intValue];
}
- (IBAction) slider47:(NSSlider *)sender
{
    param[47] = sender.intValue / 127.0;
    [label47 setIntegerValue: sender.intValue];
}

- (IBAction) save:(NSButton *)sender
{
    bankLoader->save(DEFALTBANK);
}

- (IBAction) load:(NSButton *)sender
{
     bankLoader->load(DEFALTBANK);
    [self setFader];
}

- (IBAction) up:(NSButton *)sender
{
   // bankLoader->savePatch();
   if( program<126)
   {
       ++program;
       bankLoader->loadPatch();
       [self setFader];
   }
}
- (IBAction) down:(NSButton *)sender
{
   //  bankLoade->savePatch();
    if( program>0)
    {
        --program;
        bankLoader->loadPatch();
        [self setFader];
    }
}

- (IBAction) playA:(NSButton *)sender
{
    engine->setMidi(9, 57, 100);
}
- (IBAction) playC:(NSButton *)sender
{
    engine->setMidi(9, 60, 100);
}
- (IBAction) playA2:(NSButton *)sender
{
    engine->setMidi(8, 57, 100);
}
- (IBAction) playC2:(NSButton *)sender
{
    engine->setMidi(8, 60, 100);
}

- (void)tabView:(NSTabView *)tabView willSelectTabViewItem:(NSTabViewItem *)tabViewItem
{
    if([tabViewItem.identifier isEqualToString:@"4"])
    {
        [transport setHidden:YES];
    }
    else
    {
         [transport setHidden:NO];
    }
}

- (BOOL)tabView:(NSTabView *)tabView shouldSelectTabViewItem:(NSTabViewItem *)tabViewItem
{
    printf("tab changes %@", tabViewItem.identifier);

    return true;
}
@end

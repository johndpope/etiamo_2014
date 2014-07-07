//
//  AppDelegate.h
//  EggTester
//
//  Created by Mathias Dietrich on 6/28/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "EggViewController.h"


@interface AppDelegate : NSObject <NSApplicationDelegate>{

NSWindow            *window;
IBOutlet AUGraphController *graphController;

}

@property (nonatomic, assign) NSWindow *window;
@property (nonatomic, assign) AUGraphController *c;
@property (nonatomic, assign) EggViewController *eggViewController;
@property (nonatomic, assign)  AUGraphController *graphController;


@end

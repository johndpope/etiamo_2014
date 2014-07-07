//
//  AppDelegate.m
//  EggTester
//
//  Created by Mathias Dietrich on 6/28/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window;
@synthesize eggViewController;
@synthesize graphController;


- (BOOL)windowShouldClose:(id)sender
{
    return true;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication
{
    return true;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [window makeKeyAndOrderFront:nil];
}

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification
{
    
}

- (void)windowWillMiniaturize:(NSNotification *)notification
{
    
}

- (void)windowWillClose:(NSNotification *)notification
{
    printf("closing...");
}



@end

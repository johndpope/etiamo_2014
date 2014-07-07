//
//  Model.m
//  EggTester
//
//  Created by Mathias Dietrich on 6/29/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import "Model.h"

@implementation Model

@synthesize debugStr;
@synthesize isGrapRunning;

+ (id)of {
    static Model *model = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        model = [[self alloc] init];
        
            });
    return model;
}


- (id)init {
    self = [super init];
    if (self) {
         debugStr = [[NSMutableString alloc] init];
         isGrapRunning = false;
    }
    return self;
}

@end

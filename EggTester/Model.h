//
//  Model.h
//  EggTester
//
//  Created by Mathias Dietrich on 6/29/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Model : NSObject{

    NSMutableString *debugStr;
    bool isGrapRunning;
}

@property (nonatomic, assign) NSMutableString *debugStr;
@property (nonatomic, assign) bool isGrapRunning;
    + (id)of;

@end

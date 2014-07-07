//
//  MyView.h
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "WidgetMaster.h"

@interface MyView : NSView
{
    WidgetMaster *widgetMaster;
}


@property (nonatomic, assign)WidgetMaster *widgetMaster;

@end

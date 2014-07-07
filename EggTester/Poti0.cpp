//
//  Poti0.cpp
//  EggTester
//
//  Created by Mathias Dietrich on 7/5/14.
//  Copyright (c) 2014 Sensorem. All rights reserved.
//

#include "Poti0.h"

using namespace std;

Poti0:: Poti0()
{
    width = 118;
    height = 118;
}

void Poti0::draw()
{
    //drawLine(1, x,y,x+100,y+100);
    fillRect(0,x,y,width,height);
    
    /*
    draw7Char(1, x+10,y+3, '0');
    draw7Char(1, x+18,y+3, '1');
    draw7Char(1, x+26,y+3, '2');
    draw7Char(1, x+34,y+3, '3');
    draw7Char(1, x+42,y+3, '4');
    draw7Char(1, x+50,y+3, '5');
    draw7Char(1, x+58,y+3, '6');
    draw7Char(1, x+66,y+3, '7');
    draw7Char(1, x+74,y+3, '8');
    draw7Char(1, x+82,y+3, '9');
    */
    
    drawImage(0, x, y+12);
    drawText(1, 13, x+10, y+70, "Volume");
    
    char text_array[7];
    snprintf(text_array, 7, "%4.2f",  param[param0->id]);

    // color fontSize maxWidth x y text
    drawText(1, 13, x+20, y, text_array);
}


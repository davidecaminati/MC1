// Blocking.pde
// -*- mode: C++ -*-
//
// Shows how to use the blocking call runToNewPosition
// Which sets a new target position and then waits until the stepper has 
// achieved it.
//
// Copyright (C) 2009 Mike McCauley
// $Id: Blocking.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(8,4,5,6,7); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

int pin_velocita = A0;
void setup()
{  
    stepper.setMaxSpeed(500.0);
    stepper.setAcceleration(300.0);
    
    pinMode(pin_velocita,INPUT_PULLUP);  // velocita
    
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    
    digitalWrite(8,false);
    digitalWrite(9,false);
}

void loop()
{    
    stepper.runToNewPosition(0);
    stepper.runToNewPosition(4000);
}

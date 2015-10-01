/*
 * IR-replicator for Samsung TV
 *
 * Version 0.3 Gen, 2015
 * Copyright 2015 Davide Caminati
 * http://caminatidavide.it/
 */

#include <IRremote.h>

//int BUTTON_PIN3 = 2;
int SPEAKER_PIN = 9;

IRsend irsend;  // pin 3 PWM

int lastbuttonpressed = 1;
int lastButtonState3 ;


unsigned int GIU[100]={9398, 4650, 2500, 400, 400, 350, 950, 350, 950, 400, 350, 350, 950, 400, 350, 400, 
350, 350, 400, 350, 400, 350, 400, 350, 400, 350, 950, 350, 400, 350, 950, 350, 400, 350, 400, 350, 400, 
350, 950, 350, 400, 350, 350, 400, 950, 350, 950, 400, 350, 350, 400, 350, 950, 350, 400, 350, 950, 400, 
350, 400, 350, 350, 400, 350, 400, 350, 400, 350, 350, 400, 350, 400, 350, 400, 350, 350, 950, 400, 350, 
400, 350, 350, 400, 350, 400, 350, 400, 350, 350, 400, 350, 400, 950, 350, 350, 400, 350, 400, 350, 400
};



void setup()
{
  // set pin and pullup
  delay(250);
  //if (lastButtonState3 == HIGH && buttonState3 == LOW) {

    delay(100);
    // sequence for audio
    int sequence[] = {1}; 
    for (int i = 0; i < sizeof(sequence)/sizeof(int) ; i++){
      switch (sequence[i]){
      case 1:
    	  irsend.sendRaw(GIU,100,38);
      case 2:
    	  irsend.sendRaw(GIU,100,38);
      case 3:
    	   irsend.sendRaw(GIU,100,38);
        } 
      delay(500);
      }    
}


void loop() {
}

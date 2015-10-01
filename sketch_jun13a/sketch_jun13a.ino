/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

int orecchio = 7;

int bocca = 8;

int ascolta;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT);    
  pinMode(led2, OUTPUT);    
  pinMode(led3, OUTPUT);    
  pinMode(led4, OUTPUT);    
  pinMode(led5, OUTPUT);    
  
  pinMode(orecchio, INPUT);    
  
  pinMode(bocca, OUTPUT);    
  
  digitalWrite(orecchio, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(bocca, HIGH);    // turn the LED off by making the voltage LOW
}

// the loop routine runs over and over again forever:
void loop() {
  ascolta = digitalRead(orecchio);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (ascolta == LOW) {     
    
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                 // wait for a second
    digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led3, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                 // wait for a second
    digitalWrite(led3, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                 // wait for a second
    digitalWrite(led4, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(led5, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                 // wait for a second
    digitalWrite(led5, LOW);    // turn the LED off by making the voltage LOW
    
    digitalWrite(bocca, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(bocca, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
}

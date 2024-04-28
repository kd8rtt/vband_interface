#include "Keyboard.h"

//This program acts a USB interface for a CW paddle or straight key for VBand Virtual CW Band.
//Program written by Tony Milluzzi, KD8RTT using Keyboard library example as starting point.

//declaring paddle input pins
const int dah = 3;          
const int dit = 2;

int previousdahState = HIGH; 
int previousditState = HIGH; 


void setup() {
  //declare the inputs as input_pullup
  pinMode(dah, INPUT_PULLUP);  
  pinMode(dit, INPUT_PULLUP);  
  Keyboard.begin();
}

void loop() {
  //checking the state of the inputs
  int dahState = digitalRead(dah);
  int ditState = digitalRead(dit);

  
 //replaces left paddle input with dit using "[" as defined by VBand website
  if (dahState == LOW && previousdahState == HIGH) {
      // and it's currently pressed:
    Keyboard.press(93);
    delay(50);
  }
  if (dahState == HIGH && previousdahState == LOW) {
      // and it's currently released:[[[[]]]]
    Keyboard.release(93);
    delay(50);
  }
 
 //replaces right paddle input with dah using "]" as defined by VBand website
  if (ditState == LOW && previousditState == HIGH) {
      // and it's currently pressed:
    Keyboard.press(91);
    delay(50);
  }
  if (ditState == HIGH && previousditState == LOW) {
      // and it's currently released:
    Keyboard.release(91);
    delay(50);
  }

  previousdahState = dahState;
  previousditState = ditState;

}
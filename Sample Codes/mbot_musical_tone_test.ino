/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"

#define SERIAL_MONITOR_ACTIVATE 0 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */

MeBuzzer buzzer;


void celebrate() { // Code for playing celebratory tune (Nokia Ringtone)
  buzzer.tone(1319, 125);  
  buzzer.tone(1175, 125);  
  buzzer.tone(740, 250);  
  buzzer.tone(831, 250);  
  buzzer.tone(1109, 125);  
  buzzer.tone(988, 125);  
  buzzer.tone(587, 250);
  buzzer.tone(659, 250);
  buzzer.tone(988, 125);
  buzzer.tone(880, 125);  
  buzzer.tone(554, 250);  
  buzzer.tone(659, 250);   
  buzzer.tone(880, 750);
  buzzer.noTone();
}

void setup()
{
  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
}


void loop()
{
  
  celebrate();
  delay(1000);

}
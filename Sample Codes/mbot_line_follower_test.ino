/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"

#define SERIAL_MONITOR_ACTIVATE 1 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */

MeLineFollower lineFinder(PORT_2); 

void setup()
{
  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
}

void loop()
{
  int lineSensorState = lineFinder.readSensors();
  switch(lineSensorState)
  {
    case S1_IN_S2_IN: Serial.println("Sensor 1 and 2 are inside of black line"); break;
    case S1_IN_S2_OUT: Serial.println("Sensor 2 is outside of black line"); break;
    case S1_OUT_S2_IN: Serial.println("Sensor 1 is outside of black line"); break;
    case S1_OUT_S2_OUT: Serial.println("Sensor 1 and 2 are outside of black line"); break;
    default: break;
  }
  delay(500);
}


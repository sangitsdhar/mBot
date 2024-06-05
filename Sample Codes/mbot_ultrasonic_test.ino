/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"

#define SERIAL_MONITOR_ACTIVATE 1 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */

MeUltrasonicSensor ultraSensor(PORT_3); 

void setup()
{
  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
}

void loop()
{
  Serial.print("Distance : ");
  Serial.print(ultraSensor.distanceCm() );
  Serial.println(" cm");
  delay(100);
}


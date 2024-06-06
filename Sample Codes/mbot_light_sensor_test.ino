/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"

#define SERIAL_MONITOR_ACTIVATE 1 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */

MeLightSensor lightSensor(PORT_6);
int light_value = 0;      /* a variable for the lightSensor's value */

void setup()
{
  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
}

void loop()
{
  light_value = lightSensor.read();

  // print the results to the serial monitor
  Serial.print("value = ");
  Serial.println(light_value);
  // wait 500 milliseconds before the next loop
  delay(500);

}

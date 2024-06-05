/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"

MeRGBLed led(PORT_7);

float j, f, k;

void setup()
{

}

void loop()
{
  color_loop();
}

void color_loop()
{
  for(uint8_t t = 0; t < 2; t++)
  {
    uint8_t red	= 64 * (1 + sin(t / 2.0 + j / 4.0) );
    uint8_t green = 64 * (1 + sin(t / 1.0 + f / 9.0 + 2.1) );
    uint8_t blue = 64 * (1 + sin(t / 3.0 + k / 14.0 + 4.2) );
    led.setColor(t,red,green,blue);
  }
  led.show();
  j += random(1, 6) / 6.0;
  f += random(1, 6) / 6.0;
  k += random(1, 6) / 6.0;
}


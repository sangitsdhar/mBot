/**
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
**/

#include "MeMCore.h"


#define MOTOR_INTERVAL      20
#define NORMALSPEED           200 
#define TURNINGSPEED          160
#define FASTER_WHEEL_SPEED    250 
#define SLOWER_WHEEL_SPEED    180 
#define SERIAL_MONITOR_ACTIVATE 1 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */
#define NUDGING_THRES_DIST    4 // between 4 to 9 cm
#define NINETY_DEGREE_TIME    470 // time taken (in ms) to get 90 degree turn

MeDCMotor motorL(M1);
MeDCMotor motorR(M2);

void stopMotor()
{
  motorL.run(0);
  motorR.run(0);
  delay(MOTOR_INTERVAL);
}

void moveForward() 
{
  motorL.run(-NORMALSPEED);
  motorR.run(NORMALSPEED);
  delay(MOTOR_INTERVAL);
}

void turnRight() 
{
  motorL.run(-TURNINGSPEED);
  motorR.run(-TURNINGSPEED);
  delay(NINETY_DEGREE_TIME);
}

void turnLeft()
{
  motorL.run(TURNINGSPEED);
  motorR.run(TURNINGSPEED);
  delay(NINETY_DEGREE_TIME);
}

void nudgeLeft()
{
  motorL.run(SLOWER_WHEEL_SPEED);
  motorR.run(FASTER_WHEEL_SPEED);
  delay(MOTOR_INTERVAL);
}

void nudgeRight()
{
  motorL.run(-FASTER_WHEEL_SPEED);
  motorR.run(-SLOWER_WHEEL_SPEED);
  delay(MOTOR_INTERVAL);
}

void setup()
{
  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
}


void loop()
{
    turnLeft();     
    delay(2000);
    stopMotor();
    delay(2000);
    turnRight();
    delay(2000);
    moveForward();
    delay(2000);
    stopMotor();
    delay(2000);
    nudgeRight();
    delay(2000);
    moveForward();
    delay(2000);
    nudgeLeft();
    delay(2000);
    stopMotor();
    delay(2000);
}
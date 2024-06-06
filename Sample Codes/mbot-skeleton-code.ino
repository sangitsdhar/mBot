/***********************************************************
*** Skeleton Code for the mBot Workshop ***
Functions used from the Makeblock libraries
Author: Sangit Sasidhar
***********************************************************/

#include "MeMCore.h"

/***********************************************************
Paramters that can be modified 
************************************************************/
#define SERIAL_MONITOR_ACTIVATE 1 /* Set to 1 to use the serial monitor; set to 0 to disable the serial monitor  */

// Paramters for the vehicle control
#define MOTOR_INTERVAL        20  // this controls how much the vehicle moves forward or stops
#define NORMALSPEED           200 // This is the recommended speed for normal forward motion. Can be sdjusted 
#define TURNINGSPEED          160 // The speed is used for turning left or right. Can be adjusted
#define FASTER_WHEEL_SPEED    250 // This is used in nudgeLeft and nudgeRight to slide the vehicle in the respective direction. Can be adjusted 
#define SLOWER_WHEEL_SPEED    180 // This is used in nudgeLeft and nudgeRight to slide the vehicle in the respective direction. Can be adjusted
#define NUDGING_THRES_DIST    4 // between 4 to 9 cm
#define NINETY_DEGREE_TIME    470 // time taken (in ms) to get 90 degree turn

/**********************************************************************
mBot Definitions to use the different peripherals on the vehicle
**********************************************************************/
MeUltrasonicSensor ultraSensor(PORT_3);
MeLightSensor lightSensor(PORT_6);
MeLineFollower lineFinder(PORT_2); 
MeDCMotor motorL(M1);
MeDCMotor motorR(M2);
MeLightSensor lightSensor(PORT_6);
MeRGBLed led(PORT_7);

/**************************************************
Variables commonly used in the different functions
***************************************************/
int black_line_counter = 0 /* A variable to count the number of black lines*/
int light_value = 0;      /* a variable for the lightSensor's value */


/*******************************************************************
Functions used for controlling different peripherals
*******************************************************************/

// Code for playing celebratory tune (Nokia Ringtone)
void celebrate() { 
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

//``````````````````````````````````````````````

// Vechile control functions
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

//``````````````````````````````````````````````



void setup() {
  // put your setup code here, to run once:

  if(SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

}

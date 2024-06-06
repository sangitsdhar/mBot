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
#define NEAR_WALL_DIST        4   // between 4 to 9 cm. This decides how close the mBot is to the wall nearer to the ultrasonic sensor 
#define FAR_WALL_DIST         9   // between 9 to 12 cm. This decides how far the mBot is to the wall farther to the ultrasonic sensor
#define NINETY_DEGREE_TIME    470 // time taken (in ms) to get 90 degree turn

// Paramter to decide on the Light Dark Threshold
#define LIGHT_TURN_THRESHOLD  700 // Modify this value to decide on the border between dark and bright

/**********************************************************************
mBot Definitions to use the different peripherals on the vehicle
**********************************************************************/
MeUltrasonicSensor ultraSensor(PORT_3);
MeLightSensor lightSensor(PORT_6);
MeLineFollower lineFinder(PORT_2); 
MeDCMotor motorL(M1);
MeDCMotor motorR(M2);
MeBuzzer buzzer
MeRGBLed led(PORT_7);

/**************************************************
Variables commonly used in the different functions
***************************************************/
int black_line_counter = 1;       /* A variable to count the number of black lines*/
int light_value = 0;             /* A variable for the lightSensor's value */
double ultrasonic_distance = 0;  /* A variable to store the ultrasonic sensor value*/

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

  if (SERIAL_MONITOR_ACTIVATE) // Ensure that this is set to 0 for runtime. Use only for testing
  {
    /*************************************************************************
    If you want to monitor any sensor paramters. Put the corresponding code here.
    
    eg. provided below
    ***************************************************************************/
    light_value = lightSensor.read();
    Serial.print("value = ");
    Serial.println(light_value);
    // wait 500 milliseconds before the next loop
    delay(500);
   
  }

  // Check if the mBot is on the black Strip in the grid
  if(lineFinder.readSensors()==S1_IN_S2_IN) // Condition when both the sensors on the line follower are on the black strip
  {
  
    // Stop the vehicle
  
    /* 1.  Check if the final black strip has been reached!!*/
    if(black_line_counter == 4)// adjust according to the number of black strips in the given maze
    {
     
        // Play the tune
        // reset the counter back to 0
    }
    else
    {
      /*2. Check to see if it is too bright or not so bright. 
      a. If too bright            -->  Turn right
      b. If not too bright/dark   -->  Turn Left*/
      // Read the brightness
      // Compare it with a threshold LIGHT_TURN_THRESHOLD (Modify this according to your readings)
      if(light_value > LIGHT_TURN_THRESHOLD)
      {
       // Turn RIGHT 
      }
      else
      {
        // Turn Left
      }
      black_line_counter++; // Increase the black_line_counter to keep track of all the black lines
    }
  
  }

  // If no black line is encountered then keep moving forward
  else
  {
    // check to see if it too much towards the wall of the mazes
    // Read the Ultrasonic sensor to check the distance to the side wall of the maze
    // you may need to change the ultrasonic sensor to the side of the mbot
    if (ultrasonic_distance <NEAR_WALL_DIST)
    {
      //Too close to the wall on this side. Nudge to the other direction      
    }
    if (ultrasonic_distance >FAR_WALL_DIST)
    {
      //Too close to the wall on the other side. Nudge to the other direction      
    }

    // IF it is moving along the centre of the maze then keep moving forward.
  }

}

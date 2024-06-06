<h1 align="center">CDE Summer School</h1>
<h2 align="center"> mBoT Workshop </h2>

* Welcome to the CDE Summer School. We will be exploring the mBOT in the next ~1.5 hours.
* Extended Summary:
  - [Activity 1: Ultrasonic Sensors](#activity-1-ultrasonic-sensors)
  - [Activity 2: Light Sensor](#activity-2-light-sensor)
  - [Activity 3: Line Follower](#activity-3-line-follower)
  - [Activity 4: Wheel Control](#activity-4-vehicle-control)
  - [Activity 5: Musical Ending](#activity-5-musical-ending)
 
* [Requirements of the Final Project](requirements-of-the-final-project)

     
javascript:void(location.href='https://libproxy1.nus.edu.sg/login?url='+location.href);
## Activity 1 Ultrasonic Sensors
![Ultrasonic Sensors](https://github.com/sangitsdhar/mBot/blob/main/Images/uSsensor.png)

* The ultrasonic sensor is connected to `PORT3` of the mBot
* The sensor emits ultrasonic pulses & receives the reflections from the target.
* Remember to include `#define SERIAL_MONITOR_ACTIVATE 1` at the start of the program.
* Ensure that the `SERIAL_MONITOR_ACTIVATE` is set to 1 and the following code is present in  `void setup()` to ensure that serial communication is setup correctly
```
if (SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
```
* You can see the results in the Serial Monitor that can be opened by clicking the magnifying glass icon at the top right of the IDE or pressing `Ctrl/Cmd + Shift + M`
* Remember to include the line `MeRGBLed led(PORT_7); ` so that you can use the following functions to control and use these LEDs
  - `led.setColor(rgb_no,red,green,blue);` : This function sets the corresponding RGB led (defoned by the valuey `rgb_no`) to the RGB 
* You can refer to this [ultrasonic_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_ultrasonic_test.ino) to test it out.

## Activity 2 Light Sensor

* Remember to include the line `MeLightSensor lightSensor(PORT_6);` so that you can use the following function(s) to read the sensor input
    - `lightSensor.read();`: It gives the relative light reading with 0 corresponding to total darkness and 1024 corresponding to full brightness
* You can refer to this [light_sensor_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_light_sensor_test.ino) to test this out.

## Activity 3 Line Follower
* The line follower module is connected to the `PORT 2` of the mBot.
* There are two sensors in the line follower module denoted by `S1` and `S2`
* Remember to include the line `MeLineFollower lineFinder(PORT_2);` so that you can use the following function(s) to understand the sensor input
    - `lineFinder.readSensors()`: It give the following outputs depending on the module sensor state;
        - `S1_IN_S2_IN`: Sensor 1 and 2 are inside of black line
        - `S1_IN_S2_OUT`: Sensor 2 is outside of black line
        - `S1_OUT_S2_IN`: Sensor 1 is outside of black line
        - `S1_OUT_S2_OUT`: Sensor 1 and 2 are outside of black line
* You can refer to this [line follower example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_line_follower_test.ino) to test this out.   
      
## Activity 4 Vehicle Control
* You can refer to this [vehicle_control_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_vehicle_control_test.ino) to test out the different functions that will help control the motor.
* The example code has the following functions:
    - `void stopMotor()`: It stops both the left and the right motors
    - `void moveForward()`: It rotates both the motors such that the vehicle moves forward
    - `void turnLeft()`: It rotates both motors such that the vehicle turns left (90°) 
    - `void turnRight()`: It rotates both motors such that the vehicle turns right(90°)
    - `void nudgeLeft()`: It rotates both the motors with different speeds to nudge/slide it towards the left 
    - `void nudgeRight()`: It rotates both the motors with different speeds to nudge/slide it towards the right 

## Activity 5 Musical Ending
* Remember to include the line `MeBuzzer buzzer;` so that you can use the following function(s) to control and play a tone through the buzzer.
    - `buzzer.tone(noteFrequency, noteDuration);`: This function plays the note corresponding to the frequency value in noteFrequency and for the time defined in the variable noteDuration
* You can create different tunes to suit your requirements.
* You can refer to this [music_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_musical_tone_test.ino) to test this out


## Requirements of the Final Project
  1. Use the ultrasonic sensor to guide the mBot along a straight path in the maze
  2. Stop the mBot at the grid with the black strip using the line follower
  3. Sense the light intensity at the grid with the black strip
     1. If light intensity is very bright --> Turn Right
     2. If light intensity is darker/not very bright --> Turn Left
  4. Reach the final black line at the end of the maze and play a musical tone/sound.
  5. Use the sample [skeleton code](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot-skeleton-code.ino) and/or your own versions to combine the above activities to solve the following maze

![mBoT Maze](https://github.com/sangitsdhar/mBot/blob/main/Images/maze%20picture.png)     

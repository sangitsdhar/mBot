<h1 align="center">CDE Summer School</h1>
<h2 align="center"> mBoT Workshop </h2>

* Welcome to the CDE Summer School. We will be exploring the mBOT in the next ~1.5 hours.
* Extended Summary:
  - [Setting up the IDE for mBot](#setting-up-the-ide-for-mbot)
  - [Essential Settings](#essential-settings)
  - [Arduino mBot Pin Mapping](#arduino-mbot-pin-mapping)
  - [Install Makeblock Libraries](#install-makeblock-libraries)
  - [Activity 0: Setting up Serial Communications](#activity-0-setting-up-serial-communications) 
  - [Activity 1: Ultrasonic Sensors](#activity-1-ultrasonic-sensors)
  - [Activity 2: RGB LEDs](#activity-2-rgb-led)
  - [Activity 3: Light Sensor](#activity3-light-sensor)
  - [Activity 4: Line Follower](#activity-4-line-follower)
  - [Activity 5: Wheel Control](#activity-5-wheel-control)
  - [Activity 6: Musical Ending](#activity-7-musical-ending)

## Setting up the IDE for mBot
* Install the Arduino IDE using the [Windows/Mac installer](https://www.arduino.cc/en/software)
* When it asks you to install certain drivers, click yes / allow.
* It may also prompt you that some updates are available for your board and libraries. You can click update all on your own computer. If you are using a lab computer, simply close the window.

## Essential Settings
* Select Arduino Uno as the device in Tools > Board > Arduino AVR Boards > Arduino Uno.
* Select the correct serial port in Tools > Port > COMx after ensuring that the mCore is powered on. If you are not sure which port to select, in Windows, you can go to Device Manager (type 'Device Manager' in the Windows Start Menu), and check for the port number under Ports (COM & LPT). The correct port will be the one corresponding to 'USB-SERIAL CH340'.
* Once both the above are set correctly, the bottom-right corner of Arduino IDE should show ![Ardunio connection](https://github.com/sangitsdhar/mBot/blob/main/Images/arduino%20images.png) The actual COM number could be different on your PC/laptop.
* The first time when you try to program using Arduino, you may get one or more Windows firewall warnings. Click Allow access when prompted

## Arduino mBoT Pin Mapping
* A0 RJ25 plug 4 (default not-connected)
* A1 RJ25 plug 4 (default not-connected)
* A2 RJ25 plug 3 ultrasonic
* A3 RJ25 plug 3 ultrasonic
* A6 light sensor
* A7 button
* D2 IR RCV
* D3 IR TX
* D4 DIR2 - direction motor2
* D5 PWM2 - pwm motor2
* D6 PWM1 - pwn motor1
* D7 DIR1 - direction motor1
* D8 buzzer
* D9 RJ25 plug 2 linefollower
* D10 RJ25 plug 2 linefollower
* D11 RJ25 plug 1 (default not-connected)
* D12 RJ25 plug 1 (default not-connected)
* D13 2 WS2812 RGB led

## Install Makeblock Libraries
* Install the [Makeblock libraries](https://github.com/sangitsdhar/mBot/blob/main/Drivers%20and%20Libraries/Makeblock-Libraries-master.zip) .
* In the Arduino IDE:  Sketch > Include Library > Add .ZIP Library > select the downloaded file > Open. Restart the Arduino IDE.
* If you are getting an error, unzip the .zip file and copy it to Documents\Arduino\libraries. Make sure that you can see subfolders examples, src and files library.properties, README.md in the path Documents\Arduino\libraries\Makeblock-Libraries.
* The original library can be found at https://github.com/Makeblock-official/Makeblock-Libraries. There are a number of boards available; the mBot uses the MeMCore board. The original library files use MeOrion.h whereas mBot uses MeMCore.h.
* If you get an error that Wire.h can't be found, please copy the Wire.h from Documents\Arduino\libraries\Makeblock-Libraries\src\utility to Documents\Arduino\libraries\Makeblock-Libraries\src\ folder.

## Activity 0 Setting up Serial Communications

* Being able to see the output of sensors is a simple way to ensure the activities are going in the right direction.
* Remember to includ `#define SERIAL_MONITOR_ACTIVATE 1` at the start of the program.
* Ensure that the `SERIAL_MONITOR_ACTIVATE` is set to 1 and the following code is present in  `void setup()` to ensure that serial communication is setup correctly
```
if (SERIAL_MONITOR_ACTIVATE)
    Serial.begin(9600);
```
* You can see the results in the Serial Monitor that can be opened by clicking the magnifying glass icon at the top right of the IDE or pressing `Ctrl/Cmd + Shift + M`

## Activity 1 Ultrasonic Sensors
![Ultrasonic Sensors](https://github.com/sangitsdhar/mBot/blob/main/Images/uSsensor.png)

* The ultrasonic sensor is connected to `PORT3` of the mBot
* The sensor emits ultrasonic pulses & receives the reflections from the target.
* Remember to include the line `MeRGBLed led(PORT_7); ` so that you can use the following functions to control and use these LEDs
  - `led.setColor(rgb_no,red,green,blue);` : This function sets the corresponding RGB led (defoned by the valuey `rgb_no`) to the RGB 
* You can refer to this [ultrasonic_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_ultrasonic_test.ino) to test it out.

## Activity 2 RGB LED

* The RGB LEDs are connected to the `PORT 7` of the mBOT. The two LEDs can be individually controlled or controlled together.The two leds are denoted by the variable `rgb_no` and the values can vary between `0` and `1`.
* Remember to include the the line `#include <MeMCore.h>` at the start of the program. This line enables the use of the built-in functions for the different peripherals connected to the mBOT's mCore.
* Remember to include the line `MeUltrasonic ultraSensor(PORT_3);` so that you can use the following function(s) to read the sensor input
  - `ultraSensor.distanceCm();` : Gives the distance of the target/obstacle from the sensor in centimeters.
* You can refer to the [rgb_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_rgb_test.ino) here to test this out
 
## Activity 3 Light Sensor

* Remember to include the line `MeLightSensor lightSensor(PORT_6);` so that you can use the following function(s) to read the sensor input
    - `lightSensor.read();`: It gives the relative light reading with 0 corresponding to total darkness and 1024 corresponding to full brightness
* You can refer to this [light_sensor_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_light_sensor_test.ino) to test this out.

## Activity 4 Line Follower
* The line follower module is connected to the `PORT 2` of the mBot.
* There are two sensors in the line follower module denoted by `S1` and `S2`
* Remember to include the line `MeLineFollower lineFinder(PORT_2);` so that you can use the following function(s) to understand the sensor input
    - `lineFinder.readSensors()`: It give the following outputs depending on the module sensor state;
        - `S1_IN_S2_IN`: Sensor 1 and 2 are inside of black line
        - `S1_IN_S2_OUT`: Sensor 2 is outside of black line
        - `S1_OUT_S2_IN`: Sensor 1 is outside of black line
        - `S1_OUT_S2_OUT`: Sensor 1 and 2 are outside of black line
* You can refer to this [line follower example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_line_follower_test.ino) to test this out.   
      
## Activity 5 Wheel Control
You can refer to this [vehicle_control_example](https://github.com/sangitsdhar/mBot/blob/main/Sample%20Codes/mbot_vehicle_control_test.ino) to test out the different functions that will help control the motor.
## Activity 6 Musical Ending
* Remember to include the line `MeBuzzer buzzer;` so that you can use the following function(s) to control and play a tone through the buzzer.
    - `buzzer.tone(noteFrequency, noteDuration);`: This function plays the note corresponding to the frequency value in noteFrequency and for the time defined in the variable noteDuration
* You can create different tunes to suit your requirements.

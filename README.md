<h1 align="center">CDE Summer School</h1>
<h2 align="center"> mBoT Workshop </h2>

* Welcome to the CDE Summer School. We will be exploring the mBOT in the next ~1.5 hours.
* Extended Summary:
  - [Setting up the IDE for mBot](https://github.com/sangitsdhar/mBot/edit/main/README.md#starsetting-up-the-ide-for-mbot)
  - [Essential Settings](https://github.com/sangitsdhar/mBot/edit/main/README.md#%EF%B8%8Fessential-settings)
  - Arduino mBot Pin Mapping
  - 
## :star:Setting up the IDE for mBot
* Install the Arduino IDE using the [Windows/Mac installer](https://www.arduino.cc/en/software)
* When it asks you to install certain drivers, click yes / allow.
* It may also prompt you that some updates are available for your board and libraries. You can click update all on your own computer. If you are using a lab computer, simply close the window.

## ❄️:Essential Settings
* Select Arduino Uno as the device in Tools > Board > Arduino AVR Boards > Arduino Uno.
* Select the correct serial port in Tools > Port > COMx after ensuring that the mCore is powered on. If you are not sure which port to select, in Windows, you can go to Device Manager (type 'Device Manager' in the Windows Start Menu), and check for the port number under Ports (COM & LPT). The correct port will be the one corresponding to 'USB-SERIAL CH340'.
* Once both the above are set correctly, the bottom-right corner of Arduino IDE should show  The actual COM number could be different on your PC/laptop.

The first time when you try to program using Arduino, you may get one or more Windows firewall warnings. Click Allow access when prompted

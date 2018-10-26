# tutorial-servo-camera

![](https://lh3.googleusercontent.com/BhxOiRz3axjps8XbzRfoR8e5ZI1pZbo1tWD6ZzcGIEmu8r19d7lJgfgpotTtzwIvjnH7M7kLmVSK9r7pgVN2TswTp3MiZOL6SHSYJU9MI3sxfLvLWL-fWyNKU3vxcI5qkao6DqP-ZR08g2sihjoabcPZBv2SdIMXDKXgdKTziKGl3VmL-nbJUWP9kM5SBIe7Urqn1J7p_KpGtz3suK-fkpeT0p_OFca44VaX5hNu2HAa8dDljdfN576Aa4WZWRzZPO0vnBaMU6gDSaw6-YvY_L-Mloa-bp5wJvway1OGg5PrBi0Se9Q4kuBRAs18Vt8LMiGghKA1qcS0-Tif7ehlSGOLcdcgacQC4NU9aNGir0tPwNxTLpBTRYFdc9cfygZBKFCR1Qpxaat_t0H24k2bCxLozQVO8-Q3S3LIpK7pNRq6bzDouAu8DQVoPtvuQ7ugQB9cRRLxzhl8j3lO2NDQxZgr80CntKX6Q83G7E0ONFsFuXZw_k3Qi1jqoyKpdxubmp2BplMnVsR4bu0KgaatnoAPvvub9CXmxf-ugiCOoxfK-K9JeV-iuGx79mqhGD0iQ9Efu19WuywB0_q2J8nROk8drornmGYM=w2363-h1403)

## About

This project by [Aarón Montoya-Moraga](http://montoyamoraga.io/) consists of a webcam on servos that can be controlled from a Python script.

Modified by [Sebastian Morales](https://www.adorevolution.com/) and [Tiri Kananuruk](http://xxx.tiri.xxx/)

Developed for [CW&T](https://cwandt.com/)'s [Hardware](https://github.com/teejers/cwt-hardware-sfpc) and [Sam Lavigne](http://lav.io/)'s [Scrapism](https://github.com/antiboredom/sfpc-scrapism) class, at [School for Poetic Computation](http://sfpc.io/), Fall 2018.

## Environment

This project was programmed and tested using the following software and hardware:

* Macbook running macOS High Sierra
* Arduino Uno
* Arduino IDE 1.8.5
* Python 3.6.3 (test on 3.6.3 but it also works on python 2.x. You need to commend someline in python code)
* [pyserial](https://github.com/pyserial/pyserial) Python module

## Code

* Arduino script to receive commands from the Python script.
* Python script to send commands to Arduino.

## Materials

* [Micro servos](https://www.adafruit.com/product/1967)
* [Webcam](https://www.logitech.com/en-us/video/webcams)
* [Mini Pan-Tilt Kit for micro servos](https://www.adafruit.com/product/1968)
* [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3)

## Installation

* Clone or download this repository

* Make sure you are using Python 3.x.

```shell
python --version
```

* Upload the script arduino_servo_camera.ino to the Arduino Uno.

* Connect the servo motors to the Arduino.

```shell
pan servo(roll)
connect signal cable to pin 9 (pwm pin)
tilt servo(pitch)
connect signal cable to pin 10 (pwm pin)
```

![](https://lh3.googleusercontent.com/A6euDXP39Bdx3Xkd3i5cD2oLx9SSW-21mZ6GVFxcCJXfQ16q9EbWpbsdmhw2YyBKH88KXnXPtWdpbz0vZ1KSJlIAeMOV_7CSWaHocxGT4xQVIN4T3DQF5Tkap5OTS2zPX-sL4fgcY9D3eBbU9gNRFiiyOr-J9EWhPIQITu6kjZ10AO1lJa7abXMCAcaO9oOJE_kQU_vTNYOMYCPJBIUaJ0VGPyVeJ702sQsbZ-6Vff_hnvL7ZAUDoyRDgC0VQtY8qx-EiM_neq6kf4q9O15VXpQPUWoSe1KxIfIG6wGhc4ug5OxuskATdn3opFVfEmKw9LquhkNAwppo1EVnIy8QAM-soSu6Jh63Jlr52OdS4DkNRXIC4H7HT2R77bm0dW_6PEe94zLL6ZWMIeqvPpM-OdZlhxPmqHnRseF7js6bqsaqxWVpV_IdQEXYhgWC2eKCEIKJ8rchwu13K5bC_oFd6E8zIn6rA5vOsiHQir4H88Gsz1x17gm3XLZA0r1cf-_Hu-rjmshVlYIRKmoHqitOItygWfcHHRhFI6j10la1j_P7nMtKtsG2bUMu2rYR7L9liEyau1PaPXZm-7zsa_GByCjQB49Pn3Yb=w1342-h1474)

## Usage

* Open terminal and go to the directory

```shell
cd Desktop/servo-camera
```

* Install pyserial

```shell
pip install pyserial
```

* Open the Python script servo_camera.py

* Update the arduinoPort variable if needed

```python
arduinoPort = '/dev/cu.usbmodem1411'
```

* If you are using python2, Delete .encode() out of the lines 32,36,40,44 

```python
ser.write("0,0\n")
```

* Run the Python script on terminal

```shell
python servo_camera.py
```

This script is making the camera infinitely loop through the sequence [0,0], [90, 90], [180, 180], [90, 90].


## Bibliography

* [Aaron Montoya-Moraga-tutorial](https://github.com/montoyamoraga/tutorial-servo-camera)
* [Arduino and Python](https://playground.arduino.cc/Interfacing/Python)
* [pyserial](https://github.com/pyserial/pyserial)

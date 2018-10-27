# servo_camera.py
# by aaron montoya-moraga
# modified by Sebastian and Tiri for SFPC fall 2018

# script for controlling servo motors with arduino
# via python script with pyserial module

# import pyserial for writing serial to arduino
import serial
# import time for sleep function
import time

# configuration of arduino
arduinoPort = '/dev/cu.usbmodem1411'
arduinoBaudRate = 9600

# open the serial port, this resets the arduino
ser = serial.Serial(arduinoPort, arduinoBaudRate)

# wait so that arduino can reset
time.sleep(2)

#delta of time, in seconds
deltaTime = 1.

# infinite loop so that servos go through the sequence
# [0,0], [90, 90], [180, 180], [90, 90]
# format of data sent to Arduino is yaw,pitch\n
# both values separated by a comma and ending on a new line
while True:
    #write on serial port and wait
    ser.write("0,0\n".encode()) #py3
    # ser.write("0,0\n") #py2
    time.sleep(deltaTime)

    ser.write("90,90\n".encode())
    # ser.write("90,90\n") #py2
    time.sleep(deltaTime)

    ser.write("180,180\n".encode())
    # ser.write("180,180\n") #py2
    time.sleep(deltaTime)

    ser.write("90,90\n".encode())
    # ser.write("90,90\n") #py2
    time.sleep(deltaTime)

# wait
time.sleep(2)

# close the serial port
ser.close()

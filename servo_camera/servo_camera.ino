//This project by [Aarón Montoya-Moraga](http://montoyamoraga.io/)
//consists of a webcam on servos that can be controlled from a Python script.

//Modified by Sebastian Morales](https://www.adorevolution.com/)
//and [Tiri Kananuruk](http://xxx.tiri.xxx/)

// Developed for [CW&T](https://cwandt.com/)'s [Hardware](https://github.com/teejers/cwt-hardware-sfpc)
// and [Sam Lavigne](http://lav.io/)'s [Scrapism](https://github.com/antiboredom/sfpc-scrapism) class, at [School for Poetic Computation](http://sfpc.io/), Fall 2018.

//script for controlling servo motors with arduino
//via python script with pyserial module

//include servo library
#include <Servo.h>

//declare servos
Servo servoYaw;
Servo servoPitch;

//pins for servos
int pinYaw = 9;
int pinPitch = 10;

//store of input
int inputYaw = 90;
int inputPitch = 90;

boolean newPos = false;

void setup() {
  //begin serial communication
  Serial.begin(9600);

  //attach a pin to the yaw servo
  servoYaw.attach(pinYaw);
  //attach a pin to the pitch servo
  servoPitch.attach(pinPitch);
}


void loop() {
  //only check to see if there is any new position, if not, do nothing
  if (newPos) {
    //move Yaw
    servoYaw.write(inputYaw);
    delay(1);
    //move pitch
    servoPitch.write(inputPitch);
    delay(1);
    newPos = false;
  }

}


void serialEvent() {
  //Data is separated by , and and ended by a new line(\n)
  // 45,135\n
  String yawTemp = "";
  String pitchTemp = "";
  yawTemp = Serial.readStringUntil(',');
  pitchTemp = Serial.readStringUntil('\n');
  inputYaw = yawTemp.toInt();
  inputPitch = pitchTemp.toInt();
  Serial.print("yaw: " + inputYaw);
  Serial.print(" pitch: :" + inputPitch);
  newPos = true;
}

#include "Arduino.h"
#include "ServoMotor.h"
#include <Servo.h>


Servo serv;

void ServoMotor::ServoSetup(int servo_pin) {
  ServoPin = servo_pin;
  serv.attach(servo_pin);
}

void ServoMotor::ServoAngle(int angle) {
  serv.write(angle);
}
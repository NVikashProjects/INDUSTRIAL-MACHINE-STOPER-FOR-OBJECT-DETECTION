#ifndef ServoMotor_h
#define ServoMotor_h
#include "Arduino.h"

class ServoMotor {
private:
  int ServoPin;
  int Angle;
public:
  void ServoAngle(int angle);
  void ServoSetup(int servo_pin);
};

#endif
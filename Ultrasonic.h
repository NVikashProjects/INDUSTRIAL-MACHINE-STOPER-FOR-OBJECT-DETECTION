#ifndef Ultrasonic_h
#define Ultrasonic_h
#include "Arduino.h"

class Ultrasonic {
private:
  int TrigPin;
  int EchoPin;
public:
  void UltrasonicSetup(int trigpin, int echopin);
  float UltrasonicDistance();
};

#endif
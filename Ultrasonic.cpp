#include "Ultrasonic.h"

void Ultrasonic::UltrasonicSetup(int trigpin, int echopin) {
  TrigPin = trigpin;
  EchoPin = echopin;

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

float Ultrasonic::UltrasonicDistance() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  long duration = pulseIn(EchoPin, HIGH);
  int distance = duration * 0.0323 / 2;


  return distance;
}
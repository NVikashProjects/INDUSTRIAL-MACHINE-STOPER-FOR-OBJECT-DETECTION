#include "MotorDrive.h"

void MotorDrive::MotorDriveSetup(int enable1, int MF1, int MB1, int enable2, int MF2, int MB2) {
  Enable1 = enable1;
  Enable2 = enable2;
  Front1 = MF1;
  Front2 = MF2;
  Back1 = MB1;
  Back2 = MB2;

  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(MF1, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MF2, OUTPUT);
  pinMode(MB2, OUTPUT);

  digitalWrite(MF1, LOW);
  digitalWrite(MB1, LOW);
  digitalWrite(MF2, LOW);
  digitalWrite(MB2, LOW);
}

void MotorDrive::Motor(int speed, String state) {
  analogWrite(Enable1, speed);
  analogWrite(Enable2, speed);
  if (state == "Front") {
    digitalWrite(Front1, HIGH);
    digitalWrite(Back1, LOW);
    digitalWrite(Front2, HIGH);
    digitalWrite(Back2, LOW);
  } else if (state == "Back") {
    digitalWrite(Front1, LOW);
    digitalWrite(Back1, HIGH);
    digitalWrite(Front2, LOW);
    digitalWrite(Back2, HIGH);
  }else if(state == "OFF") {
    digitalWrite(Front1, LOW);
    digitalWrite(Back1, LOW);
    digitalWrite(Front2, LOW);
    digitalWrite(Back2, LOW);
  }
}

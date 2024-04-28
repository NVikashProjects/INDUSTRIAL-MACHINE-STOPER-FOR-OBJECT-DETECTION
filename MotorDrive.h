#ifndef MotorDrive_h
#define MotorDrive_h
#include "Arduino.h"
class MotorDrive{
  private:
    int Enable1, Enable2;
    int Front1, Back1;
    int Front2, Back2;
  public:
    void MotorDriveSetup(int enable1,int MF1, int MB1, int enable2, int MF2, int MB2);
    void MotorDirection();
    void Motor(int speed, String state);
};

#endif
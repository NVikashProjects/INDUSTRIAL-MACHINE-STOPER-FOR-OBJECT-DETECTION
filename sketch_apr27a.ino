#include "ServoMotor.h"
#include "Ultrasonic.h"
#include "MotorDrive.h"
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial gsm(12, 13);

ServoMotor servo;
Ultrasonic ultrasonic;
MotorDrive motordrive;

int servomotor = 11, i = 0, j = 1;
int triger = 2, echo = 3;
int enable1 = 5, enable2 = 6, MF1 = 7, MB1 = 8, MF2 = 9, MB2 = 10;
int ir = 4;
int distance, previous;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  ultrasonic.UltrasonicSetup(triger, echo);
  servo.ServoSetup(servomotor);
  pinMode(ir, INPUT);
  motordrive.MotorDriveSetup(enable1, MF1, MB1, enable2, MF2, MB2);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  gsm.println("AT");
  delay(5000);
}

void loop() {

  servo.ServoAngle(i);
  delay(10);
  distance = ultrasonic.UltrasonicDistance();
  if (digitalRead(ir) == 0 || distance < 20) {
    motordrive.Motor(0, "OFF");
    Serial.println("Motor Stoped ...!");


    if (digitalRead(ir) == 0) {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Fire detected");
      lcd.setCursor(0, 0);
      lcd.print("Motor Stoped");

      gsm.println("AT");
      delay(1000);
      gsm.println("AT+CMGF=1");
      delay(500);
      gsm.println("AT+CMGS=\"+917708714210\"");
      delay(500);
      gsm.print("Fire detected");
      delay(500);
      gsm.write(26);
    } else {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Object detected");
      lcd.setCursor(0, 0);
      lcd.print("Motor Stoped");
      
      gsm.println("AT");
      delay(1000);
      gsm.println("AT+CMGF=1");
      delay(500);
      gsm.println("AT+CMGS=\"+917708714210\"");
      delay(500);
      gsm.print("Object detected");
      delay(500);
      gsm.write(26);
    }
    servo.ServoAngle(previous);
    lcd.clear();
  } else {
    if (i <= 180 && j == 1) {
      i = i + 1;
      if (i == 180) {
        j = 0;
      }
    } else if (181 > i >= 0 && j == 0) {
      i = i - 1;
      if (i == 0) {
        j = 1;
      }
    }
    motordrive.Motor(200, "Front");
    Serial.println("Motor Running ...");
    previous = i;    
    lcd.setCursor(0, 0);
    lcd.print("Motor Running");
  }
}

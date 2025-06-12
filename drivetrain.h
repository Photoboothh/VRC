#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setPower(int p8, int p9, int p10, int p11) {
  pwm.setPin (8, p8);
  pwm.setPin (9, p9);
  pwm.setPin (10, p10);
  pwm.setPin (11, p11);
}

void setupMotors() {
  Wire.begin(); 
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(1600);
  Wire.setClock(400000);

  setPower(0, 0, 0, 0);
}
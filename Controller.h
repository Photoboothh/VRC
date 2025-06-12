#include <PS2X_lib.h>

#define PS2_DAT 12 // MISO 
#define PS2_CMD 13 // MOSI 
#define PS2_SEL 15 // SS 
#define PS2_CLK 14 // SLK

PS2X ps2x;

void setupController() {
  int err = -1;
  while (err != 0)
  {
    err = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
  }
}

void Controldrivetrain() {
  int joystick_rx = 127 - ps2x.Analog(PSS_RX);
  int joystick_ly = 128 - ps2x.Analog(PSS_LY);
  int rightmotor = joystick_ly + joystick_rx;
  int leftmotor = joystick_ly - joystick_rx;

  int p8=0 ,p9=0, p10=0, p11=0;
  
  if (joystick_ly == 0 &&joystick_rx == -1) {
    setPower(0,0,0,0);
  }

  if (leftmotor > 0) {
    p8 = leftmotor;
    p8 = map(p8, 0, 128, 0, 2048);
  }
  if (leftmotor < 0) {
    p9 = abs(leftmotor);
    p9 = map(p9, 0, 128, 0, 2048);
  }
  if (rightmotor > 0) {
    p10 = rightmotor;
    p10 = map(p10, 0, 128, 0, 2048);
  }
  if (rightmotor < 0) {
    p11 = abs(rightmotor);
    p11 = map(p11, 0, 128, 0, 2048);
  }
  setPower(p8,p9,p10,p11);
}
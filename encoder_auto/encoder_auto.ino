#define CLK 3
#define DT 2
#define SW 4
#define VCC 5
#define GND 6

#include "Keyboard.h"
#include "Mouse.h"
#include "GyverEncoder.h"

Encoder enc1(CLK, DT, SW);

void setup() {
  Mouse.begin();
  Keyboard.begin();
  delay(500);
  Serial.begin(9600);
  enc1.setTickMode(AUTO);

  pinMode(GND,OUTPUT);
  digitalWrite(GND, LOW);
  pinMode(VCC,OUTPUT);
  digitalWrite(VCC, HIGH);
}

void loop() {
  if (enc1.isRight()) Mouse.move(0, 0, -1);
  if (enc1.isLeft()) Mouse.move(0, 0, 1);
  if (enc1.isRightH()) {
    Keyboard.press(KEY_LEFT_ALT); 
    Mouse.move(0, 0, 1);
    Keyboard.releaseAll();
  }
  if (enc1.isLeftH()) {
    Keyboard.press(KEY_LEFT_ALT); 
    Mouse.move(0, 0, -1);
    Keyboard.releaseAll();
  }
}

//пины энкодера
#define CLK 3
#define DT 2
#define SW 4
#define VCC 5
#define GND 6

//библиотеки
#include "Keyboard.h"
#include "Mouse.h"
#include "GyverEncoder.h"

//запуск энкодера
Encoder enc1(CLK, DT, SW);

void setup() {
  //запуск мыши, клавиатуры
  Mouse.begin();
  Keyboard.begin();
  delay(500);
  Serial.begin(9600);
  //обязательно для энкодера
  enc1.setTickMode(AUTO);

  //питане энкодера
  pinMode(GND,OUTPUT);
  digitalWrite(GND, LOW);
  pinMode(VCC,OUTPUT);
  digitalWrite(VCC, HIGH);
}

void loop() {
  if (enc1.isRight()) Mouse.move(0, 0, -1);//поворот вправо
  if (enc1.isLeft()) Mouse.move(0, 0, 1);//поворот влево
  if (enc1.isRightH()) {//поворот вправо при нажатии
    Keyboard.press(KEY_LEFT_ALT); 
    Mouse.move(0, 0, 1);
    Keyboard.releaseAll();
  }
  if (enc1.isLeftH()) {//поворот влево при нажатии
    Keyboard.press(KEY_LEFT_ALT); 
    Mouse.move(0, 0, -1);
    Keyboard.releaseAll();
  }
}

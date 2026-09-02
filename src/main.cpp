#include <Arduino.h>

// put fu = nction declarations here:
int btn1 = 13;
int btn2 = 12;
int btn1Read;
int btn2Read;
int j;

int LEDpin = 10;
int buzzPin = 9;
int LEDbright  = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  btn1Read= digitalRead(btn1);
  btn2Read = digitalRead(btn2);
  Serial.print("Button 1: ");
  Serial.print(btn1Read);
  Serial.print(" Button 2: ");  
  Serial.println(btn2Read);
  delay(800);


if (btn1Read == 0) {
    LEDbright = LEDbright + 25;
}
 if (btn2Read == 1) {
  LEDbright = LEDbright - 25;
}
if(LEDbright > 255) {
  LEDbright = 255;
}
if(LEDbright < 0) {
  LEDbright = 0;
} 

analogWrite(LEDpin, LEDbright);
}



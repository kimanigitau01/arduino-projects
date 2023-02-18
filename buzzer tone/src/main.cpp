#include <Arduino.h>

const int buzzer = 4; // for the piezzo speaker
const int pushButton = 5; // for the push button


void setup() {
  pinMode(buzzer, INPUT); 
  pinMode(pushButton, OUTPUT);
}

void loop() {
  int value = digitalRead(pushButton);
  if (value ==  LOW){
    tone(buzzer, 2000);    
  }else{
    noTone(buzzer);
  }
}
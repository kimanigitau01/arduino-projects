#include <Arduino.h>

const int motorPin = 11; // use PWM pin
const int pushButton = 5;
int state = 0;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP); //initalize the internal pullup resistor
  analogWrite(motorPin, 0);
}

void loop() {
  if (digitalRead(pushButton) == LOW){
    if (state == 0){
      analogWrite(motorPin, map(3, 0, 9, 0, 255));
    }else if(state == 1){
      analogWrite(motorPin, map(6, 0, 9, 0, 255));
    }else if (state == 2){
      analogWrite(motorPin, map(9, 0, 9, 0, 255));
    }else if (state == 3){
      analogWrite(motorPin, 0);
    }
    delay(1000);
  }
} 
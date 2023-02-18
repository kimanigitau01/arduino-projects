#include <Arduino.h>
const int ledPin = 2;
const int pushButton = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton, INPUT);

}

void loop() {
int buttonValue = digitalRead(pushButton);
if (buttonValue == 0){
  digitalWrite(ledPin, HIGH);
}else {
  digitalWrite(ledPin, LOW);
}
}
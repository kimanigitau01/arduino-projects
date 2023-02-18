#include <Arduino.h>

const int potPin = A0; 
const int led = 7;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float potValue =  analogRead(potPin);
  float reading = map(potValue, 0, 1023, 0, 255);
  analogWrite(led, reading);
  Serial.println(reading);
}
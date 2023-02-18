#include <Arduino.h>
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome User!!");
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("Led ON");
  delay(1000);
  digitalWrite(ledPin, LOW);
  Serial.println("led OFF");
  delay(1000);
}
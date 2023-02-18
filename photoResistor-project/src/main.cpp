#include <Arduino.h>

const int greenLed1 = 3;
const int greenLed2 = 4;
const int photoResistor = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed1, OUTPUT);
  pinMode(greenLed2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome!!");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float reading = analogRead(photoResistor);
  if (reading < 910){
    digitalWrite(greenLed1, LOW);
    digitalWrite(greenLed2, LOW);
    Serial.println(reading);
    delay(2000);
  }else{
    digitalWrite(greenLed1, HIGH);
    digitalWrite(greenLed2, HIGH);
    Serial.println(reading);
    delay(2000);
  }
}   
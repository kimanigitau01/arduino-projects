/* this program is an alarm that works together with the leds to ring whenever ther is an intruder*/
#include <Arduino.h>

int distance = 0;

const int trig = 2;
const int echo = 3;

const int alarm = 7;

const int redLed = 8;
const int greenLed = 9;

void setup() {
  Serial.begin(9600);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);

  pinMode(alarm,OUTPUT);

  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

}
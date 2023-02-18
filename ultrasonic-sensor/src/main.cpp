/* this program is an alarm that works together with the leds to ring whenever ther is an intruder
Written by: Manasseh Gitau
*/

#include <Arduino.h>

int distance = 0;
int duration  = 0;

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

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(2);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance =  (duration * 0.034) / 2;

  if (distance <= 20){
    alarmSequence(alarm, led);

  }
}

void alarmSequence(int device, int detectLed, int neutralLed){
  tone(device, 100);
  delay(10);
  tone(device, 200);
  delay(10);
  tone(device, 300);
  delay(10);

  digitalWrite(detectLed, HIGH);
  delay(500);
  digitalWrite(redLed, LOW);
  delay(500);
  digitalWrite(redLed, HIGH);
  delay(500);
  digitalWrite(redLed, LOW);
  delay(500);
  digitalWrite(greenLed, LOW);
  
}
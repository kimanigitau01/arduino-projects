/* this program is an alarm that works together with the leds to ring whenever ther is an intruder
Written by: Manasseh Gitau
*/

#include <Arduino.h>

int distance = 0;
int duration  = 0;
int distanceInInches;

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
  distance =  (duration * 0.034) / 2; // distance in centimeters
  distanceInInches = centimetersToInches(distance);

  if (distance <= 20){
    alarmSequence(alarm, redLed, greenLed);
    
    Serial.print("Distance is");
    Serial.print(distance);
    Serial.println(" cm.");

    Serial.print("Distance is");
    Serial.print(distanceInInches);
    Serial.println(" inches.");


  }else{
    normalSequence(alarm, redLed, greenLed);

    Serial.print("Distance is");
    Serial.print(distance);
    Serial.println(" cm.");

    Serial.print("Distance is");
    Serial.print(distanceInInches);
    Serial.println(" inches.");
  }
  delay(10); // to wait for next detection

}

void alarmSequence(int device, int detectLed, int neutralLed){
  tone(device, 500);
  delay(10);
  tone(device, 1000);
  delay(10);
  tone(device, 1700);
  delay(10);

  tone(device, 3000);

  Serial.println("DANGER");

  digitalWrite(detectLed, HIGH);
  delay(500);
  digitalWrite(detectLed, LOW);
  delay(500);
  digitalWrite(detectLed, HIGH);
  delay(500);
  digitalWrite(detectLed, LOW);
  delay(500);
  
  digitalWrite(neutralLed, LOW);
}

void normalSequence(int device, int detectLed, int neutralLed){
  noTone(device);

  Serial.println("ALL GOOD");
  digitalWrite(detectLed, LOW);

  digitalWrite(neutralLed, HIGH);
  delay(1000);
  digitalWrite(neutralLed, LOW);
  delay(1000);
  digitalWrite(neutralLed, HIGH);
  delay(1000);
  digitalWrite(neutralLed, LOW);
  delay(1000);
}

int centimetersToInches(int centimeters){
  int reading =  centimeters * 0.393701;
}
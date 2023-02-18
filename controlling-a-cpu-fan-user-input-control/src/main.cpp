/* Written by Manasseh Gitau
This programis used to control the speed of the motor speed by using the  input from the user

Requirements:
1. Arduino of your prefered choice
2. dc motor 
3. MJE182 pnp motor
4. jumper wires
5. 220 ohm resistor
6.  */

#include <Arduino.h>
const int motorPin = 11; // use a PWM pin

void setup() {
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, 0);

  Serial.begin(9600);
  Serial.println("Enter a number between 0 and 9: "); // input txt
}

void loop(){
  if (Serial.available()){
    // get the input from the user
    char input =  Serial.read();
    if (input >= '0' && input <= '9'){
      int speed = input - '0';
      // set the speed to the project
      analogWrite(motorPin, map(speed, 0, 9, 0, 255));
    }
  }
}
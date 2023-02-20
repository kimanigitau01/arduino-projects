#include <Arduino.h>


const int vertical = A0;
const int horizontal = A1;
const int pushButton = 3;

void setup() {
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

char state(int pushButton){

  if (pushButton == LOW){
    printf("Not Pressed");
  }else{
    printf("Presssed");
  }
}

void loop() {
  char value = state(pushButton);
  float verticalReading = analogRead(vertical);
  float horizontalReading =analogRead(horizontal);
  Serial.print("vertical: ");
  Serial.print(verticalReading);
  Serial.print("horizontal: ");
  Serial.print(horizontalReading);
  Serial.print("Push Buttton state: ");
  Serial.println(value);

}


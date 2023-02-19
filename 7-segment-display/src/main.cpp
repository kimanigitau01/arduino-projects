#include <Arduino.h>

int segmentPin[] = {2, 3, 4, 5, 6, 7, 8};

byte digits [10][8] = {

  // a, b, c, d, e, f, g
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,0,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,1,0,1}, //5
  {1,0,1,1,1,1,1}, //6
  {1,1,1,0,0,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,0,1,1}, //9

};
void setup() {
  for (int i = 0; i <8; i++){
    pinMode(segmentPin[i], OUTPUT);
    digitalWrite(segmentPin[i], LOW);
  }
Serial.begin(9600);
Serial.println("Enter a number between 0 and 9: ");

}

void setSegments(int numRequired){
  for (int i = 0; i <8; i++){
    digitalWrite(segmentPin[i], digits[numRequired][i]);
  }
}

void updateDisplay(int value){
  setSegments(value);
}


void loop() {
  if (Serial.available()){
    // get the input from the user
    char ch = Serial.read();
    int number = ch - '0';
    updateDisplay(number);
  }
  
}


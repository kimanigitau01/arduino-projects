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
byte spinDigits[6][8] = {
  // a, b,  c,  d,  e,  f
  {1,0,0,0,0,0},//a
  {0,1,0,0,0,0}, //b
  {0,0,1,0,0,0}, //c
  {0,0,0,1,0,0}, //d
  {0,0,0,0,1,0}, //e
  {0,0,0,0,0,1}, //f
};
const int pushButton = 11;
void setup() {
  for (int pin = 0; pin <= 7; pin++){
    pinMode(segmentPin[pin], OUTPUT);
    digitalWrite(segmentPin[pin], LOW);
  };

  pinMode(pushButton, INPUT_PULLUP);
}


void spin(){
  for(int rowNum = 0; rowNum < 7; rowNum++){
    for (int columnNum = 0; columnNum < 8; columnNum++){
      digitalWrite(segmentPin[rowNum], spinDigits[columnNum][rowNum]);
    };
  }
  delay(250);
}

void setSegments(int numRequired){
  for (int pin = 0; pin <= 7; pin++){
    digitalWrite(segmentPin[pin], digits[numRequired][pin]);
  };
}

void updateDisplay(int value){
  setSegments(value);
}

void roll(){
  int roll = random(1,7);
  updateDisplay(roll);
}
void loop() {
  if (pushButton == LOW){
    spin();
    roll();
    delay(500);
  }
}
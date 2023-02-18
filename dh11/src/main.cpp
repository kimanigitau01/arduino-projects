#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>
#include <dht.h>

const int dhtpin = 4;
const int rs =  12, en = 11, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.println("Welcome User");
  lcd.setCursor(0,1);
  lcd.println("LOADING...");
  Serial.println("Welcome User!!");
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(dhtpin);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
  lcd.clear();
  
}
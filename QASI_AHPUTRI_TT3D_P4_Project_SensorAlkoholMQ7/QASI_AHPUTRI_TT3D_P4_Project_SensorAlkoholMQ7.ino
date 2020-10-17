#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int SENSOR_GAS_MQ7=3;
int RED_LED=4;
int GREEN_LED=5;

void setup() {
  // put your setup code here, to run once:
pinMode(SENSOR_GAS_MQ7, INPUT_PULLUP);
pinMode(RED_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("SISTEM PENDETEKSI");
lcd.setCursor(0,1);
lcd.print("ALKOHOL");
lcd.setCursor(0,2);
lcd.print("TELEKOMUNIKASI PNJ");
delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
int SENSOR_GAS_MQ7_READ = digitalRead(SENSOR_GAS_MQ7);
if (SENSOR_GAS_MQ7_READ == LOW)
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL DETECTED");
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(20);
}
else
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL NOT DETECTED");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(20);
  }
}

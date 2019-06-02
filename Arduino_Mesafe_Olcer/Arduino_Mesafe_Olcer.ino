#include <LiquidCrystal.h>

#define trig 9
#define echo 8

int distance;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  distance = (pulseIn(echo, HIGH) / 2) / 29.1;

  lcd.home();
  lcd.print("Mesafe: ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  lcd.clear();
}

#include <LiquidCrystal.h>

#define lm35 A3

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.clear();
  lcd.home();
  lcd.print("Sicaklik: ");
  lcd.setCursor(0,1);
  lcd.print(((analogRead(lm35) / 1023.0) * 5000) / 10.0);
  delay(1000);
}

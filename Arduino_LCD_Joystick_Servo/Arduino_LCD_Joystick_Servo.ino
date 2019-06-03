#include <LiquidCrystal.h>
#include <Servo.h>

#define x A0
#define y A1
#define rs 12
#define en 11
#define d4 10
#define d5 9
#define d6 8
#define d7 7

int xAksis, yAksis;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo sg90_1;
Servo sg90_2;

void setup()
{
  lcd.begin(16, 2);
  sg90_1.attach(3);
  sg90_2.attach(5);
}

void loop()
{
  xAksis = map(analogRead(x), 0, 1023, 0, 180);
  yAksis = map(analogRead(y), 0, 1023, 0, 180);
  
  sg90_1.write(xAksis);
  sg90_2.write(yAksis);

  lcd.clear();
  lcd.home();
  lcd.print("1.Motor: ");
  lcd.print(xAksis);
  lcd.setCursor(0,1);
  lcd.print("2.Motor: ");
  lcd.print(yAksis);
  delay(50);
}

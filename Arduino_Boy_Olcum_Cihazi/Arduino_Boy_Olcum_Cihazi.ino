#include <LiquidCrystal.h>

#define tigger 6
#define echo 7
#define kalibButton 8
#define distanceButton 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int times = 0;
int distance = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("");
  pinMode(tigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(kalibButton, INPUT);
  pinMode(distanceButton, INPUT);

  while (digitalRead(kalibButton) == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("KALIBRADYON ICIN");

    lcd.setCursor(0, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);

    if (digitalRead(kalibButton) == HIGH)
    {
      delay(50);
      distance = measureDistance();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("KALIBRASYO");
      lcd.setCursor(0, 1);
      lcd.print("YAPILDI");
      delay(1000);
      lcd.clear();

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("KALIBRASYO");
      lcd.setCursor(0, 1);
      lcd.print("YAPILDI: ");
      lcd.print(distance);
      delay(1000);
      lcd.clear();
      break;
    }
  }
}

void loop()
{
  if (digitalRead(distanceButton) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("BOYUNUZ");
    lcd.setCursor(0, 1);
    lcd.print(distance - measureDistance());
    delay(2000);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("   OLCUM ICIN   ");
    lcd.setCursor(0, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);
    lcd.clear();
  }
}

int measureDistance()
{
  digitalWrite(tigger, HIGH);
  delay(1);
  digitalWrite(tigger, LOW);
  times = pulseIn(echo, HIGH);
  return (times / 2) / 28.5;
}

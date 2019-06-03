#include <Servo.h>

#define button 4
#define buzzer 7
#define echo 2
#define trig 3
#define led1 8
#define led2 9
#define led3 10
#define led4 11
#define led5 12
#define potPin A0

int pot_deger;
int pot_deger_ilk;
int alarm_mesafesi;
int pos;

Servo sg90;

void setup()
{
  sg90.attach(5);
  sg90.write(90);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  pot_deger_ilk = analogRead(potPin);
  while(1)
  {
    for(int i = 8; i < 13; i++)
    {
      digitalWrite(i, 1);
      delay(50);
      digitalWrite(i, 0);
    }
    pot_deger = analogRead(potPin);
    if(pot_deger_ilk > pot_deger + 10 || pot_deger_ilk < pot_deger - 10)
      break;
  }
  while(1)
  {
    pot_deger = map(analogRead(potPin),0,1023,1,5);
    if(pot_deger == 1)
    {
      alarm_mesafesi = 10;
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
    }
    else if(pot_deger == 2)
    {
      alarm_mesafesi = 20;
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
    }
    else if(pot_deger == 3)
    {
      alarm_mesafesi = 30;
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
    }
    else if(pot_deger == 4)
    {
      alarm_mesafesi = 40;
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 0);
    }
    else if(pot_deger == 5)
    {
      alarm_mesafesi = 50;
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
    }

    if(digitalRead(button) == 1)
      break;
  }
}

void loop()
{
  for(pos = 0; pos <= 180; pos++)
  {
    sg90.write(pos);
    delay(15);
    if(mesafe_olc() <= alarm_mesafesi)
    {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(buzzer, 1);
    }
    if(digitalRead(button) == 1)
    {
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(buzzer, 0);
    }
  }

  for(pos = 180; pos >= 0; pos--)
  {
    sg90.write(pos);
    delay(15);
    if(mesafe_olc() <= alarm_mesafesi)
    {
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
      digitalWrite(led5, 1);
      digitalWrite(buzzer, 1);
    }
    if(digitalRead(button) == 1)
    {
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      digitalWrite(led5, 0);
      digitalWrite(buzzer, 0);
    }
  }
}

int mesafe_olc()
{
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  return (pulseIn(echo, HIGH) / 2) / 29.1;
}

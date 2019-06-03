#include <RFID.h>
#include <SPI.h>

#define red 7
#define green 6

RFID lrt720(10,9);

byte kart[5] = {85,30,164,133,106};
boolean verify = true;

void setup()
{
  SPI.begin();
  lrt720.init();

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  verify = true;
  if(lrt720.isCard())
  {
    for(int i = 0; i < 5; i++)
      if(lrt720.serNum[i] != kart[i])
        verify = false;
        
    if(verify == true)
    {
      digitalWrite(green, HIGH);
      delay(1000);
      digitalWrite(green, LOW);
    }
    else
    {
      digitalWrite(red, HIGH);
      delay(1000);
      digitalWrite(red, LOW);
    }
    lrt720.halt();
  }
}

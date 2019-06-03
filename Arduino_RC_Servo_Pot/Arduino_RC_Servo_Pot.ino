#include <Servo.h>

#define potPin A0

Servo sg90;

void setup()
{
  sg90.attach(3);
}

void loop()
{
  sg90.write(map(analogRead(potPin),0,1023,0,180));
  delay(15);
}

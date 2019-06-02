#include <Keypad.h>

#define satir 4
#define sutun 4

char keys[satir][sutun] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte satirPin[satir] = {12,11,10,9};
byte sutunPin[sutun] = {8,7,6,5};

Keypad Keys = Keypad(makeKeymap(keys), satirPin, sutunPin, satir, sutun);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Keys.getKey())
    Serial.println(Keys.getKey());
}

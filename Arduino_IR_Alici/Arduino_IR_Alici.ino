#include <IRremote.h>

#define Led 3
#define ButtonOnOff 0xFFFFFF //kumandanın her hangibir tuşunun hex conu gir

IRrecv IR(2);
decode_results results;

void setup()
{
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(Led, OUTPUT);
  digitalWrite(Led, LOW);
}

void loop()
{
  if(IR.decode(&results))
  {
    if(results.value == ButtonOnOff)
      digitalWrite(Led, !digitalRead(Led));
    
    Serial.println(results.value);
    IR.resume();
  }
}

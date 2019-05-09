const int pot = A0;
const int buzzer = 11;

void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  analogWrite(buzzer,map(analogRead(pot),0,1023,0,255));
}

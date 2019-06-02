#define prop A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Toprak Nem Miktari: ");
  Serial.println(analogRead(prop));
}

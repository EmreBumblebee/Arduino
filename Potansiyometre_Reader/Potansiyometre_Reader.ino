const int pot = A0;
int data;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  data = analogRead(pot);
  Serial.print("Okunan Deger: ");
  Serial.println(data);
  Serial.print("Voltaj: ");
  Serial.println((data * 5) / 1023.0);
}

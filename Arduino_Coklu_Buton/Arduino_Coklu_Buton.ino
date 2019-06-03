int temp;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A0);
  if(temp < 950)
    Serial.println("1");
  else if(temp > 880 && temp < 980)
    Serial.println("2");
  else if(temp > 800 && temp < 900)
    Serial.println("3");
  else if(temp > 750 && temp < 820)
    Serial.println("4");
  else
    Serial.println("0");
}

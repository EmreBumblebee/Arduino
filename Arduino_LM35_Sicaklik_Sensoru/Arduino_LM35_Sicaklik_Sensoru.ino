const int lm35 = A3;
const int red = 5;
const int green = 4;
const int blue = 3;

int sensorDegeri = 0;
float voltajDegeri = 0;
float sicaklikDegeri = 0;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorDegeri = analogRead(lm35);
  Serial.print("Sicaklik: ");
  Serial.println(sensorDegeri);

  voltajDegeri = (sensorDegeri / 1023.0) * 5000; // milivolt converter
  Serial.print("Voltaj: ");
  Serial.println(voltajDegeri);

  sicaklikDegeri = voltajDegeri / 10.0; //sıcaklığın hesaplanması
  Serial.print("Sicaklik: ");
  Serial.println(sicaklikDegeri);

  // RGB Led
  if(sicaklikDegeri >= 35)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
  else if(sicaklikDegeri <= 35 && sicaklikDegeri >= 30)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  }
  else if(sicaklikDegeri < 30)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  }
}

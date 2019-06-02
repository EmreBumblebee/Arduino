#define Xaksis A0
#define Yaksis A1
#define Button 7

void setup()
{
  Serial.begin(9600);
  pinMode(Button, INPUT);
}

void loop()
{
  Serial.print("Button: ");
  Serial.println(digitalRead(Button));
  Serial.print("X Aksis: ");
  Serial.println(analogRead(Xaksis));
  Serial.print("Y Aksis: ");
  Serial.println(analogRead(Yaksis));
  Serial.println("******************************");
}

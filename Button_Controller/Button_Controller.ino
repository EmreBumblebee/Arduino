int led = 4;
int button = 5;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  digitalWrite(led, digitalRead(button));
}

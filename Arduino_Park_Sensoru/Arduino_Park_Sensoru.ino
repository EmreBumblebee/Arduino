const int trigger = 12;
const int echo = 11;
const int buzzer = 2;
const int blueLed = 3;
const int greenLed = 4;
const int yellowLed = 5;
const int redLed = 6;

int times;
int distance;

void setup()
{
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);

  times = pulseIn(echo, HIGH);
  distance = (times / 2) / 29.1;

  if(distance <= 10)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(250);
  }
  else if(distance <= 25)
  {
    digitalWrite(yellowLed, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(500);
  }
  else if(distance <= 50)
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(greenLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(750);
  }
  else
  {
    digitalWrite(blueLed, HIGH);
    delay(50);
    digitalWrite(blueLed, LOW);
    delay(1000);
  }
}

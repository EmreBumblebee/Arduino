const int echo = 8;
const int trigger = 9;

const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

int times = 0;
int distance = 0;

void setup()
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);
  times = pulseIn(echo, HIGH);
  distance = (times / 2) / 29.1;

  if(distance <= 30)
  {
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, HIGH);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
  }
  else
  {
    // motorların ikiside ileri yönünde dönmeli
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
  }
}

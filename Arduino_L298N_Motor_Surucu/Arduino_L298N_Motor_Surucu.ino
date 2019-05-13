const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;
const int en1 = 5;
const int en2 = 6;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

void loop()
{
  digitalWrite(en1, 255);
  digitalWrite(en2, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

//https://www.youtube.com/watch?v=kE0Vrtbw4Vw

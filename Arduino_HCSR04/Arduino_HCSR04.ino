const int triger = 8;
const int echo = 9;

int times;
int distance;

void setup()
{
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(triger, HIGH);
  delayMicroseconds(1000);  
  digitalWrite(triger, LOW);
  
  times = pulseIn(echo, HIGH);
  distance = (times / 2) / 29.1;

  Serial.println("Cisme olan uzaklık: ");
  Serial.print(distance);
}

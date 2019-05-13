const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 5;
const int rightBackward = 4;

const int leftSensor = 6;
const int rightSensor = 7;

int leftStatus, rightStatus;

void setup()
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  leftStatus = digitalRead(leftSensor);
  rightStatus = digitalRead(rightSensor);

  Serial.print("Left Sensor: ");
  Serial.println(leftStatus);
  Serial.print("Right Sensor: ");
  Serial.println(rightStatus);
  Serial.println("------------------------");
  
  if(leftStatus == LOW && rightStatus == LOW) // ileri
  {
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
  }
  else if(leftStatus == LOW && rightStatus == HIGH)// sağ
  {
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, HIGH);
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
  }
  else if(leftStatus == HIGH && rightStatus == LOW)// sol
  {
    digitalWrite(rightForward, HIGH);
    digitalWrite(rightBackward, LOW);
    digitalWrite(leftForward, HIGH);
    digitalWrite(leftBackward, LOW);
  }
  else// durdur
  {
    digitalWrite(rightForward, LOW);
    digitalWrite(rightBackward, LOW);
    digitalWrite(leftForward, LOW);
    digitalWrite(leftBackward, LOW);
  }
  delay(25);

  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);

  delay(50);
}

int pot = A0;
int pwm = 3;
int pot_deger = 0;
int pwm_deger = 0;

void setup()
{
  pinMode(pot, INPUT);
  pinMode(pwm, OUTPUT);
}

void loop() {
  pot_deger = analogRead(pot);
  pwm_deger = map(pot_deger, 0, 1023, 0, 255);

  analogWrite(pwm, pwm_deger);
}

int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int pot = 1;
int i = 5;
int j = 0;
int delay_speed = 0;
int delay_speed2=0;
int pwm = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(pwm , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (i; i < 11; i++) {
    delay_speed = analogRead(pot);
    if (i < 100) {
      /*digitalWrite(i, HIGH);
      delay(500);
      digitalWrite(i, LOW);
      delay(1023 - delay_speed);*/
      analogWrite(pwm, delay_speed);
      if (i == 10) {
        i = 4;

      }
      j = i;
      if (delay_speed < 102) {
        i = 100;
      }
    }
  Serial.print("delay = ");
  Serial.print(delay_speed);
  Serial.print("    ");
  }
  delay_speed2 = analogRead(pot);
  if (delay_speed2 > 102) {
    
    i = 4;
    Serial.print(i);
  }




}




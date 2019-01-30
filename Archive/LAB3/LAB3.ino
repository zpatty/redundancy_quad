int pot = 1;
int forward = 3;
int reverse = 5;
int potread = 0;
int motor;
void setup() {
  // put your setup code here, to run once:
  pinMode(forward , OUTPUT);
  pinMode(reverse , OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
potread=analogRead(pot);
motor=map(potread,0,1023, 0, 255);
if (motor < 120){
  analogWrite(reverse, 70);
  analogWrite(forward, 0);
}
else if (motor >120 && motor < 160){
  analogWrite(forward, 0);
  analogWrite(reverse, 0);
}
else {
  analogWrite(forward, 70);
  analogWrite(reverse, 0);
}
}

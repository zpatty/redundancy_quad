int motor1speed = 25;
int motor2speed = 25;
int motor1a = 6;
int motor1b = 9;
int motor2a = 10;
int motor2b = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(motor1a, motor1speed);
    analogWrite(motor2a, motor2speed);
    analogWrite(motor1b, 0);
    analogWrite(motor2b, 0);
}

int peepin = A0;
int pressure = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(peepin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
pressure = analogRead(peepin);
Serial.println(pressure);
}

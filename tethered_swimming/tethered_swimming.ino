
String go = "";
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(4,LOW);
  digitalWrite(2, HIGH);
  //delay(400);
  
  digitalWrite(3, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4,LOW);
  delay(1000); // wait for a minute
  
}

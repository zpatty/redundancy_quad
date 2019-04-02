
String go = "";
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(400); // wait
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(500); // wait for a minute
  
}

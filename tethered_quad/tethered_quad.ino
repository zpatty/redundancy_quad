
String go = "";
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  while(go != "stop"){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  Serial.write("POWER!");
  Serial.println();
  delay(250); // wait
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); 
  Serial.write("LOW");
  Serial.println();
  delay(2000);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(250);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(2000);
  if (Serial.available() > 0){
    go = Serial.readString();
    Serial.print(go);
  }
  if (go == "stop"){
    while(1 == 1){
      
    }
  }
  }
}

int Pin4=0;
int Pin5=0;
int lastPin4=0;
int counter4=0;
int Lastcounter=0;
int Button2=0;
int voltage = 0;
int ledpin[]=[1,2,3,4,5,6,7,8];
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600); 
  pinMode(12, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(1, INPUT);

  attachInterrupt(1, Button, FALLING);
}

// the loop function runs over and over again forever
void loop() {
  voltageb = analogRead(1);
  voltage = voltage/256*5;

  if (voltage < 2.5){
    for (int i=0; i<8; i++){
      if (bitRead(voltageb, i) ==1){
        digitalWrite(ledpin[i+1], LOW);
      }
      else {
        digitalWrite(ledpin[i+1], HIGH);
      }
    }
  }
  else{
    while (flag2 == 0){
      if (
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  Pin4=digitalRead(12);
  Pin5=digitalRead(3);
  digitalWrite(4, Pin4);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(5, Pin5);    // turn the LED off by making the voltage LOW
 if (Button2==0) {
    Button2=0;
    if (Pin4==LOW){
      delay(200);
      counter4++;
     
    }
    if (counter4!=Lastcounter){
      if (counter4%2>=1){
        digitalWrite(6, HIGH);
      }
      else {
        digitalWrite(6, LOW);
      }
      if ((counter4/2)%2>=1) {
        digitalWrite(7, HIGH);
      }
      else {
        digitalWrite(7, LOW);
      }
      if ((counter4/4)%2>=1) {
        digitalWrite(8, HIGH);
      }
      else {
        digitalWrite(8, LOW);
      }
      if ((counter4/8)%2>=1) {
        digitalWrite(9, HIGH);
      }
      else {
        digitalWrite(9, LOW);
      }
      if (counter4>=16){
        counter4=0;
      }
  
      Lastcounter=counter4;
      Serial.print(counter4);
    }
  }
   if (Button2==1) {
    Button2=1;
    if (Pin4==LOW){
      delay(200);
      counter4--;
     
    }
    if (counter4!=Lastcounter){
      if (counter4%2>=1){
        digitalWrite(6, HIGH);
      }
      else {
        digitalWrite(6, LOW);
      }
      if ((counter4/2)%2>=1) {
        digitalWrite(7, HIGH);
      }
      else {
        digitalWrite(7, LOW);
      }
      if ((counter4/4)%2>=1) {
        digitalWrite(8, HIGH);
      }
      else {
        digitalWrite(8, LOW);
      }
      if ((counter4/8)%2>=1) {
        digitalWrite(9, HIGH);
      }
      else {
        digitalWrite(9, LOW);
      }
      if (counter4<=0){
        counter4=16;
      }
  
      Lastcounter=counter4;
      Serial.print(counter4);
    }
  }
}

void Button() {
  for (int i=1000; i--; i<1) { // a time-killing loop
 } 
  if (Button2==0){
    Button2=1;
  }
  else {
    Button2=0;
  }
}


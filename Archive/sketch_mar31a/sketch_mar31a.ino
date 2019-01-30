int led=13;
void wait(void);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print('H');
wait();
Serial.print('E');
wait();
Serial.print('L');
wait();
Serial.print('L');
wait();
Serial.print('O');
wait();
Serial.print(' ');
wait();
Serial.print('W');
wait();
Serial.print('O');
wait();
Serial.print('R');
wait();
Serial.print('L');
wait();
Serial.print('D');
wait();
}

void wait(){
  delay(100);
}


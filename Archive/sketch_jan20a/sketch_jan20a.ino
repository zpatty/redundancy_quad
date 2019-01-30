/Blink two LEDs and then interrupt when a push button is pressed
int interrupt_pin = 2; // this provides the interrupt signal
int led1 = 6;
int led2 = 7;
int pushbuttonPin = 2
int led1_state=0
int led2_state=0
void setup() {
pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
pinMode(interrupt_pin, INPUT);
 attachInterrupt(0, turn_on_both_leds, CHANGE);
} // end setup
void loop() {
  led1_state=HIGH;
  led2_state=LOW;
 digitalWrite(led1,led1_state);
 digitalWrite(led2,led2_state);
 delay(500);
 led1_state=LOW;
 led2_state=HIGH;
 digitalWrite(led1,led1_state);
 digitalWrite(led2,led2_state);
 delay(3000);
} // end loop
void turn_on_both_leds() {
  long i;
 digitalWrite(led1,LOW);
 digitalWrite(led2,LOW);
 for (int i=1000; i--; i<1) { // a time-killing loop
 digitalWrite(led1,led1_state);
 digitalWrite(led2,led2_state);
 } // end for
} // end turn_on_both_leds

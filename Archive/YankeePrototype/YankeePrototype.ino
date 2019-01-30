#include <SoftReset.h>

/*
  This code is designed to measure the time between swings of a bat in order to determine its second moment of inertia.

*/
#define BreakBeamPin 2
#define DebounceTimeMicros 20 //Will not count two interrupts that occur less than this many microseconds apart.
#define NumOfCycles 10 //this denotes the number of swings for which to calculate the average.
#define PrepCycles 5 //This is the number of cycles through which the bat must be allowed to swing before we begin calculating its period.
#define AllowableStdev 1000
#include <avr/io.h> 
#include <avr/wdt.h>


void setup() {
  attachInterrupt(digitalPinToInterrupt(BreakBeamPin), marktime, RISING); //marktime is a function that measures times between when the beam is broken.
  Serial.begin(9600);
  pinMode(13, OUTPUT); //Pin 13 is used as an LED to tell the user whether the beam connected.
}

int i = -PrepCycles; //this index counts the number of swings of the bat. It's set to the negative of the number of preparation cycles.
uint32_t zero = micros(); //zero is the time we're measuring from.
uint32_t duration[NumOfCycles]; //duration is the time we're measuring to, and we take 15 measurements.
double average; //This value will be set to the average of the duration values
double stdev;  //This value calculates the standard deviation of the durations.
bool flag = 0; //The bat breaks the beam twice per cycle. This determines which half of the cycle the bat is on.
int go = 0;
void loop() {
  if (Serial.available() > 0) {
    digitalWrite(13, digitalRead(2)); //turn the LED on pin 13 on if the beam is unbroken.
    if (i == NumOfCycles) {
      //when the beam has been broken the proper number of times, we do three things:

      //******************
      //Thing 1: calculate the average time between swings.
      for (int j = 0; j < NumOfCycles; j++) {
        average += (double)duration[j] / NumOfCycles;
      }

      //*****************
      //Thing 2: calculate the standard deviation of the swings
      double squaresum = 0;
      for (int j = 0; j < NumOfCycles; j++) {
        squaresum += ((double)duration[j] - average) * ((double)duration[j] - average);
        //Serial.println(duration[j]);
      }
      stdev = sqrt(squaresum / (NumOfCycles - 1));

      //*****************
      //Thing 3: Print that information to the Serial Monitor.
      //Serial.print("Ave:");Serial.print("\t");Serial.println("StDev");
      Serial.print(average);
      Serial.print("\n");
      //Serial.print("\t");Serial.println(stdev);
      //if(stdev > AllowableStdev){Serial.println("TEST FAILED: Standard Deviation too large");}
      //else{Serial.println("TEST PASSED: Standard Deviation Within Allowable Range");}
      average = 0;
      squaresum = 0;
      //Serial.print("\n\nProgram Done.\nReset Arduino when ready to begin \n");
      soft_restart();
      
    }
  }
}

void marktime(void) {
  //whenever the beam is broken, the function marktime is called.

  //First, let's do a quick debounce check, to make sure the beam doesn't get broken twice in a row by accident.
  if (micros() - zero > DebounceTimeMicros) {
    if (flag == 1) {
      //if we pass the debounce check, calculate the time since the last time the beam was broken.
      if (i >= 0) { //start recording periods in the duration vector only once the number of prep cycles has been completed.
        duration[i] = micros() - zero;
      }
      //then reset the measurement
      zero = micros();
      i++;
      flag = 0; //lower the flag so we only count one beam-break per oscillation of the bat.
    }
    else {
      flag = 1;  //if we didn't count the last beam-break, count this one.
    }
  }
}

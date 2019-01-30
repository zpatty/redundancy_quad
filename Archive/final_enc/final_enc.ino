//this is the code for a bagel delivery robot. It drives in straight line after a bagel is dropped onto the "ladder" (which has a pressure sensor).
//When it reaches the target, the ultrasonic "eyes" slows it and stops it, and then triggers the telescoping rod, which tilts the ladder and drops the bagel

//motors:
int motor1a = 6;
int motor1b = 9;
int motor2a = 10;
int motor2b = 11;
//ultrasonic pins:
int trigPin = 4;
int echoPin = 5;
//the duration between sending a receiving ultrasonic signal and the calculated distance to the obstacle
long duration, distance;
//PWM for the motor speed
int motor1speed = 235;
int motor2speed = 235;
//stores last few distances to prevent artifacts from impacting ultrasonic eyes
int sdistance[2];
//dummy variables
int i = 0;
//telescoping motor pins
int tmotor2 = 2;
int tmotor3 = 3;
//reverse PWM for stopping
int reverse1 = 0;
int reverse2 = 0;
//pressure sensor pin
int pressurepin = A0;
//pressure value
int pressure = 0;
//dummy
int start = 0;
//encoder pins
int encoder1PinA = 7;
int encoder1PinB = 8;
int encoder1Pos = 0;
int encoder1PinALast = LOW;
//dummy
int n = LOW;
//encoders
int pos1 = 0;
int encoder2PinA = 12;
int encoder2PinB = 13;
int encoder2Pos = 0;
int encoder2PinALast = LOW;
int pos2 = 0;
//encoder compensation constant
int k = 5;
int error = 0;

void setup() {
  // put your setup code here, to run once:
  //initialize all inputs and outputs
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tmotor2, OUTPUT);
  pinMode(tmotor3, OUTPUT);
  pinMode(pressurepin, INPUT);
  Serial.begin(9600);
  pinMode (encoder1PinA, INPUT);
  pinMode (encoder1PinB, INPUT);
  pinMode (encoder2PinA, INPUT);
  pinMode (encoder2PinB, INPUT);
}

void loop() {
  //first, wait for pressure reading from bagel dropping. begin main code once this happens
  pressure = analogRead(pressurepin);
  if (pressure > 100) {
    start = 1;
  }
  //begin main code when start flag is raised
  if (start == 1) {
    //call encoder functions to measure relative position
    pos1 = measure1();
    pos2 = measure2();

    error = pos1 - pos2; //difference between wheel rotations

    motor1speed = motor1speed - error / k; //change speed to compensate for error using the error over our compensation constant
    motor2speed = motor2speed + error / k;

    pos1 = 0; // reset position
    pos2 = 0;

    delay(50);

    //write speeds to motors
    analogWrite(motor1a, motor1speed);
    analogWrite(motor2a, motor2speed);
    analogWrite(motor1b, reverse1);
    analogWrite(motor2b, reverse2);

    //send out pulse from the ultrasonic sensor
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    //find the duration to receive the echo
    //pulseIn waits for the pin to go HIGH, starts timing, then waits for the pin to go LOW and stops timing. 
    //Returns the length of the pulse in microseconds or 0 if no complete pulse was received within the timeout.
    duration = pulseIn(echoPin, HIGH); 
    //calculate distance using equation from
    distance = (duration / 2) / 29.1; //equation from http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
    sdistance[i] = distance; // store the distance in array
    i++; //dummy variable for counting through distance storage array
    if (i == 1) {
      i = 0;
    }
    //print out some values for sanity check
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print("motor1speed = ");
    Serial.println(motor1speed);
    delay(h);
    //if statement to slow down. optimal thresholds change drastically with weight.
    if (distance < 15 && sdistance[0] < 15 && sdistance[1] < 15 && motor1speed > 75) {
      motor1speed = motor1speed - (motor1speed - distance) / 10;
      motor2speed = motor2speed - (motor2speed - distance) / 10;
    }
    analogWrite(motor1a, motor1speed); //write motor speeds
    analogWrite(motor2a, motor2speed);
    analogWrite(motor1b, reverse1);
    analogWrite(motor2b, reverse2);
    //if statement to stop robot
    if (distance < 15 && sdistance[0] < 15 && sdistance[1] < 15) {
     
      motor1speed = 0; // send motor speeds to 0
      motor2speed = 0;
      reverse1 = 255; // pulse reverse signal to stop on a dime
      reverse2 = 255;
      analogWrite(motor1a, motor1speed);
      analogWrite(motor2a, motor2speed);
      analogWrite(motor1b, reverse1);
      analogWrite(motor2b, reverse2);
      delay(200); // length of reverse pulse
      reverse1 = 0;
      reverse2 = 0;
      analogWrite(motor1b, reverse1);
      analogWrite(motor2b, reverse2);
      Serial.print("STOP!");
      delay(750); //wait before triggering telescoping
      digitalWrite(2, HIGH); // pulse the telescoping motor for half a second
      delay(450);
      digitalWrite(2, LOW);
      z = 0;
      exit(0); // exit loop permanently
    }


    /*if (distance < 10 && sdistance[0] < 10 && sdistance[1] < 10) {
      motor1speed = 0;
      motor2speed = 0;
      if (z==1){
        digitalWrite(2, HIGH);
        delay(400);
        digitalWrite(2, LOW);
        z=0;
        Serial.print("z = ");
        Serial.print(z);
        Serial.print("Stop Distance = ");
        Serial.print(distance);
        exit(0);
      }*/

  }
}

//function for first encoder
float measure1()
{
  //read encoder pin
  n = digitalRead(encoder1PinA);
  //compare to last reading
  if ((encoder1PinALast == LOW) && (n == HIGH)) {
    //find relative position vs second encoder
    if (digitalRead(encoder1PinB) == LOW) {
      encoder1Pos--; //if the last reading for this encoder was LOW and the current one is HIGH and if the other encoder is LOW, then we know we're slightly behind and adjust
    } else {
      encoder1Pos++; // if not, we know we're slightly ahead and adjust
    }
    Serial.println (encoder1Pos);
    Serial.print ("");
  }
  encoder1PinALast = n; //store last reading

  return encoder1Pos;

}

//measuring encoder position of motor 2
//same structure as above
float measure2()
{
  n = digitalRead(encoder2PinA);
  if ((encoder2PinALast == LOW) && (n == HIGH)) {
    if (digitalRead(encoder2PinB) == LOW) {
      encoder2Pos--;
    } else {
      encoder2Pos++;
    }
    Serial.println (encoder2Pos);
    Serial.print ("");
  }
  encoder2PinALast = n;

  return encoder2Pos;

}



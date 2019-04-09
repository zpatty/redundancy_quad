#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_SIMBLEE.h>
#include <utility/imumaths.h>

/* This driver reads raw data from the BNO055

   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground

   History
   =======
   2015/MAR/03  - First release (KTOWN)

/* Set the delay between fresh samples */
#define BNO055_SAMPLERATE_DELAY_MS (100)
//Adafruit_BNO055 bno = Adafruit_BNO055();
Adafruit_BNO055_SIMBLEE bno = Adafruit_BNO055_SIMBLEE();

//pins for the IO pins on BNO055
int vddio = 2;
//int gndio = 6;
int vddio20 = 20;
int vddio21 = 21;
int vddio28 = 28; 

int gndio23 = 23;
int gndio25 = 25;
int gndio29 = 29;

int leg0pin = 18;
int leg1pin = 17;
int leg2pin = 19;
int leg3pin = 14;
int leg4pin = 13;
int leg5pin = 10;
int leg6pin = 15;
int leg7pin = 16;
/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void)
{

  //power and gnd lines for the BNO055
  pinMode(vddio20, OUTPUT);
  pinMode(vddio21, OUTPUT);
  pinMode(vddio28, OUTPUT);
  pinMode(gndio23, OUTPUT);
  pinMode(gndio25, OUTPUT);
  pinMode(gndio29, OUTPUT);

  // mosfet gpios for the legs
  pinMode(leg0pin, OUTPUT);
  pinMode(leg1pin, OUTPUT);
  pinMode(leg2pin, OUTPUT);
  pinMode(leg3pin, OUTPUT);
  pinMode(leg4pin, OUTPUT);  
  pinMode(leg5pin, OUTPUT);
  pinMode(leg6pin, OUTPUT);
  pinMode(leg7pin, OUTPUT);
  
  digitalWrite(vddio20, HIGH);
  digitalWrite(vddio21, HIGH);
  digitalWrite(vddio28, HIGH);
  digitalWrite(gndio23, LOW);
  digitalWrite(gndio25, LOW);
  digitalWrite(gndio29, LOW);
  digitalWrite(leg7pin, HIGH);
  delay(1000);

  
  Serial.begin(9600);

  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");
  delay(100);
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(false);

   
  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void)
{
  
  // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055_SIMBLEE::VECTOR_EULER);

  /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(euler.x());
  Serial.print(" Y: ");
  Serial.print(euler.y());
  Serial.print(" Z: ");
  Serial.print(euler.z());
  Serial.println("\t\t");
  
  /*
  // Quaternion data
  imu::Quaternion quat = bno.getQuat();
  Serial.print("qW: ");
  Serial.print(quat.w(), 4);
  Serial.print(" qX: ");
  Serial.print(quat.y(), 4);
  Serial.print(" qY: ");
  Serial.print(quat.x(), 4);
  Serial.print(" qZ: ");
  Serial.print(quat.z(), 4);
  Serial.print("\t\t");
  */

  /* Display calibration status for each sensor. */
//  uint8_t system, gyro, accel, mag = 0;
//  bno.getCalibration(&system, &gyro, &accel, &mag);
//  Serial.print("CALIBRATION: Sys=");
//  Serial.print(system, DEC);
//  Serial.print(" Gyro=");
//  Serial.print(gyro, DEC);
//  Serial.print(" Accel=");
//  Serial.print(accel, DEC);
//  Serial.print(" Mag=");
//  Serial.println(mag, DEC);

//  digitalWrite(leg0pin, HIGH);
//  digitalWrite(leg1pin, HIGH);
//  digitalWrite(leg2pin, HIGH);
//  digitalWrite(leg3pin, HIGH);
//  digitalWrite(leg4pin, HIGH);
//  digitalWrite(leg5pin, HIGH);
//  digitalWrite(leg6pin, HIGH);
//  digitalWrite(leg7pin, HIGH);
//  delay(100);
//  digitalWrite(leg0pin, LOW);
//  digitalWrite(leg1pin, LOW);
//  digitalWrite(leg2pin, LOW);
//  digitalWrite(leg3pin, LOW);
//  digitalWrite(leg4pin, LOW);
//  digitalWrite(leg5pin, LOW);
//  digitalWrite(leg6pin, LOW);
//  digitalWrite(leg7pin, LOW);
//  delay(3000);
  
  delay(BNO055_SAMPLERATE_DELAY_MS);
}

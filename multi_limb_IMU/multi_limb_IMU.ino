#include <SimbleeForMobile.h>
//#include "thermometer_png.h"
//#include "CAT.h"

/* MPU9250 
 by: Kris Winer (should probably credit him for like 99.999% of the code)
 license: Beerware - Use this code however you'd like. If you 
 find it useful you can buy me a beer some time. (from Kris Winer)
  */
#include <SPI.h>
#include <Wire.h> 
#define AK8963_ADDRESS   0x0C

#define WHO_AM_I_AK8963  0x00 // should return 0x48
#define INFO             0x01
#define AK8963_ST1       0x02  // data ready status bit 0
#define AK8963_XOUT_L   0x03  // data
#define AK8963_XOUT_H  0x04
#define AK8963_YOUT_L  0x05
#define AK8963_YOUT_H  0x06
#define AK8963_ZOUT_L  0x07
#define AK8963_ZOUT_H  0x08
#define AK8963_ST2       0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL      0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC      0x0C  // Self test control
#define AK8963_I2CDIS    0x0F  // I2C disable
#define AK8963_ASAX      0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY      0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ      0x12  // Fuse ROM z-axis sensitivity adjustment value

#define SELF_TEST_X_GYRO 0x00                  
#define SELF_TEST_Y_GYRO 0x01                                                                           
#define SELF_TEST_Z_GYRO 0x02

#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E    
#define SELF_TEST_Z_ACCEL 0x0F

#define SELF_TEST_A      0x10

#define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define XG_OFFSET_L      0x14
#define YG_OFFSET_H      0x15
#define YG_OFFSET_L      0x16
#define ZG_OFFSET_H      0x17
#define ZG_OFFSET_L      0x18
#define SMPLRT_DIV       0x19
#define CONFIG           0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG     0x1C
#define ACCEL_CONFIG2    0x1D
#define LP_ACCEL_ODR     0x1E   
#define WOM_THR          0x1F   

#define MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define FIFO_EN          0x23
#define I2C_MST_CTRL     0x24   
#define I2C_SLV0_ADDR    0x25
#define I2C_SLV0_REG     0x26
#define I2C_SLV0_CTRL    0x27
#define I2C_SLV1_ADDR    0x28
#define I2C_SLV1_REG     0x29
#define I2C_SLV1_CTRL    0x2A
#define I2C_SLV2_ADDR    0x2B
#define I2C_SLV2_REG     0x2C
#define I2C_SLV2_CTRL    0x2D
#define I2C_SLV3_ADDR    0x2E
#define I2C_SLV3_REG     0x2F
#define I2C_SLV3_CTRL    0x30
#define I2C_SLV4_ADDR    0x31
#define I2C_SLV4_REG     0x32
#define I2C_SLV4_DO      0x33
#define I2C_SLV4_CTRL    0x34
#define I2C_SLV4_DI      0x35
#define I2C_MST_STATUS   0x36
#define INT_PIN_CFG      0x37
#define INT_ENABLE       0x38
#define DMP_INT_STATUS   0x39  // Check DMP interrupt
#define INT_STATUS       0x3A
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define MOT_DETECT_STATUS 0x61
#define I2C_SLV0_DO      0x63
#define I2C_SLV1_DO      0x64
#define I2C_SLV2_DO      0x65
#define I2C_SLV3_DO      0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET  0x68
#define MOT_DETECT_CTRL  0x69
#define USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define PWR_MGMT_2       0x6C
#define DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define DMP_REG_1        0x70
#define DMP_REG_2        0x71 
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define WHO_AM_I_MPU9250 0x75  // Should return 0x71
#define XA_OFFSET_H      0x77
#define XA_OFFSET_L      0x78
#define YA_OFFSET_H      0x7A
#define YA_OFFSET_L      0x7B
#define ZA_OFFSET_H      0x7D
#define ZA_OFFSET_L      0x7E

// Using the MSENSR-9250 breakout board, ADO is set to 0 
// Seven-bit device address is 110100 for ADO = 0 and 110101 for ADO = 1
#define ADO 0
#if ADO
#define MPU9250_ADDRESS 0x68  // Device address when ADO = 1
#else
#define MPU9250_ADDRESS 0x68  // Device address when ADO = 0
#define AK8963_ADDRESS 0x0C   //  Address of magnetometer
#endif  

#define AHRS true         // set to false for basic data read
#define SerialDebug false   // set to true to get Serial output for debugging

// Set initial input parameters
enum Ascale {
  AFS_2G = 0,
  AFS_4G,
  AFS_8G,
  AFS_16G
};

enum Gscale {
  GFS_250DPS = 0,
  GFS_500DPS,
  GFS_1000DPS,
  GFS_2000DPS
};

enum Mscale {
  MFS_14BITS = 0, // 0.6 mG per LSB
  MFS_16BITS      // 0.15 mG per LSB
};

// Specify sensor full scale
uint8_t Gscale = GFS_250DPS;
uint8_t Ascale = AFS_2G;
uint8_t Mscale = MFS_16BITS; // Choose either 14-bit or 16-bit magnetometer resolution
uint8_t Mmode = 0x02;        // 2 for 8 Hz, 6 for 100 Hz continuous magnetometer data read
float aRes, gRes, mRes;      // scale resolutions per LSB for the sensors

#define AHRS true         // Set to false for basic data read
#define SerialDebug true  // Set to true to get Serial output for debugging

// Pin definitions
int intPin = 11;  // These can be changed, 2 and 3 are the Arduinos ext int pins
int SCLpin = 16;
int SDApin = 17;

int16_t accelCount[3];  // Stores the 16-bit signed accelerometer sensor output
int16_t gyroCount[3];   // Stores the 16-bit signed gyro sensor output
int16_t magCount[3];    // Stores the 16-bit signed magnetometer sensor output
float magCalibration[3] = {0, 0, 0}, magbias[3] = {0, 0, 0};  // Factory mag calibration and mag bias
float gyroBias[3] = {0, 0, 0}, accelBias[3] = {0, 0, 0};      // Bias corrections for gyro and accelerometer
int16_t tempCount;      // temperature raw count output
float   temperature;    // Stores the real internal chip temperature in degrees Celsius
float   SelfTest[6];    // holds results of gyro and accelerometer self test

// global constants for 9 DoF fusion and AHRS (Attitude and Heading Reference System)
float GyroMeasError = PI * (40.0f / 180.0f);   // gyroscope measurement error in rads/s (start at 40 deg/s)
float GyroMeasDrift = PI * (0.0f  / 180.0f);   // gyroscope measurement drift in rad/s/s (start at 0.0 deg/s/s)

float beta = sqrt(3.0f / 4.0f) * GyroMeasError;   // compute beta
float zeta = sqrt(3.0f / 4.0f) * GyroMeasDrift;   // compute zeta, the other free parameter in the Madgwick scheme usually set to a small or zero value
#define Kp 2.0f * 5.0f // these are the free parameters in the Mahony filter and fusion scheme, Kp for proportional feedback, Ki for integral
#define Ki 0.0f

uint32_t delt_t = 0; // used to control display output rate
uint32_t count = 0, sumCount = 0; // used to control display output rate
float pitch, yaw, roll;
float deltat = 0.0f;// sum = 0.0f;        // integration interval for both filter schemes
uint32_t lastUpdate = 0, firstUpdate = 0; // used to calculate integration interval
uint32_t Now = 0;        // used to calculate integration interval

float ax, ay, az, gx, gy, gz, mx, my, mz; // variables to hold latest sensor data values 
float q[4] = {1.0f, 0.0f, 0.0f, 0.0f};    // vector to hold quaternion
float eInt[3] = {0.0f, 0.0f, 0.0f};       // vector to hold integral error for Mahony method

float magBias[3],magScale[3];

int tmp102Address = 0x48;

int sampleNumber = 500;
String inputString = "";         // a String to hold incoming data

int NUM_SAMPLES = 50;
const uint8_t nSamples = 50;
uint8_t range = 0;
uint32_t sum = 0;
uint32_t average = 0;
uint8_t status;

float data[9];

// Robot

uint8_t Switch; // 8-bit field in which to store switch start ID number
uint8_t Wave1_b; // 8-bit field in which to store switch Wave1_b ID number
uint8_t FL1; // 8-bit field in which to store button FL1 ID number
uint8_t FL3; // 8-bit field in which to store button FL3 ID number
uint8_t FR1; // 8-bit field in which to store button FR1 ID number
uint8_t FR3; // 8-bit field in which to store button FR3 ID number
uint8_t RL1; // 8-bit field in which to store button RL1 ID number
uint8_t RL3; // 8-bit field in which to store button RL3 ID number
uint8_t RR1; // 8-bit field in which to store button RR1 ID number
uint8_t RR3; // 8-bit field in which to store button RR3 ID number
uint8_t Wave1_f; // 8-bit field in which to store switch Wave1_f ID number
uint8_t Wave2_b; // 8-bit field in which to store switch Wave2_b ID number
uint8_t Wave2_f; // 8-bit field in which to store switch Wave2_f ID number
uint8_t Wave3_b; // 8-bit field in which to store switch Wave3_b ID number
uint8_t Wave3_f; // 8-bit field in which to store switch Wave3_f ID number
uint8_t Wave2_sf; // 8-bit field in which to store switch Wave2_sf ID number
uint8_t Wave2_sb; // 8-bit field in which to store switch Wave2_sb ID number
uint8_t Wave3; // 8-bit field in which to store switch Wave3 ID number
uint8_t Warmup; // 8-bit field in which to store switch Warmup ID number  
uint8_t text_roll;
uint8_t text_pitch;
uint8_t text_yaw;
int fl1 = 23; // pin number for seg1
int fl3 = 4; // pin number for seg3
int fr1 = 3; // pin number for seg5
int fr3 = 8; // pin number for seg1
int rr1 = 19; // pin number for seg3
int rr3 = 18; // pin number for seg5
int rl1 = 30; // pin number for seg1
int rl3 = 28; // pin number for seg3

int wave1_f = 0; //initial value of indicator of wave1f mode
int Fl1 = 0; //initial value of indicator of Fl1 mode
int Fl3 = 0; //initial value of indicator of Fl3 mode
int Fr1 = 0; //initial value of indicator of Fr1 mode
int Fr3 = 0; //initial value of indicator of Fr3 mode
int Rl1 = 0; //initial value of indicator of Rl1 mode
int Rl3 = 0; //initial value of indicator of Rl3 mode
int Rr1 = 0; //initial value of indicator of Rr1 mode
int Rr3 = 0; //initial value of indicator of Rr3 mode
int wave1_b = 0; //initial value of indicator of wave1b mode
int wave2_f = 0; //initial value of indicator of wave2f mode
int wave2_b = 0; //initial value of indicator of wave2b mode
int wave3_f = 0; //initial value of indicator of wave3f mode
int wave3_b = 0; //initial value of indicator of wave3b mode
int wave2_sf = 0; //initial value of indicator of wave2sf mode
int wave2_sb = 0; //initial value of indicator of wave2sb mode
int wave3_s = 0; //initial value of indicator of wave3 mode
int warm_up = 0; //initial value of indicator of wave3 mode
int start = 0; //initial value of indicator of switch start
int onTime = 150; //on time for each segments
int offTime = 500; //off time for each segments
int coolTime = 0; //off time for each segment
unsigned long TIME = 60000*30; //Run time
uint32_t warmupTIME = 2200;
int fl1ID; //indicator of front left limb 1
int fl3ID; //indicator of front left limb 3
int fr1ID; //indicator of front right limb 1
int fr3ID; //indicator of front right limb 3
int rr1ID; //indicator of rear right limb 1
int rr3ID; //indicator of rear right limb 3
int rl1ID; //indicator of rear left limb 1
int rl3ID; //indicator of rear left limb 3
int rcount = 1;
unsigned long startTime;
unsigned long currentTime;


// ui setup
color_t screenColor = WHITE;
color_t textFieldColor = rgb(85,85,85); // input text field color (gray)
color_t textColor = WHITE; // input text color
color_t statusColor = BLACK; // status font color
int statusX = 50;
int statusY = 160;
int statusFont = 26; // status font size
color_t startColor = RED; // start font color
int startX = 80;
int startY = 195;
int startFont = 20; // start font size
color_t modeColor = BLACK;
int modeFont = 26;
int modeX = 20;
int modeY = 220;
color_t waveColor = GREEN;
int waveFont = 15;
int waveX1 = 5;
int waveX2 = 165;
int waveX3 = 95;
int wave1bY = 260;
int wave1fY = 305;
color_t setupColor = BLACK;
int setupFont = 26;
int setupX = 20;
int setupY = 60;
color_t onTimeColor = BLACK;
int onTimeFont = 20;
int onTimeX = 5;
int onTimeY = 95;
int offTimeX = 5;
int offTimeY = 135;
int coolTimeX = 155;
int coolTimeY = 95;
int TIMEX = 155;
int TIMEY = 135; 
int onTimeTextX = 85;
int onTimeTextY = 95;
int offTimeTextX = 85;
int offTimeTextY = 135;
int coolTimeTextX = 250;
int coolTimeTextY = 95;
int TIMETextX = 250;
int TIMETextY = 135;
int timeTextWidth = 67;
color_t offTimeColor = BLACK;
color_t coolTimeColor = BLACK;
color_t TIMEColor = BLACK;
int offTimeFont = 20;
int coolTimeFont = 20;
int TIMEFont = 20;
int startSwitchX = 175;
int startSwitchY = 195;
int waveSwitchX1 = 100;
int waveSwitchX2 = 260;
int waveSwitchX3 = 170;
int wave1bSwitchY = 255;
int wave1fSwitchY = 305;

color_t startSwitchColor = RED;
color_t waveSwitchColor = GREEN;
color_t limbIndColor = BLACK;
color_t limbFontColor = BLACK;
int limbFont = 20;
int fIDY = 475;
int rIDY = 525;
int l1IDX = 20;
int l2IDX = 50;
int l3IDX = 80;
int l4IDX = 110;
int r1IDX = 190;
int r2IDX = 220;
int r3IDX = 250;
int r4IDX = 280;
int limbIDL = 20;
int limbIDW = 20;
int fbuttonY = 300;
int rbuttonY = 350;
int l1buttonX = 0;
int l2buttonX = 40;
int l3buttonX = 80;
int l4buttonX = 120;
int r1buttonX = 165;
int r2buttonX = 205;
int r3buttonX = 245;
int r4buttonX = 285;
int buttonW = 39;
int imageX = 0;
int imageY = 0;

volatile bool needsUpdate;
uint32_t eventId;

int SDA = 2;
int pullup = 4;
int SCL = 3;
int interrupt = 5;
int VDDIO = 6;

void update();
void wave1b();
void wave1f();
void fl1event();
void fl3event();
void fr1event();
void fr3event();
void rl1event();
void rl3event();
void rr1event();
void rr3event();
void off();

void I2Cscan()
{
// scan for i2c devices
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknow error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

}


void setup() {
  pinMode(fl1, OUTPUT);
  pinMode(fl3, OUTPUT);
  pinMode(fr1, OUTPUT);
  pinMode(fr3, OUTPUT);
  pinMode(rr1, OUTPUT);
  pinMode(rr3, OUTPUT);
  pinMode(rl1, OUTPUT);
  pinMode(rl3, OUTPUT);
  pinMode(interrupt, INPUT);
  pinMode(VDDIO,OUTPUT);
  pinMode(pullup,OUTPUT);
  digitalWrite(VDDIO,HIGH);
  digitalWrite(pullup,HIGH);


  
  Wire2.beginOnPins(SCL,SDA);
  // TWBR = 12;  // 400 kbit/sec I2C speed
  Serial.begin(9600);
  
  while(!Serial){
    delay(100);
  }

  delay(5000);

  // Set up the interrupt pin, its set as active high, push-pull
  digitalWrite(interrupt, LOW);
  
  //I2Cscan();
  // IMU setup
  byte c = readByte(MPU9250_ADDRESS, WHO_AM_I_MPU9250);  // Read WHO_AM_I register for MPU-9250
  Serial.println(c, HEX);
  delay(100);
  if (c == 0x71) // WHO_AM_I should always be 0x68
  {  
    MPU9250SelfTest(SelfTest); // Start by performing self test and reporting values
    calibrateMPU9250(gyroBias, accelBias); // Calibrate gyro and accelerometers, load biases in bias registers
    delay(1000); 
    
    initMPU9250(); // Initialize device for active mode read of acclerometer, gyroscope, and temperature
  
    // Read the WHO_AM_I register of the magnetometer, this is a good test of communication
    byte d = readByte(AK8963_ADDRESS, WHO_AM_I_AK8963);  // Read WHO_AM_I register for AK8963
    delay(1000); 
  
    // Get magnetometer calibration from AK8963 ROM
    initAK8963(magCalibration); 
    getMres();
    delay(1000);  
  }
  else
  {
    Serial.print("Could not connect to MPU9250: 0x");
    Serial.println(c, HEX);
    while(1) ; // Loop forever if communication doesn't happen
  }

  SimbleeForMobile.advertisementData = "SEAQ 2.0";
  SimbleeForMobile.domain = "Simblee.com";
  SimbleeForMobile.deviceName = "SEAQ 2";
  SimbleeForMobile.begin();
}
void loop() {
  getOrientation();
  
  if(needsUpdate){
    update;
    needsUpdate = false;
  }
  if (start == 0){
      off();
  }
  if (start == 1){
    if (wave1_b == 1){
      wave1b();
    }
    if (wave1_f == 1){
      wave1f();
    }
    if (Fl1 == 1){
      fl1event();
    }
    if (Fl3 == 1){
      fl3event();
    }
    if (Fr1 == 1){
      fr1event();
    }
    if (Fr3 == 1){
      fr3event();
    } 
    if (Rl1 == 1){
      rl1event();
    }
    if (Rl3 == 1){
      rl3event();
    }
    if (Rr1 == 1){
      rr1event();
    }
    if (Rr3 == 1){
      rr3event();
    }        
  }
  SimbleeForMobile.process();
}

uint32_t ontime;
uint32_t offtime;
uint32_t cooltime;
unsigned long runtime;
void ui() { 
  SimbleeForMobile.beginScreen(screenColor,PORTRAIT); 
  
  SimbleeForMobile.drawText(statusX, statusY, "Status", statusColor, statusFont);
  SimbleeForMobile.drawText(startX, startY, "Start", startColor, startFont);
  SimbleeForMobile.drawText(modeX, modeY, "Mode", modeColor, modeFont);
  SimbleeForMobile.drawText(waveX1, wave1bY, "Sim R Diagonal", waveColor, waveFont);
  SimbleeForMobile.drawText(waveX2, wave1bY, "Sim L Diagonal", waveColor, waveFont);
  SimbleeForMobile.drawText(setupX, setupY, "Setup", setupColor, setupFont);
  SimbleeForMobile.drawText(onTimeX, onTimeY, "ON Time", onTimeColor, onTimeFont);
  SimbleeForMobile.drawText(offTimeX, offTimeY, "OFF Time", offTimeColor, offTimeFont);
  SimbleeForMobile.drawText(coolTimeX, coolTimeY, "COOL Time", coolTimeColor, coolTimeFont);
  SimbleeForMobile.drawText(TIMEX, TIMEY, "RUN Time", TIMEColor, TIMEFont);
  Switch = SimbleeForMobile.drawSwitch(startSwitchX,startSwitchY, startSwitchColor); 
  Wave1_b = SimbleeForMobile.drawSwitch(waveSwitchX1,wave1bSwitchY,waveSwitchColor); 
  Wave1_f = SimbleeForMobile.drawSwitch(waveSwitchX2,wave1bSwitchY,waveSwitchColor);
  FL1 = SimbleeForMobile.drawButton(l1buttonX, fbuttonY, buttonW, "1", BLACK);
  FL3 = SimbleeForMobile.drawButton(l3buttonX, fbuttonY, buttonW, "3", BLACK);
  FR1 = SimbleeForMobile.drawButton(r1buttonX, fbuttonY, buttonW, "1", BLACK);
  FR3 = SimbleeForMobile.drawButton(r3buttonX, fbuttonY, buttonW, "3", BLACK);
  RL1 = SimbleeForMobile.drawButton(l1buttonX, rbuttonY, buttonW, "1", BLACK);
  RL3 = SimbleeForMobile.drawButton(l3buttonX, rbuttonY, buttonW, "3", BLACK);
  RR1 = SimbleeForMobile.drawButton(r1buttonX, rbuttonY, buttonW, "1", BLACK);
  RR3 = SimbleeForMobile.drawButton(r3buttonX, rbuttonY, buttonW, "3", BLACK);
  ontime = SimbleeForMobile.drawTextField(onTimeTextX, onTimeTextY, timeTextWidth, onTime, "", textColor, textFieldColor);
  offtime = SimbleeForMobile.drawTextField(offTimeTextX, offTimeTextY, timeTextWidth, offTime, "", textColor, textFieldColor);
  cooltime = SimbleeForMobile.drawTextField(coolTimeTextX, coolTimeTextY, timeTextWidth, coolTime, "", textColor, textFieldColor);
  runtime = SimbleeForMobile.drawTextField(TIMETextX, TIMETextY, timeTextWidth, TIME, "", textColor, textFieldColor);
  fl1ID = SimbleeForMobile.drawRect(l1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fl3ID = SimbleeForMobile.drawRect(l3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fr1ID = SimbleeForMobile.drawRect(r1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fr3ID = SimbleeForMobile.drawRect(r3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  rr1ID = SimbleeForMobile.drawRect(r1IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rr3ID = SimbleeForMobile.drawRect(r3IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rl1ID = SimbleeForMobile.drawRect(l1IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rl3ID = SimbleeForMobile.drawRect(l3IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  text_roll = SimbleeForMobile.drawText(40,  540, roll);
  text_pitch = SimbleeForMobile.drawText(80,  540, pitch);
  text_yaw = SimbleeForMobile.drawText(120,  540, yaw);
  SimbleeForMobile.endScreen();
  update;
}

void off()
{
    wave1_b = 0;
    wave1_f = 0;

    digitalWrite(fl1, LOW);
    digitalWrite(fl3, LOW);
    digitalWrite(fr1, LOW);
    digitalWrite(fr3, LOW);
    digitalWrite(rl1, LOW);
    digitalWrite(rl3, LOW);
    digitalWrite(rr1, LOW);
    digitalWrite(rr3, LOW);
    delay(offTime);
}

void wave1b() 
{
  if (wave1_b == 1){
    if(rcount == 1){
      startTime = millis();
      rcount = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      rcount = 1;
      wave1_b = 0;
    }
  SimbleeForMobile.process();  
//  digitalWrite(rr4, HIGH);
  digitalWrite(fl1, HIGH);
  digitalWrite(rr1, LOW);
  digitalWrite(rr3, HIGH);
  digitalWrite(fl3, LOW);
  digitalWrite(fr1, LOW);
  digitalWrite(fr3, LOW);
  digitalWrite(rl1, LOW);
  digitalWrite(rl3, LOW);
  SimbleeForMobile.updateColor(rr3ID, RED);
  SimbleeForMobile.updateColor(fl1ID, RED);
  delay(onTime);
  }
  digitalWrite(rr3, LOW);
  digitalWrite(fl1, LOW);
  SimbleeForMobile.updateColor(rr3ID, BLACK);
  SimbleeForMobile.updateColor(fl1ID, BLACK);
  delay(offTime);
  if (wave1_b == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      rcount = 1;
      wave1_b = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rl1, HIGH);
  digitalWrite(fr3, HIGH);
  SimbleeForMobile.updateColor(rl1ID, RED);
  SimbleeForMobile.updateColor(fr3ID, RED);
  delay(onTime);
  }
  digitalWrite(rl1, LOW);
  digitalWrite(fr3, LOW);
  SimbleeForMobile.updateColor(rl1ID, BLACK);
  SimbleeForMobile.updateColor(fr3ID, BLACK);
  delay(offTime);
  if (wave1_b == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      rcount = 1;
      wave1_b = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rr1, HIGH);
  digitalWrite(fl3, HIGH);
  SimbleeForMobile.updateColor(rr1ID, RED);
  SimbleeForMobile.updateColor(fl3ID, RED);
  delay(onTime);
  }
  digitalWrite(rr1, LOW);
  digitalWrite(fl3, LOW);
  SimbleeForMobile.updateColor(rr1ID, BLACK);
  SimbleeForMobile.updateColor(fl3ID, BLACK);
  delay(offTime);
  if (wave1_b == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      rcount = 1;
      wave1_b = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rl3, HIGH);
  digitalWrite(fr1, HIGH);
  SimbleeForMobile.updateColor(rl3ID, RED);
  SimbleeForMobile.updateColor(fr1ID, RED);
  delay(onTime);
  }
  digitalWrite(rl3, LOW);
  digitalWrite(fr1, LOW);
  SimbleeForMobile.updateColor(rl3ID, BLACK);
  SimbleeForMobile.updateColor(fr1ID, BLACK);
  delay(offTime);

}

void wave1f() 
{
  if (wave1_f == 1){
    if(rcount == 1){
      startTime = millis();
      rcount = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      rcount = 1;
      wave1_f = 0;
    }
}
}

void update()
{
//  onTime = onTime;
//  offTime = offTime;
  if(eventId != offtime) SimbleeForMobile.updateValue(offtime, offTime);
  if(eventId != ontime) SimbleeForMobile.updateValue(ontime, onTime);
  if(eventId != cooltime) SimbleeForMobile.updateValue(cooltime, coolTime);
  if(eventId != runtime) SimbleeForMobile.updateValue(runtime, TIME);
}

void fl1event()
{
      SimbleeForMobile.process();
      digitalWrite(fl1, HIGH);
      SimbleeForMobile.updateColor(fl1ID, RED);
      SimbleeForMobile.updateColor(FL1, RED);      
      delay(onTime);
      digitalWrite(fl1, LOW);
      SimbleeForMobile.updateColor(fl1ID, BLACK);
      SimbleeForMobile.updateColor(FL1, BLACK);      
      delay(offTime);

}


void fl3event()
{
      SimbleeForMobile.process();
      digitalWrite(fl3, HIGH);
      SimbleeForMobile.updateColor(fl3ID, RED);
      SimbleeForMobile.updateColor(FL3, RED);      
      delay(onTime);
      digitalWrite(fl3, LOW);
      SimbleeForMobile.updateColor(fl3ID, BLACK);
      SimbleeForMobile.updateColor(FL3, BLACK);      
      delay(offTime);

}


void fr1event()
{
      SimbleeForMobile.process();
      digitalWrite(fr1, HIGH);
      SimbleeForMobile.updateColor(fr1ID, RED);
      SimbleeForMobile.updateColor(FR1, RED);      
      delay(onTime);
      digitalWrite(fr1, LOW);
      SimbleeForMobile.updateColor(fr1ID, BLACK);
      SimbleeForMobile.updateColor(FR1, BLACK);      
      delay(offTime);
}


void fr3event()
{
      SimbleeForMobile.process();
      digitalWrite(fr3, HIGH);
      SimbleeForMobile.updateColor(fr3ID, RED);
      SimbleeForMobile.updateColor(FR3, RED);      
      delay(onTime);
      digitalWrite(fr3, LOW);
      SimbleeForMobile.updateColor(fr3ID, BLACK);
      SimbleeForMobile.updateColor(FR3, BLACK);
      delay(offTime);

}

void rr1event()
{
      SimbleeForMobile.process();
      digitalWrite(rr1, HIGH);
      SimbleeForMobile.updateColor(rr1ID, RED);
      SimbleeForMobile.updateColor(RR1, RED);
      delay(onTime);
      digitalWrite(rr1, LOW);
      SimbleeForMobile.updateColor(rr1ID, BLACK);
      SimbleeForMobile.updateColor(RR1, BLACK);
      delay(offTime);

}

void rr3event()
{
      SimbleeForMobile.process();
      digitalWrite(rr3, HIGH);
      SimbleeForMobile.updateColor(rr3ID, RED);
      SimbleeForMobile.updateColor(RR3, RED);      
      delay(onTime);
      digitalWrite(rr3, LOW);
      SimbleeForMobile.updateColor(rr3ID, BLACK);
      SimbleeForMobile.updateColor(RR3, BLACK);
      delay(offTime);

}



void rl1event()
{
      SimbleeForMobile.process();
      digitalWrite(rl1, HIGH);
      SimbleeForMobile.updateColor(rl1ID, RED);
      SimbleeForMobile.updateColor(RL1, RED);      
      delay(onTime);
      digitalWrite(rl1, LOW);
      SimbleeForMobile.updateColor(rl1ID, BLACK);
      SimbleeForMobile.updateColor(RL1, BLACK); 
      delay(offTime);

}


void rl3event()
{
      SimbleeForMobile.process();
      digitalWrite(rl3, HIGH);
      SimbleeForMobile.updateColor(rl3ID, RED);
      SimbleeForMobile.updateColor(RL3, RED);
      delay(onTime);
      digitalWrite(rl3, LOW);
      SimbleeForMobile.updateColor(rl3ID, BLACK);
      SimbleeForMobile.updateColor(RL3, BLACK);
      delay(offTime);

}


void getOrientation()
{
  if (readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {  // On interrupt, check if data ready interrupt
    readAccelData(accelCount);  // Read the x/y/z adc values
    getAres();
     
    // Now we'll calculate the accleration value into actual g's
    ax = (float)accelCount[0]*aRes; // - accelBias[0];  // get actual g value, this depends on scale being set
    ay = (float)accelCount[1]*aRes; // - accelBias[1];   
    az = (float)accelCount[2]*aRes; // - accelBias[2];  
   
    readGyroData(gyroCount);  // Read the x/y/z adc values
    getGres();
 
    // Calculate the gyro value into actual degrees per second
    gx = (float)gyroCount[0]*gRes;  // get actual gyro value, this depends on scale being set
    gy = (float)gyroCount[1]*gRes;  
    gz = (float)gyroCount[2]*gRes;   
  
    readMagData(magCount);  // Read the x/y/z adc values
    getMres();
    magbias[0] = -554.;  // User environmental x-axis correction in milliGauss, should be automatically calculated
    magbias[1] = -83.;  // User environmental x-axis correction in milliGauss
    magbias[2] = -84.;  // User environmental x-axis correction in milliGauss
    
    // Calculate the magnetometer values in milliGauss
    // Include factory calibration per data sheet and user environmental corrections
    mx = (float)magCount[0]*mRes*magCalibration[0] - magBias[0];  // get actual magnetometer value, this depends on scale being set
    my = (float)magCount[1]*mRes*magCalibration[1] - magBias[1];  
    mz = (float)magCount[2]*mRes*magCalibration[2] - magBias[2];   

  }
  
  Now = micros();
  deltat = ((Now - lastUpdate)/1000000.0f); // set integration time by time elapsed since last filter update
  lastUpdate = Now;

  sum += deltat; // sum for averaging filter update rate
  sumCount++;

  MadgwickQuaternionUpdate(ax, ay, az, gx*PI/180.0f, gy*PI/180.0f, gz*PI/180.0f,  my,  mx, mz);
  
  if (!AHRS) {
    delt_t = millis() - count;
    if(delt_t > 500) {

    if(SerialDebug) {
    // Print acceleration values in milligs!
    Serial.print("X-acceleration: "); Serial.print(1000*ax); Serial.print(" mg ");
    Serial.print("Y-acceleration: "); Serial.print(1000*ay); Serial.print(" mg ");
    Serial.print("Z-acceleration: "); Serial.print(1000*az); Serial.println(" mg ");
// 
//    // Print gyro values in degree/sec
    Serial.print("X-gyro rate: "); Serial.print(gx, 3); Serial.print(" degrees/sec "); 
    Serial.print("Y-gyro rate: "); Serial.print(gy, 3); Serial.print(" degrees/sec "); 
    Serial.print("Z-gyro rate: "); Serial.print(gz, 3); Serial.println(" degrees/sec"); 
//    
//    // Print mag values in degree/sec
    Serial.print("X-mag field: "); Serial.print(mx); Serial.print(" mG "); 
    Serial.print("Y-mag field: "); Serial.print(my); Serial.print(" mG "); 
    Serial.print("Z-mag field: "); Serial.print(mz); Serial.println(" mG"); 
 }
    
    count = millis();
    }
  }
  else {
      
    // Serial print and/or display at 0.5 s rate independent of data rates
    delt_t = millis() - count;
    if (delt_t > 50) { // update LCD once per half-second independent of read rate

    if(SerialDebug) {
    Serial.print("ax = "); Serial.print((int)1000*ax);  
    Serial.print(" ay = "); Serial.print((int)1000*ay); 
    Serial.print(" az = "); Serial.print((int)1000*az); Serial.println(" mg");
    Serial.print("gx = "); Serial.print( gx, 2); 
    Serial.print(" gy = "); Serial.print( gy, 2); 
    Serial.print(" gz = "); Serial.print( gz, 2); Serial.println(" deg/s");
    Serial.print("mx = "); Serial.print( (int)mx ); 
    Serial.print(" my = "); Serial.print( (int)my ); 
    Serial.print(" mz = "); Serial.print( (int)mz ); Serial.println(" mG");
    
    Serial.print("q0 = "); Serial.print(q[0]);
    Serial.print(" qx = "); Serial.print(q[1]); 
    Serial.print(" qy = "); Serial.print(q[2]); 
    Serial.print(" qz = "); Serial.println(q[3]); 
    }               
    
    yaw   = atan2(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] - q[2] * q[2] - q[3] * q[3]);   
    pitch = -asin(2.0f * (q[1] * q[3] - q[0] * q[2]));
    roll  = atan2(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] - q[1] * q[1] - q[2] * q[2] + q[3] * q[3]);
    pitch *= 180.0f / PI;
    yaw   *= 180.0f / PI; 
    yaw   += 9; // Declination at Pittsburgh, PA: 6/23/17, IGRF12
    roll  *= 180.0f / PI;
     
    data[6] = (float) yaw+180;
    data[7] = (float) pitch;
    data[8] = (float) roll;
    
    Serial.print("Orientation: ");
    Serial.print((float)yaw+180);
    Serial.print(F(" "));
    Serial.print((float)pitch);
    Serial.print(F(" "));
    Serial.print((float)roll);
    Serial.println(F(""));

    
    count = millis(); 
    sumCount = 0;
    sum = 0;    
    }
  }

}

void ui_event(event_t &event){
  if (event.id == Switch){
    if (event.value == 1)
      start = 1;
    else if (event.value == 0)
      start = 0;
  }
  if (event.id == Wave1_b){
    if (event.value == 1)
      wave1_b = 1;
    else if (event.value == 0)
      wave1_b = 0;
  }
  if (event.id == Wave1_f){
    if (event.value == 1)
      wave1_f = 1;
    else if (event.value == 0)
      wave1_f = 0;
  }
  SimbleeForMobile.setEvents(FL1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FL1){
    if (event.type == EVENT_PRESS)
      Fl1 = 1;
    else if (event.type == EVENT_RELEASE)
      Fl1 = 0;
   }
   SimbleeForMobile.setEvents(FL3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FL3){
    if (event.type == EVENT_PRESS)
      Fl3 = 1;
    else if (event.type == EVENT_RELEASE)
      Fl3 = 0;
   }
   SimbleeForMobile.setEvents(FR1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR1){
    if (event.type == EVENT_PRESS)
      Fr1 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr1 = 0;
   }
   SimbleeForMobile.setEvents(FR3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR3){
    if (event.type == EVENT_PRESS)
      Fr3 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr3 = 0;
   }
  SimbleeForMobile.setEvents(RL1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL1){
    if (event.type == EVENT_PRESS)
      Rl1 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl1 = 0;
   }
   SimbleeForMobile.setEvents(RL3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL3){
    if (event.type == EVENT_PRESS)
      Rl3 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl3 = 0;
   }
   SimbleeForMobile.setEvents(RR1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR1){
    if (event.type == EVENT_PRESS)
      Rr1 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr1 = 0;
   }
   SimbleeForMobile.setEvents(RR3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR3){
    if (event.type == EVENT_PRESS)
      Rr3 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr3 = 0;
   }
  if (event.id == offtime){
    offTime = event.value;
  }  
  if (event.id == ontime){
    onTime = event.value;
  }  
  if (event.id == cooltime){
    coolTime = event.value;
  }  
  if (event.id == runtime){
    TIME = event.value;
  }  

  needsUpdate = true;
}

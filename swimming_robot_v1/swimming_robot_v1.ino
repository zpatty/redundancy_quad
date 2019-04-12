 #include <SimbleeForMobile.h>
//#include "thermometer_png.h"
//#include "CAT.h"

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_SIMBLEE.h>
#include <utility/imumaths.h>


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

float rot_x, rot_y, rot_z;


uint8_t Switch; // 8-bit field in which to store switch start ID number
uint8_t Wave_F; // 8-bit field in which to store switch Wave_F ID number
uint8_t L1; // 8-bit field in which to store button L1 ID number
uint8_t L2; // 8-bit field in which to store button L2 ID number
uint8_t L3; // 8-bit field in which to store button L3 ID number
uint8_t L4; // 8-bit field in which to store button L4 ID number
uint8_t L5; // 8-bit field in which to store button L5 ID number
uint8_t L6; // 8-bit field in which to store button L6 ID number
uint8_t L7; // 8-bit field in which to store button L7 ID number
uint8_t L8; // 8-bit field in which to store button L8 ID number
uint8_t text_x;
uint8_t text_y;
uint8_t text_z;


uint8_t Wave_B; // 8-bit field in which to store switch Wave_B ID number

uint8_t Warmup; // 8-bit field in which to store switch Warmup ID number  

int leg0pin = 18;
int leg1pin = 17;
int leg2pin = 11;
int leg3pin = 14;
int leg4pin = 13;
int leg5pin = 10;
int leg6pin = 15;
int leg7pin = 16;


int l1 = 18; // pin number for seg1
int l2 = 17; // pin number for seg2 
int l3 = 11 ; // pin number for seg3
int l4 = 14; // pin number for seg4
int l5 = 13; // pin number for seg5
int l6 = 10; // pin number for seg6
int l7 = 15; // pin number for seg1
int l8 = 16; // pin number for seg2 

int IL1 = 0; //initial value of indicator of IL1 mode
int IL2 = 0; //initial value of indicator of IL2 mode
int IL3 = 0; //initial value of indicator of IL3 mode
int IL4 = 0; //initial value of indicator of IL4 mode
int IL5 = 0; //initial value of indicator of IL5 mode
int IL6 = 0; //initial value of indicator of IL6 mode
int IL7 = 0; //initial value of indicator of IL7 mode
int IL8 = 0; //initial value of indicator of IL8 mode

int wave_F = 0; //initial value of indicator of wavef mode
int wave_B = 0; //initial value of indicator of waveb mode
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
int l1ID; //indicator of front left limb 1
int l2ID; //indicator of front left limb 2
int l3ID; //indicator of front left limb 3
int l4ID; //indicator of front left limb 4
int l5ID; //indicator of front right limb 1
int l6ID; //indicator of front right limb 2
int l7ID; //indicator of front right limb 3
int l8ID; //indicator of front right limb 4

int count = 1;
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
int wavebY = 260;
int wavefY = 305;
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
int wavebSwitchY = 255;
int wavefSwitchY = 305;

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

void update();
void wavef();
void wavef();
void l1event();
void l2event();
void l3event();
void l4event();
void l5event();
void l6event();
void l7event();
void l8event();
void off();

void setup() {
  // set up BNO
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

  // Set up legs
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
  SimbleeForMobile.advertisementData = "SEAQ 2.0";
  SimbleeForMobile.domain = "Simblee.com";
  SimbleeForMobile.deviceName = "SEAQ 2";
  SimbleeForMobile.begin();
}

float sample_rate = 1; // this sample rate controls how often we get orientation
unsigned long last_time = 0;
unsigned long this_time;
void loop() {
  if(needsUpdate){
    update;
    needsUpdate = false;
  }
  this_time = millis();
  if (this_time - last_time > sample_rate){
    getOrientation();
  }
  last_time = millis();
  if (start == 0){
      off();
  }
  if (start == 1){
    if (wave_F == 1){
      wavef();
    }
    if (wave_B == 1){
      wavef();
    }
    if (IL1 == 1){
      l1event();
    }
    if (IL2 == 1){
      l2event();
    }
    if (IL3 == 1){
      l3event();
    }
    if (IL4 == 1){
      l4event();
    }
    if (IL5 == 1){
      l5event();
    }
    if (IL6 == 1){
      l6event();
    }
    if (IL7 == 1){
      l7event();
    }
    if (IL8 == 1){
      l8event();
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
  SimbleeForMobile.drawText(waveX1, wavefY, "Sim R Diagonal", waveColor, waveFont);
  SimbleeForMobile.drawText(waveX2, wavefY, "Sim L Diagonal", waveColor, waveFont);
  SimbleeForMobile.drawText(setupX, setupY, "Setup", setupColor, setupFont);
  SimbleeForMobile.drawText(onTimeX, onTimeY, "ON Time", onTimeColor, onTimeFont);
  SimbleeForMobile.drawText(offTimeX, offTimeY, "OFF Time", offTimeColor, offTimeFont);
  SimbleeForMobile.drawText(coolTimeX, coolTimeY, "COOL Time", coolTimeColor, coolTimeFont);
  SimbleeForMobile.drawText(TIMEX, TIMEY, "RUN Time", TIMEColor, TIMEFont);
  Switch = SimbleeForMobile.drawSwitch(startSwitchX,startSwitchY, startSwitchColor); 
  Wave_F = SimbleeForMobile.drawSwitch(waveSwitchX1,wavefSwitchY,waveSwitchColor); 
  Wave_B = SimbleeForMobile.drawSwitch(waveSwitchX2,wavefSwitchY,waveSwitchColor);
  L1 = SimbleeForMobile.drawButton(l1buttonX, rbuttonY, buttonW, "1", BLACK);
  L2 = SimbleeForMobile.drawButton(l2buttonX, rbuttonY, buttonW, "2", BLACK);
  L3 = SimbleeForMobile.drawButton(l3buttonX, rbuttonY, buttonW, "3", BLACK);
  L4 = SimbleeForMobile.drawButton(l4buttonX, rbuttonY, buttonW, "4", BLACK);
  L5 = SimbleeForMobile.drawButton(r1buttonX, rbuttonY, buttonW, "1", BLACK);
  L6 = SimbleeForMobile.drawButton(r2buttonX, rbuttonY, buttonW, "2", BLACK);
  L7 = SimbleeForMobile.drawButton(r3buttonX, rbuttonY, buttonW, "3", BLACK);
  L8 = SimbleeForMobile.drawButton(r4buttonX, rbuttonY, buttonW, "4", BLACK);  
  ontime = SimbleeForMobile.drawTextField(onTimeTextX, onTimeTextY, timeTextWidth, onTime, "", textColor, textFieldColor);
  offtime = SimbleeForMobile.drawTextField(offTimeTextX, offTimeTextY, timeTextWidth, offTime, "", textColor, textFieldColor);
  cooltime = SimbleeForMobile.drawTextField(coolTimeTextX, coolTimeTextY, timeTextWidth, coolTime, "", textColor, textFieldColor);
  runtime = SimbleeForMobile.drawTextField(TIMETextX, TIMETextY, timeTextWidth, TIME, "", textColor, textFieldColor);
  l1ID = SimbleeForMobile.drawRect(l1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l2ID = SimbleeForMobile.drawRect(l2IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l3ID = SimbleeForMobile.drawRect(l3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l4ID = SimbleeForMobile.drawRect(l4IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l5ID = SimbleeForMobile.drawRect(r1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l6ID = SimbleeForMobile.drawRect(r2IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l7ID = SimbleeForMobile.drawRect(r3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  l8ID = SimbleeForMobile.drawRect(r4IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  text_x = SimbleeForMobile.drawText(40,  540, rot_x);
  text_y = SimbleeForMobile.drawText(80,  540, rot_y);
  text_z = SimbleeForMobile.drawText(120,  540, rot_z);
  SimbleeForMobile.endScreen();
  update;
}

void off()
{
    wave_F = 0;
    wave_B = 0;

    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
    digitalWrite(l4, LOW);
    digitalWrite(l5, LOW);
    digitalWrite(l6, LOW);
    digitalWrite(l7, LOW);
    digitalWrite(l8, LOW);
    delay(offTime);
}

void wavef() 
{
  if (wave_F == 1){
    if(count == 1){
      startTime = millis();
      count = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
//  digitalWrite(rr4, HIGH);
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, LOW);
  SimbleeForMobile.updateColor(l1ID, RED);
  delay(onTime);
  }
  digitalWrite(l1, LOW);
  SimbleeForMobile.updateColor(l1ID, BLACK);
  delay(offTime);
  if (wave_F == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l2, HIGH);
  SimbleeForMobile.updateColor(l2ID, RED);
  delay(onTime);
  }
  digitalWrite(l2, LOW);
  SimbleeForMobile.updateColor(l2ID, BLACK);
  delay(offTime);
  if (wave_F == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l3, HIGH);
  SimbleeForMobile.updateColor(l3ID, RED);
  delay(onTime);
  }
  digitalWrite(l3, LOW);
  SimbleeForMobile.updateColor(l3ID, BLACK);
  delay(offTime);
  if (wave_F == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l4, HIGH);
  SimbleeForMobile.updateColor(l4ID, RED);
  delay(onTime);
  }
  digitalWrite(l4, LOW);
  SimbleeForMobile.updateColor(l4ID, BLACK);
  delay(offTime);
  if (wave_F == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l5, HIGH);
  SimbleeForMobile.updateColor(l5ID, RED);
  delay(onTime);
  }
  digitalWrite(l5, LOW);
  SimbleeForMobile.updateColor(l5ID, BLACK);
  delay(offTime);

  if (wave_F == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }

  SimbleeForMobile.process();  
  digitalWrite(l6, HIGH);
  SimbleeForMobile.updateColor(l6ID, RED);
  delay(onTime);
  }
  digitalWrite(l6, LOW);
  SimbleeForMobile.updateColor(l6ID, BLACK);
  delay(offTime);
  if (wave_F == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l7, HIGH);
  SimbleeForMobile.updateColor(l7ID, RED);
  delay(onTime);
  }
  digitalWrite(l7, LOW);
  SimbleeForMobile.updateColor(l7ID, BLACK);
  delay(offTime);
  if (wave_F == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_F = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l8, HIGH);
  SimbleeForMobile.updateColor(l8ID, RED);
  delay(onTime);
  }
  digitalWrite(l8, LOW);
  SimbleeForMobile.updateColor(l8ID, BLACK);
  delay(offTime);
}
void waveb() 
{
  if (wave_B == 1){
    if(count == 1){
      startTime = millis();
      count = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  digitalWrite(l8, HIGH);
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  SimbleeForMobile.updateColor(l8ID, RED);
  delay(onTime);
  }
  digitalWrite(l8, LOW);
  SimbleeForMobile.updateColor(l8ID, BLACK);
  delay(offTime);
  if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l7, HIGH);
  SimbleeForMobile.updateColor(l7ID, RED);
  delay(onTime);
  }
  digitalWrite(l7, LOW);
  SimbleeForMobile.updateColor(l7ID, BLACK);
  delay(offTime);
    if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l6, HIGH);
  SimbleeForMobile.updateColor(l6ID, RED);
  delay(onTime);
  }
  digitalWrite(l6, LOW);
  SimbleeForMobile.updateColor(l6ID, BLACK);
  delay(offTime);
    if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();
  digitalWrite(l5, HIGH);
  SimbleeForMobile.updateColor(l5ID, RED);
  delay(onTime);
  }
  digitalWrite(l5, LOW);
  SimbleeForMobile.updateColor(l5ID, BLACK);
  delay(offTime);
  if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l4, HIGH);
  SimbleeForMobile.updateColor(l4ID, RED);
  delay(onTime);
  }
  digitalWrite(l4, LOW);
  SimbleeForMobile.updateColor(l4ID, BLACK);
  delay(offTime);
  if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l3, HIGH);
  SimbleeForMobile.updateColor(l3ID, RED);
  delay(onTime);
  }
  digitalWrite(l3, LOW);
  SimbleeForMobile.updateColor(l3ID, BLACK);
  delay(offTime);
  if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l2, HIGH);
  SimbleeForMobile.updateColor(l2ID, RED);
  delay(onTime);
  }
  digitalWrite(l2, LOW);
  SimbleeForMobile.updateColor(l2ID, BLACK);
  delay(offTime);
  if (wave_B == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave_B = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(l1, HIGH);
  SimbleeForMobile.updateColor(l1ID, RED);
  delay(onTime);
  }
  digitalWrite(l1, LOW);
  SimbleeForMobile.updateColor(l1ID, BLACK);
  delay(offTime + coolTime);
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

void l1event()
{
      SimbleeForMobile.process();
      digitalWrite(l1, HIGH);
      SimbleeForMobile.updateColor(l1ID, RED);
      SimbleeForMobile.updateColor(L1, RED);      
      delay(onTime);
      digitalWrite(l1, LOW);
      SimbleeForMobile.updateColor(l1ID, BLACK);
      SimbleeForMobile.updateColor(L1, BLACK);      
      delay(offTime);

}

void l2event()
{
      SimbleeForMobile.process();
      digitalWrite(l2, HIGH);
      SimbleeForMobile.updateColor(l2ID, RED);
      SimbleeForMobile.updateColor(L2, RED);      
      delay(onTime);
      digitalWrite(l2, LOW);
      SimbleeForMobile.updateColor(l2ID, BLACK);
      SimbleeForMobile.updateColor(L2, BLACK);      
      delay(offTime);

}

void l3event()
{
      SimbleeForMobile.process();
      digitalWrite(l3, HIGH);
      SimbleeForMobile.updateColor(l3ID, RED);
      SimbleeForMobile.updateColor(L3, RED);      
      delay(onTime);
      digitalWrite(l3, LOW);
      SimbleeForMobile.updateColor(l3ID, BLACK);
      SimbleeForMobile.updateColor(L3, BLACK);      
      delay(offTime);

}

void l4event()
{
      SimbleeForMobile.process();
      digitalWrite(l4, HIGH);
      SimbleeForMobile.updateColor(l4ID, RED);
      SimbleeForMobile.updateColor(L4, RED);     
      delay(onTime);
      digitalWrite(l4, LOW);
      SimbleeForMobile.updateColor(l4ID, BLACK);
      SimbleeForMobile.updateColor(L4, BLACK);      
      delay(offTime);

}

void l5event()
{
      SimbleeForMobile.process();
      digitalWrite(l5, HIGH);
      SimbleeForMobile.updateColor(l5ID, RED);
      SimbleeForMobile.updateColor(L5, RED);      
      delay(onTime);
      digitalWrite(l5, LOW);
      SimbleeForMobile.updateColor(l5ID, BLACK);
      SimbleeForMobile.updateColor(L5, BLACK);      
      delay(offTime);
}

void l6event()
{
      SimbleeForMobile.process();
      digitalWrite(l6, HIGH);
      SimbleeForMobile.updateColor(l6ID, RED);
      SimbleeForMobile.updateColor(L6, RED);      
      delay(onTime);
      digitalWrite(l6, LOW);
      SimbleeForMobile.updateColor(l6ID, BLACK);
      SimbleeForMobile.updateColor(L6, BLACK);      
      delay(offTime);
}

void l7event()
{
      SimbleeForMobile.process();
      digitalWrite(l7, HIGH);
      SimbleeForMobile.updateColor(l7ID, RED);
      SimbleeForMobile.updateColor(L7, RED);      
      delay(onTime);
      digitalWrite(l7, LOW);
      SimbleeForMobile.updateColor(l7ID, BLACK);
      SimbleeForMobile.updateColor(L7, BLACK);
      delay(offTime);

}

void l8event()
{
      SimbleeForMobile.process();
      digitalWrite(l8, HIGH);
      SimbleeForMobile.updateColor(l8ID, RED);
      SimbleeForMobile.updateColor(L8, RED);      
      delay(onTime);
      digitalWrite(l8, LOW);
      SimbleeForMobile.updateColor(l8ID, BLACK);
      SimbleeForMobile.updateColor(L8, BLACK);      
      delay(offTime);

}

void getOrientation()
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

  rot_x = euler.x();
  rot_y = euler.y();
  rot_z = euler.z();
  if (SimbleeForMobile.updatable){
        SimbleeForMobile.updateValue(text_x, rot_x);
        SimbleeForMobile.updateValue(text_y, rot_y);
        SimbleeForMobile.updateValue(text_z, rot_z);
      }
    
  SimbleeForMobile.process();
  
  delay(BNO055_SAMPLERATE_DELAY_MS);
}

void ui_event(event_t &event){
  if (event.id == Switch){
    if (event.value == 1)
      start = 1;
    else if (event.value == 0)
      start = 0;
  }
  if (event.id == Wave_F){
    if (event.value == 1)
      wave_F = 1;
    else if (event.value == 0)
      wave_F = 0;
  }
  if (event.id == Wave_B){
    if (event.value == 1)
      wave_B = 1;
    else if (event.value == 0)
      wave_B = 0;
  }
  SimbleeForMobile.setEvents(L1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L1){
    if (event.type == EVENT_PRESS)
      IL1 = 1;
    else if (event.type == EVENT_RELEASE)
      IL1 = 0;
   }
   SimbleeForMobile.setEvents(L2, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L2){
    if (event.type == EVENT_PRESS)
      IL2 = 1;
    else if (event.type == EVENT_RELEASE)
      IL2 = 0;
   }
   SimbleeForMobile.setEvents(L3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L3){
    if (event.type == EVENT_PRESS)
      IL3 = 1;
    else if (event.type == EVENT_RELEASE)
      IL3 = 0;
   }
   SimbleeForMobile.setEvents(L4, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L4){
    if (event.type == EVENT_PRESS)
      IL4 = 1;
    else if (event.type == EVENT_RELEASE)
      IL4 = 0;
   }
   SimbleeForMobile.setEvents(L5, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L5){
    if (event.type == EVENT_PRESS)
      IL5 = 1;
    else if (event.type == EVENT_RELEASE)
      IL5 = 0;
   }
   SimbleeForMobile.setEvents(L6, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L6){
    if (event.type == EVENT_PRESS)
      IL6 = 1;
    else if (event.type == EVENT_RELEASE)
      IL6 = 0;
   }
   SimbleeForMobile.setEvents(L7, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L7){
    if (event.type == EVENT_PRESS)
      IL7 = 1;
    else if (event.type == EVENT_RELEASE)
      IL7 = 0;
   }
   SimbleeForMobile.setEvents(L8, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == L8){
    if (event.type == EVENT_PRESS)
      IL8 = 1;
    else if (event.type == EVENT_RELEASE)
      IL8 = 0;
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

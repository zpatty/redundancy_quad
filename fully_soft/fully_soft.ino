#include <SimbleeForMobile.h>
//#include "thermometer_png.h"
//#include "CAT.h"
uint8_t Switch; // 8-bit field in which to store switch start ID number
uint8_t Wave1_b; // 8-bit field in which to store switch Wave1_b ID number
uint8_t FL1; // 8-bit field in which to store button FL1 ID number
uint8_t FL2; // 8-bit field in which to store button FL2 ID number
uint8_t FL3; // 8-bit field in which to store button FL3 ID number
uint8_t FL4; // 8-bit field in which to store button FL4 ID number
uint8_t FR1; // 8-bit field in which to store button FR1 ID number
uint8_t FR2; // 8-bit field in which to store button FR2 ID number
uint8_t FR3; // 8-bit field in which to store button FR3 ID number
uint8_t FR4; // 8-bit field in which to store button FR4 ID number
uint8_t RL1; // 8-bit field in which to store button RL1 ID number
uint8_t RL2; // 8-bit field in which to store button RL2 ID number
uint8_t RL3; // 8-bit field in which to store button RL3 ID number
uint8_t RL4; // 8-bit field in which to store button RL4 ID number
uint8_t RR1; // 8-bit field in which to store button RR1 ID number
uint8_t RR2; // 8-bit field in which to store button RR2 ID number
uint8_t RR3; // 8-bit field in which to store button RR3 ID number
uint8_t RR4; // 8-bit field in which to store button RR4 ID number
uint8_t Wave1_f; // 8-bit field in which to store switch Wave1_f ID number
uint8_t Wave2_b; // 8-bit field in which to store switch Wave2_b ID number
uint8_t Wave2_f; // 8-bit field in which to store switch Wave2_f ID number
uint8_t Wave3_b; // 8-bit field in which to store switch Wave3_b ID number
uint8_t Wave3_f; // 8-bit field in which to store switch Wave3_f ID number
uint8_t Wave2_sf; // 8-bit field in which to store switch Wave2_sf ID number
uint8_t Wave2_sb; // 8-bit field in which to store switch Wave2_sb ID number
uint8_t Wave3; // 8-bit field in which to store switch Wave3 ID number
uint8_t Warmup; // 8-bit field in which to store switch Warmup ID number  
int fl1 = 31; // pin number for seg1
int fl2 = 20; // pin number for seg2 
int fl3 = 4; // pin number for seg3
int fl4 = 6; // pin number for seg4
int fr1 = 3; // pin number for seg5
int fr2 = 5; // pin number for seg6
int fr3 = 8; // pin number for seg1
int fr4 = 11; // pin number for seg2 
int rr1 = 19; // pin number for seg3
int rr2 = 17; // pin number for seg4
int rr3 = 18; // pin number for seg5
int rr4 = 16; // pin number for seg6
int rl1 = 30; // pin number for seg1
int rl2 = 29; // pin number for seg2 
int rl3 = 28; // pin number for seg3
int rl4 = 25; // pin number for seg4

int wave1_f = 0; //initial value of indicator of wave1f mode
int Fl1 = 0; //initial value of indicator of Fl1 mode
int Fl2 = 0; //initial value of indicator of Fl2 mode
int Fl3 = 0; //initial value of indicator of Fl3 mode
int Fl4 = 0; //initial value of indicator of Fl4 mode
int Fr1 = 0; //initial value of indicator of Fr1 mode
int Fr2 = 0; //initial value of indicator of Fr2 mode
int Fr3 = 0; //initial value of indicator of Fr3 mode
int Fr4 = 0; //initial value of indicator of Fr4 mode
int Rl1 = 0; //initial value of indicator of Rl1 mode
int Rl2 = 0; //initial value of indicator of Rl2 mode
int Rl3 = 0; //initial value of indicator of Rl3 mode
int Rl4 = 0; //initial value of indicator of Rl4 mode
int Rr1 = 0; //initial value of indicator of Rr1 mode
int Rr2 = 0; //initial value of indicator of Rr2 mode
int Rr3 = 0; //initial value of indicator of Rr3 mode
int Rr4 = 0; //initial value of indicator of Rr4 mode
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
int fl2ID; //indicator of front left limb 2
int fl3ID; //indicator of front left limb 3
int fl4ID; //indicator of front left limb 4
int fr1ID; //indicator of front right limb 1
int fr2ID; //indicator of front right limb 2
int fr3ID; //indicator of front right limb 3
int fr4ID; //indicator of front right limb 4
int rr1ID; //indicator of rear right limb 1
int rr2ID; //indicator of rear right limb 2
int rr3ID; //indicator of rear right limb 3
int rr4ID; //indicator of rear right limb 4
int rl1ID; //indicator of rear left limb 1
int rl2ID; //indicator of rear left limb 2
int rl3ID; //indicator of rear left limb 3
int rl4ID; //indicator of rear left limb 4
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

void update();
void wave1b();
void wave1f();
void fl1event();
void fl2event();
void fl3event();
void fl4event();
void fr1event();
void fr2event();
void fr3event();
void fr4event();
void rl1event();
void rl2event();
void rl3event();
void rl4event();
void rr1event();
void rr2event();
void rr3event();
void rr4event();
void off();

void setup() {
  Serial.begin(9600);
  pinMode(fl1, OUTPUT);
  pinMode(fl2, OUTPUT);
  pinMode(fl3, OUTPUT);
  pinMode(fl4, OUTPUT);
  pinMode(fr1, OUTPUT);
  pinMode(fr2, OUTPUT);
  pinMode(fr3, OUTPUT);
  pinMode(fr4, OUTPUT);
  pinMode(rr1, OUTPUT);
  pinMode(rr2, OUTPUT);
  pinMode(rr3, OUTPUT);
  pinMode(rr4, OUTPUT);
  pinMode(rl1, OUTPUT);
  pinMode(rl2, OUTPUT);
  pinMode(rl3, OUTPUT);
  pinMode(rl4, OUTPUT);
  SimbleeForMobile.advertisementData = "SEAQ 2.0";
  SimbleeForMobile.domain = "Simblee.com";
  SimbleeForMobile.deviceName = "SEAQ 2";
  SimbleeForMobile.begin();
}
void loop() {
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
    if (Fl2 == 1){
      fl2event();
    }
    if (Fl3 == 1){
      fl3event();
    }
    if (Fl4 == 1){
      fl4event();
    }
    if (Fr1 == 1){
      fr1event();
    }
    if (Fr2 == 1){
      fr2event();
    }
    if (Fr3 == 1){
      fr3event();
    }
    if (Fr4 == 1){
      fr4event();
    }   
    if (Rl1 == 1){
      rl1event();
    }
    if (Rl2 == 1){
      rl2event();
    }
    if (Rl3 == 1){
      rl3event();
    }
    if (Rl4 == 1){
      rl4event();
    }
    if (Rr1 == 1){
      rr1event();
    }
    if (Rr2 == 1){
      rr2event();
    }
    if (Rr3 == 1){
      rr3event();
    }
    if (Rr4 == 1){
      rr4event();
    }           
  }
  SimbleeForMobile.process();
}

uint32_t ontime;
uint32_t offtime;
uint32_t cooltime;
unsigned long runtime;
void ui() { 
 // #define IMAGE1 2 // image number
//  SimbleeForMobile.imageSource(IMAGE1, JPG, CAT_jpg, CAT_jpg_len);
//  int catImage_ID = SimbleeForMobile.drawImage(IMAGE1, imageX, imageY);
  SimbleeForMobile.beginScreen(screenColor,PORTRAIT); 
  SimbleeForMobile.drawText(statusX, statusY, "Status", statusColor, statusFont);
  SimbleeForMobile.drawText(startX, startY, "Start", startColor, startFont);
  SimbleeForMobile.drawText(modeX, modeY, "Mode", modeColor, modeFont);
  SimbleeForMobile.drawText(waveX1, wave1bY, "Sim R Diagonal", waveColor, waveFont);
  SimbleeForMobile.drawText(waveX2, wave1bY, "Sim L Diagonal", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX1, wave2bY, "Wave 2b", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX1, wave2fY, "Wave 2f", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX2, wave3bY, "Wave 3b", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX2, wave3fY, "Wave 3f", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX2, wave2sfY, "Wave 2sf", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX2, wave2sbY, "Wave 2sb", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX1, wave3Y, "Wave 3", waveColor, waveFont);
//  SimbleeForMobile.drawText(waveX2, warmupY, "Warm Up", waveColor, waveFont);
  SimbleeForMobile.drawText(setupX, setupY, "Setup", setupColor, setupFont);
  SimbleeForMobile.drawText(onTimeX, onTimeY, "ON Time", onTimeColor, onTimeFont);
  SimbleeForMobile.drawText(offTimeX, offTimeY, "OFF Time", offTimeColor, offTimeFont);
  SimbleeForMobile.drawText(coolTimeX, coolTimeY, "COOL Time", coolTimeColor, coolTimeFont);
  SimbleeForMobile.drawText(TIMEX, TIMEY, "RUN Time", TIMEColor, TIMEFont);
  Switch = SimbleeForMobile.drawSwitch(startSwitchX,startSwitchY, startSwitchColor); 
  Wave1_b = SimbleeForMobile.drawSwitch(waveSwitchX1,wave1bSwitchY,waveSwitchColor); 
  Wave1_f = SimbleeForMobile.drawSwitch(waveSwitchX2,wave1bSwitchY,waveSwitchColor);
  FL1 = SimbleeForMobile.drawButton(l1buttonX, fbuttonY, buttonW, "1", BLACK);
//  FL2 = SimbleeForMobile.drawButton(l2buttonX, fbuttonY, buttonW, "2", BLACK);
  FL3 = SimbleeForMobile.drawButton(l3buttonX, fbuttonY, buttonW, "3", BLACK);
//  FL4 = SimbleeForMobile.drawButton(l4buttonX, fbuttonY, buttonW, "4", BLACK);
  FR1 = SimbleeForMobile.drawButton(r1buttonX, fbuttonY, buttonW, "1", BLACK);
//  FR2 = SimbleeForMobile.drawButton(r2buttonX, fbuttonY, buttonW, "2", BLACK);
  FR3 = SimbleeForMobile.drawButton(r3buttonX, fbuttonY, buttonW, "3", BLACK);
//  FR4 = SimbleeForMobile.drawButton(r4buttonX, fbuttonY, buttonW, "4", BLACK);
  RL1 = SimbleeForMobile.drawButton(l1buttonX, rbuttonY, buttonW, "1", BLACK);
//  RL2 = SimbleeForMobile.drawButton(l2buttonX, rbuttonY, buttonW, "2", BLACK);
  RL3 = SimbleeForMobile.drawButton(l3buttonX, rbuttonY, buttonW, "3", BLACK);
//  RL4 = SimbleeForMobile.drawButton(l4buttonX, rbuttonY, buttonW, "4", BLACK);
  RR1 = SimbleeForMobile.drawButton(r1buttonX, rbuttonY, buttonW, "1", BLACK);
//  RR2 = SimbleeForMobile.drawButton(r2buttonX, rbuttonY, buttonW, "2", BLACK);
  RR3 = SimbleeForMobile.drawButton(r3buttonX, rbuttonY, buttonW, "3", BLACK);
//  RR4 = SimbleeForMobile.drawButton(r4buttonX, rbuttonY, buttonW, "4", BLACK);
//  Wave2_b = SimbleeForMobile.drawSwitch(waveSwitchX1,wave2bSwitchY,waveSwitchColor);
//  Wave2_f = SimbleeForMobile.drawSwitch(waveSwitchX1,wave2fSwitchY,waveSwitchColor);
//  Wave3_b = SimbleeForMobile.drawSwitch(waveSwitchX2,wave3bSwitchY,waveSwitchColor);
//  Wave3_f = SimbleeForMobile.drawSwitch(waveSwitchX2,wave3fSwitchY,waveSwitchColor); 
//  Wave2_sf = SimbleeForMobile.drawSwitch(waveSwitchX2,wave2sfSwitchY,waveSwitchColor);
//  Wave2_sb = SimbleeForMobile.drawSwitch(waveSwitchX2,wave2sbSwitchY,waveSwitchColor);
//  Wave3 = SimbleeForMobile.drawSwitch(waveSwitchX1,wave3SwitchY,waveSwitchColor);     
//  Warmup = SimbleeForMobile.drawSwitch(waveSwitchX2,warmupSwitchY,waveSwitchColor);     
  ontime = SimbleeForMobile.drawTextField(onTimeTextX, onTimeTextY, timeTextWidth, onTime, "", textColor, textFieldColor);
  offtime = SimbleeForMobile.drawTextField(offTimeTextX, offTimeTextY, timeTextWidth, offTime, "", textColor, textFieldColor);
  cooltime = SimbleeForMobile.drawTextField(coolTimeTextX, coolTimeTextY, timeTextWidth, coolTime, "", textColor, textFieldColor);
  runtime = SimbleeForMobile.drawTextField(TIMETextX, TIMETextY, timeTextWidth, TIME, "", textColor, textFieldColor);
  fl1ID = SimbleeForMobile.drawRect(l1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
//  fl2ID = SimbleeForMobile.drawRect(l2IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fl3ID = SimbleeForMobile.drawRect(l3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
//  fl4ID = SimbleeForMobile.drawRect(l4IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fr1ID = SimbleeForMobile.drawRect(r1IDX, fIDY, limbIDL, limbIDW, limbIndColor);
//  fr2ID = SimbleeForMobile.drawRect(r2IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  fr3ID = SimbleeForMobile.drawRect(r3IDX, fIDY, limbIDL, limbIDW, limbIndColor);
//  fr4ID = SimbleeForMobile.drawRect(r4IDX, fIDY, limbIDL, limbIDW, limbIndColor);
  rr1ID = SimbleeForMobile.drawRect(r1IDX, rIDY, limbIDL, limbIDW, limbIndColor);
//  rr2ID = SimbleeForMobile.drawRect(r2IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rr3ID = SimbleeForMobile.drawRect(r3IDX, rIDY, limbIDL, limbIDW, limbIndColor);
//  rr4ID = SimbleeForMobile.drawRect(r4IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rl1ID = SimbleeForMobile.drawRect(l1IDX, rIDY, limbIDL, limbIDW, limbIndColor);
//  rl2ID = SimbleeForMobile.drawRect(l2IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  rl3ID = SimbleeForMobile.drawRect(l3IDX, rIDY, limbIDL, limbIDW, limbIndColor);
//  rl4ID = SimbleeForMobile.drawRect(l4IDX, rIDY, limbIDL, limbIDW, limbIndColor);
  SimbleeForMobile.endScreen();
  update;
}

void off()
{
    wave1_b = 0;
    wave1_f = 0;

    digitalWrite(fl1, LOW);
    digitalWrite(fl2, LOW);
    digitalWrite(fl3, LOW);
    digitalWrite(fl4, LOW);
    digitalWrite(fr1, LOW);
    digitalWrite(fr2, LOW);
    digitalWrite(fr3, LOW);
    digitalWrite(fr4, LOW);    
    digitalWrite(rl1, LOW);
    digitalWrite(rl2, LOW);
    digitalWrite(rl3, LOW);
    digitalWrite(rl4, LOW);
    digitalWrite(rr1, LOW);
    digitalWrite(rr2, LOW);
    digitalWrite(rr3, LOW);
    digitalWrite(rr4, LOW);
    delay(offTime);
}

void wave1b() 
{
  if (wave1_b == 1){
    if(count == 1){
      startTime = millis();
      count = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_b = 0;
    }
  SimbleeForMobile.process();  
//  digitalWrite(rr4, HIGH);
  digitalWrite(fl1, HIGH);
  digitalWrite(rr1, LOW);
  digitalWrite(rr2, LOW);
  digitalWrite(rr3, HIGH);
  digitalWrite(fl2, LOW);
  digitalWrite(fl3, LOW);
  digitalWrite(fl4, LOW);
  digitalWrite(fr1, LOW);
  digitalWrite(fr2, LOW);
  digitalWrite(fr3, LOW);
  digitalWrite(fr4, LOW);
  digitalWrite(rl1, LOW);
  digitalWrite(rl2, LOW);
  digitalWrite(rl3, LOW);
  digitalWrite(rl4, LOW);
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
      count = 1;
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
      count = 1;
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
      count = 1;
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
//  if (wave1_b == 1){
//        currentTime = millis();
//    if (abs(currentTime - startTime) >= abs(TIME)){
//      count = 1;
//      wave1_b = 0;
//    }
////  SimbleeForMobile.process();
//  digitalWrite(rr2, HIGH);
//  digitalWrite(fl3, HIGH);
//  SimbleeForMobile.updateColor(rr2ID, RED);
//  SimbleeForMobile.updateColor(fl3ID, RED);
//  delay(onTime);
//  }
//  digitalWrite(rr2, LOW);
//  digitalWrite(fl3, LOW);
//  SimbleeForMobile.updateColor(rr2ID, BLACK);
//  SimbleeForMobile.updateColor(fl3ID, BLACK);
//  delay(offTime);
//  if (wave1_b == 1){
//        currentTime = millis();
//    if (abs(currentTime - startTime) >= abs(TIME)){
//      count = 1;
//      wave1_b = 0;
//    }
//  SimbleeForMobile.process();
//  digitalWrite(rl3, HIGH);
//  digitalWrite(fr2, HIGH);
//  SimbleeForMobile.updateColor(rl3ID, RED);
//  SimbleeForMobile.updateColor(fr2ID, RED);
//  delay(onTime);
//  }
//  digitalWrite(rl3, LOW);
//  digitalWrite(fr2, LOW);
//  SimbleeForMobile.updateColor(rl3ID, BLACK);
//  SimbleeForMobile.updateColor(fr2ID, BLACK);
//  delay(offTime);
//    if (wave1_b == 1){
//        currentTime = millis();
//    if (abs(currentTime - startTime) >= abs(TIME)){
//      count = 1;
//      wave1_b = 0;
//    }
//  SimbleeForMobile.process();
//  digitalWrite(rr1, HIGH);
//  digitalWrite(fl4, HIGH);
//  SimbleeForMobile.updateColor(rr1ID, RED);
//  SimbleeForMobile.updateColor(fl4ID, RED);
//  delay(onTime);
//  }
//  digitalWrite(rr1, LOW);
//  digitalWrite(fl4, LOW);
//  SimbleeForMobile.updateColor(rr1ID, BLACK);
//  SimbleeForMobile.updateColor(fl4ID, BLACK);
//  delay(offTime);
//      if (wave1_b == 1){
//        currentTime = millis();
//    if (abs(currentTime - startTime) >= abs(TIME)){
//      count = 1;
//      wave1_b = 0;
//    }
//  SimbleeForMobile.process();
//  digitalWrite(rl4, HIGH);
//  digitalWrite(fr1, HIGH);
//  SimbleeForMobile.updateColor(rl4ID, RED);
//  SimbleeForMobile.updateColor(fr1ID, RED);
//  delay(onTime);
//  }
//  digitalWrite(rl4, LOW);
//  digitalWrite(fr1, LOW);
//  SimbleeForMobile.updateColor(rl4ID, BLACK);
//  SimbleeForMobile.updateColor(fr1ID, BLACK);
//  delay(offTime + coolTime);
}

void wave1f() 
{
  if (wave1_f == 1){
    if(count == 1){
      startTime = millis();
      count = 2;
    }
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rr1, LOW);
  digitalWrite(rr2, LOW);
  digitalWrite(rr3, LOW);
  digitalWrite(rr4, LOW);
  digitalWrite(fr1, LOW);
  digitalWrite(fr2, LOW);
  digitalWrite(fr3, LOW);
  digitalWrite(fr4, HIGH);
  digitalWrite(rl1, HIGH);
  digitalWrite(rl2, LOW);
  digitalWrite(rl3, LOW);
  digitalWrite(rl4, LOW);
  digitalWrite(fl1, LOW);
  digitalWrite(fl2, LOW);
  digitalWrite(fl3, LOW);
  digitalWrite(fl4, LOW);
  SimbleeForMobile.updateColor(rl1ID, RED);
  SimbleeForMobile.updateColor(fr4ID, RED);
  delay(onTime);
  }
  digitalWrite(rl1, LOW);
  digitalWrite(fr4, LOW);
  SimbleeForMobile.updateColor(rl1ID, BLACK);
  SimbleeForMobile.updateColor(fr4ID, BLACK);
  delay(offTime);
  if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rr4, HIGH);
  digitalWrite(fl1, HIGH);
  SimbleeForMobile.updateColor(rr4ID, RED);
  SimbleeForMobile.updateColor(fl1ID, RED);
  delay(onTime);
  }
  digitalWrite(rr4, LOW);
  digitalWrite(fl1, LOW);
  SimbleeForMobile.updateColor(rr4ID, BLACK);
  SimbleeForMobile.updateColor(fl1ID, BLACK);
  delay(offTime);
  if (wave1_f == 1){   
    currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rl2, HIGH);
  digitalWrite(fr3, HIGH);
  SimbleeForMobile.updateColor(rl2ID, RED);
  SimbleeForMobile.updateColor(fr3ID, RED);
  delay(onTime);
  }
  digitalWrite(rl2, LOW);
  digitalWrite(fr3, LOW);
  SimbleeForMobile.updateColor(rl2ID, BLACK);
  SimbleeForMobile.updateColor(fr3ID, BLACK);
  delay(offTime);
  if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();  
  digitalWrite(rr3, HIGH);
  digitalWrite(fl2, HIGH);
  SimbleeForMobile.updateColor(rr3ID, RED);
  SimbleeForMobile.updateColor(fl2ID, RED);
  delay(onTime);
  }
  digitalWrite(rr3, LOW);
  digitalWrite(fl2, LOW);
  SimbleeForMobile.updateColor(rr3ID, BLACK);
  SimbleeForMobile.updateColor(fl2ID, BLACK);
  delay(offTime);
  if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();
  digitalWrite(rl3, HIGH);
  digitalWrite(fr2, HIGH);
  SimbleeForMobile.updateColor(rl3ID, RED);
  SimbleeForMobile.updateColor(fr2ID, RED);
  delay(onTime);
  }
  digitalWrite(rl3, LOW);
  digitalWrite(fr2, LOW);
  SimbleeForMobile.updateColor(rl3ID, BLACK);
  SimbleeForMobile.updateColor(fr2ID, BLACK);
  delay(offTime);
  if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();
  digitalWrite(rr2, HIGH);
  digitalWrite(fl3, HIGH);
  SimbleeForMobile.updateColor(rr2ID, RED);
  SimbleeForMobile.updateColor(fl3ID, RED);
  delay(onTime);
  }
  digitalWrite(rr2, LOW);
  digitalWrite(fl3, LOW);
  SimbleeForMobile.updateColor(rr2ID, BLACK);
  SimbleeForMobile.updateColor(fl3ID, BLACK);
  delay(offTime);
    if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();
  digitalWrite(rl4, HIGH);
  digitalWrite(fr1, HIGH);
  SimbleeForMobile.updateColor(rl4ID, RED);
  SimbleeForMobile.updateColor(fr1ID, RED);
  delay(onTime);
  }
  digitalWrite(rl4, LOW);
  digitalWrite(fr1, LOW);
  SimbleeForMobile.updateColor(rl4ID, BLACK);
  SimbleeForMobile.updateColor(fr1ID, BLACK);
  delay(offTime);
      if (wave1_f == 1){
        currentTime = millis();
    if (abs(currentTime - startTime) >= abs(TIME)){
      count = 1;
      wave1_f = 0;
    }
  SimbleeForMobile.process();
  digitalWrite(rr1, HIGH);
  digitalWrite(fl4, HIGH);
  SimbleeForMobile.updateColor(rr1ID, RED);
  SimbleeForMobile.updateColor(fl4ID, RED);
  delay(onTime);
  }
  digitalWrite(rr1, LOW);
  digitalWrite(fl4, LOW);
  SimbleeForMobile.updateColor(rr1ID, BLACK);
  SimbleeForMobile.updateColor(fl4ID, BLACK);
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

void fl2event()
{
      SimbleeForMobile.process();
      digitalWrite(fl2, HIGH);
      SimbleeForMobile.updateColor(fl2ID, RED);
      SimbleeForMobile.updateColor(FL2, RED);      
      delay(onTime);
      digitalWrite(fl2, LOW);
      SimbleeForMobile.updateColor(fl2ID, BLACK);
      SimbleeForMobile.updateColor(FL2, BLACK);      
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

void fl4event()
{
      SimbleeForMobile.process();
      digitalWrite(fl4, HIGH);
      SimbleeForMobile.updateColor(fl4ID, RED);
      SimbleeForMobile.updateColor(FL4, RED);     
      delay(onTime);
      digitalWrite(fl4, LOW);
      SimbleeForMobile.updateColor(fl4ID, BLACK);
      SimbleeForMobile.updateColor(FL4, BLACK);      
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

void fr2event()
{
      SimbleeForMobile.process();
      digitalWrite(fr2, HIGH);
      SimbleeForMobile.updateColor(fr2ID, RED);
      SimbleeForMobile.updateColor(FR2, RED);      
      delay(onTime);
      digitalWrite(fr2, LOW);
      SimbleeForMobile.updateColor(fr2ID, BLACK);
      SimbleeForMobile.updateColor(FR2, BLACK);      
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

void fr4event()
{
      SimbleeForMobile.process();
      digitalWrite(fr4, HIGH);
      SimbleeForMobile.updateColor(fr4ID, RED);
      SimbleeForMobile.updateColor(FR4, RED);      
      delay(onTime);
      digitalWrite(fr4, LOW);
      SimbleeForMobile.updateColor(fr4ID, BLACK);
      SimbleeForMobile.updateColor(FR4, BLACK);      
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

void rr2event()
{
      SimbleeForMobile.process();
      digitalWrite(rr2, HIGH);
      SimbleeForMobile.updateColor(rr2ID, RED);
      SimbleeForMobile.updateColor(RR2, RED);      
      delay(onTime);
      digitalWrite(rr2, LOW);
      SimbleeForMobile.updateColor(rr2ID, BLACK);
      SimbleeForMobile.updateColor(RR2, BLACK);
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

void rr4event()
{
      SimbleeForMobile.process();
      digitalWrite(rr4, HIGH);
      SimbleeForMobile.updateColor(rr4ID, RED);
      SimbleeForMobile.updateColor(RR4, RED);
      delay(onTime);
      digitalWrite(rr4, LOW);
      SimbleeForMobile.updateColor(rr4ID, BLACK);
      SimbleeForMobile.updateColor(RR4, BLACK);
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

void rl2event()
{
      SimbleeForMobile.process();
      digitalWrite(rl2, HIGH);
      SimbleeForMobile.updateColor(rl2ID, RED);
      SimbleeForMobile.updateColor(RL2, RED);
      delay(onTime);
      digitalWrite(rl2, LOW);
      SimbleeForMobile.updateColor(rl2ID, BLACK);
      SimbleeForMobile.updateColor(RL2, BLACK);
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

void rl4event()
{
      SimbleeForMobile.process();
      digitalWrite(rl4, HIGH);
      SimbleeForMobile.updateColor(rl4ID, RED);
      SimbleeForMobile.updateColor(RL4, RED);
      delay(onTime);

      digitalWrite(rl4, LOW);
      SimbleeForMobile.updateColor(rl4ID, BLACK);
      SimbleeForMobile.updateColor(RL4, BLACK);
      delay(offTime);

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
   SimbleeForMobile.setEvents(FL2, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FL2){
    if (event.type == EVENT_PRESS)
      Fl2 = 1;
    else if (event.type == EVENT_RELEASE)
      Fl2 = 0;
   }
   SimbleeForMobile.setEvents(FL3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FL3){
    if (event.type == EVENT_PRESS)
      Fl3 = 1;
    else if (event.type == EVENT_RELEASE)
      Fl3 = 0;
   }
   SimbleeForMobile.setEvents(FL4, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FL4){
    if (event.type == EVENT_PRESS)
      Fl4 = 1;
    else if (event.type == EVENT_RELEASE)
      Fl4 = 0;
   }
   SimbleeForMobile.setEvents(FR1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR1){
    if (event.type == EVENT_PRESS)
      Fr1 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr1 = 0;
   }
   SimbleeForMobile.setEvents(FR2, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR2){
    if (event.type == EVENT_PRESS)
      Fr2 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr2 = 0;
   }
   SimbleeForMobile.setEvents(FR3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR3){
    if (event.type == EVENT_PRESS)
      Fr3 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr3 = 0;
   }
   SimbleeForMobile.setEvents(FR4, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == FR4){
    if (event.type == EVENT_PRESS)
      Fr4 = 1;
    else if (event.type == EVENT_RELEASE)
      Fr4 = 0;
   }
  SimbleeForMobile.setEvents(RL1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL1){
    if (event.type == EVENT_PRESS)
      Rl1 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl1 = 0;
   }
   SimbleeForMobile.setEvents(RL2, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL2){
    if (event.type == EVENT_PRESS)
      Rl2 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl2 = 0;
   }
   SimbleeForMobile.setEvents(RL3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL3){
    if (event.type == EVENT_PRESS)
      Rl3 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl3 = 0;
   }
   SimbleeForMobile.setEvents(RL4, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RL4){
    if (event.type == EVENT_PRESS)
      Rl4 = 1;
    else if (event.type == EVENT_RELEASE)
      Rl4 = 0;
   }
   SimbleeForMobile.setEvents(RR1, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR1){
    if (event.type == EVENT_PRESS)
      Rr1 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr1 = 0;
   }
   SimbleeForMobile.setEvents(RR2, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR2){
    if (event.type == EVENT_PRESS)
      Rr2 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr2 = 0;
   }
   SimbleeForMobile.setEvents(RR3, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR3){
    if (event.type == EVENT_PRESS)
      Rr3 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr3 = 0;
   }
   SimbleeForMobile.setEvents(RR4, EVENT_PRESS|EVENT_RELEASE);
   if(event.id == RR4){
    if (event.type == EVENT_PRESS)
      Rr4 = 1;
    else if (event.type == EVENT_RELEASE)
      Rr4 = 0;
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

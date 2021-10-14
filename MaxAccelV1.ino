#include <M5StickCPlus.h>

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float accXSq = 0.0F;
float accYSq = 0.0F;
float accZSq = 0.0F;
float magSq = 0.0F;
float curMag = 0.0F;
float maxMag = 0.0F;



void setup() {
  // put your setup code here, to run once:
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setCursor(80, 15);
  M5.Lcd.println("IMU TEST");
  
}


/*****************************************
M5.IMU.getGyroData(&gyroX,&gyroY,&gyroZ);
M5.IMU.getAccelData(&accX,&accY,&accZ);
M5.IMU.getAhrsData(&pitch,&roll,&yaw);
M5.IMU.getTempData(&temp);
*****************************************/
void loop() {
  // put your main code here, to run repeatedly:
  
  M5.IMU.getAccelData(&accX,&accY,&accZ);
  magSq = ((pow(accX,2)) + (pow(accY,2)) + (pow(accZ,2)));
  curMag = pow(magSq,0.5);
  
  
  M5.Lcd.setTextSize(2);
  if(curMag > maxMag){
    maxMag = curMag;
  }
  
  M5.Lcd.setCursor(80, 50);
  M5.Lcd.println(maxMag);
  
}

/* 
 * Project Crowhill_IOT_Midterm
 * Author: Crowhill, Celestino
 * Date: 25-OCT-2023, 6-NOV-2033
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"
//#include "Adafruit_GFX.h"
//#include "Adafruit_SSD1306.h"
#include "IoTClassroom_CNM.h"
#include "neopixel.h"
#include "Button.h"
#include "Colors.h"
#define OLED_RESET D4
const int BUTTON1 = D2; //can i change to "Button B1 (D2)?
const int BUTTON2 = D3;
const int BUTTON3 = D4;
const int BUTTON4 = D5;
Button button1(BUTTON1);
Button button2(BUTTON2);
Button button3(BUTTON3);
Button button4(BUTTON4);//
bool isClicked;
bool onoff;
int i;
int j;
//Sensor1 = A1;
//Button;
Adafruit_NeoPixel pixel1( PIXEL_COUNT , SPI1, WS2812B);//plug into d15
//Adafruit_NeoPixel pixel2( PIXEL_COUNT , SPI1, WS2812B);//plug into d?
//const int white = NeoP2;//on if sensor is tripped
const int PIXEL_COUNT = 12;
//const int PIXEL_COUNT2 = 12;
//Adafruit_NeoPixel pixel2( PIXEL_COUNT , SPI1, WS2812B);//plug into d?
const int NeoP1 = D4;
//Adafruit_SSD1306 display(OLED_RESET);
//int month = 12;
//int day = 18;
//int year = 1981;
//const char honor = 0xA4;
//int rotate = 2
const int NUMBULBS=6; //need help with articulating button to ph to sensor
int color;
HueBrite = BULB
Button PH (D5);


SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() { //can i condense all the seial prints? 
Serial.begin (9600);
j=0;
i=0;
pixel.begin();
pixel.show();
pixel.clear();
onoff = false;
  //display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  // initialize with the I2C addr 0x3D (for the 128x64)
  //display.setTextSize(2);
  //display.setTextColor(WHITE);
  //display.setCursor(0,0);
  //display.setTextColor(WHITE);
  //delay(2000);
  //display.clearDisplay();
Serial.begin(9600);
  waitFor(Serial.isConnected,15000);
  WiFi.on();
  WiFi.setCredentials("IoTNetwork");
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf("on");
  }
  Serial.printf("\n\n");
  onoff = false;

  Serial.begin(9600);
  waitFor(Serial.isConnected,1500);
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
 
  WiFi.connect();
    while(WiFi.connecting()){
      Serial.printf(".");
    }
  delay(1000);
  Serial.printf("\n\n");

}

void loop(){
  pixel.clear();
  if(button1.isClicked()){
      onoff = !onoff;
        else(pixel.setPixelColor(i, teal)); //neo pixel color is on unless turned off
  }                  
  //if(Sensor.isTripped); //need to download library for sensor  do not know the c 
    
    for(i=0; i<16; i=i+1){ //alarm for neo pixel when sensor is tripped
      pixel.setPixelColor(i,red);
      pixel.show();
      delay(500);
       }
   if(Button2.isClicked()){
      onoff =!onoff;
      else {
        pixel.clear();
        (i=0; i<12; i=i+1) 
        pixel.setPixelColor(i,teal);
        pixel.show();
      }
  }
   if(button3.isClicked){ // Wemo code
      onoff == !onoff; 
     
   else(){
    
    }
}
  //display.setTextSize(1)
  //display.setTextColor(WHITE);
  //display.setCursor(0,0);
  //display.clearDisplay();
  //display.printf("Se%cior Celestino born %i/%i/%i", honor, month, day, year);
  //display.display();
   if(HueBrite=255){ ///code for sensor will flash the hue lights
    i=0, 
    
    if (Button4.isClicked()){ //manual button alarm with ph lights
    onoff =!onoff;
    }
      if (onoff == true){
    setHue(BULB,true,red[color%7],random(32,0),255);

  }
        if (!onoff){
    setHue(BULB,false,white[color%7],random(32,0),255);
}
}
  Serial.printf("what up%i\n", MYWEMO);
  wemoWrite(MYWEMO,HIGH);
  delay(5000);
  Serial.printf("later# %i\n", MYWEMO);
  wemoWrite(MYWEMO,LOW);
  delay(5000);
 
}
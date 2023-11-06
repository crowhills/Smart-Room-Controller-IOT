/* 
 * Project Smart Room Controller
 * Author: C.C
 * Date: 5_NOV_2023
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */
#include "Particle.h"
#include "Adafruit_GFX.h"
#include "IoTClassroom_CNM.h"
#include "neopixel.h"
#include "Button.h"
#include "Colors.h"
#include "Adafruit_SSD1306.h"
#define OLED_RESET D4
const int BUTTON1 = D3;    //NeoPixel
const int NeoP1 = D15; 
const int PIXEL_COUNT = 12;
const int BUTTON2 = D4;    //HueLights
const int NUMBULBS = 6; 
const int Diode = A1;      //automatic Mode Wemo
const int MYWEMO = 0;
//int magenta = 0xFF00FF;
//int teal = 0x008080;
int x;
int i;
int j;
int y;
int threshold = 18; //4095
int rotate = 2;
int color = 0;
Adafruit_NeoPixel pixel(12, SPI1, WS2812B);
Button button1(BUTTON1);
Adafruit_SSD1306 display(OLED_RESET);
Button button2(BUTTON2);
bool onoff1 = false;
bool isClicked;
bool onoff2;
bool onoffH;
int HueBrite = NUMBULBS;

//SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() { 
Serial.begin (9600);
pinMode(Diode, INPUT);
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");
  waitFor(Serial.isConnected,15000);
  WiFi.on();
  WiFi.setCredentials("IoTNetwork");
  WiFi.connect();
pixel.begin();
pixel.show();
pixel.clear();
j=0;   
i=0;
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  delay(2000);
  display.clearDisplay();

  }
  
  
void loop(){              //NeoPixel
  pixel.clear();
  if(button1.isClicked()){
     if(onoff1 == !onoff1){

    for (i=0; i<12; i++){
        pixel.setPixelColor(i, teal);
    }
        pixel.show();
      }
    else{
    onoff1 = false;
    Serial.printf("button not clicked %i\n");
    } 
  }
       
   
  if(HueBrite==255){       //HueLights
    
    if (button2.isClicked()){ 
          onoffH =!onoffH;
    }
      if (onoffH = true){
          setHue(NUMBULBS,random(32,0),255);
      }
        if (!onoffH){
            setHue(NUMBULBS,random(32,0),255);
       }
  }

if (x > threshold) {      //Photodiode/Wemo
    x = analogRead(Diode); 
    Serial.printf("%i\n", x);
      wemoWrite(MYWEMO, HIGH);
} 
  else {
   wemoWrite(MYWEMO, LOW);
  }

  display.setTextSize(1);  //OLED
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.printf("I think it is fair   to say the weather    is wild today");
  display.display();
}





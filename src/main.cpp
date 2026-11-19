#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE, 6, 5);

void setup(){
    Serial.begin(115200);
    Wire.begin();
    u8x8.begin();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    pinMode(1,INPUT);
    delay(3000);
}

bool previousState = false;
long previousLow = 0;
long currentLow = 0;

void loop(){
    if(digitalRead(1)){
        u8x8.drawString(0,0,"Motion Detected.");
        u8x8.drawString(0,1,"               ");
        previousState = true;
    }else{
        currentLow = millis();
        if(previousState){
            previousLow = currentLow;
        }else if((currentLow - previousLow) > 1400){
            u8x8.drawString(0,0,"No Motion       ");
            u8x8.drawString(0,1,"Detected.");
        }    
        previousState = false;
    }
    //delay(100);
}
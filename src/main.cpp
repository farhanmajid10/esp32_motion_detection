#include <Arduino.h>
//#include <Wire.h>
#include <U8g2lib.h>
#include "oled_display.h"
#include "motion_sensor.h"

#define motion_sensor_pin 1

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE, 6, 5);
oled_display display(u8x8);
PIR_Sensor motion_sensor(motion_sensor_pin);

void setup(){
    Serial.begin(115200);
    display.begin();
    display.setFont(u8x8_font_chroma48medium8_r);
    motion_sensor.begin();
    delay(3000);
}

bool previousState = false;
long previousLow = 0;
long currentLow = 0;
    
void loop(){
    if(motion_sensor.is_detected()){
        display.drawString(0,0,"Motion Detected.");
        display.drawString(0,1,"               ");
        previousState = true;
    }else{
        currentLow = millis();
        if(previousState){
            previousLow = currentLow;
        }else if((currentLow - previousLow) > 1400){
            display.drawString(0,0,"No Motion       ");
            display.drawString(0,1,"Detected.");
        }    
        previousState = false;
    }
    //delay(100);
}
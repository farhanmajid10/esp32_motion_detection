#include <Arduino.h>
//#include <Wire.h>
#include <U8g2lib.h>
#include "oled_display.h"
#include "motion_sensor.h"

#define motion_sensor_pin 1
#define scl_pin 6
#define sda_pin 5

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE, scl_pin, sda_pin);
oled_display display(u8x8);
PIR_Sensor motion_sensor(motion_sensor_pin);

void setup(){
    Serial.begin(115200);
    display.begin();
    display.setFont(u8x8_font_chroma48medium8_r);
    motion_sensor.begin();
    delay(3000);
}

bool previous_display_state = false;
unsigned long previous_high = 0;

void loop(){
    bool motion_detected = motion_sensor.is_detected();
    if(motion_detected){
        previous_high = millis();
        if(!previous_display_state){
            display.drawString(0,0,"Motion Detected.");
            display.drawString(0,1,"               ");
            previous_display_state = true;
        }
    }else if (previous_display_state){
        unsigned long current = millis();
        if((current - previous_high) > 1400){
            display.drawString(0,0,"No Motion       ");
            display.drawString(0,1,"Detected.");
            previous_display_state = false;
        }    
    }
    //delay(100);
}
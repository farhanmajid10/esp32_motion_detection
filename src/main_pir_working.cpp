/*

#include <Arduino.h>

const int PIR_PIN = 1;
int counter = 0;

int previous_state = 0;
int current_state = 0;
unsigned long rise_time = 0;
unsigned long fall_time = 0;
bool valid_time = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(115200);
  delay(1000);
  previous_state = digitalRead(PIR_PIN);
}

void loop() {
    current_state = digitalRead(PIR_PIN);
    if((current_state == 1) && (previous_state == 0)){
        rise_time = millis();
        Serial.print("Motion Detected. Count = ");
        Serial.println(++counter);
        valid_time = true;
    }else if((current_state == 0) && (previous_state == 1)){
        fall_time = millis();
        Serial.print("Motion Cleared. ");
        if(valid_time){
            Serial.print("High time: ");
            Serial.println(fall_time - rise_time);
        }else{
            Serial.println("Invalid time");
        }
        valid_time = false;
    }
    previous_state = current_state;
    delay(100); 
}

*/

/*
functions to remember for arduino

Serial.println()
PinMode()
digitalRead()
digitalWrite()
delay()
Serial.begin()
*/
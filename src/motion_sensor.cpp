#include <motion_sensor.h>

#include <Arduino.h>

PIR_Sensor::PIR_Sensor(uint8_t pin){
    pin_ = pin;
}
void PIR_Sensor::begin(){
    pinMode(pin_, INPUT);
}

bool PIR_Sensor::is_detected(void) const{
    return (digitalRead(pin_) == HIGH);
}

#include "i2c_custom.h"
#include "Arduino.h"


i2c_custom::i2c_custom(uint8_t scl, uint8_t sda): scl_(scl),sda_(sda){

}

bool i2c_custom::start(){
    return false;
}
bool i2c_custom::stop(){
    return false;
}
bool i2c_custom::write_ack(bool ack){
    return false;
}
int i2c_custom::read_ack(){
    return -1;
}
int i2c_custom::send_byte(uint8_t byte){
    return -1;
}
bool i2c_custom::read_byte(uint8_t& byte){
    return false;
}
bool i2c_custom::write_bit(bool bit){
    return false;
}
bool i2c_custom::read_bit(bool& bit){
    return false;
}
bool i2c_custom::begin(){
    return false;
}
bool i2c_custom::restart(){
    return false;
}
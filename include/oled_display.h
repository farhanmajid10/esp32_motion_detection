#pragma once

#include <U8x8lib.h> //because we used the data types from there.

class oled_display{
public:
    explicit oled_display(U8X8_SSD1306_128X64_NONAME_HW_I2C& u8x8); //set this to private variable.
    void begin();//call begin for the u8x8_ object.
    void setFont(const uint8_t *font_8x8);//set font.
    int drawString(uint8_t x, uint8_t y, const char* s);// will take in the x and y coordinates and then the string to be printed.
private:
    U8X8_SSD1306_128X64_NONAME_HW_I2C& u8x8_;//private variable.
};
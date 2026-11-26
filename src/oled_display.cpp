#include "oled_display.h"
#include <cstring> //not cstring.h

//uint8_t scl = 6;
//uint8_t sda = 5;

//this line should be in the main, right? Here I just need the function?
//U8X8_SSD1306_128X64_NONAME_HW_I2C display(U8X8_PIN_NONE, scl, sda);

oled_display::oled_display(U8X8_SSD1306_128X64_NONAME_HW_I2C& u8x8): u8x8_(u8x8)
{};//fixed initializer problem. Need to understand this better.

void oled_display::begin(){
    u8x8_.begin();// Don't know how to check validity.
}

void oled_display::setFont(const uint8_t *font_8x8){
    u8x8_.setFont(font_8x8);//setting font. Don't know how to check validity.
}

int oled_display::drawString(uint8_t x, uint8_t y, const char* s){
    if(s == nullptr){return -1;}
    if((x > 15) || (y > 7)){ // No need to check for 0.
        return -2;
    }
    size_t length_of_string = std::strlen(s);
    if(((length_of_string) == 0) || ((length_of_string + x) > 16)){return -3;}
    u8x8_.drawString(x,y,s);
    return 0;
    //check for size of s, if 0 or greater than 16, it is invalid.
    //check for nullptr
    //check that x is bewteen 0 and 7(including)
    //if yes, then good, if not then invalid.
    //might change the retun type for error checking.
}
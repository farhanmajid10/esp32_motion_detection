#pragma once

#include <stdint.h>

class PIR_Sensor{
    public:
        explicit PIR_Sensor(uint8_t pin);
        void begin();
        bool is_detected(void) const;
    private:   
        uint8_t pin_;
};
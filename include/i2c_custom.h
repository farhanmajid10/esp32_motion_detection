#pragma once

class i2c_custom{
public:
    i2c_custom(uint8_t scl, uint8_t sda);
    bool start();
    bool stop();
    bool write_ack(bool ack);
    int read_ack();
    int send_byte(uint8_t byte);
    bool read_byte(uint8_t& byte);
    bool write_bit(bool bit);
    bool read_bit(bool& bit);
    bool begin();
    bool restart();
private:
    uint8_t sda_;
    uint8_t scl_;
};
#include <Arduino.h>
#include <Wire.h>

#define TMP105_ADDR 0x48

class Thermo3Click {
    private:
        uint8_t _i2caddr;

    public:
        Thermo3Click() {}
        bool begin();
        bool begin(uint8_t addr);
        float readTemperature();
        void writeRegister(uint8_t reg, uint16_t val);
        uint16_t readRegister(byte reg);
};

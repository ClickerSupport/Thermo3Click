#include <Thermo3Click.h>

bool Thermo3Click::begin() {
    begin(TMP105_ADDR);
}

bool Thermo3Click::begin(uint8_t addr) {
    _i2caddr = addr;
    Wire.begin();
}

float Thermo3Click::readTemperature() {
    int16_t tmp = readRegister(0) / 16;
    return tmp * 0.0625;
}

void Thermo3Click::writeRegister(uint8_t reg, uint16_t val) {
    Wire.beginTransmission(_i2caddr);
    Wire.write(reg);
    Wire.write(val >> 8);
    Wire.write(val & 0xFF);
    Wire.endTransmission();
}

uint16_t Thermo3Click::readRegister(byte reg) {
    uint16_t value;
    Wire.beginTransmission((uint8_t)_i2caddr);
    Wire.write((uint8_t)reg);
    Wire.endTransmission();
    Wire.requestFrom((uint8_t)_i2caddr, (byte)2);
    value = (Wire.read() << 8) | Wire.read();
    return value;
}

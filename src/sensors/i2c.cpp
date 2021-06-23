/**
 * @file i2c.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Send variables higher than 16-bit and floats over I2C.
 * @version 0.1
 * @date 2021-06-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Wire.h>

void writeBigInt(uint16_t input) {
  uint8_t* bytes = (uint8_t*)(&input);
  Wire.write(bytes, sizeof(uint16_t));
}

void writeBigInt(int16_t input) {
  uint8_t* bytes = (uint8_t*)(&input);
  Wire.write(bytes, sizeof(int16_t));
}

void writeBitInt(uint32_t input) {
    uint8_t* bytes = (uint8_t*)(&input);
  Wire.write(bytes, sizeof(uint32_t));
}

void writeBitInt(int32_t input) {
    uint8_t* bytes = (uint8_t*)(&input);
  Wire.write(bytes, sizeof(int32_t));
}

void writeFloat(float input) {
  uint8_t* bytes = (uint8_t*)(&input);
  Wire.write(bytes, sizeof(float));
}
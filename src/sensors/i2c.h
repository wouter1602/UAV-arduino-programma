/**
 * @file i2c.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Small functions to send more bytes
 * @version 0.1
 * @date 2021-06-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef I2C_H
#define I2C_H

void writeBigInt(uint16_t input);
void writeBigInt(int16_t input);
void writeBigInt(uint32_t input);
void writeBigInt(int32_t input);
void writeFloat(float input);

#endif  // I2C_H

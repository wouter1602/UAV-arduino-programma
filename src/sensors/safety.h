/**
 * @file safety.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Handels cell safety and max current safety
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef SAFETY_H
#define SAFETY_H

#include <inttypes.h>

struct ADC_Data {
  uint16_t cell_1;
  uint16_t cell_2;
  uint16_t cell_3;
  uint16_t current;
};

void setupSafety(ADC_Data& adcData);
void checkCellVoltage(ADC_Data& adcData);
void checkCurrent(ADC_Data& adcData);

#endif  // SAFETY_H
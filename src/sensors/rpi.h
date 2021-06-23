/**
 * @file rpi.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef RPI_H
#define RPI_H

#include "ToF.h"
#include "motor.h"
#include "nine-dof.h"
#include "safety.h"

#define MAX_MARKERS 20

struct markerData {
    uint8_t markerId = 0;
    uint16_t markerX = 0;
    uint16_t markerY = 0;
};

struct RpiData {
    markerData markers[MAX_MARKERS];
};

void setupRpi(void);

void sendRpiData(MotorSettings& motorData, 
                 MotorForce& motorForce,
                 TimeOfFlightData& TimeOfFlightData,
                 DoFData& degreesOfFreedomData,
                 ADC_Data& adcData);
void receiveRpiData(RpiData& data);

#endif  // RPI_H

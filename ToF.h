/**
 * @file ToF.h
 * @author Robert van der Vlist (18143040@student.hhs.nl)
 * @brief Header file to setup and read the Time of Fligh sensors
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
 * Datasheet Time of Flight sensor (VL53L0x):
 * https://www.st.com/resource/en/data_brief/vl53l0x.pdf
 * https://www.st.com/resource/en/user_manual/dm00279088-world-smallest-timeofflight-ranging-and-gesture-detection-sensor-application-programming-interface-stmicroelectronics.pdf
 */
#ifndef TOF_H
#define TOF_H

#include <stdint.h>

/**
 * @brief Struct with three sensor data ints.
 * 
 */
struct TimeOfFlightData {
    uint16_t sensor1;
    uint16_t sensor2;
    uint16_t sensor3;
};


void setupToF(void);
TimeOfFlightData readToF(void);

#endif //TOF_H
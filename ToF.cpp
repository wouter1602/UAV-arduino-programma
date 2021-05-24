/**
 * @file ToF.cpp
 * @author Robert van der Vlist (18143040@student.hhs.nl)
 * @brief Cpp file that setsup the Time of Flight sensors and reads them
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "ToF.h"

#include <Arduino.h>
#include <Wire.h>

#include "defines.h"

/**
 * @brief Initialize the Time of Flight sensors.
 *
 */
void setupToF() {
#ifdef DEBUG
  Serial.println("[INFO] Completed ToF setup.");
#endif  // DEBUG
}

/**
 * @brief Returns Time of Flight data back in referenced struct.
 *
 * @param data Time of Flight struct reference for the data.
 */
void readToF(TimeOfFlightData& data) {}

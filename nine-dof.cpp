/**
 * @file nine-dof.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "nine-dof.h"

#include <Arduino.h>
#include <Wire.h>

#include "defines.h"

/**
 * @brief Reads all the gyro data from the 9-axis DoF sensor
 *
 * @return GyroData struct with gyro data
 */
void readGyro(GyroData& data) {}

/**
 * @brief Reads all the accelerometer data from the 9-axis DoF sensor
 *
 * @return AccelerometerData struct with accelerometer data
 */
void readAccelerometer(AccelerometerData& data) {}

/**
 * @brief Reads all the compass data from the 9-axis DoF sensor
 *
 * @param CompassData struct with compass data
 */
void readCompass(CompassData& data) {}

/**
 * @brief Enables 9-axis DoF sensor
 *
 */
void setupDoF() {
#ifdef DEBUG
  Serial.println("[INFO] Completed setup 9-axis DoF sensor");
#endif  // DEBUG
}

/**
 * @brief returns Reference to struct with all the data of the Mems unit
 *
 * @param DoFData Reference Struct with Gyro, Accelerometer and compass data.
 */
void readDoF(DoFData& data) {
  readGyro(data.gyroData);
  readAccelerometer(data.accelerometerData);
  readCompass(data.compassData);
}
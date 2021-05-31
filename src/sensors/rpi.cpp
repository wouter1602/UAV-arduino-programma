/**
 * @file rpi.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <Arduino.h>
#include <Wire.h>

#include "rpi.h"

#include "../../defines.h"

/**
 * @brief
 *
 */
void setupRpi() {
  Wire.beginTransmission(RPI_ADDRESS);
  Wire.write("datum");
  Wire.endTransmission();
  delay(15);

  Wire.requestFrom(RPI_ADDRESS, 11);
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print("[INFO] Received: ");
    Serial.println(c);
  }
  
#ifdef DEBUG
  Serial.println("[INFO] Completed Raspberry Pi setup.");
#endif  // DEBUG
}

/**
 * @brief 
 * 
 * @param motorData 
 * @param motorForce 
 * @param TimeOfFlightData 
 * @param degreesOfFreedomData 
 */
void sendRpiData(MotorSettings& motorData, MotorForce& motorForce,
                 TimeOfFlightData& TimeOfFlightData,
                 DoFData& degreesOfFreedomData){}

/**
 * @brief 
 * 
 * @param data 
 */
void receiveRpiData(RpiData& data) {

}
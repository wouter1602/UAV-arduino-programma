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

#include "rpi.h"

#include <Arduino.h>
#include <Wire.h>

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
                 DoFData& degreesOfFreedomData, ADC_Data& adcData) {
  Wire.beginTransmission(RPI_ADDRESS);
#ifdef USE_RPI_TEST_DATA
  Wire.write("D");
  Wire.write(TOF_FAKE_DATA1);
  RPI_DATA_TAB
  Wire.write(TOF_FAKE_DATA2);
  RPI_DATA_TAB
  Wire.write(TOF_FAKE_DATA3);
  RPI_DATA_TAB
  Wire.write(ADC_FAKE_CELL1);
  RPI_DATA_TAB
  Wire.write(ADC_FAKE_CELL2);
  RPI_DATA_TAB
  Wire.write(ADC_FAKE_CELL2);
  RPI_DATA_TAB
  Wire.write(CURRENT_FAKE);
  RPI_DATA_TAB
  Wire.write(MOTOR_FAKE_PWM1);
  RPI_DATA_TAB
  Wire.write(MOTOR_FAKE_PWM2);
  RPI_DATA_TAB
  Wire.write(MOTOR_FAKE_PWM3);
  RPI_DATA_TAB
  Wire.write((uint32_t)MOTOR_FAKE_FORCE1);
  RPI_DATA_TAB
  Wire.write((uint32_t)MOTOR_FAKE_FORCE2);
  RPI_DATA_TAB
  Wire.write((uint32_t)MOTOR_FAKE_FORCE3);
#else
  Wire.write("D");
  Wire.write(TimeOfFlightData.sensor1);
  RPI_DATA_TAB
  Wire.write(TimeOfFlightData.sensor2);
  RPI_DATA_TAB
  Wire.write(TimeOfFlightData.sensor3);
  RPI_DATA_TAB
  Wire.write(adcData.cell_1);
  RPI_DATA_TAB
  Wire.write(adcData.cell_2);
  RPI_DATA_TAB
  Wire.write(adcData.cell_3);
  RPI_DATA_TAB
  Wire.write(adcData.current);
  RPI_DATA_TAB
  Wire.write(motorData.motorPWMSpeed1);
  RPI_DATA_TAB
  Wire.write(motorData.motorPWMSpeed2);
  RPI_DATA_TAB
  Wire.write(motorData.motorPWMSpeed3);
  RPI_DATA_TAB
  Wire.write((uint32_t)motorForce.motor1Force);
  RPI_DATA_TAB
  Wire.write((uint32_t)motorForce.motor2Force);
  RPI_DATA_TAB
  Wire.write((uint32_t)motorForce.motor3Force);

#endif  // USE_RPI_TEST_DATA
  Wire.endTransmission();
  #ifdef DEBUG
  Serial.println("[INFO] Send sensor data to the Raspberry Pi.");
  #endif // DEBUG
}

/**
 * @brief
 *
 * @param data
 */
void receiveRpiData(RpiData& data) {}
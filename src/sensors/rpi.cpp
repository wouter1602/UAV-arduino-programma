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
#include "i2c.h"

#pragma pack(push, 1)
struct WireData {
  uint8_t datatype = 'D';
  TimeOfFlightData tof;
  ADC_Data adc;
  MotorSettings motorPWM;
  MotorForce motorForce;
  DoFData dof;
};
#pragma pack(pop)

void writeWiredata(WireData* wireData) {
  uint8_t* bytes = (uint8_t*)wireData;
  Wire.write(bytes, sizeof(WireData));
}

#ifdef USE_RPI_TEST_DATA
void setRpiTestData(MotorSettings& motorData, MotorForce& motorForce,
                    TimeOfFlightData& timeOfFlightData,
                    DoFData& degreesOfFreedomData, ADC_Data& adcData) {
  motorData.motorPWMSpeed1 = MOTOR_FAKE_PWM1;
  motorData.motorPWMSpeed2 = MOTOR_FAKE_PWM2;
  motorData.motorPWMSpeed3 = MOTOR_FAKE_PWM3;

  motorForce.motor1Force = MOTOR_FAKE_FORCE1;
  motorForce.motor2Force = MOTOR_FAKE_FORCE2;
  motorForce.motor3Force = MOTOR_FAKE_FORCE3;

  timeOfFlightData.sensor1 = TOF_FAKE_DATA1;
  timeOfFlightData.sensor2 = TOF_FAKE_DATA2;
  timeOfFlightData.sensor3 = TOF_FAKE_DATA3;

  adcData.cell_1 = ADC_FAKE_CELL1;
  adcData.cell_2 = ADC_FAKE_CELL2;
  adcData.cell_3 = ADC_FAKE_CELL3;
  adcData.current = CURRENT_FAKE;
}
#endif  // USE_RPI_TEST_DATA

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
  setRpiTestData(motorData, motorForce, TimeOfFlightData, degreesOfFreedomData,
                 adcData);
#endif  // USE_RPI_TEST_DATA

  WireData wireData;
  wireData.tof = TimeOfFlightData;
  wireData.adc = adcData;
  wireData.motorPWM = motorData;
  wireData.motorForce = motorForce;
  wireData.dof = degreesOfFreedomData;
  writeWiredata(&wireData);

  Wire.endTransmission();
#ifdef DEBUG
  Serial.println("[INFO] Send sensor data to the Raspberry Pi.");
#endif  // DEBUG
}

inline void emptyDataStruct(RpiData& data){
  for (uint8_t i = 0; i < MAX_MARKERS; i++) {
    data.markers[0].markerId = 0;
    data.markers[0].markerX = 0;
    data.markers[0].markerY = 0;
  }
  
}

/**
 * @brief
 *
 * @param data
 */
void receiveRpiData(RpiData& data) {
  emptyDataStruct(data);
  uint8_t rawData[MAX_MARKERS*5] = {0};
  uint8_t markersFound = 0;
  uint8_t i = 0;

  Wire.beginTransmission(RPI_ADDRESS);
  Wire.write('D');
  delay(15);      //Uit orginele code

  Wire.requestFrom(RPI_ADDRESS, 1);

  while (Wire.available()) {
    markersFound = Wire.read();
  }

  Wire.endTransmission();

  if (markersFound == 0 || markersFound > MAX_MARKERS) {
    return;     // Don't ask for markers because there are none
  } else {
    Wire.beginTransmission(RPI_ADDRESS);
    Wire.write('E');
    delay(15);

    Wire.requestFrom(RPI_ADDRESS, (markersFound * 5));

    while (Wire.available()) {
      rawData[i] = Wire.read();
      i++;
    }

    for (uint8_t i = 0; i < markersFound; i++) {
      uint8_t pos = i * 5;
      data.markers[i].markerId = rawData[pos];
      data.markers[i].markerX = rawData[pos+1] << 8 + rawData[pos + 2];
      data.markers[i].markerY = rawData[pos+3] << 8 + rawData[pos + 4];
    }
    
  }  

}
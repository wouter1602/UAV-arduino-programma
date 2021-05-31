/**
 * @file ToF.cpp
 * @author Robert van der Vlist (18143040@student.hhs.nl)
 * @author Wouter van Velzen (19093861@studnet.hhs.nl)
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

#include "../../defines.h"
#include "../lib/VL53L0x/Adafruit_VL53L0X.h"

/**
 * @brief Struct with the three ToF sensors
 *
 */
struct ToFSensros {
  Adafruit_VL53L0X ToF1 = Adafruit_VL53L0X();
  Adafruit_VL53L0X ToF2 = Adafruit_VL53L0X();
  Adafruit_VL53L0X ToF3 = Adafruit_VL53L0X();

  VL53L0X_RangingMeasurementData_t measure1;
  VL53L0X_RangingMeasurementData_t measure2;
  VL53L0X_RangingMeasurementData_t measure3;

  bool measurementBusy = false;

  unsigned long oldMillis = millis();
  unsigned long newMillis = millis();
} tofSensors;

/**
 * @brief Sets the correct addresses of the ToF sensors.
 * TODO: this function contains delays. maybe they could be removed.
 */
inline void setID() {
  // Set ToF shutdown pins as outputs.
  pinMode(TOF_XSHUT1, OUTPUT);
  pinMode(TOF_XSHUT2, OUTPUT);
  pinMode(TOF_XSHUT3, OUTPUT);

  // Reset all ToF sensors
  digitalWrite(TOF_XSHUT1, HIGH);
  digitalWrite(TOF_XSHUT2, HIGH);
  digitalWrite(TOF_XSHUT3, HIGH);

  delay(10);  // Wait 10 ms for the reset
  // TODO: check if delay can be lower.

  // All ToF sensros disabled accept ToF 1
  digitalWrite(TOF_XSHUT1, LOW);
  digitalWrite(TOF_XSHUT2, HIGH);
  digitalWrite(TOF_XSHUT3, HIGH);

  delay(10);  // Wait for the sensor to bootup
  // TODO: check if delay can be lower.

  if (!tofSensors.ToF1.begin(TOF_ADDRESS1)) {
#ifdef DEBUG
    Serial.println("[ERROR] Failed to boot first VL53L0x ToF sensor.");
#endif  // DEBUG
  }

  digitalWrite(TOF_XSHUT2, LOW);  // Enable ToF 2

  delay(10);  // Wait for the second sensor to bootup
  // TODO: check if delay can be lower.

  if (!tofSensors.ToF2.begin(TOF_ADDRESS2)) {
#ifdef DEBUG
    Serial.println("[ERROR] Failed to boot second VL53L0x ToF sensor.");
#endif  // DEBUG
  }

  digitalWrite(TOF_XSHUT3, LOW);  // Enable ToF 3

  delay(10);  // Wait for sensor to bootup
  // TODO: check if delay can be lower.

  if (!tofSensors.ToF3.begin(TOF_ADDRESS3)) {
#ifdef DEBUG
    Serial.println("[ERROR] Failed to boot third VL53L0x ToF sensor.");
#endif  // DEBUG
  }
}

/**
 * @brief Initialize the Time of Flight sensors.
 *
 */
void setupToF() {
  // Set ID's
  setID();
#ifdef DEBUG
  Serial.println("[INFO] Completed ToF setup.");
#endif  // DEBUG
}

/**
 * @brief Returns Time of Flight data back in referenced struct.
 *
 * @param data Time of Flight struct reference for the data.
 */
void readToF(TimeOfFlightData& data) {
  tofSensors.newMillis = millis();
  
  if (tofSensors.measurementBusy == false) {
    // Read distance of ToF sensors.
    tofSensors.ToF1.rangingTest(&tofSensors.measure1, false);
    tofSensors.ToF2.rangingTest(&tofSensors.measure2, false);
    tofSensors.ToF3.rangingTest(&tofSensors.measure3, false);
    tofSensors.measurementBusy = true;
#ifdef DEBUG
    Serial.println("[INFO] started ToF measurement");
#endif  // DEBUG
  }

  if (tofSensors.measure1.RangeStatus != 4) {
    data.sensor1 = tofSensors.measure1.RangeMilliMeter;
#ifdef DEBUG
    Serial.print("[INFO] ToF sensor 1 data: ");
    Serial.print(data.sensor1);
    Serial.println(" mm.");
#endif  // DEBUG
  } else {
#ifdef DEBUG
    Serial.println("[INFO] ToF sensor 1 out of range.");
#endif  // DEBUG
  }

  if (tofSensors.measure2.RangeStatus != 4) {
    data.sensor2 = tofSensors.measure2.RangeMilliMeter;
#ifdef DEBUG
    Serial.print("[INFO] ToF sensor 2 data: ");
    Serial.print(data.sensor2);
    Serial.println(" mm.");
#endif  // DEBUG
  } else {
#ifdef DEBUG
    Serial.println("[INFO] ToF sensor 2 out of range.");
#endif  // DEBUG
  }

  if (tofSensors.measure3.RangeStatus != 4) {
    data.sensor2 = tofSensors.measure3.RangeMilliMeter;
#ifdef DEBUG
    Serial.print("[INFO] ToF sensor 3 data: ");
    Serial.print(data.sensor3);
    Serial.println(" mm.");
#endif  // DEBUG
  } else {
#ifdef DEBUG
    Serial.println("[INFO] ToF sensor 3 out of range.");
#endif  // DEBUG
  }

//Reset measurement busy when all the data is received or an timeout is met.
  if ((tofSensors.measure1.RangeMilliMeter != 4 &&
       tofSensors.measure2.RangeMilliMeter != 4 &&
       tofSensors.measure3.RangeMilliMeter != 4) ||
       (tofSensors.newMillis - tofSensors.oldMillis > TOF_MEASUREMENT_TIMEOUT)) {
    tofSensors.measurementBusy = false;
  }
}

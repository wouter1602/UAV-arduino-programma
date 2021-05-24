/**
 * @file main.ino
 * @author Groep A2
 * @brief
 * @version 0.1
 * @date 2021-05-24
 * Made to run on the Arduino Mega
 * @copyright Copyright (c) 2021
 *
 */

// Datasheet
// https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega640-1280-1281-2560-2561-Datasheet-DS40002211A.pdf

#include <Arduino.h>
#include <Wire.h>

#include "ToF.h"
#include "defines.h"
#include "motor.h"
#include "safety.h"

/**
 * @brief Setup Initial TWI (I²C) setup
 *
 */
void setupWire(void) {
    Wire.begin();
}

/**
 * @brief
 *
 */
void setup(void) {
#ifdef DEBUG
  Serial.begin(112500);
#endif  // DEBUG
  setupSafety();
  setupWire();
  setupToF();
  setupMotor();
}

/**
 * @brief
 *
 */
void loop(void) {
    checkCellVoltage();
    checkCurrent();
}

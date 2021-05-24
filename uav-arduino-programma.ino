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
#include "nine-dof.h"
#include "safety.h"

TimeOfFlightData tofData;
DoFData dofData;
MotorSettings motorData;

int16_t motorForce1 = 0;  // Could also be float
int16_t motorForce2 = 0;  // Could also be float
int16_t motorForce3 = 0;  // Could also be float

/**
 * @brief
 *
 */
void setup(void) {
#ifdef DEBUG
  Serial.begin(112500);
#endif  // DEBUG
  setupSafety();
  Wire.begin();
  setupToF();
  setupMotor();
  setupDoF();

  readToF(tofData);  // Give ToF struct initial data.
  readDoF(dofData);  // Give DoF struct initial data.
  convertForceToPWM(motorData, 0, 0,
                    0);  // Give motor driver struct initial data.
}

/**
 * @brief
 *
 */
void loop(void) {
  // Safety functions
  checkCellVoltage();
  checkCurrent();

  // ToF functions
  readToF(tofData);

  // DoF functions
  readDoF(dofData);

  // Motor functions
  convertForceToPWM(motorData, motorForce1, motorForce2, motorForce3);
  setMotorSpeed(motorData);
}

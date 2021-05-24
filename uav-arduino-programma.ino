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

// Controllers
#include "angle_controller.h"

// Sensor and motor variables
TimeOfFlightData tofData;
DoFData dofData;
MotorSettings motorData;
MotorForce motorForceData;

// Global controller data
unsigned long tNew = 0;
unsigned long tOld = 0;

// Select controller
uint8_t controllerChoice = 0;

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
  convertForceToPWM(motorData,
                    motorForceData);  // Give motor driver struct initial data.

  tOld = millis();  // Provide inital data
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

  // Controllers
  tNew = millis();
  if (tNew - tOld > DELTA_t) {  // millis function overlow is unlikely sind it
                                // hapens after approx 50 days.
    switch (controllerChoice) {
      case NOTING_CONTROLLER:
        asm("nop");  // do noting
        break;
      case ANGLE_CONTROLLER:
        angle_controller(motorData, motorForceData, tofData, dofData);
      default:
        asm("nop");
        break;
    }
  }

  // Motor functions
  convertForceToPWM(motorData, motorForceData);
  setMotorSpeed(motorData);
}

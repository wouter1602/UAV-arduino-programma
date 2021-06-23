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

#include "defines.h"
#include "src/sensors/ToF.h"
#include "src/sensors/motor.h"
#include "src/sensors/nine-dof.h"
#include "src/sensors/rpi.h"
#include "src/sensors/safety.h"

// Controllers
#include "src/controller/angle_controller.h"
#include "src/controller/aruco_markers_controller.h"
#include "src/controller/circular_track_controller.h"
#include "src/controller/wall_controller.h"

// Sensor and motor variables
ADC_Data adcData;
TimeOfFlightData tofData;
DoFData dofData;
MotorSettings motorData;
MotorForce motorForceData;
RpiData rpiData;
// Global controller data
unsigned long tNew = 0;
unsigned long tOld = 0;

// Select controller
uint8_t controllerChoice = WALL_CONTROLLER;

/**
 * @brief
 *
 */
void setup(void) {
#ifdef DEBUG
  Serial.begin(115200);
#endif  // DEBUG
  setupSafety(adcData);
  Wire.begin();
  setupToF();
  setupMotor();
#ifdef COMPILE_ANGLE_CONTROLLER
  setupDoF();
#endif  // COMPILE_ANGLE_CONTROLLERs
  setupRpi();

  readToF(tofData);  // Give ToF struct initial data.
#ifdef COMPILE_ANGLE_CONTROLLER
  readDoF(dofData);  // Give DoF struct initial data.
#endif               // COMPILE_ANGLE_CONTROLLER
  convertForceToPWM(motorData,
                    motorForceData);  // Give motor driver struct initial data.

  tOld = millis();  // Provide inital data
  digitalWrite(RELAY_RPI, HIGH);
  digitalWrite(RELAY_BLOWERS, HIGH);
}

/**
 * @brief
 *
 */
void loop(void) {
  // Safety functions
  checkCellVoltage(adcData);
  checkCurrent(adcData);

  // ToF functions
  readToF(tofData);

#ifdef COMPILE_ANGLE_CONTROLLER
  // DoF functions
  readDoF(dofData);
#endif  // COMPILE_ANGLE_CONTROLLER

  // Controllers
  tNew = millis();
  if (tNew - tOld > DELTA_t) {  // millis function overlow is unlikely since it
                                // hapens after approx 50 days.
    switch (controllerChoice) {
      case NOTHING_CONTROLLER:
        asm("nop");  // do noting
        break;

#ifdef COMPILE_ANGLE_CONTROLLER
      case ANGLE_CONTROLLER:
        angle_controller(motorData, motorForceData, tofData, dofData);
        break;
#endif  // COMPILE_ANGLE_CONTROLLER

#ifdef COMPILE_WALL_CONTROLLER
      case WALL_CONTROLLER:
        wallController(motorData, motorForceData, tofData, dofData);
        break;
#endif  // COMPILE_WALL_CONTROLLER

#ifdef COMPILE_CIRCULAR_TRACK_CONTROLLER
      case CIRCULAR_TRACK_CONTROLLER:
        circularTrackController(motorData, motorForceData, tofData, dofData);
        break;
#endif  // COMPILE_CIRCULAR_TRACK_CONTROLLER

#ifdef COMPILE_ARUCO_CONTROLLER
      case ARUCO_MARKERS_CONTROLLER:
        arucoMarkersController(motorData, motorForceData, tofData, dofData,
                               rpiData);
        break;
#endif  // COMPILE_ARUCO_CONTROLLER

      default:
        asm("nop");
        break;
    }
  }

  // Motor functions
  convertForceToPWM(motorData, motorForceData);
  Serial.println(motorForceData.motor1Force);
  Serial.println(motorData.motorPWMSpeed1);
  setMotorSpeed(motorData);

  // sendRpiData(motorData, motorForceData, tofData, dofData, adcData);
}

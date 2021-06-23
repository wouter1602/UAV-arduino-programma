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

#include "src/sensors/ToF.h"
#include "defines.h"
#include "src/sensors/motor.h"
#include "src/sensors/nine-dof.h"
#include "src/sensors/safety.h"

// Controllers
//#include "src/controller/angle_controller.h"
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
  setupDoF();
  setupRpi();

  
  readToF(tofData);  // Give ToF struct initial data.
  readDoF(dofData);  // Give DoF struct initial data.
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

  // DoF functions
  readDoF(dofData);
  
  // Controllers
  tNew = millis();
  if (tNew - tOld > DELTA_t) {  // millis function overlow is unlikely since it
                                // hapens after approx 50 days.
    switch (controllerChoice) {
      case NOTHING_CONTROLLER:
        asm("nop");  // do noting
        break;
      case ANGLE_CONTROLLER:
        //angle_controller(motorData, motorForceData, tofData, dofData);
        break;
      case WALL_CONTROLLER:
        wallController(motorData, motorForceData, tofData, dofData);
        break;
      case CIRCULAR_TRACK_CONTROLLER:
        circularTrackController(motorData, motorForceData, tofData, dofData);
        break;
      case ARUCO_MARKERS_CONTROLLER:
        arucoMarkersController(motorData, motorForceData, tofData, dofData, rpiData);
        break;
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

  sendRpiData(motorData, motorForceData, tofData, dofData, adcData);
}

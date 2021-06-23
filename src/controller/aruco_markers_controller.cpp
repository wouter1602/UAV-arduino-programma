/**
 * @file aruco_markers_controller.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Solves problem 19 of the projectbook
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../defines.h"

#ifdef COMPILE_ARUCO_CONTROLLER //Will not compile if not defined to save space

#include "aruco_markers_controller.h"

#define SETPOINT 2.0  // Controller setpoint
#define KP 1.0        // Controller proportional variable
#define KD 1.0        // Controller differential variable
#define KI 1.0        // Controller integral variable

#define ERROR_SOM_LOW -0.12
#define ERROR_SOM_HIGH 0.2

/**
 * @brief
 *
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data
 * @param rpiData
 */
void arucoMarkersController(MotorSettings& motorData, MotorForce& motorForce,
                            TimeOfFlightData& timeOfFlightData,
                            DoFData& degreesOfFreedomData, RpiData& rpiData) {
  static float force = 0.01;  // in N
  static float a = 0.0;   // in m/s²
  static float v = 0.0;   // in m/s
  static float error = 0.0;
  static float error = 0.0;
  static float errorOld = 0.0;
  static float errorSom = 0.0;
  static float deltaError = 0.0;
  static float kDDelta = 1.0;
  static float kPDelta = 1.0;

  uint16_t x = rpiData.markers[0].markerX;

  errorOld = error;
  error = SETPOINT - x;

  deltaError = error - errorOld;
  errorSom += error;

  errorSom = constrain(errorSom, ERROR_SOM_LOW, ERROR_SOM_HIGH);

  force = KP * error + ((KD * deltaError) / DELTA_t);

  force = constrain(force, 2 * MIN_FORCE_MOTOR1, 2 * MAX_FORCE_MOTOR1);

  float perMotorForce = force / 2;
  if (force > 0.0) {  // Rotate right
    motorForce.motor1Force = perMotorForce;
    motorForce.motor2Force = -1 * perMotorForce;
    if (!digitalRead(RELAY_BLOWERS)) {
      digitalWrite(RELAY_BLOWERS, HIGH);
    }

  } else if (force < 0.0) {  // Rotate left
    motorForce.motor1Force = -1 * perMotorForce;
    motorForce.motor2Force = perMotorForce;
    if (!digitalRead(RELAY_BLOWERS)) {
      digitalWrite(RELAY_BLOWERS, HIGH);
    } else {
      digitalWrite(RELAY_BLOWERS, LOW);
    }
  }
}

#endif //COMPILE_ARUCO_CONTROLLER

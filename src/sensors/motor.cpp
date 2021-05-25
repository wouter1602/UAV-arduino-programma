/**
 * @file motor.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "motor.h"

#include "../../defines.h"

/**
 * @brief Enables PWM for the motor drivers
 *
 */
void setupMotor() {
#ifdef DEBUG
  Serial.println("[INFO] Completed motor setup.");
#endif  // DEBUG
}

/**
 * @brief Converts te force in Newton to PWM values
 *
 * @param data Reference struct to MotorSettings struct
 * @param motorForce Struct with the force in per motor in Newton
 */
void convertForceToPWM(MotorSettings& data, MotorForce& motorForce) {

}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData) {}
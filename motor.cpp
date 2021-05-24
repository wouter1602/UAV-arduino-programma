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

#include "defines.h"

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
 * @brief Converts te force to PWM values
 *
 * @param data Reference struct to MotorSettings struct
 * @param motor1
 * @param motor2
 * @param motor3
 */
void convertForceToPWM(MotorSettings& data, int16_t motor1, int16_t motor2,
                                int16_t motor3) {

}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData) {}
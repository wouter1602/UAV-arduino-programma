/**
 * @file motor.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @author Jasper van Vliet (19069987@student.hhs.nl)
 * @brief
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "motor.h"

#include <math.h>

#include "../../defines.h"

/**
 * @brief Enables PWM for the motor drivers
 *
 */
void setupMotor() {
  pinMode(MOTOR_PWM1, OUTPUT);
  pinMode(MOTOR_PWM2, OUTPUT);
  pinMode(MOTOR_PWM3, OUTPUT);

  pinMode(MOTOR_ENABLE_LEFT1, OUTPUT);
  pinMode(MOTOR_ENABLE_LEFT2, OUTPUT);
  pinMode(MOTOR_ENABLE_LEFT3, OUTPUT);

  pinMode(MOTOR_ENABLE_RIGHT1, OUTPUT);
  pinMode(MOTOR_ENABLE_RIGHT2, OUTPUT);
  pinMode(MOTOR_ENABLE_RIGHT3, OUTPUT);
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
  // Aansturing motor links
  if (motorForce.motor1Force > 0.0) {
    data.motorPWMSpeed1 = round((2289.3 * motorForce.motor1Force) - 38.70);
  } else if (motorForce.motor1Force < 0.0) {
    data.motorPWMSpeed1 =
        round(-1 * (1892.2 * motorForce.motor1Force) - 43.784);
  } else {
    data.motorPWMSpeed1 = 0;
  }

  // Aansturing motor rechts
  if (motorForce.motor2Force > 0.0) {
    data.motorPWMSpeed2 = round((2265.9 * motorForce.motor2Force) - 53.011);
  } else if (motorForce.motor2Force < 0.0) {
    data.motorPWMSpeed2 =
        round(-1 * (2041.3 * motorForce.motor2Force) - 34.483);
  } else {
    data.motorPWMSpeed2 = 0;
  }

  // Aansturing motor zijkant
  if (motorForce.motor3Force > 0.0) {
    data.motorPWMSpeed3 = round((2320.9 * motorForce.motor3Force) - 43.143);
  } else if (motorForce.motor3Force < 0.0) {
    data.motorPWMSpeed3 =
        round(-1 * (1990.5 * motorForce.motor3Force) - 23.693);
  } else {
    data.motorPWMSpeed3 = 0;
  }
}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData) {
  if (motorData.motorPWMSpeed1 < 0) {
    motorData.motorPWMSpeed1 = abs(motorData.motorPWMSpeed1);
    digitalWrite(MOTOR_ENABLE_LEFT1, HIGH);
    digitalWrite(MOTOR_ENABLE_RIGHT1, LOW);
  } else {
    digitalWrite(MOTOR_ENABLE_LEFT1, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT1, HIGH);
  }

  if (motorData.motorPWMSpeed2 < 0) {
    motorData.motorPWMSpeed2 = abs(motorData.motorPWMSpeed2);
    digitalWrite(MOTOR_ENABLE_LEFT2, HIGH);
    digitalWrite(MOTOR_ENABLE_RIGHT2, LOW);
  } else {
    digitalWrite(MOTOR_ENABLE_LEFT2, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT2, HIGH);
  }

  if (motorData.motorPWMSpeed3 < 0) {
    motorData.motorPWMSpeed3 = abs(motorData.motorPWMSpeed3);
    digitalWrite(MOTOR_ENABLE_LEFT3, HIGH);
    digitalWrite(MOTOR_ENABLE_RIGHT3, LOW);
  } else {
    digitalWrite(MOTOR_ENABLE_LEFT3, LOW);
    digitalWrite(MOTOR_ENABLE_RIGHT3, HIGH);
  }
  analogWrite(MOTOR_PWM1, motorData.motorPWMSpeed1);
  analogWrite(MOTOR_PWM2, motorData.motorPWMSpeed2);
  analogWrite(MOTOR_PWM3, motorData.motorPWMSpeed3);
}

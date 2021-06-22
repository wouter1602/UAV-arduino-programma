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
  //Aansturing motor links
  if(motorForce.motor1Force  > 0){
    data.motorPWMSpeed1 = (2289.3*motorForce.motor1Force ) - 38.70;
  }if(motorForce.motor1Force  < 0){
    data.motorPWMSpeed1 = (1892.2*motorForce.motor1Force ) - 43.784;
  }else{
    data.motorPWMSpeed1 = 0;
  }

  //Aansturing motor rechts
  if(motorForce.motor2Force > 0){
    data.motorPWMSpeed2 = (2265.9*motorForce.motor2Force) - 53.011;
  }if(motorForce.motor2Force < 0){
    data.motorPWMSpeed2 = (2041.3*motorForce.motor2Force) - 34.483;
  }else{
    data.motorPWMSpeed2 = 0;
  }

  //Aansturing motor zijkant
  if(motorForce.motor3Force > 0){
    data.motorPWMSpeed3 = (2320.9*motorForce.motor3Force) - 43.143;
  }if(motorForce.motor3Force < 0){
    data.motorPWMSpeed3 = (1990.5*motorForce.motor3Force) - 23.693;
  }else{
    data.motorPWMSpeed3 = 0;
  }
}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData){
  analogWrite(MOTOR_PWM1, motorData.motorPWMSpeed1);
  analogWrite(MOTOR_PWM2, motorData.motorPWMSpeed2);
  analogWrite(MOTOR_PWM3, motorData.motorPWMSpeed3);
}
  




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
}(
  
  
  

/**
 * @brief Converts te force in Newton to PWM values
 *
 * @param data Reference struct to MotorSettings struct
 * @param motorForce Struct with the force in per motor in Newton
 */
void convertForceToPWM(MotorSettings& data, MotorForce& motorForce) {
  //Aansturing motor links
  if(motor1Force  > 0){
    motorPWMSpeed1 = (2289.3*motor1Force ) - 38.70;
  }if(motor1Force  < 0){
    motorPWMSpeed1 = (1892.2*motor1Force ) - 43.784;
  }else{
    motorPWMSpeed1 = 0;
  }

  //Aansturing motor rechts
  if(motor2Force > 0){
    motorPWMSpeed2 = (2265.9*motor2Force) - 53.011;
  }if(motor2Force < 0){
    motorPWMSpeed2 = (2041.3*motor2Force) - 34.483;
  }else{
    motorPWMSpeed2 = 0;
  }

  //Aansturing motor zijkant
  if(motor3Force > 0){
    motorPWMSpeed3 = (2320.9*motor3Force) - 43.143;
  }if(motor3Force < 0){
    motorPWMSpeed3 = (1990.5*motor3Force) - 23.693;
  }else{
    motorPWMSpeed3 = 0;
  }
}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData){
  MOTOR_PWM1 = analogWrite(motorPWMSpeed1);
  MOTOR_PWM2 = analogWrite(motorPWMSpeed2);
  MOTOR_PWM3 = analogWrite(motorPWMSpeed3);
}
  




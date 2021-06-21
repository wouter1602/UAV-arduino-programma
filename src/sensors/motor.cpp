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
    Newton_links = ;
  Newton_rechts = ;
  Newton_zijkant = ;

  //Aansturing motor links
  if(Newton_links > 0){
    PWM_Motor_links = (2289.3*Newton_links) - 38.70;
  }if(Newton_links < 0){
    PWM_Motor_links = (1892.2*Newton_links) - 43.784;
  }else{
    PWM_Motor_rechts = 0;
  }

  //Aansturing motor rechts
  if(Newton_rechts > 0){
    PWM_Motor_rechts = (2265.9*Newton_rechts) - 53.011;
  }if(Newton_rechts < 0){
    PWM_Motor_rechts = (2041.3*Newton_rechts) - 34.483;
  }else{
    PWM_Motor_rechts = 0;
  }

  //Aansturing motor zijkant
  if(Newton_zijkant > 0){
    PWM_Motor_zijkant = (2320.9*Newton_zijkant) - 43.143;
  }if(Newton_zijkant < 0){
    PWM_Motor_zijkant = (1990.5*Newton_zijkant) - 23.693;
  }else{
    PWM_Motor_zijkant = 0;
  }
}

/**
 * @brief Set motorspeed to the motors
 *
 * @param motorData
 */
void setMotorSpeed(MotorSettings& motorData){
  MOTOR_PWM1 = analogWrite(PWM_motor_rechts);
  MOTOR_PWM2 = analogWrite(PWM_motor_links);
  MOTOR_PWM3 = analogWrite(PWM_motor_zijkant);
}
  




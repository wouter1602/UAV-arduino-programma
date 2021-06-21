/**
 * @file wall_controller.cpp
 * @author Kaj Zwinkels (17014026@student.hhs.nl)
 * @brief Solves problem 16 of the projectbook.
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "wall_controller.h"

#include "../../defines.h"

/**
 * @brief 
 * 
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data 
 */
void wallController(MotorSettings& motorData, MotorForce& motorForce,
                    TimeOfFlightData& timeOffFlightData,
                    DoFData& degreesOfFreedomData) {}

void WALL_CONTROLLER() {

 float x = readToF()/1000; //Gemeten mm omzetten naar m. 

 error_d_front = sp_d_front - x;
 d_error_d_front = error_d_front - error_old_d_front; 
 F = Kp_d_front * error_d_front * Kd_d_front * d_error_d_front;

 F = constrain (F, Fmin, Fmax);
 error_old_d_front = error_d_front;

 float motorForceData = F/2;  //Delen door 2 want twee stuwmotoren
 if((abs(x-sp_d_front) <hysterese)){
  motorForceData = 0; 
 }
}

if (WALL_CONTROLLER){
  setMotorSpeed(motorForceData, motorForceData, 0);
} else if (sensor1_front){
  sensor1_front(motorForceData);
  
}

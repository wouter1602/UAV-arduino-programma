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

float F = 0.01;              // N beginwaarde
const float Fmax = 0.2;
const float Fmin = -0.228;
float a;                    // m/s2
float v = 0.0, x = 0.5;     // Beginwaarden
 
float error;
float error_old;
float d_err;
float error_d_front;
float error_old_d_front = 0.0;
float d_error_d_front;
float Kd_d_front = 1.0;
float Kp_d_front = 1.0;
const float sp = 0.3; //setpoint in meters
const float Kp = 2.0; //propsineel hier mee iets doen uitzoeken wat het doet.
const float Kd = 2.0; // differentiële hier mee iets doen uitzoeken wat het doet. 
 
long t_old, t_nw;
float dt;

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
                    DoFData& degreesOfFreedomData) {

 float x = timeOffFlightData.sensor1/1000; //Gemeten mm omzetten naar m. 

 error_d_front = sp - x;
 d_error_d_front = error_d_front - error_old_d_front; 
 F = Kp_d_front * error_d_front * Kd_d_front * d_error_d_front;

 F = constrain (F, Fmin, Fmax);      
 error_old_d_front = error_d_front;

 float motorForceData = F/2;  //Delen door 2 want twee stuwmotoren   
 
 motorForce.motor1Force = motorForceData;
 motorForce.motor2Force = motorForceData;
 
}


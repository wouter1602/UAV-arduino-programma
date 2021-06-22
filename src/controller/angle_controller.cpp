/**
 * @file angle_controller.cpp
 * @author Jasper van Vliet (19069987@student.hhs.nl)
 * @brief Solves problem 11 and 12 of the projectbook.
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "angle_controller.h"

#include "../../defines.h"


const float m = 1.434;          // Massa in kg
float F_gyro = 0.01;            // F =  0.01 zodat de kracht niet bij 0 N begint
float Fmax = 0.11 * 2;          // Maximale stuwkracht, maal 2 want 2 motoren
float Fmin = -0.12 * 2;         // Minimale stuwkracht, maal 2 want 2 motoren
const float sp = 0;             // setpoint
const float Kp_gyro = 2.1;      // Proportionele versterkingsfactor
const float Kd_gyro = 0.7;      // Versterkingsfactor voor de demping
const float Ki_gyro = 1.0;      // Ki
float error_gyro, error_gyro_oud, error_gyro_som, d_error_gyro;     // Fout tussen procesvariabele en setpoint
const float Icg = 0.028961;     //Massatraagheidsmoment 
float Mz = 0;                   //Verstoring
float b = 0.168;                //afstand tussen stuwkrachtmotoren
const bool simulator = true;
long t_oud, t_nw;
float dt;

float avg_alpha = 0.0;
float avg_omega = 0.0;

/**
 * @brief
 *
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data
 */
 
void angle_controller(MotorSettings& motorData, MotorForce& motorForce,
                      TimeOfFlightData& TimeOfFlightData,
                      DoFData& degreesOfFreedomData) {

  t_nw = millis();
  if (t_nw - t_oud > cyclustijd) {
  dt = (t_nw - t_oud) * .001;
  t_oud = t_nw;
  

  error_gyro = sp - theta;
  d_error_gyro = error_gyro - error_gyro_oud;
  error_gyro_som = error_gyro_som + error_gyro*dt;
  float F_gyro = Kp_gyro * error_gyro + Kd_gyro * d_error_gyro/dt + Ki_gyro * error_gyro_som *dt;
   
  constrain(F_gyro, Fmin, Fmax)); 
  error_gyro_oud = error_gyro;

   
  float motorForceData = F/2;
   
  motorForce.motor1Force = motorForceData;
  motorForce.motor2Force = motorForceData;
  }
}




/**
 * @file angle_controller.h
 * @author Jasper van Vliet (19069987@student.hhs.nl)
 * @brief Solves problem 11 and 12 of the projectbook.
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ANGLE_CONTROLLER_H
#define ANGLE_CONTROLLER_H

#include "../sensors/ToF.h"
#include "../sensors/motor.h"
#include "../sensors/nine-dof.h"


const float m = 1.434;          // Massa in kg
float F_gyro = 0.01;            // F =  0.01 zodat de kracht niet bij 0 N begint
float Fmax = 0.11 * 2;          // Maximale stuwkracht, maal 2 want 2 motoren
float Fmin = -0.12 * 2;         // Minimale stuwkracht, maal 2 want 2 motoren
const float sp = 1/2*PI;             // setpoint
const float Kp_gyro = 2.1;      // Proportionele versterkingsfactor
const float Kd_gyro = 0.7;      // Versterkingsfactor voor de demping
const float Ki_gyro = 1.0;      // Ki
float error_gyro, error_gyro_oud, error_gyro_som, d_error_gyro;     // Fout tussen procesvariabele en setpoint
const float Icg = 0.028961;     //Massatraagheidsmoment 
float Mz = 0;                   //Verstoring
float b = 0.168;                //afstand tussen stuwkrachtmotoren
const bool simulator = true;
float F_motor = 0.0;
long t_oud, t_nw;
float dt;

float avg_alpha = 0.0;
float avg_omega = 0.0;


void angle_controller(MotorSettings& motorData, MotorForce& motorForce,
                      TimeOfFlightData& timeOfFlightData,
                      DoFData& degreesOfFreedomData);

#endif  // ANGLE_CONTROLLER_H

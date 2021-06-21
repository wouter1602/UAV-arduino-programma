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

  regelaar_verstoring();
  gyro_data();

  alpha = (F_gyro * b + Mz)/ Icg;      
  omega = omega + alpha * dt; 
  theta = theta + omega * dt; 


  error_gyro = sp - theta;
  d_error_gyro = error_gyro - error_gyro_oud;
  error_gyro_som = error_gyro_som + error_gyro*dt;
  float F_gyro = Kp_gyro * error_gyro + Kd_gyro * d_error_gyro/dt
  + Ki_gyro * error_gyro_som *dt;
  F_gyro = constrain((F_gyro/2), (Fmin/2), (Fmax/2));
  error_gyro_oud = error_gyro;
  Kracht_naar_PWM(constrain(F_motor - F_gyro, Fmin, Fmax),
  constrain(F_motor + F_gyro, Fmin, Fmax)); 
  }
}

}

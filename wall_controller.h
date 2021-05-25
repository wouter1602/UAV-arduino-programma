/**
 * @file wall_controller.h
 * @author Kaj Zwinkels (you@domain.com)
 * @brief Solves problem 16 of the projectbook.
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef WALL_CONTROLLER_H
#define WALL_CONTROLLER_H

#include "ToF.h"
#include "motor.h"
#include "nine-dof.h"

/**
 * @brief 
 * 
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data
 */
void wallController(MotorSettings& motorData, MotorForce& motorForce,
                     TimeOfFlightData& timeOfFlightData,
                     DoFData& degreesOfFreedomData);

#endif  // WALL_CONTROLLER_H
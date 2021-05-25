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
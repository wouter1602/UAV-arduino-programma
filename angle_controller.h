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

#include "ToF.h"
#include "motor.h"
#include "nine-dof.h"

void angle_controller(MotorSettings& motorData, MotorForce& motorForce,
                      TimeOfFlightData& timeOfFlightData,
                      DoFData& degreesOfFreedomData);

#endif  // ANGLE_CONTROLLER_H
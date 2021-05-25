/**
 * @file wall_controller.h
 * @author Kaj Zwinkels (17014026@student.hhs.nl)
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

void wallController(MotorSettings& motorData, MotorForce& motorForce,
                    TimeOfFlightData& timeOfFlightData,
                    DoFData& degreesOfFreedomData);

#endif  // WALL_CONTROLLER_H
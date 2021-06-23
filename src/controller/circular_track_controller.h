/**
 * @file circular_track_controller.h
 * @author Kaj Zwinkels (17014026@student.hhs.nl)
 * @brief Solves problem 17 of the projectbook.
 * @version 0.1
 * @date 2021-05-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../../defines.h"

#ifdef COMPILE_CIRCULAR_TRACK_CONTROLLER

#ifndef CIRCULAR_TRACK_CONTROLLER_H
#define CIRCULAR_TRACK_CONTROLLER_H

#include "../sensors/ToF.h"
#include "../sensors/motor.h"
#include "../sensors/nine-dof.h"

void circularTrackController(MotorSettings& motorData, MotorForce& motorForce,
                      TimeOfFlightData& timeOfFlightData,
                      DoFData& degreesOfFreedomData);

#endif //CIRCULAR_TRACK_CONTROLLER_H

#endif //COMPILE_CIRCULAR_TRACK_CONTROLLER

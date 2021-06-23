/**
 * @file aruco_markers_controller.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Solves problem 19 of the projectbook
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../defines.h"

#ifdef COMPILE_ARUCO_CONTROLLER

#ifndef ARRUCO_MARKERS_CONTROLLER_H
#define ARRUCO_MARKERS_CONTROLLER_H

#include "../sensors/ToF.h"
#include "../sensors/motor.h"
#include "../sensors/nine-dof.h"
#include "../sensors/rpi.h"

void arucoMarkersController(MotorSettings& motorData, MotorForce& motorForce,
                            TimeOfFlightData& timeOfFlightData,
                            DoFData& degreesOfFreedomData, RpiData& rpiData);

#endif  // ARRUCO_MARKERS_CONTROLLER_H

#endif  // COMPILE_ARUCO_CONTROLLER

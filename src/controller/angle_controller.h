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

#include "../../defines.h"

#ifdef COMPILE_ANGLE_CONTROLLER

#ifndef ANGLE_CONTROLLER_H
#define ANGLE_CONTROLLER_H

#include "../sensors/ToF.h"
#include "../sensors/motor.h"
#include "../sensors/nine-dof.h"
//#include "../lib/MPU9250/SparkFunMPU9250-DMP.h"
//#include "../lib/MPU9250/MPU9250_RegisterMap.h"

void angle_controller(MotorSettings& motorData, MotorForce& motorForce,
                      TimeOfFlightData& timeOfFlightData,
                      DoFData& degreesOfFreedomData);

#endif  // ANGLE_CONTROLLER_H

#endif  // COMPILE_ANGLE_CONTROLLER

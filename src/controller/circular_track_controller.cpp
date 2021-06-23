/**
 * @file circular_track_controller.cpp
 * @author Kaj Zwinkels (17014026@student.hhs.nl)
 * @brief Solves problem 17 of the projectbook.
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */


#include "../../defines.h"

#ifdef COMPILE_CIRCULAR_TRACK_CONTROLLER    ////Will not compile if not defined to save space

#include "circular_track_controller.h"



/**
 * @brief 
 * 
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data 
 */
void circularTrackController(MotorSettings& motorData, MotorForce& motorForce,
                             TimeOfFlightData& timeOfFlightData,
                             DoFData& degreesOfFreedomData) {}

#endif //COMPILE_CIRCULAR_TRACK_CONTROLLER

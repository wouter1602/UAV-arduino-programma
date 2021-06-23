/**
 * @file aruco_markers_controller.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Solves problem 19 of the projectbook
 * @version 0.1
 * @date 2021-05-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../../defines.h"

#ifdef COMPILE_ARUCO_CONTROLLER //Will not compile if not defined to save space
#include "aruco_markers_controller.h"



/**
 * @brief
 *
 * @param motorData Struct with PWM values for the motor
 * @param motorForce Struct with motor force
 * @param TimeOfFlightData Struct with ToF distance data
 * @param degreesOfFreedomData Struct with 9-axes DoF data
 * @param rpiData 
 */
void arucoMarkersController(MotorSettings& motorData, MotorForce& motorForce,
                            TimeOfFlightData& timeOfFlightData,
                            DoFData& degreesOfFreedomData, RpiData& rpiData) {}

#endif //COMPILE_ARUCO_CONTROLLER

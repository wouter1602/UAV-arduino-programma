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

#include "circular_track_controller.h"

#include "../../defines.h"

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
                             DoFData& degreesOfFreedomData) {
    void loop() {
  S2 = ToF.sensor2;                    #afstand tot muur sensor 2 in mm
  S3 = ToF.sensor3;                    #afstand tot muur sensor 3 in mm
  delta_S = S2-S3;                     #verschil afstand S2 en S3 
  hoekUAV = atan (delta_S/4200);       #hoek van de UAV
  switch(hoekUAV) {
      case hoekUAV > 10 :
         motorForce.motorForce1 = -1.5
         motorForce.motorForce2 = 1.0
         break;
      case hoekUAV > 20 :
         motorForce.motorForce1 = -3.0
         motorForce.motorForce2 = 2.0
         break;
      case hoekUAV > 30 :
         motorForce.motorForce1 = -4.5
         motorForce.motorForce2 = 3.5
         break;
      case hoekUAV > 40 :
         motorForce.motorForce1 = -6.0
         motorForce.motorForce2 = 5.0
         break;
      case hoekUAV < 10 :
         motorForce.motorForce2 = -1.5
         motorForce.motorForce1 = 1.0
         break;
      case hoekUAV < 20 :
         motorForce.motorForce2 = -3.0
         motorForce.motorForce1 = 2.0
         break;
      case hoekUAV < 30 :
         motorForce.motorForce2 = -4.5
         motorForce.motorForce1 = 3.5
         break;
      case hoekUAV < 40 :
         motorForce.motorForce2 = -6.0
         motorForce.motorForce1 = 5.0
         break;
      
      default :
         motorForce.motorForce1 = 0.0
         motorForce.motorForce2 = 0.0
}
}

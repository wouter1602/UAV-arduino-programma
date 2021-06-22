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

#include "../sensors/ToF.h"
#include "../sensors/motor.h"
#include "../sensors/nine-dof.h"

/*
    Simulatie van plaats s en snelheid v van een massa m en een stuwkracht F
    Bewegingsvergelijking:
       m.a = F
 
    Integratie obv
       a = dv/dt
       v = dx/dt
 
    => dv = a.dt => v_nw - v_oud = a.dt => v_nw = v_oud + a.dt =>
       v = v + a*dt
       x = x + v*dt
*/
const bool simulator = true;        // moest van die man er in
 
const float m = 1.143;      // kg gewicht van de UAV is 1.143 kilo
float F = 0.01;              // N beginwaarde
const float Fmax = 0.2;
const float Fmin = -0.228;
float a;                    // m/s2
float v = 0.0, x = 0.5;     // Beginwaarden
 
float error;
float error_old;
float d_err;
float error_d_front;
float d_error_d_front;
float Kp_d_front; 
float Kd_d_front;
const float sp = 0.3; //setpoint in meters
const float Kp = 2.0; //propsineel hier mee iets doen uitzoeken wat het doet.
const float Kd = 2.0; // diffrentiel hier mee iets doen uitzoeken wat het doet. 
 
long t_old, t_nw;
float dt;
  error_oud = sp - x;
 
  t_oud = millis(); // starttijd
  tijdVoorNwePixelPlot = t_oud;
  tEind = t_oud + simulatietijd;
}
 
void wallController(MotorSettings& motorData, MotorForce& motorForce,
                    TimeOfFlightData& timeOfFlightData,
                    DoFData& degreesOfFreedomData);

#endif  // WALL_CONTROLLER_H

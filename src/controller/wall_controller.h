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
float error_oud;
float d_err;
const float sp = 0.3; //setpoint in meters
const float Kp = 2.0; //propsineel hier mee iets doen uitzoeken wat het doet.
const float Kd = 2.0; // diffrentiel hier mee iets doen uitzoeken wat het doet. 
 
long t_oud, t_nw;
float dt;
 
// Zorg dat de plot op één pagina past
const long cyclustijd = 10;           // ms je lees nu alles uit in 10ms en stuur je dat na de motoren en daarna weer opnieuw
const long simulatietijd = 10 * 1000; // ms staat dus op 10 seconde
long tEind;
const int pixels = 500;               // aantal weer te geven punten omdat arduino niet meer wil
const float tijdPerPixel = simulatietijd * 1.0 / pixels; // als je uur zou willen sim dan kan je dit hier mooi uitrekenen kan je dus zelfs simvan een uur
double tijdVoorNwePixelPlot;
 
// hieronder moeten alle programmas komen dus de tofen derest. (rens leg me dit uit pls)
// je kan ook een strucht terug sturen voor meerdere antworden.
 
float ToF() {
  float afstand;
  return (afstand);
}
 
void setup() {
  Serial.begin(57600);
  Serial.print("F a v x");  // De legenda
  if (tijdPerPixel < cyclustijd) Serial.println("___XXXXXX____tijdPerPixel.<.cyclustijd____XXXXXX");
  else Serial.println();
 
  error_oud = sp - x;
 
  t_oud = millis(); // starttijd
  tijdVoorNwePixelPlot = t_oud;
  tEind = t_oud + simulatietijd;
}
 
void loop() {
  t_nw = millis(); // lees de tijd
  if (t_nw - t_oud > cyclustijd) {    // dit is een sneaky lus.
    dt = (t_nw - t_oud) * .001; //lees alle ingangeuit
    t_oud = t_nw;
    if (not simulator) {
      x = ToF();
    }
 
    // Regenlaar die er voor gaatzorgen dat je niet gaat slingeren (als eenveer)
    error = sp - x;
    d_err = error - error_oud;
    F = Kp * error + Kd * d_err / dt;
    F = constrain(F, Fmin, Fmax); //eerst de min dan de max EI
    error_oud = error;
 
    if (simulator) {
      a = F / m;      //
      x = x + v * dt; // deze twee vgln eigenlijk verwisselen van plaats (evt: s += v * dt)
      v = v + a * dt; // deze twee vgln eigenlijk verwisselen van plaats (evt: v += a * dt)
 
      // Alleen plotten als tijdPerPixel is verlopen
      if (t_nw > tijdVoorNwePixelPlot) {
        tijdVoorNwePixelPlot = tijdVoorNwePixelPlot + tijdPerPixel;
        Serial.print(F * 100);
        Serial.print(" ");
        Serial.print(a * 100);
        Serial.print(" ");
        Serial.print(v* 100);
        Serial.print(" ");
        Serial.println(x * 100);
      }
      // Stop met plotten, anders loopt de grafiek van het scherm af
      while (t_nw > tEind); // Vanglus, einde van het programma
    }
  }
}

void wallController(MotorSettings& motorData, MotorForce& motorForce,
                    TimeOfFlightData& timeOfFlightData,
                    DoFData& degreesOfFreedomData);

#endif  // WALL_CONTROLLER_H

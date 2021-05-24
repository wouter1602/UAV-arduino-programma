/**
 * @file main.ino
 * @author Groep A2
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <Arduino.h>
#include <Wire.h>

#include "defines.h"
#include "ToF.h"
#include "motor.h"

/**
 * @brief Setup Initial TWI (I²C) setup
 * 
 */
void setupWire(void) {

}


/**
 * @brief 
 * 
 */
void setup(void) {
    #ifdef DEBUG
    Serial.begin(112500);
    #endif
    setupWire();
    setupToF();
    setupMotor();
}


/**
 * @brief 
 * 
 */
void loop(void) {

}

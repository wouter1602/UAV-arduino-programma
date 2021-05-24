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

#include "defines.h"
#include "ToF.h"



/**
 * @brief 
 * 
 */
void setup(void) {
    setupToF();

    #ifdef DEBUG
    Serial.begin(112500);
    #endif
    
}


/**
 * @brief 
 * 
 */
void loop(void) {

}
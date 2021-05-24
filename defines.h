/**
 * @file defines.h
 * @author Wouter van Velzen (19093861@sutdnet.hhs.nl)
 * @brief List with defines used in the main program
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef DEFINES_H
#define DEFINES_H

#include <Arduino.h>

#define DEBUG  // If debug is defined the program wil debug through the serial
               // port.

// Pin defines

// ToF pins
#define TOF_XSHUT1 31
#define TOF_XSHUT2 32
#define TOF_XSHUT3 33

// Motor pins
#define MOTOR_PWM1 6
#define MOTOR_PWM2 7
#define MOTOR_PWM3 8
#define MOTOR_ENABLE_LEFT1 24
#define MOTOR_ENABLE_RIGHT1 25
#define MOTOR_ENABLE_LEFT2 27
#define MOTOR_ENABLE_RIGHT2 26
#define MOTOR_ENABLE_LEFT3 28
#define MOTOR_ENABLE_RIGHT3 29

// Safety pins
#define ADC_CELL1 A14
#define ADC_CELL2 A13
#define ADC_CELL3 A12
#define ADC_CURRENT A15
#define RELAY_RPI 22
#define RELAY_BLOWERS 23

#endif  // DEFINES_H
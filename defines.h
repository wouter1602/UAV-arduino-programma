/**
 * @file defines.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
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

// Physical attributes Hovercraft
#define HOVER_MASS 1.434        // in kg
#define MAX_FORCE_MOTOR1 5.0   // in N
#define MIN_FORCE_MOTOR1 -6.0  // in N
#define MAX_FORCE_MOTOR2 5.0   // in N
#define MIN_FORCE_MOTOR2 -6.0  // in N
#define MAX_FORCE_MOTOR3 5.0   // in N
#define MIN_FORCE_MOTOR3 -6.0  // in N
#define DELTA_t 10             // in ms

// Controllers abbreviations
#define NOTHING_CONTROLLER 0
#define ANGLE_CONTROLLER 1
#define WALL_CONTROLLER 2
#define CIRCULAR_TRACK_CONTROLLER 3
#define ARUCO_MARKERS_CONTROLLER 4

// Pin defines

// ToF pins
#define TOF_XSHUT1 31
#define TOF_XSHUT2 32
#define TOF_XSHUT3 33

#define TOF_ADDRESS1 0x30
#define TOF_ADDRESS2 0x32
#define TOF_ADDRESS3 0x34

#define TOF_MEASUREMENT_TIMEOUT 4  // in ms

// Motor pins
#define MOTOR_PWM1 5
#define MOTOR_PWM2 6
#define MOTOR_PWM3 7
#define MOTOR_ENABLE_LEFT1 24
#define MOTOR_ENABLE_RIGHT1 25
#define MOTOR_ENABLE_LEFT2 26
#define MOTOR_ENABLE_RIGHT2 27
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

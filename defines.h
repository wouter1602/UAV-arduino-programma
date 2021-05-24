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

#define DEBUG       //If debug is defined the program wil debug through the serial port.

// Pin defines

//Motor pins
#define MOTOR_PWM1 1            //Needs correct pin
#define MOTOR_PWM2 2            //Needs correct pin
#define MOTOR_PWM3 3            //Needs correct pin
#define MOTOR_ENABLE_LEFT1 4    //Needs correct pin
#define MOTOR_ENABLE_RIGHT1 5   //Needs correct pin
#define MOTOR_ENABLE_LEFT2 6    //Needs correct pin
#define MOTOR_ENABLE_RIGHT2 7   //Needs correct pin
#define MOTOR_ENABLE_LEFT3 8    //Needs correct pin
#define MOTOR_ENABLE_RIGHT3 9   //Needs correct pin

#endif //DEFINES_H
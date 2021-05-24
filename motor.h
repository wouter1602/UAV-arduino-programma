/**
 * @file motor.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief 
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

/**
 * @brief PWM value for the motor drivers.
 * Negative number is CCW positive number is CW.
 * 
 */
struct MotorSettings{
    int16_t motorPWMSpeed1;
    int16_t motorPWMSpeed2;
    int16_t motorPWMSpeed3;
};

void setupMotor(void);
MotorSettings convertForceToPWM(int16_t motor1, int16_t motor2, int16_t motor3); // Could als be floats.
void setMotorSpeed(MotorSettings motordata);



#endif //MOTOR_H
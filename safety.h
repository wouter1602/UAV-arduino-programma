/**
 * @file safety.h
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief Handels cell safety and max current safety
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef SAFETY_H
#define SAFETY_H

void setupSafety(void);
void checkCellVoltage(void);
void checkCurrent(void);

#endif  // SAFETY_H
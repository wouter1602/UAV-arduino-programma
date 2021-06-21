/**
 * @file nine-dof.h
 * @author your name (you@domain.com)
 * @brief Functions to read the mems MPU-9250
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

/*
 * Datasheet Mems 9-axes DoF (gyro + Accelerometer + Compass) (MPU-9250)
 * https://invensense.tdk.com/wp-content/uploads/2015/02/PS-MPU-9250A-01-v1.1.pdf
 */

#ifndef NINE_DOF_H
#define NINE_DOF_H

float alpha = 0.0;                    // m/s2  HOEKVERSNELLING
float omega = 0.0, theta = 0.0; // Beginwaarden OMEGA, hoeksnelheid, en hoek in rad met random getal
/**
 * @brief Struct with the gyro data.
 * 
 */
struct GyroData {
//TODO: Create a data set here.
};

/**
 * @brief Struct with the accelerometer data
 * 
 */
struct AccelerometerData {
//TODO: Create a data set here.
};

/**
 * @brief Struct with the compass data.
 * 
 */
struct CompassData {
//TODO: Create a data set here.
};

/**
 * @brief Struct with all the 9-axis DoF sensor data
 * 
 */
struct DoFData {
    GyroData gyroData;
    AccelerometerData accelerometerData;
    CompassData compassData;
};

void setupDoF(void);

void readDoF(DoFData& data);

#endif  // NINE_DOF_H

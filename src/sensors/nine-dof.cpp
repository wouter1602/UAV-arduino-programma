/**
 * @file nine-dof.cpp
 * @author Jasper van Vliet (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "nine-dof.h"

#include <Arduino.h>
#include <Wire.h>

#include "../../defines.h"
#include "../lib/MPU9250/SparkFunMPU9250-DMP.h"
#include "../lib/MPU9250/MPU9250_RegisterMap.h"

MPU9250_DMP imu;

float alpha = 0.0;                    // m/s2  HOEKVERSNELLING
float omega = 0.0, theta = 0.0; // Beginwaarden OMEGA, hoeksnelheid, en hoek in rad met random getal
float avg_omega = 0.0;

/**
 * @brief Reads all the gyro data from the 9-axis DoF sensor
 *
 * @param GyroData struct with gyro data
 */
void readGyro(GyroData& data) {
    float gyroX = imu.calcGyro(imu.gx);
    float gyroY = imu.calcGyro(imu.gy);
    float gyroZ = imu.calcGyro(imu.gz);
}

/**
 * @brief Reads all the accelerometer data from the 9-axis DoF sensor
 *
 * @param AccelerometerData struct with accelerometer data
 */
void readAccelerometer(AccelerometerData& data) {
    float accelX = imu.calcAccel(imu.ax);
    float accelY = imu.calcAccel(imu.ay);
    float accelZ = imu.calcAccel(imu.az);
}

/**
 * @brief Reads all the compass data from the 9-axis DoF sensor
 *
 * @param CompassData struct with compass data
 */
void readCompass(CompassData& data) {
    float magX = imu.calcMag(imu.mx);
    float magY = imu.calcMag(imu.my);
    float magZ = imu.calcMag(imu.mz);
}

/**
 * @brief Enables 9-axis DoF sensor
 *
 */
void setupDoF() {
	imu.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);    //zet alle sensoren aan
	imu.setGyroFSR(2000); // Set gyro to 2000 dps
	imu.setAccelFSR(2); // Set accel to +/-2g
	imu.setLPF(5); // Set LPF corner frequency to 5Hz
	imu.setSampleRate(10); // Set sample rate to 10Hz
	imu.setCompassSampleRate(10); // Set mag rate to 10Hz
#ifdef DEBUG
  Serial.println("[INFO] Completed setup 9-axis DoF sensor");
#endif  // DEBUG
}

/**
 * @brief returns Reference to struct with all the data of the Mems unit
 *
 * @param DoFData Reference Struct with Gyro, Accelerometer and compass data.
 */
 
void readDoF(DoFData& data) {
    readGyro(data.gyroData);
    readAccelerometer(data.accelerometerData);
    readCompass(data.compassData);
  
    float omega = imu.calcGyro(imu.gz);  //Uitlezen van de gyroscoop om de Z-as
    avg_omega = (avg_omega + omega)/2;   //Neem het gemiddelde van 2 metingen om grote
                                         //afwijkingen te voorkomen
    theta = theta + (avg_omega * DELTA_t);    //Integratie van omega om theta te verkrijgen
    Serial.println(theta);               //print theta

}

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

/**
 * @brief Reads all the gyro data from the 9-axis DoF sensor
 *
 * @param GyroData struct with gyro data
 */
void readGyro(GyroData& data) {
    data.omega = imu.calcGyro(imu.gz);
}

/**
 * @brief Reads all the accelerometer data from the 9-axis DoF sensor
 *
 * @param AccelerometerData struct with accelerometer data
 */
void readAccelerometer(AccelerometerData& data) {
   // float accelZ = imu.calcAccel(imu.az);
}

/**
 * @brief Reads all the compass data from the 9-axis DoF sensor
 *
 * @param CompassData struct with compass data
 */
void readCompass(CompassData& data) {
}

/**
 * @brief Enables 9-axis DoF sensor
 *
 */
 void setupDoF() {
	pinMode(RELAY_BLOWERS, OUTPUT);
	imu.setSensors(INV_XYZ_GYRO | INV_XYZ_ACCEL | INV_XYZ_COMPASS);    //zet alle sensoren aan
	imu.setGyroFSR(2000); // Set gyro to 2000 dps
	imu.setAccelFSR(2); // Set accel to +/-2g
	imu.setLPF(5); // Set LPF corner frequency to 5Hz
	imu.setSampleRate(10); // Set sample rate to 10Hz
	imu.setCompassSampleRate(10); // Set mag rate to 10Hz
	imu.dmpBegin(DMP_FEATURE_GYRO_CAL |   // Enable gyro cal
			  DMP_FEATURE_SEND_CAL_GYRO,// Send cal'd gyro values
			  10);                   // Set DMP rate to 10 Hz
	#ifdef DEBUG
	Serial.println("[INFO] Completed setup 9-axis DoF sensor");
	#endif  // DEBUG
}


/**
 * @brief Calibrates 9-axis DoF sensor
 *
 */
void Kalibratie(GyroData& data) { 
    digitalWrite(RELAY_BLOWERS, LOW);
		 	 
	for(uint16_t kalibratie_meting = 0; kalibratie_meting <= 20;){
		if (imu.fifoAvailable() )
		{
		// Use dmpUpdateFifo to update the ax, gx, mx, etc. values
			if (imu.dmpUpdateFifo() == INV_SUCCESS)
			{
			//Serial.println(String(omega) + " dps");
			}
		}
		if(data.omega < 0.2){
			kalibratie_meting += 1;
		}	 
	 }
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
}


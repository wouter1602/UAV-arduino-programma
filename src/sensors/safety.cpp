/**
 * @file safety.cpp
 * @author Wouter van Velzen (19093861@student.hhs.nl)
 * @brief
 * @version 0.1
 * @date 2021-05-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "safety.h"

#include "../../defines.h"

#define TURN_OFF_RELAY          \
  digitalWrite(RELAY_RPI, LOW); \
  digitalWrite(RELAY_BLOWERS, LOW);

#define OVER_CURRENT 500         // ADC value need for more than 7A
#define OVER_VOLTAGE_CELL1 500   // ADC value needed for more than 4,2V
#define UNDER_VOLTAGE_CELL1 500  // ADC value needed for less than 3V
#define OVER_VOLTAGE_CELL2 500   // ADC value needed for more than 4,2V
#define UNDER_VOLTAGE_CELL2 500  // ADC value needed for less than 3V
#define OVER_VOLTAGE_CELL3 500   // ADC value needed for more than 4,2V
#define UNDER_VOLTAGE_CELL3 500  // ADC value needed for less than 3V

struct ADC_Data {
  uint16_t cell_1;
  uint16_t cell_2;
  uint16_t cell_3;
  uint16_t current;
} adcData;

/**
 * @brief Set the Raspberry Pi + Fans Relay on or off
 *
 * @param output True = on, False = off
 */
void setRelayRPI(bool output) {
  if (output) {
    digitalWrite(RELAY_RPI, HIGH);
  } else {
    digitalWrite(RELAY_RPI, LOW);
  }
}

/**
 * @brief Set the Blowers on or off
 *
 * @param output True = on, False = off
 */
void setRelayBlowers(bool output) {
  if (output) {
    digitalWrite(RELAY_BLOWERS, HIGH);
  } else {
    digitalWrite(RELAY_BLOWERS, LOW);
  }
}

/**
 * @brief Read ADC values for the battery and save  them in a private struct
 *
 */
void readCellADC() {
  adcData.cell_1 = analogRead(ADC_CELL1);
  adcData.cell_2 = analogRead(ADC_CELL2);
  adcData.cell_3 = analogRead(ADC_CELL3);
}

/**
 * @brief Read ADC values for the current and save them in a private struct
 *
 */
void readCurrentADC() { adcData.current = analogRead(ADC_CURRENT); }

/**
 * @brief
 *
 */
void setupSafety() {
  // Set pin as output
  pinMode(RELAY_RPI, OUTPUT);
  pinMode(RELAY_BLOWERS, OUTPUT);
  pinMode(ADC_CELL1, INPUT);
  pinMode(ADC_CELL2, INPUT);
  pinMode(ADC_CELL3, INPUT);
  pinMode(ADC_CURRENT, INPUT);

  // Read ADC values
  checkCellVoltage();
  readCellADC();
  readCurrentADC();

  #ifdef DEBUG
Serial.println("[INFO] Completed setup Safety.");
  #endif //DEBUG
}

/**
 * @brief Read ADC values of the and turn of the relays if the voltage is too
 * high or low
 *
 */
void checkCellVoltage(void) {
  readCellADC();
  if (adcData.cell_1 > OVER_VOLTAGE_CELL1 ||
      adcData.cell_1 < UNDER_VOLTAGE_CELL1) {
    TURN_OFF_RELAY
#ifdef DEBUG
    Serial.println("[ERROR] Cell 1 too high or low. shutting down all relays.");
#endif  // DEBUG
  }
  if (adcData.cell_2 > OVER_VOLTAGE_CELL2 ||
      adcData.cell_2 < UNDER_VOLTAGE_CELL2) {
    TURN_OFF_RELAY
#ifdef DEBUG
    Serial.println("[ERROR] Cell 2 too high or low. shutting down all relays.");
#endif  // DEBUG
  }
  if (adcData.cell_3 > OVER_VOLTAGE_CELL3 ||
      adcData.cell_3 < UNDER_VOLTAGE_CELL3) {
    TURN_OFF_RELAY
#ifdef DEBUG
    Serial.println("[ERROR] Cell 3 too high or low. shutting down all relays.");
#endif  // DEBUG
  }

#ifdef DEBUG
  Serial.println("[INFO] Read cell ADC values:");
  Serial.print("Cell 1: ");
  Serial.println(adcData.cell_1);
  Serial.print("Cell 2: ");
  Serial.println(adcData.cell_2);
  Serial.print("Cell 3: ");
  Serial.println(adcData.cell_3);
#endif  // DEBUG
}

/**
 * @brief Check if current is too high. If too high turn of relay's
 * In the first pass only the blowers will be turend off.
 * If the current is still too high after turning off the blower the Raspberry
 * Pi will also be turned off.
 */
void checkCurrent(void) {
  readCurrentADC();
#ifdef DEBUG
  Serial.print("[INFO] Read ADC Current: ");
  Serial.println(adcData.current);
#endif  // DEBUG
  if (adcData.current > OVER_CURRENT) {
    if (digitalRead(RELAY_BLOWERS) == LOW) {
      digitalWrite(RELAY_RPI, LOW);
#ifdef DEBUG
      Serial.println(
          "[ERROR] Current too high! shuting off Raspberry pi + fans.");
#endif  // DEBUG
    } else {
      digitalWrite(RELAY_BLOWERS, LOW);
#ifdef DEBUG
      Serial.println("[ERROR] Current too high! shuting off blowers.");
#endif  // DEBUG
    }
  }
}

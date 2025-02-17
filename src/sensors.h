#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// Forward declaration of the calibration constants (we’ll compute them in code).
extern float aCal;
extern float bCal;

// Functions
void initSensors();

float getHumidity();

float getDHTTempC();

float getDHTTempF();

int getSoilMoistureRaw();

int getSoilMoisturePercent();

float getThermistorC();

float getThermistorF();

int getLightADC();

float getLux();

#endif

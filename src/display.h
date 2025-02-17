#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

void initDisplay();

void updateDisplay(float humidity, float tempF, int soilMoistPercent, float lux);

#endif

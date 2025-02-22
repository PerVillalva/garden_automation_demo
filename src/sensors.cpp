#include "sensors.h"
#include "config.h"

#include <DHT.h>
#include <math.h> // for log() and pow()

// Create a DHT object using pins from Config.h
static DHT dht(DHT_PIN, DHT_TYPE);

// Global calibration variables for the LDR
float aCal = 0;
float bCal = 0;

// ------------------
// Internal Helpers
// ------------------

// Convert LDR ADC reading to resistance
static float readingToResistance(int reading) {
    // Avoid divide-by-zero
    if (reading == 0) reading = 1;

    // Convert ADC to voltage
    const float vOut = reading * (5.0 / 1023.0);

    // Voltage divider formula:
    // vOut = (R_FIXED / (R_LDR + R_FIXED)) * 5V
    // => R_LDR = R_FIXED * (5 / vOut - 1)
    const float rLDR = R_FIXED * (5.0 / vOut - 1.0);
    return rLDR;
}

// Convert LDR resistance to lux
static float resistanceToLux(float rLDR) {
    if (rLDR <= 0) rLDR = 1;
    // R_LDR = aCal * (lux)^(-bCal) => lux = (aCal / R_LDR)^(1/bCal)
    return pow(aCal / rLDR, 1.0 / bCal);
}

// ------------------
// Public Functions
// ------------------

// Initialize sensors and calibrate the LDR
void initSensors() {
    dht.begin(); // Start DHT

    // Calibrate LDR using two reference points
    const float rBright = readingToResistance(BRIGHT_READING);
    const float rDim = readingToResistance(DIM_READING);

    // Solve for bCal:
    // b = (ln(rBright) - ln(rDim)) / (ln(DIM_LUX) - ln(BRIGHT_LUX))
    bCal = (log(rBright) - log(rDim)) / (log(DIM_LUX) - log(BRIGHT_LUX));

    // Solve for aCal:
    // ln(a) = ln(rBright) + b * ln(BRIGHT_LUX)
    aCal = exp(log(rBright) + bCal * log(BRIGHT_LUX));
}

// ------------------
// DHT Sensor
// ------------------
float getHumidity() {
    return dht.readHumidity();
}

float getDHTTempC() {
    return dht.readTemperature(); // in Celsius
}

float getDHTTempF() {
    return dht.readTemperature(true); // in Fahrenheit
}

// ------------------
// Soil Moisture
// ------------------
int getSoilMoistureRaw() {
    return analogRead(MOISTURE_PIN);
}

int getSoilMoisturePercent() {
    const int rawValue = getSoilMoistureRaw();
    int percent = map(rawValue, WET_VALUE, DRY_VALUE, 100, 0);
    percent = constrain(percent, 0, 100);
    return percent;
}

// ------------------
// Thermistor
// ------------------
float getThermistorC() {
    const int tempValue = analogRead(TEMP_SENSOR_PIN);
    const float resistance = (1023.0 / tempValue - 1.0) * SERIES_RESISTOR;
    const float tempK = 1.0 / ((log(resistance / ROOM_TEMP_RESISTOR) / BETA)
                               + (1.0 / ROOM_TEMP_K));
    const float tempC = tempK - 273.15;
    return tempC;
}

float getThermistorF() {
    float c = getThermistorC();
    return (c * 9.0 / 5.0) + 32.0;
}

// ------------------
// LDR
// ------------------
int getLightADC() {
    return analogRead(LIGHT_SENSOR_PIN);
}

float getLux() {
    const int adc = getLightADC();
    const float rLDR = readingToResistance(adc);
    const float lux = resistanceToLux(rLDR);
    return lux;
}

#ifndef CONFIG_H
#define CONFIG_H

// ------------------
// Pin Definitions
// ------------------
#define DHT_PIN 2
#define MOISTURE_PIN A1
#define LIGHT_SENSOR_PIN A0
#define TEMP_SENSOR_PIN A2

// LCD Pins
constexpr int rs = 7;
constexpr int en = 8;
constexpr int d4 = 9;
constexpr int d5 = 10;
constexpr int d6 = 11;
constexpr int d7 = 12;

// ------------------
// DHT Sensor
// ------------------
#define DHT_TYPE  DHT11  // DHT11 or DHT22

// ------------------
// Thermistor
// ------------------
constexpr float BETA = 3950.0; // NTC Beta value
constexpr float SERIES_RESISTOR = 10000.0; // Thermistor series resistor
constexpr float ROOM_TEMP_RESISTOR = 10000.0; // Thermistor resistance at 25°C
constexpr float ROOM_TEMP_K = 25.0 + 273.15; // 25°C in Kelvin

// ------------------
// LDR Calibration
// ------------------
constexpr float R_FIXED = 10000.0; // Fixed resistor in the LDR divider

// Reference points for LDR (measured with a "known" table lamp light source)
constexpr int BRIGHT_READING = 307; // ADC reading in bright scenario
constexpr float BRIGHT_LUX = 1000.0;
constexpr int DIM_READING = 710; // ADC reading in dim scenario
constexpr float DIM_LUX = 200.0;

// ------------------
// Soil Moisture
// ------------------
constexpr int DRY_VALUE = 500;
constexpr int WET_VALUE = 239;

// ------------------
// Timings
// ------------------
constexpr int DELAY_TIME = 5000;
constexpr int SETUP_TIME = 5000;

#endif

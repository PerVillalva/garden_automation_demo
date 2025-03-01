#include <Arduino.h>
#include "config.h"
#include "sensors.h"
#include "display.h"

void setup() {
    Serial.begin(9600);

    initSensors(); // Calibrate LDR, init DHT
    initDisplay(); // Init LCD

    delay(SETUP_TIME); // Let sensors stabilize

    Serial.println("Setup complete.\n");
}

void loop() {
    // --- Read Sensors ---
    const float humidity = getHumidity();
    float dhtTempC = getDHTTempC();
    const float dhtTempF = getDHTTempF();
    const int soilMoistPercent = getSoilMoisturePercent();
    float thermC = getThermistorC();
    const float thermF = getThermistorF();
    const float luxVal = getLux();

    // --- Print to Serial ---
    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.print("% | DHT11 Temp F: ");
    Serial.print(dhtTempF, 1);
    Serial.print("F | DHT11 Temp C: ");
    Serial.print(dhtTempC, 1);
    Serial.print("C | Thermistor Temp F: ");
    Serial.print(thermF, 1);
    Serial.print("F | Thermistor Temp C: ");
    Serial.print(thermC, 1);
    Serial.print("C | Soil Moisture: ");
    Serial.print(soilMoistPercent);
    Serial.print("% | Lux: ");
    Serial.println(luxVal);

    // --- Update LCD ---
    updateDisplay(humidity, thermF, soilMoistPercent, luxVal);

    // --- Delay ---
    delay(DELAY_TIME);
}

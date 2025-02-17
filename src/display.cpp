#include "display.h"
#include "config.h"
#include <LiquidCrystal.h>

// Create the LCD object with pins from Config.h
static LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void initDisplay() {
    lcd.begin(16, 2);
}

void updateDisplay(const float humidity, const float tempF, const int soilMoistPercent, const float lux) {
    // Clear or set cursor as needed
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("AH:");
    lcd.print(humidity, 1);
    lcd.print("% T:");
    lcd.print(tempF, 1);
    lcd.print("F");

    lcd.setCursor(0, 1);
    lcd.print("SH:");
    lcd.print(soilMoistPercent);
    lcd.print("% Lx:");
    lcd.print(lux, 1);
}

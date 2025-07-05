#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected() {
    Serial.println("Beat!");
}

void setup() {
    // Initialize serial communication for Bluetooth (HC-05)
    Serial.begin(9600);  // Set baud rate to 9600 for Bluetooth

    Serial.print("Initializing pulse oximeter..");

    // Initialize the PulseOximeter instance
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }

    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    // Continuously update the pulse oximeter data
    pox.update();

    // Send heart rate and SpO2 data over Bluetooth every second
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        float heartRate = pox.getHeartRate();
        float spO2 = pox.getSpO2();

        // Send heart rate and SpO2 data via Bluetooth (Serial)
        Serial.print("Heart rate: ");
        Serial.print(heartRate);
        Serial.print(" bpm / SpO2: ");
        Serial.print(spO2);
        Serial.println(" %");

        tsLastReport = millis();  // Update timestamp
    }
}
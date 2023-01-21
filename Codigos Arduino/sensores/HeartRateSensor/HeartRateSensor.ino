#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS     1000
 
PulseOximeter pox;
uint32_t tsLastReport = 0;
 
void onBeatDetected()
{
    Serial.println("Beat!");
}
 
void setup()
{
    Serial.begin(9600);
    Serial.println("hello");

    /*Serial.print("Initializing pulse oximeter..");
 
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }*/
    setupOximeter();
 
    // Register a callback for the beat detection
    //pox.setOnBeatDetectedCallback(onBeatDetected);
}

void setupOximeter()
{
    pox.resume();
      while(!pox.begin())
    {
    Serial.println("Initializing pulse oximeter..");  
    delay(1);
    }
    Serial.println("Pox inicializado");
     pox.setIRLedCurrent(MAX30100_LED_CURR_50MA);
}
 
void loop()
{
    // Make sure to call update as fast as possible
        pox.resume();
    /*if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        setupOximeter();
        delay(2000);*/
        for(int i =0; i<9000;i++)
        {
        pox.update();
        delay(1);
        }
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");
        /*delay(100);
        }
        tsLastReport = millis();

    }*/
        pox.shutdown();
    //delay(1000);
}

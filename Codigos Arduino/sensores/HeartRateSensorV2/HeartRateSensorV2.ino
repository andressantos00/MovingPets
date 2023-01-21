#include <Wire.h>
#include "MAX30100.h"
#include "MAX30100_PulseOximeter.h"

MAX30100 sensor;
PulseOximeter pox;

void onBeatDetected()
{
    Serial.println("Beat!");
}
 
void setup()
{
    Serial.begin(9600);
    
    //Serial.print("Resuming normal operation..");
    //sensor.resume();
    while(!pox.begin())
    {
    Serial.print("Initializing pulse oximeter..");  
    delay(10);
    }
    /*while(!sensor.begin())
    {
    Serial.print("Initializing pulse oximeter..");  
    delay(10);
    }
    Serial.println("SUCCESS");*/
    
    //sensor.setLedsCurrent(MAX30100_LED_CURR_50MA, MAX30100_LED_CURR_50MA);
    pox.setIRLedCurrent(MAX30100_LED_CURR_50MA);
    //sensor.setMode(MAX30100_MODE_SPO2_HR);

    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);
}


void readTemperature()
{
      sensor.startTemperatureSampling();
      while(!sensor.isTemperatureReady()) {}
      float temperature = sensor.retrieveTemperature();
      Serial.print(temperature);
      Serial.println(" C");
      
}
 
void loop()
{




    // Make sure to call update as fast as possible
    pox.update();
    Serial.print("Heart rate:");
    Serial.print(pox.getHeartRate());
    Serial.print("bpm / SpO2:");
    Serial.print(pox.getSpO2());
    Serial.println("%");
    
    //readTemperature();

    //Serial.print("Shutting down..");
    //sensor.shutdown();
    delay(1000);
}

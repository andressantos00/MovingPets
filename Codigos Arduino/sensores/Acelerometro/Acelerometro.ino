#include <Wire.h>
#include <Adafruit_Sensor.h>    // Adafruit  sensor library
#include <Adafruit_ADXL345_U.h>  // ADXL345 library

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();   // ADXL345 Object

//const uint8_t scl = 14; //D5
//const uint8_t sda = 12; //D6

void setup() {

  //Wire.begin(sda, scl);

  Serial.begin(9600);
  if(!accel.begin())   // if ASXL345 sensor not found
  {
    Serial.println("ADXL345 not detected");
    while(1);
  }

}

void loop() {

 sensors_event_t event;
 accel.getEvent(&event);
 Serial.print("X: ");
 Serial.print(event.acceleration.x );
 Serial.print("  ");
  Serial.print("Y: ");
 Serial.print(event.acceleration.y);
 Serial.print("  ");
  Serial.print("Z: ");
 Serial.print(event.acceleration.z);
 Serial.print("  ");
 Serial.println("m/s^2 ");
 delay(500);

}

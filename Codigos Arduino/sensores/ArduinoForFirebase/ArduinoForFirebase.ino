#include <FirebaseArduino.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "ESP8266WebServer.h"

#define REPORTING_PERIOD_MS     10000

#define FIREBASE_HOST "movingpetsdatabase-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "3OdVT59WD9887xX7vxcLmQsTr6XXeCCwzZBx4YEK"

#define WIFI_SSID       "Vodafone-DBCD72"
#define WIFI_PASSWORD   "2D7KNEEGyc93VFHF"
 
uint32_t tsLastReport = 0;
 

float bpm = 80;
float spO2=98;
float tempC=30;
float dev_id=1;

void setup()
{
  Serial.begin(9600);
  
  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    /*//Firebase.set("Sensor/Marley/Device", 0);
    //Firebase.set("Sensor/Accelerometer", 0);
     Firebase.set("Sensor/Marley/Device", 0);
     Firebase.set("Sensor/Marley/HeartRate", 0);
     Firebase.set("Sensor/Marley/OxygenLevels", 0);
     Firebase.set("Sensor/Marley/Temperature", 0);*/


  if (Firebase.failed()) 
  {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());
  }

            Serial.println("enviei");
          Firebase.setFloat("Sensor/Marley/HeartRate2", bpm);
          Firebase.setInt("Sensor/Marley/OxygenLevels2", spO2);
          Firebase.setFloat("Sensor/Marley/Temperature2", tempC);
          Firebase.setInt("Sensor/Marley/Device2", dev_id);

}

void loop()
{

}

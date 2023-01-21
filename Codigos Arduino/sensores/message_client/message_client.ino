#include <ESP8266WiFi.h>    // The Basic Function Of The ESP NOD MCU

#define AP_SSID "MovingPetsNetwork"
#define AP_PASS "magicword"
IPAddress server(192, 168, 25, 240);   // the fix IP address of the server
WiFiClient client;

void setup() {
  Serial.begin(9600);           // Setting the Serial Port - Computer Communication
  
  WiFi.begin(AP_SSID, AP_PASS);         // connects to the MovingPets WIFI
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Waiting for conection");
    delay(1000);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi Conected");
  }
  
  Serial.println("Connected To      : " + String(WiFi.SSID()));
  //Serial.println("Signal Strenght   : " + String(WiFi.RSSI()) + " dBm");
  //Serial.print  ("Server IP Address : ");  Serial.println(WiFi.softAPIP()); // Print Server IP
  //Serial.print  ("Device MC Address : ");  Serial.println(String(WiFi.macAddress())); // Print Client macAddress
  //Serial.print  ("Device IP Address : ");  Serial.println(WiFi.localIP());        // Print Client IP Address
}

void loop() {
  SendMessage();
  delay(1000);
}

void SendMessage()
{
  if(client.connect(server, 80))  // Connection to the server
  {
    String a = "Device ID";
    String b = "batteryvoltage";
    client.println(a + "\r" + b + "\r");
    client.flush();
  }
  Serial.println("Package sent");
}

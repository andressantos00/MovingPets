#include <ESP8266WiFi.h>    // The Basic Function Of The ESP NOD MCU
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <WiFiUdp.h>


#define AP_SSID "MovingPetsNetwork"
#define AP_PASS "magicword"
IPAddress server(192, 168, 25, 240);   // the fix IP address of the server
WiFiClient client;

unsigned long int timer_connection = 0;


uint8_t bssid[6];
uint32_t canal;

void conecaolenta()
{
    WiFi.begin(AP_SSID, AP_PASS);
    Serial.println("Connecção LENTA");
    while (WiFi.status() != WL_CONNECTED)
  {
    delay(1);
  }
}


void wifi_setup(IPAddress ip, IPAddress dns, IPAddress gateway ,IPAddress subnet)
{
  WiFi.forceSleepWake();
  WiFi.mode(WIFI_STA);
  WiFi.persistent( false ); // Disable the WiFi persistence.  The ESP8266 will not load and save WiFi settings unnecessarily in the flash memory.
  WiFi.config( ip,dns, gateway, subnet );
  delay(1);

  ESP.rtcUserMemoryRead( 0, (uint32_t*)&bssid, sizeof( bssid ) );
  ESP.rtcUserMemoryRead( 8*6, &canal, sizeof( canal ) );

  Serial.println("A tentar conecao rápida");
  WiFi.begin(AP_SSID, AP_PASS,canal,bssid,true);         // connects to the MovingPets WIFI
  timer_connection = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on by making the voltage HIGH
    //Serial.println("Waiting for conection");
    delay(1);
    if(millis() - timer_connection >= 5000)   //Se demorar mais que 5s a conectar, fazer uma conecção normal
    { 
    conecaolenta();
    }
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi Conected");
    digitalWrite(LED_BUILTIN, HIGH);  
  }
  //Serial.println("Connected To      : " + String(WiFi.SSID()));
  //Serial.println("Signal Strenght   : " + String(WiFi.RSSI()) + " dBm");
  //Serial.print  ("Server IP Address : ");  Serial.println(WiFi.softAPIP()); // Print Server IP
  //Serial.print  ("Device IP Address : ");  Serial.println(WiFi.localIP());        // Print Client IP Address
  //Serial.print("Device MC Address : "); Serial.println(String(WiFi.macAddress())); // Print Client macAddress
  //Serial.print("Device Channel : ");   Serial.println(String(WiFi.channel()));
  
  memcpy( bssid, WiFi.BSSID(), 6 ); //Copiar os 6bytes do MAC address
  ESP.rtcUserMemoryWrite( 0, (uint32_t*)&bssid, sizeof( bssid ) );
  ESP.rtcUserMemoryWrite( 8*6, &canal, sizeof( canal ));
  /*Serial.println();
  Serial.println(String(bssid[0]));
  Serial.println(String(bssid[1]));
  Serial.println(String(bssid[2]));
  Serial.println(String(bssid[3]));
  Serial.println(String(bssid[4]));
  Serial.println(String(bssid[5]));*/
}

void ReCheckConection()
{
  if(WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on by making the voltage HIGH
    WiFi.begin(AP_SSID, AP_PASS);         // connects to the WiFi router
    while (WiFi.status() != WL_CONNECTED)
    {
    Serial.println("Waiting for conection");
    delay(1000);
    }
  }
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage HIGH
}

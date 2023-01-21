#include <WiFiManager.h>

#define AP_SSID "MovingPetsNetwork"
#define AP_PASS "magicword"

#define     MAXSC     200             // MAXIMUM NUMBER OF CLIENTS

WiFiServer  server(80);               // THE SERVER AND THE PORT NUMBER
WiFiClient  Clients[MAXSC];           // THE SERVER CLIENTS (Devices)
IPAddress ip(192, 168, 25, 240);      // IP address of the server
IPAddress gateway(192, 168, 25, 1);   // gateway of your network
IPAddress subnet(255, 255, 255, 0);   // subnet mask of your network


WiFiManager wm;

void void_setup_AP()
{
  WiFi.mode(WIFI_AP_STA);                   // Set the device as a Station and Soft Access Point simultaneously
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(AP_SSID, AP_PASS);            // Begin Access Point
  server.begin();  
  Serial.print("IP address for network ");
  Serial.print(AP_SSID);
  Serial.print(" : ");
  Serial.println(WiFi.softAPIP());
}

void setup_start_config()
{
  //wm.setAPStaticIPConfig(ip, gateway, subnet);
  /*wm.setConfigPortalBlocking(true);
  if(wm.autoConnect(AP_SSID,AP_PASS))     //if you get here you have connected to the WiFi
  {
    Serial.println("connected...yeey :)");
    wm.setConfigPortalBlocking(false);
  }
  else 
  {
    Serial.println("ERROR: Not suposed see this message, it should be blocking");     // Not suposed to get here ever!!
  }
  wm.startConfigPortal(AP_SSID,AP_PASS);    // Volta a abrir o portal caso queiramos mudar de rede WiFi com acesso á internet
  //server.begin(); */
  /*wm.autoConnect(AP_SSID,AP_PASS);     //if you get here you have connected to the WiFi
  Serial.println("delay");
  delay(2000);
  wm.startConfigPortal(AP_SSID,AP_PASS);    // Volta a abrir o portal caso queiramos mudar de rede WiFi com acesso á internet
  wm.setConfigPortalBlocking(true);
  Serial.println("PASSOUUUUU");*/
  wm.autoConnect(AP_SSID,AP_PASS);     //if you get here you have connected to the WiFi
  wm.autoConnect(AP_SSID,AP_PASS);     //if you get here you have connected to the WiFi
  delay(1000);                        // Set the device as a Station and Soft Access Point simultaneously
  void_setup_AP(); 
}



void wp_run()
{
  wm.process();
}

void wp_clear_config()
{
  wm.resetSettings();   
  Serial.println("WIFI MANAGER RESET SETTINGS: ERASE ALL STORED DATA");
  ESP.restart();
}

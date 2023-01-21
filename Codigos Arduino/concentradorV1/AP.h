// Set AP credentials
#define AP_SSID "MovingPetsNetwork"
#define AP_PASS "magicword"

#define     MAXSC     200             // MAXIMUM NUMBER OF CLIENTS

WiFiServer  server(80);               // THE SERVER AND THE PORT NUMBER
WiFiClient  Clients[MAXSC];           // THE SERVER CLIENTS (Devices)
IPAddress ip(192, 168, 25, 240);      // IP address of the server
IPAddress gateway(192, 168, 25, 1);   // gateway of your network
IPAddress subnet(255, 255, 255, 0);   // subnet mask of your network

void setup_AP()
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

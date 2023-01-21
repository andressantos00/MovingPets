// Set WiFi credentials
#define WIFI_SSID "Vodafone-DBCD72"
#define WIFI_PASS "2D7KNEEGyc93VFHF"

void setup_wifi()
{
  // Set device as a Wi-Fi Station
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Waiting for conection");
    delay(1000);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi Conected");
  }
  Serial.print("IP address for network ");
  Serial.print(WIFI_SSID);
  Serial.print(" : ");
  Serial.println(WiFi.localIP());
  Serial.print("Wi-Fi Channel: ");
  Serial.println(WiFi.channel());
  Serial.print("Device MC Address : ");
  Serial.println(String(WiFi.macAddress())); // Print Client macAddress
}

void ReCheckConection()
{
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(WIFI_SSID, WIFI_PASS);         // connects to the WiFi router
    while (WiFi.status() != WL_CONNECTED)
    {
    }
  }
}

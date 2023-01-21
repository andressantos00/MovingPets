#include <ESP8266WiFi.h>
long SLEEPTIME=5e6; //5s
const char* WLAN_SSID = "MovingPetsNetwork";
const char* WLAN_PASSWD = "magicword";

uint8_t bssid[6];
uint32_t canal;

WiFiClient clientWiFi;

/*struct {
  uint32_t crc32;   // 4 bytes
  uint8_t channel;  // 1 byte,   5 in total
  uint8_t ap_mac[6];// 6 bytes, 11 in total
  uint8_t padding;  // 1 byte,  12 in total
} rtcData;*/

//We will use static ip
int deviceId = 2;
IPAddress ip( 192, 168, 25, deviceId);// pick your own suitable static IP address
IPAddress gateway( 192, 168, 25, 1 ); // may be different for your network
IPAddress subnet( 255, 255, 255, 0 ); // may be different for your network (but this one is pretty standard)
IPAddress dns(192,168,25,1);

void setup() 
{
  Serial.begin(9600);
  
  WiFi.mode( WIFI_OFF );    // we disable WiFi, coming from DeepSleep, as we do not need it right away
  WiFi.forceSleepBegin();
  delay( 1 );

  /*// Try to read WiFi settings from RTC memory
  bool rtcValid = false;
  if( ESP.rtcUserMemoryRead( 0, (uint32_t*)&rtcData, sizeof( rtcData ) ) ) {
  // Calculate the CRC of what we just read from RTC memory, but skip the first 4 bytes as that's the checksum itself.
  uint32_t crc = calculateCRC32( ((uint8_t*)&rtcData) + 4, sizeof( rtcData ) - 4 );
  if( crc == rtcData.crc32 ) {
    rtcValid = true;
  }
  }*/

  ESP.rtcUserMemoryRead( 0, (uint32_t*)&bssid, sizeof( bssid ) );
  ESP.rtcUserMemoryRead( 8*6, &canal, sizeof( canal ) );

  WiFi.forceSleepWake();  //Switch Radio back On
  delay( 1 );
  WiFi.persistent( false ); // Disable the WiFi persistence.  The ESP8266 will not load and save WiFi settings unnecessarily in the flash memory.
  WiFi.mode( WIFI_STA );  // Bring up the WiFi connection
  WiFi.config( ip,dns, gateway, subnet );

  /*Serial.println();
  Serial.println(String(rtcData.ap_mac[0]));
  Serial.println(String(rtcData.ap_mac[1]));
  Serial.println(String(rtcData.ap_mac[2]));
  Serial.println(String(rtcData.ap_mac[3]));
  Serial.println(String(rtcData.ap_mac[4]));
  Serial.println(String(rtcData.ap_mac[5]));*/
            
  /*if( rtcValid ) 
  {
  WiFi.begin( WLAN_SSID, WLAN_PASSWD, rtcData.channel, rtcData.ap_mac, true );    //quick connection
  }
  else 
  {
  WiFi.begin( WLAN_SSID, WLAN_PASSWD ); // The RTC data was not valid, so make a regular connection
  }*/
  
  WiFi.begin( WLAN_SSID, WLAN_PASSWD, canal, bssid, true );    //quick connection
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Waiting for conection");
    delay(5);
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi Conected");
  }

  /*// Write current connection info back to RTC
  rtcData.channel = WiFi.channel();
  memcpy( rtcData.ap_mac, WiFi.BSSID(), 6 ); // Copy 6 bytes of BSSID (AP's MAC address)
  rtcData.crc32 = calculateCRC32( ((uint8_t*)&rtcData) + 4, sizeof( rtcData ) - 4 );
  ESP.rtcUserMemoryWrite( 0, (uint32_t*)&rtcData, sizeof( rtcData ) );*/



  memcpy( bssid, WiFi.BSSID(), 6 ); //Copiar os 6bytes do MAC address
  /*Serial.println();
  Serial.println(String(bssid[0]));
  Serial.println(String(bssid[1]));
  Serial.println(String(bssid[2]));
  Serial.println(String(bssid[3]));
  Serial.println(String(bssid[4]));
  Serial.println(String(bssid[5]));*/
  ESP.rtcUserMemoryWrite( 0, (uint32_t*)&bssid, sizeof( bssid ) );
  ESP.rtcUserMemoryWrite( 8*6, &canal, sizeof( canal ));


  
  WiFi.disconnect( true );
  delay( 1 );
  ESP.deepSleep( SLEEPTIME, WAKE_RF_DISABLED ); // WAKE_RF_DISABLED to keep the WiFi radio disabled when we wake up
}

void loop() 
{
}

// the CRC routine
uint32_t calculateCRC32( const uint8_t *data, size_t length ) 
{
  uint32_t crc = 0xffffffff;
  while( length-- ) {
    uint8_t c = *data++;
    for( uint32_t i = 0x80; i > 0; i >>= 1 ) {
      bool bit = crc & 0x80000000;
      if( c & i ) {
        bit = !bit;
      }
      crc <<= 1;
      if( bit ) {
        crc ^= 0x04c11db7;
      }
    }
  }
  return crc;
}

#include <bibliotecas.h>

String host = "script.google.com";
int httpsPort = 443;

String GAS_ID="AKfycbwT1wa5zj8vJ5HfNJbkjFAaKWO28ACZHhboZ3Ebi5raXaXJejtfGNYl7IorFEH8FVNWkQ"; // google sheet spreadsheet script ID

WiFiClientSecure client;

void setup_googleSheets()
{
  client.setInsecure();
  
  //Serial.print("connecting to ");
  //Serial.println(host);
  client.connect(host, httpsPort);
  if (!client.connect(host, httpsPort)) 
  {
    Serial.println("connection to Google sheets failed");
    return;
  }
  //Serial.println("connection sucessful");
}

void send_to_googleSheets(String DeviceID, String BatteryVoltage, String BatimentosCardiacos, String NiveisOxigenio,String Aceleracao, String Temperatura, String Checksum)
{            
  String url = "/macros/s/" + GAS_ID + "/exec?" + "value1=" + DeviceID + "&" + "value2=" + BatteryVoltage + "&" + "value3=" + BatimentosCardiacos + "&"
  + "value4=" + NiveisOxigenio + "&" + "value5=" + Aceleracao + "&" + "value6=" + Temperatura + "&" + "value7=" + Checksum + "&";
  Serial.print("requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
}

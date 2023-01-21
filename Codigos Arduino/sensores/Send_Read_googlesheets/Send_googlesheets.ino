#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Vodafone-DBCD72"; // Your wifi name or SSID.
const char* password = "2D7KNEEGyc93VFHF"; // Your wifi password.

const char* host = "script.google.com";
const int httpsPort = 443;

String GAS_ID="AKfycbwT1wa5zj8vJ5HfNJbkjFAaKWO28ACZHhboZ3Ebi5raXaXJejtfGNYl7IorFEH8FVNWkQ"; //--> spreadsheet script ID

WiFiClientSecure client;

void setup() 
{
Serial.begin(9600); 
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("Successfully connected");
  client.setInsecure();


  sendData();
}
 
void loop() 
{

//delay(5000);
}




void getnewURL()
{
String _redirHost;
String _redirUrl;

  
  //while (client.connected())
//{
  Serial.println("DEBUG1");
  while(client.available())
  {

    //String linew;                             // LER O OUTPUT TODO COM OS ERROS E LOCATION QUE VÊM DEPOIS DO GET
    //linew = client.readStringUntil('\n');
    //int index = linew.indexOf("Location");
    //Serial.println(linew);
    //if(index >= 0)
    //Serial.println(linew);

    bool flag = client.find("Location: ");
    Serial.println(flag);
    if (flag == 1)                            // SE EXISTIR UM ELEMENTO LOCATION, LER ESSA LINHA
    {
    client.readStringUntil('/');              // DESCARTAR OS DOIS // DEPOIS DE HTTPS
    client.readStringUntil('/');
    _redirHost = client.readStringUntil('/');
    _redirUrl = String('/') + client.readStringUntil('\n');
    Serial.println(_redirHost);
    Serial.println(_redirUrl);
    break;
    }
  }
//}
  bool _keepAlive = true;
   String _Request =  String("GET ") + _redirUrl + " HTTP/1.1\r\n" +
                          "Host: " + _redirHost + "\r\n" +
                          "User-Agent: ESP8266\r\n" +
                          (_keepAlive ? "" : "Connection: close\r\n") + 
                          "\r\n\r\n";

  client.print(_Request);

  Serial.println("Novo URL enviado");
  client.find("\r\n\r\n");              // DESCARTAR OS 3 PARAMETROS QUE VEM ANTES
  client.find("\r\n\r\n");
  client.find("\r\n\r\n");
  while (client.connected())
  {
  String linew;                             
  client.readStringUntil('\n');           // DESCARTAR A PRIMEIRA LINHA
  linew = client.readStringUntil('\n');
  Serial.println(linew);
  break;
  }
}

int geterrorcode()
{
  String line;
  int statusCode;
  String reasonPhrase;
  unsigned int pos = -1;
  unsigned int pos2 = -1;
  // Skip any empty lines
  do{
    line = client.readStringUntil('\n');
  }while(line.length() == 0);
  Serial.println(line);
  pos = line.indexOf("HTTP/1.1 ");
  pos2 = line.indexOf(" ", 9);
  
  if (!pos){
    statusCode = line.substring(9, pos2).toInt();
    reasonPhrase = line.substring(pos2+1, line.length()-1);
  }
  else{
    Serial.println("Error! No valid Status Code found in HTTP Response.");
    statusCode = 0;
    reasonPhrase = "";
  }
  Serial.println(statusCode);
  return statusCode;
}      


void sendData() 
{
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.println("connection sucessful");

  String url = "/macros/s/" + GAS_ID + "/exec?";
  url = url + "value1=1&value2=10";
  Serial.print("requesting URL: ");
  Serial.println(url);

    // Clear the input stream of any junk data before making the request
   while(client.available())
    client.read();
  
  bool _keepAlive = true;
  String _Request =  String("GET ") + url + " HTTP/1.1\r\n" +
                          "Host: " + host + "\r\n" +
                          "User-Agent: ESP8266\r\n" +
                          (_keepAlive ? "" : "Connection: close\r\n") + 
                          "\r\n\r\n";

  client.print(_Request);
  int errorcode = geterrorcode();
  if(errorcode == 302)                          // Se tiver um URL redirect
  {
  getnewURL();
  }
  Serial.println("Finished");
}



  

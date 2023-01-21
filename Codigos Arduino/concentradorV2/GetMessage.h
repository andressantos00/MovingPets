/*String host = "script.google.com";
int httpsPort = 443;

String GAS_ID="AKfycbwT1wa5zj8vJ5HfNJbkjFAaKWO28ACZHhboZ3Ebi5raXaXJejtfGNYl7IorFEH8FVNWkQ"; // google sheet spreadsheet script ID

WiFiClientSecure client;

int line_position_count[200];

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

void send_to_googleSheets(String DeviceID, String BatteryVoltage, String BatimentosCardiacos, String NiveisOxigenio,String Aceleracao, String Temperatura, String Checksum, String Linha)
{            
  String url = "/macros/s/" + GAS_ID + "/exec?" + "value1=" + DeviceID + "&" + "value2=" + BatteryVoltage + "&" + "value3=" + BatimentosCardiacos + "&" + "value4=" + NiveisOxigenio + "&" + "value5=" + Aceleracao + "&" + "value6=" + Temperatura + "&" + "value7=" + Checksum + "&" + "value8=" + Linha;
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");
}

void GetMessage()
{
  WiFiClient client = server.available();
  //Serial.println("Qual é a mensagem?");
  
  if (client) 
  {
  String DeviceID = client.readStringUntil('\r');
  String BatteryVoltage = client.readStringUntil('\r');
  String BatimentosCardiacos = client.readStringUntil('\r');
  String NiveisOxigenio = client.readStringUntil('\r');
  //String x_acelerometro = client.readStringUntil('\r');
  //String y_acelerometro = client.readStringUntil('\r');
  //String z_acelerometro = client.readStringUntil('\r');
  String Aceleracao = client.readStringUntil('\r'); 
  String Temperatura = client.readStringUntil('\r');
  String Checksum = client.readStringUntil('\r');

  // CHECK IF CHECKSUM IS VALID
  // SEND TO DATABASE
  int a = DeviceID.toInt();

  int linha = (a - 1)*100 + line_position_count[a] + 1;
  line_position_count[a] = line_position_count[a] + 1;

  if(line_position_count[a] >= 100)
  {
  line_position_count[a] = 0;
  }
  
  String package = DeviceID + " " + BatteryVoltage + " " + BatimentosCardiacos + " "  + NiveisOxigenio 
            + " " + Aceleracao + " " + Temperatura + " " + Checksum + " ";
  Serial.println(package);

  setup_googleSheets();
  send_to_googleSheets(DeviceID,BatteryVoltage,BatimentosCardiacos,NiveisOxigenio,Aceleracao,Temperatura,Checksum,String(linha));
  client.flush();
  }
}*/

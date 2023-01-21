#include <FirebaseArduino.h>
#include <Arduino.h>
#include <NTPClient.h>

#define FIREBASE_HOST "movingpetsdatabase-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "3OdVT59WD9887xX7vxcLmQsTr6XXeCCwzZBx4YEK"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

int line_position_count[200];
WiFiClientSecure client;


void setup_real_time_date()
{
  timeClient.begin();
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(0);
}

void setup_firebase()
{
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void get_and_send_firebase()
{
  WiFiClient client = server.available();
  //Serial.println("Qual é a mensagem?");
  
  if (client) 
  {
  String DeviceID = client.readStringUntil('\r');
  String BatteryVoltage = client.readStringUntil('\r');
  String BatimentosCardiacos = client.readStringUntil('\r');
  String NiveisOxigenio = client.readStringUntil('\r');
  String Aceleracao = client.readStringUntil('\r'); 
  String Temperatura = client.readStringUntil('\r');
  String Checksum = client.readStringUntil('\r');


  timeClient.update();
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int currentMonth = ptm->tm_mon+1;
  int currentYear = ptm->tm_year+1900;
  int monthDay = ptm->tm_mday;
  
  String formattedTime = timeClient.getFormattedTime();
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);

  int a = DeviceID.toInt();

  int linha = (a - 1)*9 + line_position_count[a] + 1;
  line_position_count[a] = line_position_count[a] + 1;

  if(line_position_count[a] >= 9)
  {
  line_position_count[a] = 0;
  }
  
  String package = DeviceID + " " + BatteryVoltage + " " + BatimentosCardiacos + " "  + NiveisOxigenio 
            + " " + Aceleracao + " " + Temperatura + " " + Checksum + " ";
  Serial.println(package);

  //Criar Path
  String path_data_hora = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/Data&Hora";
  String path_BatimentosCardiacos = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/BatimentosCardiacos";
  String path_BatteryVoltage = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/BatteryVoltage";
  String path_NiveisOxigenio = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/NiveisOxigenio";
  String path_Aceleracao = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/Aceleracao";
  String path_Temperatura = "Coleiras/Device_" + DeviceID + "/ " + String(linha) + "/Temperatura";

  Firebase.setString(path_data_hora, currentDate + " " + formattedTime);
  Firebase.setString(path_BatimentosCardiacos, BatimentosCardiacos);
  Firebase.setString(path_BatteryVoltage, BatteryVoltage);
  Firebase.setString(path_NiveisOxigenio, NiveisOxigenio);
  Firebase.setString(path_Aceleracao, Aceleracao);
  Firebase.setString(path_Temperatura, Temperatura);

  client.flush();
  }
}

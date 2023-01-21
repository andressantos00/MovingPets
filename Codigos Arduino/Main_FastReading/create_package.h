String package;
String package_forprint;
float checksum = 0;

void SendMessage()
{
  if(client.connect(server, 80))  // Send message
  {
    client.println(package);
    client.flush();
  }
  Serial.println(package_forprint);
  Serial.println("Package sent");
}

void create_send_package(int DeviceID,float BatteryVoltage,int BatimentosCardiacos,float NiveisOxigenio,float Aceleracao,float Temperatura)
{
  checksum = DeviceID + BatteryVoltage + BatimentosCardiacos + NiveisOxigenio + Aceleracao + Temperatura;
  
  package_forprint = String(DeviceID) + " " + String(BatteryVoltage) + " " + String(BatimentosCardiacos) + " "  + String(NiveisOxigenio) 
            + " " + String(Aceleracao) + " " + String(Temperatura) + " " + String(checksum) + " ";
            
  package = String(DeviceID) + "\r" + String(BatteryVoltage) + "\r" + String(BatimentosCardiacos) + "\r"  + String(NiveisOxigenio) 
            + "\r" + String(Aceleracao) + "\r" + String(Temperatura) + "\r" + String(checksum) + "\r"; 
            
  SendMessage();
  
  package = "";               // resetar as strings
  package_forprint = "";
}

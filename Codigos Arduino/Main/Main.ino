#include "acelerometro.h"
#include "oximeter.h"
#include "wifi.h"
#include "leitor_bateria.h"
#include "temperatura.h"
#include "create_package.h"


unsigned long int timer_acelerometro = 0;
unsigned long int timer_oximeter = 0;
unsigned long int timer_temperatura = 0;
unsigned long int timer_battery = 0;
unsigned long int timer_package = 0;
unsigned long int timer_prints = 0;
unsigned long int timer_sensores = 0;


int DeviceID = 1;
float BatteryVoltage;
float BatimentosCardiacos;
float NiveisOxigenio;
float acelerometro[3];
float Aceleracao;
float Temperatura;
float Calibracao_temperatura = 1.9;

IPAddress ip( 192, 168, 25, DeviceID + 1);// pick your own suitable static IP address
IPAddress gateway( 192, 168, 25, 1 ); // may be different for your network
IPAddress subnet( 255, 255, 255, 0 ); // may be different for your network (but this one is pretty standard)
IPAddress dns(192,168,25,1);


void setup()                                 
{
  Serial.begin(9600);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  //pinMode(A0, INPUT);
  //ADC_MODE(33);

  WiFi.disconnect(); 
  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();
  delay(1);

  setup_acelerometro();         //Fazer uma média de 1segundo
  setup_oximeter();
  setup_temperatura();


  timer_sensores = millis();
  while(millis() - timer_sensores <= 60000)
  {
  update_oximeter();
  delay(10);
  update_acelerometro(&acelerometro[0]);
  delay(10);
  }
  Aceleracao = update2_acelerometro();
  update2_oximeter(&BatimentosCardiacos,&NiveisOxigenio);

    
  Temperatura = update_temperatura() + Calibracao_temperatura;
  BatteryVoltage = update_battery();
  wifi_setup(ip,dns, gateway, subnet);
  ReCheckConection();
  //create_send_package(DeviceID,BatteryVoltage,BatimentosCardiacos,NiveisOxigenio,&acelerometro[0],Temperatura);
  create_send_package(DeviceID,BatteryVoltage,BatimentosCardiacos,NiveisOxigenio,Aceleracao,Temperatura);

  WiFi.disconnect( true );
  delay( 1 );
  Serial.println("vou dormir 10segundos");
  ESP.deepSleep(10e6, WAKE_RF_DISABLED);
}

void loop()
{
/*//------------------------- acelerometro --------------------------------
  if(millis() - timer_acelerometro >= 1000)
  {
  update_acelerometro(&acelerometro[0]);
  timer_acelerometro = millis();
  }
//------------------------------ oximeter ---------------------------
  if(millis() - timer_oximeter >= 10)
  {
  update_oximeter();
  timer_oximeter = millis();
  }
//---------------------- temperatura -----------------------------------
  if(millis() - timer_temperatura >= 1000)
  {
  Temperatura = update_temperatura();
  timer_temperatura = millis();
  }

//---------------------- Batery_voltage -----------------------------------
  if(millis() - timer_battery >= 1000)
  {
  update_battery();
  timer_battery = millis();
  }

//---------------------- create package -----------------------------------
  if(millis() - timer_package >= 1000)
  {
  ReCheckConection();
  create_send_package(DeviceID,BatteryVoltage,BatimentosCardiacos,NiveisOxigenio,&acelerometro[0],Temperatura);
  timer_package = millis();
  }

  //---------------------- prints -----------------------------------
  //if(millis() - timer_prints >= 1000)
  //{
  //print_acelerometro();
  //print_oximeter();
  //print_temperatura();
  //timer_prints = millis();
  //}*/
}

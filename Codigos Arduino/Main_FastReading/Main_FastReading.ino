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
float Calibracao_temperatura = 2.9;

IPAddress ip( 192, 168, 25, DeviceID + 1);// pick your own suitable static IP address
IPAddress gateway( 192, 168, 25, 1 ); // may be different for your network
IPAddress subnet( 255, 255, 255, 0 ); // may be different for your network (but this one is pretty standard)
IPAddress dns(192,168,25,1);


void setup()                                 
{
  Serial.begin(9600);
  Serial.println("hello");
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  //ADC_MODE(33);

}

void loop()
{
  delay(100);
  setup_acelerometro();         //Fazer uma média de 1segundo
  delay(100);
  setup_oximeter();
  setup_temperatura();
  timer_sensores = millis();
  while(millis() - timer_sensores <= 20000)
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
  delay(500);
}

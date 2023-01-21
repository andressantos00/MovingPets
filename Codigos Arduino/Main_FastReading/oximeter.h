#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox;
long int timer_oxi = 0;

void setup_oximeter()
{
  pox.resume();
  while(!pox.begin())
  {
  Serial.println("Initializing pulse oximeter..");  
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on by making the voltage HIGH
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage HIGH
  delay(100);   
  }
  Serial.println("SUCESS pulse oximeter");
  pox.setIRLedCurrent(MAX30100_LED_CURR_50MA);
}

void update_oximeter()
{
    //pox.resume();
    //timer_oxi = millis();
    //while(millis() - timer_oxi <= 4000)
    //{
    pox.update();
    //delay(10);
    //}

}
void update2_oximeter(float* BatimentosCardiacos,float* NiveisOxigenio)
{
   *BatimentosCardiacos = pox.getHeartRate();
   *NiveisOxigenio=pox.getSpO2();
   Serial.print("Heart rate:");
   Serial.print(pox.getHeartRate());
   Serial.print("bpm / SpO2:");
   Serial.print(pox.getSpO2());
   Serial.println("%");
   //pox.setIRLedCurrent(MAX30100_LED_CURR_0MA);
   //delay(1);
   pox.shutdown();
   delay(1);
}



void print_oximeter()
{
  Serial.print("Heart rate:");
  Serial.print(pox.getHeartRate());
  Serial.print("bpm / SpO2:");
  Serial.print(pox.getSpO2());
  Serial.println("%");
}

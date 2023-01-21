#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire); // Pass our oneWire reference to Dallas Temperature. 



void setup_temperatura()
{    
  sensors.begin();
  sensors.setResolution(11);  // set the resolution to 11 bit (Each Dallas/Maxim device is capable of several different resolutions)
}

float update_temperatura()
{
  sensors.requestTemperatures();      // ATENCAO ESTA FUNCAO DEMORA MUITO TEMPO A TER FEEDBACK
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temp C: ");
  Serial.println(tempC);
  return(tempC);
}

void print_temperatura()
{ 
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temp C: ");
  Serial.println(tempC);
}

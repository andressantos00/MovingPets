// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  // set the resolution to 11 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(11);
}

void printTemperature()
{
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temp C: ");
  Serial.println(tempC);
}

void loop(void)
{ 
  sensors.requestTemperatures(); // Send the command to get temperatures
  printTemperature(); // Use a simple function to print out the data
}

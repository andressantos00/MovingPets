#include <Wire.h>
#include <Adafruit_Sensor.h>    // Adafruit  sensor library
#include <Adafruit_ADXL345_U.h>  // ADXL345 library

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();   // ADXL345 Object
sensors_event_t event;

float a1 = 0;
float sum = 0;
long int timer_acel = 0;
long int counter_acel = 0;

void setup_acelerometro()
{
    if(!accel.begin())   // Ligar e verificar se o módulo está ligado
    {
    Serial.println("ADXL345 not detected");
    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on by making the voltage HIGH
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage HIGH
    delay(100);    
    }
    Serial.println("SUCESS acelerometer");
    digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on by making the voltage HIGH
}

void update_acelerometro(float *acelerometro)
{
    //timer_acel = millis();
    //while(millis() - timer_acel <= 2000)
    //{
    
    accel.getEvent(&event); //LER OS VALORES DO ACELEROMETRO
    //acelerometro[0] = event.acceleration.x;
    //acelerometro[1] = event.acceleration.y;
    //acelerometro[2] = event.acceleration.z;
    //Serial.println("Disntãncia:");
    a1 = sqrt( (sq(event.acceleration.x) + sq(event.acceleration.y) + sq(event.acceleration.z)));
    sum = sum + a1;
    //Serial.println(a1);
    counter_acel = counter_acel +1;
    
    //delay(10);

}

float update2_acelerometro()
{
    Serial.println("Distância média:");
    Serial.println(sum/counter_acel);
    float Aceleracao = sum/counter_acel;
    return Aceleracao;
}



void print_acelerometro()
{
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print("  ");
  Serial.print("Y: ");
  Serial.print(event.acceleration.y);
  Serial.print("  ");
  Serial.print("Z: ");
  Serial.print(event.acceleration.z);
  Serial.print("  ");
  Serial.println("m/s^2 ");     
}

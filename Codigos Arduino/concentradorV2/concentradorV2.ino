#include "bibliotecas.h"

void setup() 
{
  Serial.begin(9600);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  button_setup();
  setup_start_config();
  //setup_wifi();
  setup_firebase();
}
 
void loop() 
{
  ReCheckConection();
  //Serial.println("debug1");
  get_and_send_firebase();
  button_read();
  //wp_run();
  delay(1);
}

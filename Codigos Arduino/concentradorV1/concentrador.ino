#include "bibliotecas.h"

void setup() {
  Serial.begin(9600);
  setup_AP();
  setup_wifi();
}
 
void loop() 
{
  //ReCheckConection();
  GetMessage();
  delay(1);
}

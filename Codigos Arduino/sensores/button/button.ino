#include <EasyButton.h>

#define BUTTON_PIN D5

bool pullup = false;
bool invert = false;
uint8 debounce = 40;

EasyButton button(BUTTON_PIN, debounce, pullup, invert);

void onPressedForDuration() 
{
    Serial.println("Button has been pressed for the given duration!");
}

void onPressed() 
{
    Serial.println("Button has been pressed!");
}

void setup() 
{
  Serial.begin(9600);
  Serial.println();
  button.begin();
  button.onPressed(onPressed);
  button.onPressedFor(3000, onPressedForDuration);  // Pressed durante 3segundos
}

void loop() 
{ 
    button.read();
    delay(1);
}

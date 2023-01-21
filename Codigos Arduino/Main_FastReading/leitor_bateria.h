float update_battery()
{
  int a = analogRead(A0);
  float volts = (a * 3.3 ) / 1024.0 * 2;
  Serial.println("Lendo Voltagem Bateria");
  Serial.print(volts);
  Serial.println(" V");
  return volts;
}

float checkTemp() {
  delay(2000);           // wait for 2 seconds for the sensor to stabilize
  float temperature = dht.readTemperature();   // read the temperature in Celsius
  return temperature;
}

State compareTemp(float x) {
  if (x < 20) {
    Serial.println("WARNING: LOW TEMPERATURE");
    return LOWER;
  }
  if (x > 30) {
    Serial.println("WARNING: HIGH TEMPERATURE");
    return HIGHER;
  }
  return ACCEPT;
}


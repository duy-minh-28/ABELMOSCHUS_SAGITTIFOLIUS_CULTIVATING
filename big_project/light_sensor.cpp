#include "light_sensor.h"


void initLightSensor(){
	pinMode(LIGHT_SENSOR_PIN,INPUT);
}
// Function to check the light intensity and return a float value
float checkLight() {
  // Read the analog voltage from the sensor
  int sensorValue = analogRead(LIGHT_SENSOR_PIN);
  
  // Convert the sensor value to light intensity in lux
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage
  float lux = voltage * 100.0; // Convert voltage to lux
  
  return lux;
}

// Function to check if the light is considered "dark"
boolean isDark(float luxValue) {
  if (luxValue < 100) {
    return true;
  }
  else {
    return false;
  }
}

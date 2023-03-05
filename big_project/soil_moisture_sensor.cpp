#include "soil_moisture_sensor.h"

int soilMoistureValue = 0;

void initSoilMoistureSensor(){
	pinMode(SOIL_MOISTURE_SENSOR_PIN,INPUT);
}


int readMoisture() {
  soilMoistureValue = analogRead(SOIL_MOISTURE_SENSOR_PIN); // read the value from the soil moisture sensor
  return soilMoistureValue;
}

soilMoistureState compareMoisture(int value) {
  value = readMoisture(); // read the value from the soil moisture sensor
  if (value < 300) {
    return dry; // soil is dry
  }
  if (value >= 300 && soilMoistureValue < 700) {
    return moist; // soil is moderately moist
  }
  return wet; // soil is wet
}

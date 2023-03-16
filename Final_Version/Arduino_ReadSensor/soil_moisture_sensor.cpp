#include "soil_moisture_sensor.h"

int soilMoistureValue = 0;

void initSoilMoistureSensor(){
	pinMode(SOIL_MOISTURE_SENSOR_PIN,INPUT);
}


int readMoisture() {
  int dryValueADC = 1023;
  int wetValueADC = 0;

  int dryPercent = 0;
  int wetPercent = 100;
  
  int soilMoistureADC = analogRead(SOIL_MOISTURE_SENSOR_PIN); // read the value from the soil moisture sensor
  soilMoistureValue = map(soilMoistureADC,dryValueADC,wetValueADC,dryPercent,wetPercent);
  return soilMoistureValue;
}

soilMoistureState compareMoisture(int value) {
  value = readMoisture(); // read the value from the soil moisture sensor
  if (value < 30) {
    return dry; // soil is dry
  }
  if (value >= 30 && soilMoistureValue < 70) {
    return moist; // soil is moderately moist
  }
  return wet; // soil is wet
}

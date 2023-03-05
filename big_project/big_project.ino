#include "soil_moisture_sensor.h"
#include "dht22.h"
#include "light_sensor.h"

String soilMoistureMessage(int sensorValue) {
  String message;
  if (compareMoisture(sensorValue) == dry) {
    message = "Soil is too dry";
  } else if (compareMoisture(sensorValue) == moist) {
    message = "Soil is OK";
  } else {
    message = "Soil is too wet";
  }
  return message;
}

String lightMessage(float sensorValue) {
  String message;
  if (isDark(sensorValue)) {
    message = "Lacks of light";
  } else {
    message = "Light is OK";
  }
  return message;
}
void setup() {
  // put your setup code here, to run once:
  initSoilMoistureSensor();
  initLightSensor();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int soilMoistureValue = readMoisture();
  float lightValue = checkLight();
  Serial.print("\nSoil Moisture: ");
  Serial.print(soilMoistureValue);
  Serial.println("%");
  Serial.println(soilMoistureMessage(soilMoistureValue));
  Serial.print("Light: ");
  Serial.println(lightValue);
  Serial.println(lightMessage(lightValue));
  delay(2000);
}

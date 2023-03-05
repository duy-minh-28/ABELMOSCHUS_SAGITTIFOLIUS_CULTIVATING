#include "soil_moisture_sensor.h"
#include "dht22.h"
#include "light_sensor.h"

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
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);
  Serial.print("Light: ");
  Serial.println(lightValue);
  delay(500);
}

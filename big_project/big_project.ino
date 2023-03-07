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
  //message = tempValue/lightValue/soilMoistureValue/tempCompare/lightCompare/soilMoistureCompare
  String message = "";
  int soilMoistureValue = readMoisture();
  float lightValue = checkLight();
  float dhtValue = checkTemp();
  if (isnan(dhtValue)) {
    message += "DHT is not connected/";
  }
  message += ("%f", lightValue);
  message += "/";
  message += ("%d", soilMoistureValue);
  message += "%";
  message += "/";
  message += ("%d", compareTemp(dhtValue));//0 -> NOT CONNECTED
  message += "/";
  message += ("%d", isDark(lightValue));
  message += "/";
  message += ("%d", compareMoisture(soilMoistureValue));
  Serial.println(message);
  delay(2000);
}

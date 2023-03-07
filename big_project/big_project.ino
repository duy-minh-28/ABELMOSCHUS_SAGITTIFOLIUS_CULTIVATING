#include "soil_moisture_sensor.h"
#include "dht22.h"
#include <SoftwareSerial.h>
#include "light_sensor.h"

SoftwareSerial espSerial(5, 6);

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

String tempMessage(float dhtValue) {
  String message;
  if (compareTemp(dhtValue) == 0) {
    message = "DHT is not connected";
  } else if (compareTemp(dhtValue) == 1) {
    message = "Temperature is too low";
  } else if (compareTemp(dhtValue) == 2) {
    message = "Temperature is OK";
  } else if (compareTemp(dhtValue) == 3) {
    message = "Temperature is too high";
  }
  return message;
}

void setup() {
  // put your setup code here, to run once:
  initSoilMoistureSensor();
  initLightSensor();
  Serial.begin(115200);
  espSerial.begin(115200);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //message = tempValue/lightValue/soilMoistureValue/tempCompare/lightCompare/soilMoistureCompare
  String message = "";
  int soilMoistureValue = readMoisture();
  float lightValue = checkLight();
  float dhtValue = checkTemp();
  if (isnan(dhtValue)) {
    message += "DHT is not connected";
  }
  else {
    message += ("%d", dhtValue);   
  }
  message += "/";
  message += ("%f", lightValue);
  message += "/";
  message += ("%d", soilMoistureValue);
  message += "%";
  message += "/";
  message += tempMessage(dhtValue);
  message += "/";
  message += lightMessage(lightValue);
  message += "/";
  message += soilMoistureMessage(soilMoistureMessage);
  Serial.println(message);
  espSerial.println(message);
  delay(3000);
}

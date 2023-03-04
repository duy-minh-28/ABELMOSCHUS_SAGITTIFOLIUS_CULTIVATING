int soilPin = A0;     // the analog pin the soil moisture sensor is connected to
int soilMoistureValue = 0; // variable to store the soil moisture level


int readMoisture() {
  soilMoistureValue = analogRead(soilPin); // read the value from the soil moisture sensor
  return soilMoistureValue;
}

state compare() {
  soilMoistureValue = readMoisture(); // read the value from the soil moisture sensor
  if (soilMoistureValue < 300) {
    return dry; // soil is dry
  }
  if (soilMoistureValue >= 300 && soilMoistureValue < 700) {
    return moist; // soil is moderately moist
  }
  return wet; // soil is wet
}




// Define the analog input pin used by the sensor
const int sensorPin = A0;

// Function to check the light intensity and return a float value
float check() {
  // Read the analog voltage from the sensor
  int sensorValue = analogRead(sensorPin);
  
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

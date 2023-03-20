//Arduino IDE runs in C++ so this need to be defined for it to calls C

#include<Arduino.h>

#define SOIL_MOISTURE_SENSOR_PIN A1
//Start coding here
enum soilMoistureState {
	dry,
	moist,
	wet} ; // define the different states of soil moisture
void initSoilMoistureSensor();
int readMoisture();
soilMoistureState compareMoisture(int value);

//Init Sensor -> void

//Read Sensor Value -> int

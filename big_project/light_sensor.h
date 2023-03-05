//Arduino IDE runs in C++ so this need to be defined for it to calls C

#include<Arduino.h>
#define LIGHT_SENSOR_PIN A0

//Start coding here
void initLightSensor();
float checkLight();
boolean isDark(float luxValue);

//Init Sensor -> void

//Read Sensor Value -> int

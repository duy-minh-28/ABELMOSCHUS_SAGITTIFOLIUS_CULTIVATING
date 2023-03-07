//Arduino IDE runs in C++ so this need to be defined for it to calls C

#include<Arduino.h>
#include<DHT.h>

#define DHT22_PIN 2
#define DHTTYPE DHT22 

enum DHT22State {
  NOT_CONNECTED,
  LOWER,
  ACCEPT,
  HIGHER
};

void initDHT22();
float checkTemp();
DHT22State compareTemp(float x);

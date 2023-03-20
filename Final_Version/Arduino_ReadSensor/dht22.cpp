#include "dht22.h"

DHT dht(DHT22_PIN, DHTTYPE);
void initDHT22() {
    dht.begin();
}

float checkTemp() {
    //delay(2000);           // wait for 2 seconds for the sensor to stabilize
    float temperature = dht.readTemperature();   // read the temperature in Celsius
    return temperature;
}

//DHT22State compareTemp(float x) {
//    if (isnan(x)) {
//      return NOT_CONNECTED;
//    }
//    else if (x < 20) {
//      return LOWER;
//    }
//    else if (x > 30) {
//      return HIGHER;
//    }
//    return ACCEPT;
//}

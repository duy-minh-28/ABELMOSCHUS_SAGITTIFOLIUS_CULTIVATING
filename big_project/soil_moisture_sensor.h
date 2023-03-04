//Arduino IDE runs in C++ so this need to be defined for it to calls C
#ifdef __cplusplus 
 extern "C" {
#endif

#include<Arduino.h>
//Start coding here
enum state {
	dry,
	moist,
	wet}; // define the different states of soil moisture
int readMoisture() {}
state compareMoisture();

//Init Sensor -> void

//Read Sensor Value -> int


#ifdef __cplusplus
}
#endif


/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1XTl0wuGMstNlO23tMfWXRHrSwI5uFNy";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "IoT1603";
char pass[] = "123123123";

#define LED D5

void setup(){
    // Debug console
    Serial.begin(9600);
  
    //Blynk.begin(auth, ssid, pass);
    // You can also specify server:
    //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
    Blynk.begin(auth, ssid, pass, IPAddress(192,168,2,148), 8080);
  
    pinMode(LED, OUTPUT);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

int button;
BLYNK_WRITE(V1){
    button = param.asInt();
    if(button == 1){
        digitalWrite(LED, HIGH); 
    }else{
        digitalWrite(LED, LOW); 
    }
    
}


void loop(){ 
    Blynk.run();
    if (Serial.available()) {
        Serial.write(Serial.read());
    }
}

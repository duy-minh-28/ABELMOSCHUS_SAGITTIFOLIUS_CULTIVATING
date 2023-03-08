#define BLYNK_PRINT Serial 

//#define BLYNK_TEMPLATE_ID   "ESP8266"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "jCpbhR1wF4OC0S89sFaqpiRhCOP5NAud";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TuanVM2";
char pass[] = "mangfptkemlam";

#define LED D5

void setup(){
    // Debug console
    Serial.begin(9600);
    Serial.print("--Starting--"); 
    
    //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
    Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,10), 8080);
    
    pinMode(LED, OUTPUT);

    String myString = "125";
    int myInt = myString.toInt();
    Serial.println(myInt);
    Serial.println("1");

    //checking
    Blynk.virtualWrite(V10, "abc");
    String num = "10";
    int num2 = num.toInt();
    Blynk.virtualWrite(V11, num2);
    
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

int a;
float b;
float c;
String x;
String data1;
String data2;
String data3; 
String data4; 
String data5; 
String data6; 
int count=0;  
  
void getting_data() { 

    if (Serial.available() > 0) {
        String received = Serial.readString();
        //Code to split each elements from received string
        int first = 0;
        int last = 0;
        int index = 0;
        while (last >= 0) {
          last = received.indexOf('/', first);
          if (last >= 0) {
            String part = received.substring(first, last);
            switch (index) {
              case 0 : data1 = part; break;
              case 1 : data2 = part; break;
              case 2 : data3 = part; break;
              case 3 : data4 = part; break;
              case 4 : data5 = part; break;
            }
            Serial.println(part);
            first = last + 1;
            index++;
          }
        }
        //Ex: 10/12.0/22.0/abc/def/ghk
        data6 = received.substring(first);
        Serial.print("data1: "); Serial.println(data1);
        Serial.print("data2: "); Serial.println(data2);
        Serial.print("data3: "); Serial.println(data3);
        Serial.print("data4: "); Serial.println(data4);
        Serial.print("data5: "); Serial.println(data5);
        Serial.print("data6: "); Serial.println(data6); 

        //Serial.print("data3: "); Serial.println(data3); 
        //a = data3.toInt();
        Blynk.virtualWrite(V0, data1);
        Blynk.virtualWrite(V1, data2);
        Blynk.virtualWrite(V2, data3);
    }
 
}


int button;
BLYNK_WRITE(V3){
    button = param.asInt();
    if(button == 1){
      digitalWrite(LED, HIGH); 
    }else{
      digitalWrite(LED, LOW); 
    }
}

void loop(){  

    
    getting_data(); 
    Blynk.run(); 
}

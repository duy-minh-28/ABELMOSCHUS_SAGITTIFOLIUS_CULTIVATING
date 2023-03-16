#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

const char* ssid = "MINH";
const char* password = "123456789";
String ipAddress = "192.168.98.31";
 
int value = 31;
//float temp_value = 30;
//float light_value = 50;
//float soil_moisture_value = 40; 
 
String currentDate;
String temp_value;
String light_value;
String soil_moisture_value;

const unsigned long eventInterval = 5000;
unsigned long previousTime = 0;

WiFiClient client;
void setup() {
    Serial.begin(115200);
    delay(10);
  
    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
  
    WiFi.begin(ssid, password);
  
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");

    // Initialize a NTPClient to get time
    timeClient.begin();  
    timeClient.setTimeOffset(25200);
    
    // Make GET request
    Serial.println("Making GET request...");

    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

void get_data_esp(){ 
    Serial.println("###get_data_esp()###");
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
                if (index == 0) {
                    temp_value = part;
                } else if (index == 1) {
                    light_value = part;
                }
                Serial.println(part);
                first = last + 1;
                index++;
            }
        } 
        soil_moisture_value = received.substring(first);
        Serial.println(temp_value); 
        Serial.println(light_value); 
        Serial.println(soil_moisture_value); 
    }
}
 
void getdate(){
    timeClient.update();
    String formattedTime = timeClient.getFormattedTime();
    time_t epochTime = timeClient.getEpochTime(); 
    //Get a time structure
    struct tm *ptm = gmtime ((time_t *)&epochTime);  
    int monthDay = ptm->tm_mday; 
    int currentMonth = ptm->tm_mon+1;
    int currentYear = ptm->tm_year+1900;
    //Print complete date:
    currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay) + "%20" + String(formattedTime);
    Serial.print("Current date: ");
    Serial.println(currentDate);
}

void get_php(String get_command){ 
    Serial.println("~~~~~~~~~~~~~~~~~~~~getphp~~~~~~~~~~~~~~~~~~~~");
    //a.Connect
    const int httpPort = 8080;
    if (!client.connect(ipAddress, httpPort)) {
        Serial.println("Connection failed");
        return;
    } 
    //b.doGet
//    unsigned long currentTime = millis();
//    if ((currentTime - previousTime) >= eventInterval){
//        //1.update time
//        previousTime = currentTime;
//        //2.event - update
//        client.print(get_command);
//    }
    client.print(get_command);
    //delay(500);

    String host = "Host: " + ipAddress + "\r\n";
    client.print(host); 
    //c.Close Connection
    client.print("Connection: close\r\n\r\n");
    while (client.connected()) {
        String line = client.readStringUntil('\n');
        Serial.println(line);
    } 
    Serial.print("get_command: ");
    Serial.println(get_command);
    Serial.println("~~~~~~~~~~~~~~~~~~~~End getphp~~~~~~~~~~~~~~~~~~~~");
}
    
void loop() {
    getdate();
    get_data_esp();
    String update_data = "GET /IOP_Project/update-sensor_main/update_sensors.php?" 
                        +  String("date_value=") + String(currentDate)
                        +  String("&temp_value=") + String(temp_value)
                        +  String("&light_value=") + String(light_value)
                        +  String("&soil_moisture_value=") + String(soil_moisture_value)
                        +  " HTTP/1.1\r\n";  

    //Update sensor data
    get_php(update_data); 
    

    Serial.println("===================Request sent/Update===================");
    
    Serial.println("Closing connection"); 
    delay(5000);
}

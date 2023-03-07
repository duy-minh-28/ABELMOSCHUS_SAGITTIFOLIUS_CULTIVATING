#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "webPage.h"

// Replace with your network credentials
const char* ssid = "locxoay";
const char* password = "kimanh2002";
ESP8266WebServer server(80); //instantiate server at port 80 (http port)
String page = "";
String data1, data2, data3, data4, data5, data6 ;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", []() {
    //page = "<head><meta http-equiv=\"refresh\" content=\"3\"><style>h1{margin-left: 400px;color: pink;}</style></head><center><h1>Web based Water Level monitor</h1><h3>Current humidnity is :</h3> <h4>" + data1 + "</h4><h3>Current temperature is :</h3>" + data2 + "<h4></h4></center>";
    server.send(200, "text/html", webPage);
  });
  server.begin();
  Serial.println("Web server started!");
}


void loop() {
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
    data6 = received.substring(first);
    Serial.println(data6);
    server.handleClient();
  }
}

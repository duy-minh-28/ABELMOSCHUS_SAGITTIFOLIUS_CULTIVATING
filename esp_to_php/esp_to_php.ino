#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "MINH";
const char* password = "123456789";
String ipAddress = "192.168.245.178";
int sectionID = 9;
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

  Serial.println("");
  Serial.println("WiFi connected");

  // Make GET request
  Serial.println("Making GET request...");


}

void loop() {
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(ipAddress, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  String data = "GET /insert.php?sectionID=" + String(sectionID)
                + "&organicWaste_kg=12.00&inorganicWaste_kg=12.00 HTTP/1.1\r\n";
  client.print(data);
  String host = "Host: "+ipAddress+"\r\n";
  client.print(host);
  client.print("Connection: close\r\n\r\n");

  Serial.println("Request sent");

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }

  Serial.println();
  Serial.println("Closing connection");
  sectionID++;
  delay(5000);
}

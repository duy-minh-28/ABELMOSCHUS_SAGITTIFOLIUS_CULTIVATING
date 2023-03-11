#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "MINH";
const char* password = "123456789";

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

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect("192.168.31.178", httpPort)) {
    Serial.println("Connection failed");
    return;
  }

  client.print("GET /insert.php?sectionID=8&organicWaste_kg=12.00&inorganicWaste_kg=12.00 HTTP/1.1\r\n");
  client.print("Host: 192.168.31.178\r\n");
  client.print("Connection: close\r\n\r\n");

  Serial.println("Request sent");

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }

  Serial.println();
  Serial.println("Closing connection");
}

void loop() {
}

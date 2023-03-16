#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#include "soil_moisture_sensor.h"
#include "dht22.h"
#include "light_sensor.h"

SoftwareSerial espSerial(5, 6); //RX-TX

LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x27, 16 column and 2 rows


void setup() {
  // put your setup code here, to run once:
  initDHT22();
  initSoilMoistureSensor();
  initLightSensor();
  lcd.init(); // initialize the lcd
  lcd.backlight();
  Serial.begin(115200);
  espSerial.begin(115200);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //message = tempValue/lightValue/soilMoistureValue/tempCompare/lightCompare/soilMoistureCompare
  String message = "";
  String lcdMessage = "";
  String lcdMessage2ndROW = "";
  int soilMoistureValue = readMoisture();
  float lightValue = checkLight();
  float dhtValue = checkTemp();

  if (isnan(dhtValue)) {
    message += "DHT is not connected";
    lcdMessage += "Error";
  }
  else {
    message += ("%d", dhtValue);
    lcdMessage += String(dhtValue) + " C";
  }
  message += "/";
  message += ("%f", lightValue);
  message += "/";
  message += ("%d", soilMoistureValue);

  lcdMessage += " ";
  lcdMessage += ("%.0f", lightValue);
  lcdMessage += " lux";

  lcdMessage2ndROW += String(soilMoistureValue);
  lcdMessage2ndROW += "%";

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lcdMessage);
  lcd.setCursor(6, 1);
  lcd.print(lcdMessage2ndROW);

  //message += ("40");
  //message += "/";
  //message += ("50");
  //message += "/";
  //message += ("100");


  Serial.println(message);
  espSerial.println(message);
  delay(3000);
}

#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 12
#define DHTTYPE DHT11


const char* ssid = "Nagpal";
const char* password = "Goria@2112";
DHT dht (DHTPIN,DHTTYPE);
void setup() {
  dht.begin();
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println("Connected to the WiFi network");
  
}
  
void loop() {
  
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
    HTTPClient http;
  
    http.begin("https://script.google.com/macros/s/AKfycbx-9HfPxy0LpHln0A1epV13T3MTdhlvPund0hjIFo-LduddTSYo192ET3x5uoTztwIKkQ/exec?func=addData&val=" + String(t)); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
  
    if (httpCode > 0) { //Check for the returning code
  
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
  
    else {
      Serial.println("Error on HTTP request");
    }
  
    http.end(); //Free the resources
  }
  
  delay(10000);
  
}
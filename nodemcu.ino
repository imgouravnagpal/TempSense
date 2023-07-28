#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <DHT.h>

const char* ssid = "ssid";
const char* password = "password";

const char* host = "script.google.com";
const int httpsPort = 443;
  const char* fingerprint = "CA EC 20 3A FD 8A 76 1E 0C 99 7C DB 33 65 0A 87 1A 3D 3E EB";


#define DHTPIN 12  // Replace 2 with the actual pin number your DHT11 sensor is connected to
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  dht.begin();
  
}

void loop() {
  // Wait for a while before taking the next reading
  delay(5000);

  // Read temperature from DHT11 sensor
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed to read temperature from DHT sensor.");
    return;
  }

  // Use WiFiClientSecure for secure HTTPS connection
  WiFiClientSecure client;
  client.setInsecure();
  Serial.print("Connecting to ");
  Serial.println(host);

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed!");
    return;
  }

 

  // Convert temperature to a String
  String tempString = String(temperature, 2); // 2 decimal places

  // Prepare the "val" parameter for the API call
  String apiParams = "func=addData&val=" + tempString;

  // Make the HTTPS request
  client.print(String("GET ") + "/macros/s/AKfycbzZ5xVADpVYYyUH6ts14_u7PK6jkiuIumCcz3mRtN6rR76oy2HKoTcNbr6kf5KaoYS2Eg/exec?" + apiParams + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("Request sent.");

  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers received.");
      break;
    }
  }

  while (client.available()) {
    String response = client.readStringUntil('\n');
    Serial.println(response);
  }

  Serial.println("Response received.");

  client.stop();
  
}

#include <DallasTemperature.h>
#include <OneWire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#define DHTPIN 21
#define DHTTYPE DHT11



//Wifi setup
const char* ssid = "Iaac-Wifi";
const char* password = "EnterIaac22@";
const char* mqtt_server = "167.99.44.189";

WiFiClient espClient;
PubSubClient client(espClient);




//Temperature probe setup
OneWire oneWire(14);
DallasTemperature tempSensor(&oneWire);
float MT;
float MM;


const int DHTPin = 21;
const int lamp = 23;


// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);


// Timers auxiliar variables
 long now = millis();
 long lastMeasure = 0;

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if(topic=="air/lamp"){
      Serial.print("Changing Room lamp to ");
      if(messageTemp == "on"){
        digitalWrite(lamp, HIGH);
        Serial.print("On");
      }
      else if(messageTemp == "off"){
        digitalWrite(lamp, LOW);
        Serial.print("Off");
      }
  }
  Serial.println();
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect

    if (client.connect("ESP8266Client")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("air/lamp");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}





void setup() {


  // LED output?
  pinMode(lamp, OUTPUT);
  dht.begin();

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);


    Serial.println("Dallas Temperature IC Control Library Demo");
  //sensors.begin();

}







void loop() {
  // Moisture Media Sensor
      Serial.print("Moisture Sensor Value:");
      Serial.println(analogRead(A3));
      delay(100);
      MM = analogRead(A3);

  // Phototransistor
      int value = analogRead(33);
      int perValue = map(value,0,1024,0,100);
      Serial.println("Phototransistor: ");
      Serial.println(value);
      delay(50);



  // Temperature Media probe
      MT = tempSensor.getTempCByIndex(0);
      tempSensor.requestTemperaturesByIndex(0);
      Serial.print("Media Temperature: ");
      Serial.print(tempSensor.getTempCByIndex(0));
      Serial.println(" C");
      delay(50);


    if (!client.connected())
      reconnect();
      client.loop();
      long now = millis();
      if (now - lastMeasure > 50) {
      lastMeasure = now;
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      float f = dht.readTemperature(true);
  
      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
      }

      float hic = dht.computeHeatIndex(t, h, false);
      static char temperatureTemp[7];
      dtostrf(hic, 6, 2, temperatureTemp);
      static char humidityTemp[7];
      dtostrf(h, 6, 2, humidityTemp);
      static char mediatemperatureTemp[7];
      dtostrf(MT, 6, 2, mediatemperatureTemp);
      static char mediamoistureMois[7];
      dtostrf(MM, 6, 2, mediamoistureMois);
      static char lightLight[7];
      dtostrf(perValue, 6, 2, lightLight);

  // Publishes Temperature and Humidity values
      client.publish("air/temperature", temperatureTemp);
      client.publish("air/humidity", humidityTemp);
      client.publish("media/temperature", mediatemperatureTemp);
      client.publish("air/light", lightLight);
      client.publish("media/moisture", mediamoistureMois);

      Serial.print("Aerial Humidity: ");
      Serial.print(h);
      Serial.print(" %\t Aerial Temperature: ");
      Serial.print(t);
      Serial.print(" *C ");
      Serial.print(f);
      Serial.print(" *F\t Heat index: ");
      Serial.print(hic);
      Serial.println(" *C ");
      }
}

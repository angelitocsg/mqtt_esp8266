#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "POL_WiFiConnect.h"
#include "POL_MQTT.h"
#include "POL_Config.h"

POL_WiFiConnect myWifi;
POL_MQTT myMqtt;

void setup() {
  Serial.begin(115200);
  Serial.println("Started");

  myWifi.connect();
  myMqtt.setup(mqtt_callback);

  Serial.println(myWifi.getIp());
}

void loop() {
  myMqtt.checkConnection();
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

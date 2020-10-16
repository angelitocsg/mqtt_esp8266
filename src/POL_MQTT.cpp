#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "POL_MQTT.h"
#include "POL_Config.h"

WiFiClient espClient;
PubSubClient clientMQTT(espClient);

POL_MQTT::POL_MQTT() { }

void POL_MQTT::setup(MQTT_CALLBACK_SIGNATURE)
{
  clientMQTT.setServer(mqttServer, mqttPort);
  clientMQTT.setCallback(callback);
}

void POL_MQTT::checkConnection() {
  if (!clientMQTT.connected()) {
    Serial.println("Try to reconnect to mqtt server...");
    reconnect();
  }
  clientMQTT.loop();
}

void POL_MQTT::reconnect() {
  Serial.println("Reconnecting...");
  while (!clientMQTT.connected()) {
    if (clientMQTT.connect(mqttClientId, mqttUser, mqttPass)) {
      Serial.println("conected");
      clientMQTT.publish(mqttPublishID, "HELLO!");
      clientMQTT.subscribe(mqttSubscribeID);
    } else {
      delay(5000);
      Serial.println("MQTT Failed");
    }
  }
}

void POL_MQTT::sendMessage(char* message) {
  checkConnection();
  if (clientMQTT.connected()) {
    clientMQTT.publish(mqttPublishID, message);
  }
}

String POL_MQTT::getPayloadText(byte* payload, unsigned int length) {
  String payloadText;
  for (int i = 0; i < length; i++)
  {
    char c = (char)payload[i];
    payloadText += c;
  }
  return payloadText;
}

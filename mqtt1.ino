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
  Serial.print("Message arrived ["); Serial.print(topic); Serial.print("] ");
  String payloadText = myMqtt.getPayloadText(payload, length);
  Serial.println();

  if (payloadText == "A1")
  {
    Serial.println("Ação A1 ativada");
    myMqtt.sendMessage("Recebido ação A1");
  }
  else if (payloadText == "A2")
  {
    Serial.println("Ação A2 ativada");
    myMqtt.sendMessage("Recebido ação A2");
  }
  else
  {
    myMqtt.sendMessage("Recebido mensagem desconhecida.");
  }
}

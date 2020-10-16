#ifndef POL_MQTT_h
#define POL_MQTT_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Arduino.h"

class POL_MQTT
{
  public:
    POL_MQTT();
    void setup(MQTT_CALLBACK_SIGNATURE);
    void checkConnection();
    String getPayloadText(byte* payload, unsigned int length);
    void sendMessage(char* message);
  private:
    void reconnect();
    MQTT_CALLBACK_SIGNATURE;
};

#endif

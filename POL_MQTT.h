#ifndef POL_MQTT_h
#define POL_MQTT_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Arduino.h"

// #ifdef ESP8266
// #include <functional>
// #define XMQTT_CALLBACK_SIGNATURE std::function<void(char*, uint8_t*, unsigned int)> callback
// #else
// #define XMQTT_CALLBACK_SIGNATURE void (*callback)(char*, uint8_t*, unsigned int)
// #endif

class POL_MQTT
{
  public:
    POL_MQTT();
    void setup(MQTT_CALLBACK_SIGNATURE);
    boolean isConnected();
    void reconnect();
    void checkConnection();
  private:
    const char* _ClientName;
    const char* _Server;
    uint16_t _Port;
    const char* _Username;
    const char* _Password;
    const char* _TopicIn;
    const char* _TopicOut;
    PubSubClient client1;
    MQTT_CALLBACK_SIGNATURE;
};

#endif

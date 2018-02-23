#include <ESP8266WiFi.h>
#include "POL_WiFiConnect.h"
#include "POL_Config.h"

POL_WiFiConnect::POL_WiFiConnect() { }

void POL_WiFiConnect::connect()
{
  WiFi.begin(wifiSSID, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Try to connect to wireless network...");
  }
  ip = WiFi.localIP();
}

boolean POL_WiFiConnect::connected()
{
  if (WiFi.status() != WL_CONNECTED)
    return false;
  else
    return true;
}

IPAddress POL_WiFiConnect::getIp()
{
  return ip;
}

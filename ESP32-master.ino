#include "WiFi.h"
#include "AsyncUDP.h"
#include <PubSubClient.h>
#include <PubSubClientTools.h>

const char * ssid = "YOUR_SSID";
const char * password = "PASSWORD";
#define MQTT_SERVER "broker.mqtt-dashboard.com"

AsyncUDP udp;

WiFiClient espClient;
PubSubClient client(MQTT_SERVER, 1883, espClient);
PubSubClientTools mqtt(client);

const String s = "";
int port = 5060;
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("WiFi.localIP()");
  Serial.println(WiFi.localIP());
  connectMQTT();

  if (udp.listen(port)) {
    //  if (udp.connect(IPAddress(192, 168, 43, 99), port)) {
    Serial.println("UDP connected");
    udp.onPacket([](AsyncUDPPacket packet) {
    });

  }
}
void connectMQTT() {
  if (client.connect("ESP32")) {
    Serial.println("connected");

    mqtt.subscribe("udp",  topic);

  } else {
    Serial.println(s + "failed, rc=" + client.state());
  }
}
String a ;
void topic(String topic, String message) {
  Serial.println(s + "Message arrived in function 1 [" + topic + "] " + message);
  a = message;
  udp.broadcastTo(message.c_str(), port);
  //  or Send to specific ip/device
  //  udp.sendTo(message, ip, 1234, IPAddress(192, 168, 43, 99), port);//, tcpip_if);
}
void loop()
{
  delay(1000);
  client.loop();
}

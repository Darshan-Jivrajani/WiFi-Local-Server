#include <WiFi.h>
#include <AsyncUDP.h>
#include <iostream>
#define LED 02

const char * ssid = "YOUR_SSID";
const char * password = "PASSWORD";

AsyncUDP udp;
int port = 5060;
WiFiClient espClient;

char buf[1000];

IPAddress local_IP(192, 168, 43, 184);
//it wil set the gateway static IP address to 192, 168, 1,1
IPAddress gateway(192, 168, 43, 1);

// Following three settings are optional
IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  pinMode(LED, OUTPUT);
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    while (1) {
      delay(1000);
    }
  }
  Serial.println(WiFi.localIP());
  udpServer();
}

void loop()
{
  delay(1000);
}

void udpServer() {
  //      if (udp.listenMulticast(IPAddress(local_IP), port)) {
  if (udp.listenMulticast(IPAddress(239, 1, 2, 3), port)) {
    //  if (udp.listenMulticast(IPAddress(192, 168, 43, 75), port)) {
    Serial.print("UDP Listening on IP: ");
    Serial.print(WiFi.localIP());
    Serial.print(" Port:- ");
    Serial.println(port);
    udp.onPacket([](AsyncUDPPacket packet) {
     
      for (int i = 0; i < packet.length(); i++) {
        buf[i] = (char) * (packet.data() + i);
        //        Serial.println(buf[i]);
      }
      Serial.println(buf);

      if (String(buf) == "11") {
        Serial.println("LED 1");
        digitalWrite(LED, 1);
      }
      else if (String(buf) == "10") {
        Serial.println("LED 0");
        digitalWrite(LED, 0);
      }
      Serial.println("..");
      for (int i = 0; i < sizeof(buf); i++) {
        buf[i] = 0;
      }
    });
  }
}

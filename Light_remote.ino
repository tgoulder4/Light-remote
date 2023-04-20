#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <string>
ESP8266WebServer server(80);
int baudRate = 115200;
void setup() {
  // put your setup code here, to run once:
  String ssid = "VM3966165";
  String password = "vyxy7hhFsnj7";
  Serial.begin(115200); 
  delay(10);
  Serial.println(("Serial connection begun with" + std::to_string(baudRate) + " baud rate.").c_str());
  pinMode(D0,OUTPUT);
  Serial.println("LED configured as output");
  connectToWiFi(ssid,password);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void connectToWiFi(const String SSID, const String PASS){
  WiFi.begin(SSID.c_str(), PASS.c_str());
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  digitalWrite(D0, LOW);
  Serial.println("Successfully connected, IP address is ");
  Serial.println(WiFi.localIP());
}
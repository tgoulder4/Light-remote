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
  Serial.begin(baudRate); 
  delay(10);
  Serial.println("Serial connection begun with" + std::to_string(baudRate) + " baud rate.");
  pinMode(D0,OUTPUT);
  Serial.println("LED configured as output");
  Serial.println(connectToWiFi(ssid,password));



}

void loop() {
  // put your main code here, to run repeatedly:

}

std::string connectToWiFi(const std::string& SSID, const std::string& PASS){
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  digitalWrite(D0, LOW);
  return "Successfully connected!";
}
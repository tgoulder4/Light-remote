#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <RF27.h>
#include <nRF24L01.h>
#include <string>
ESP8266WebServer server(80);
int baudRate = 115200;
void setup() {
  // put your setup code here, to run once:
  const String ssid = "VM3966165";
  const String password = "vyxy7hhFsnj7";
  const int cePin = "CMD";
  const int csnPin = "TX";
  Serial.begin(9600); 
  delay(10);
  Serial.println(("Serial connection begun with" + std::to_string(baudRate) + " baud rate.").c_str());
  pinMode(D0,OUTPUT);
  Serial.println("LED configured as output");
  connectToWiFi(ssid,password);
  delay(10);
  RF24 radio(cePin,csnPin);
  radio.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    //check for wifi broadcast every 10 seconds
  //...
  //when someone connects, we can send the html and css to them
  // WiFiClient client = server.available();
  // if (client.connected()){
  //   //server.available returns a valid or invalid client which can be checked using above
    
  // }
}

void connectToWiFi(const String SSID, const String PASS){
  WiFi.begin(SSID.c_str(), PASS.c_str());
  while (WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println("Successfully connected, IP address is ");
  Serial.println(WiFi.localIP());
}
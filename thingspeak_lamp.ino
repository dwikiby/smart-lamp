#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//koneksi ke Wifi
const char* ssid = "Cendramawa";
const char* password = "adminlmart";

//konfigurasi thingspeak
unsigned long channel = 1414088; //isi sesuai channel id
unsigned int fieldl = 1;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(D8, OUTPUT);
  digitalWrite(D8, LOW);
  
  //start connecting to wifi network
  Serial.println();
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  int fieldl_value = ThingSpeak.readFloatField(channel, fieldl);
  Serial.println(fieldl_value);
  if(fieldl_value == 1) {
    digitalWrite(D8, HIGH);
    Serial.println("ON");
  }
  else if (fieldl_value == 0) {
    digitalWrite(D8, LOW);
    Serial.println("OFF");
  }
  delay(3000);
}

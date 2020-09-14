
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
DHT dht(D2,DHT11);
const char* ssid="Redmi";
const char* pass="b8fe96c11455";
WiFiClient client;
long channelId = 918453;
char ip[]="184.106.153.149";
const char* apikey = "R3O2EFBNP0ARZYGR";
int i=0;
float t,h;
void setup() {
  // put your setup code here, to run once:
pinMode(D2,OUTPUT);
Serial.begin(9600);
dht.begin();
Serial.println("Conecting to");
Serial.println("ssid");
WiFi.begin(ssid,pass);
while(WiFi.status() != WL_CONNECTED) {  
  Serial.print(".");
  delay(500);
}
Serial.println("WiFi Connected");
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
//i++;
if (client.connect(ip,80)){
  t=dht.readHumidity();
  h=dht.readTemperature();
//ThingSpeak.setField(1,i); //field set
Serial.println(t);
Serial.println(h);  
}
ThingSpeak.setField(1,t); //field set
ThingSpeak.setField(2,h); //field set
ThingSpeak.writeFields(channelId,apikey);
client.stop();
delay(10000);
}

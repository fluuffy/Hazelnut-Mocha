#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid     = "***********";
const char* password = "***********";

//const char* host = "www.adafruit.com";
ESP8266WebServer server(80);
String webString="";
void handle_root() {
  server.send(200, "text/plain", "Hello from the otter side");
  delay(100);
}
void setup() {
  Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 server.on("/", handle_root);
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

int value = 0;

void loop() {
  server.handleClient();
  }
  

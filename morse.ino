#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <PubSubClient.h>

int downPin = D4;
// basically our previous state
bool isDown = false;

const char* ssid = "YourWiFi";
const char* pass = "YourPassword";
const char* mqttServer = "YourMQTTServer";
const int mqttPort = 1883;
const char* mqttUser = "YourUser";
const char* mqttPassword = "YourPass";
const char* pubChannel = "test";
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(downPin, INPUT_PULLUP);
  Serial.begin(115200);
  
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }

  client.setServer(mqttServer, mqttPort);
  
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
}

void loop() {
  client.loop();
  // check if state changed
  // run event function
  // update state
  // delay for debounce
  if ((!isDown) && (digitalRead(downPin) == LOW)) {
    onKeyDown();
    isDown = true;
    delay(10);
  }
  if (isDown && (digitalRead(downPin) == HIGH)) {
    onKeyUp();
    isDown = false;
    delay(10);
  }
}

// Event handlers
//Do whatever you want to do when the morse device starts being pressed down
bool isOn = true;
void onKeyDown() {
  client.publish(pubChannel, "1");
}

//Do whatever you want to do when the morse device is released
void onKeyUp() {
  client.publish(pubChannel, "0");
}

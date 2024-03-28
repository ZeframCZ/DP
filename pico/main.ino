#include <WiFi.h>
#include <AsyncMqtt_Generic.h>


#define WIFI_SSID         "___"
#define WIFI_PASSWORD     "___"
#define MQTT_HOST         "160.217.169.226"
#define MQTT_PORT         1883
int status = WL_IDLE_STATUS;
AsyncMqttClient mqttClient;


#include</home/jiricech/Desktop/test_pico_C/main_2/main/onMQTT.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting to SSID: ");
  Serial.println(WIFI_SSID);
  status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);


  Serial.println("Connecting to MQTT...");
  
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onUnsubscribe(onMqttUnsubscribe);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.onPublish(onMqttPublish);
  
  mqttClient.setCredentials("test_user_1", "test_password_1");
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.connect();

}

void loop() {
  mqttClient.connect();
  mqttClient.publish("test/rpiW", 0, true, "Ola");
  delay(600000);
  //delay(600);
  mqttClient.disconnect();
  
}

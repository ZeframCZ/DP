
#define MQTT_HOST         "160.217.169.226"
#define MQTT_PORT         1883

bool mqtt_connected = false;



void connect_mqtt(AsyncMqttClient* mqttClient){
    while(mqtt_connected == false){
      mqttClient->connect();
    }
    blink(10, 60);
}


void onMqttConnect(bool sessionPresent){
  Serial.print("Connected to MQTT.");
  mqtt_connected = true;
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  blink(10,50);
  Serial.println("Disconnected from MQTT.");
  //AsyncMqttClient mqttClient = set_mqtt();
  //connect_mqtt(&mqttClient);
}

void onMqttSubscribe(const uint16_t& packetId, const uint8_t& qos){
  Serial.println("Subscribed.");
}

void onMqttUnsubscribe(const uint16_t& packetId){
  Serial.println("Unsubscribed.");
}

void onMqttMessage(char* topic, char* payload, const AsyncMqttClientMessageProperties& properties, const size_t& len, const size_t& index, const size_t& total){
  Serial.println("Message received.");
}

void onMqttPublish(const uint16_t& packetId){
  Serial.println("Published message.");
}


AsyncMqttClient set_mqtt(){
  AsyncMqttClient mqttClient;
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onUnsubscribe(onMqttUnsubscribe);
  mqttClient.onMessage(onMqttMessage);
  mqttClient.onPublish(onMqttPublish);
  mqttClient.setCredentials("test_user_1", "test_password_1");
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  return mqttClient;
}

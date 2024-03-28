void blink(int n, int time){
  for(int i = 0 ;i < n ;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(time);
    digitalWrite(LED_BUILTIN, LOW);
    delay(time);
  }
}


void onMqttConnect(bool sessionPresent){
  blink(3,70);
  Serial.print("Connected to MQTT.");

  mqttClient.publish("test/rpiW", 0, false, "RP2040W Test1");
  Serial.println("Publishing at QoS 0");
}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  blink(1,200);
  Serial.println("Disconnected from MQTT.");
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
  blink(1,1000);
}

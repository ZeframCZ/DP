#include <WiFi.h>
#include <AsyncMqtt_Generic.h>
#include <string.h>

void blink(int n, int time){
  for(int i = 0 ;i < n ;i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(time);
    digitalWrite(LED_BUILTIN, LOW);
    delay(time);
  }
}

#include</home/jiricech/Desktop/test_pico_C/main_2/main/onMQTT.h>
#include</home/jiricech/Desktop/test_pico_C/main_2/main/networking.h>
#include</home/jiricech/Desktop/test_pico_C/main_2/main/logic.h>

uint8_t status;
AsyncMqttClient mqttClient = set_mqtt();

void setup() {
  Serial.begin(9600);
  status = connect_wifi("Cechovi", "Cechovi01");
  connect_mqtt(&mqttClient);
}


char input[500]={'\0'};
char per_payload[500]={'\0'};
char per_topic[500]={'\0'};
bool per_send = false;
int pulish_time = 1000;


unsigned long the_time = 0;
unsigned long cur_time;

void loop() {
  //status = WiFi.status();
  int number_of_characters = Serial.available();
  int i = 0;

  //update time 
  unsigned long cur_time = millis();

  //Read command from Serial
  while (Serial.available() > 0) {
    delay(10);
    // read the incoming byte:
    input[i] = Serial.read();
    i++;
  }
  //Serial is not empty -> user wants something -> determine what.
  if (input[0] != '\0'){


    //Publish a single message
    if (strstr(input, "pub") != 0){
      blink(3, 100);
      char arg_payload[500]={'\0'};
      char arg_topic[500]={'\0'};
      sprintf(arg_payload, "%s", "None");
      sprintf(arg_topic, "%s", "None");
      find_str(input, 'm', arg_payload);
      find_str(input, 't', arg_topic);
      Serial.println(arg_topic);
      Serial.println(arg_payload);

      mqttClient.publish(arg_topic, 1, false, arg_payload);
      
      for(int i = 0 ; i < 500 ; i++){
        input[i] = '\0';
      }
    }
    

    //publish a message every x seconds
    if (strstr(input, "per") != 0){
      blink(2, 500);
      int arg = find_int(input, 's');
      sprintf(per_payload, "%s", "None");
      sprintf(per_topic, "%s", "None");
      find_str(input, 'm', per_payload);
      find_str(input, 't', per_topic);

      if (arg!=0){
        pulish_time = arg*1000;
      }
      the_time = cur_time+pulish_time;
      per_send = !per_send;
    }
    //connect to mqtt
    if (strstr(input, "con") != 0){
      connect_mqtt(&mqttClient);
    }
    //DEBUG
    if (strstr(input, "deb") != 0){
      blink(5, 50);
      Serial.println("\n---DEBUG---");
      Serial.println("the_time");
      Serial.println(the_time);
      Serial.println("cur_time");
      Serial.println(cur_time);
      Serial.println("pulish_time");
      Serial.println(pulish_time);
      Serial.println("send_periodically");
      Serial.println(per_send);
      Serial.println("status");
      Serial.println(status);
      Serial.println("---DEBUG---\n");
    }
    //HELP
    if (strstr(input, "help") != 0){
      blink(2, 50);
      Serial.println("\n---HELP---");
      Serial.println("(Publish a single message)       pub -t topic -m payload");
      Serial.println("(Publish a message periodically) per -s time(s) -m payload -t topic");
      Serial.println("                                 help");
      Serial.println("(Debug)                          deb");
      Serial.println("(connect to mqtt broker)         con");
      Serial.println("---HELP---\n");
    }
    //clear input
    for(int i = 0 ; i < 500 ; i++){
      input[i] = '\0';
    }
  }
  
  //Send periodic message
  if (cur_time >= the_time && per_send == true){
    if (status == 3){
      
      char pt[11];
      if(intlen(pulish_time)<11){
        sprintf(pt, "%d", pulish_time);
        Serial.println(pt);
      }
      mqttClient.publish(per_topic, 1, false, per_payload);
    }else{
      status = connect_wifi("Cechovi", "Cechovi01");
      connect_mqtt(&mqttClient);
    }
    the_time = cur_time+pulish_time;
  }
}

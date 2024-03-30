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
  status = connect_wifi("____", "____");
  connect_mqtt(&mqttClient);
}


char input[500];
bool send_periodically = false;
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
      char arg_payload[500];
      char arg_topic[500];
      find_str(input, 'm', arg_payload);
      //find_str(input, 't', arg_topic);


      if (strlen(arg_payload)!=0){
        //mqttClient.publish(arg_topic, 1, false, arg_payload);
        mqttClient.publish("rpi/pico/test", 1, false, arg_payload);
        Serial.println(arg_payload);
      }
    }
    

    //publish a message every x seconds
    if (strstr(input, "per") != 0){
      blink(2, 500);
      int arg = find_int(input, 't');
      if (arg!=0){
        pulish_time = arg*1000;
      }
      the_time = cur_time+pulish_time;
      send_periodically = !send_periodically;
    }

    if (strstr(input, "con") != 0){
      connect_mqtt(&mqttClient);
    }
    //DEBUG
    if (strstr(input, "deb") != 0){
      blink(5, 50);
      Serial.println("---DEBUG---");
      Serial.println("the_time");
      Serial.println(the_time);
      Serial.println("cur_time");
      Serial.println(cur_time);
      Serial.println("pulish_time");
      Serial.println(pulish_time);
      Serial.println("send_periodically");
      Serial.println(send_periodically);
      Serial.println("status");
      Serial.println(status);
      Serial.println("---DEBUG---");
    }
    //clear input
    for(int i = 0 ; i < 500 ; i++){
      input[i] = '\0';
    }
  }
  //Serial.println(input, DEC);

  
  //Send periodic message
  if (cur_time >= the_time && send_periodically == true){
    if (status == 3){
      
      char pt[11];
      if(intlen(pulish_time)<11){
        sprintf(pt, "%d", pulish_time);
        Serial.println(pt);
      }
      //wchar_t
      char message[500] = {'\0'};
      jointnstr(message, "This message is sent ", 500);
      jointnstr(message, pt, 500);
      jointnstr(message, "ms apart.", 500);
      mqttClient.publish("test/picoW", 1, false, message);
    }else{
      status = connect_wifi("____", "____");
      connect_mqtt(&mqttClient);
    }
    the_time = cur_time+pulish_time;
  }
}

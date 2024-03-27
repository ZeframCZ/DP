import paho.mqtt.client as mqtt 
import random

def on_connect(client, userdata, flags, reason_code):
    print(f"Connected with result code {reason_code}")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))


mqttc = mqtt.Client()
mqttc.on_connect = on_connect
mqttc.on_message = on_message


mqttc.username_pw_set(username="test_user_1",password="test_password_1")#test_user_1
mqttc.connect("160.217.169.226", 1883, 10)
data = str(random.randrange(0,5000))
mqttc.publish("test_topic_number_2", data, False)

print(data)

mqttc.disconnect()


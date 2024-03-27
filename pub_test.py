import paho.mqtt.client as mqtt 
import random


username = "test_user_1"
password = "test_password_1"

data = str(random.randrange(0,5000))
qos = 0
retain = False

ip = "160.217.169.226"
port = 1883


def on_connect(client, userdata, flags, reason_code):
    print(f"Connected with result code {reason_code}")

def on_message(client, userdata, msg):
    print(msg.topic+" "+str(msg.payload))


try:
    mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
except:
    mqttc = mqtt.Client()

mqttc.on_connect = on_connect
mqttc.on_message = on_message
mqttc.username_pw_set(username = username,password = password)#test_user_1
mqttc.connect(ip, port, keepalive = 10)

mqttc.publish("test_topic_number_2", data, qos = qos, retain = retain)
print(data)

mqttc.disconnect()

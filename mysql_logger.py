"""Collects MQTT data into SQL"""
from datetime import datetime
import paho.mqtt.client as mqtt


username = "test_user_1"
password = "test_password_1"

ip = "160.217.169.226"
port = 1883

import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="Backora2024Ju.",
  database = "testdatabase"
)

cur = mydb.cursor()


try:
    cur.execute("CREATE TABLE messages(timestamp VARCHAR(255), topic VARCHAR(255), content VARCHAR(255)")

except:
    print("table already exists.")


def input_data(topic, content):
    timestamp = datetime.now()


    cur.execute("INSERT INTO messages (timestamp, topic, content) VALUES(%s, %s, %s)",(timestamp, topic, content))

    mydb.commit()


def on_connect_5(client, userdata, flags, reason_code, x):
    if reason_code == 0:
        print("Connection succesfull.")
        client.subscribe("#")
    else:
        print(f"Connected with result code {reason_code}")
        exit()

def on_connect_4(client, userdata, flags, reason_code):
    if reason_code == 0:
        print("Connection succesfull.")
        client.subscribe("#")
    else:
        print(f"Connected with result code {reason_code}")
        exit()

def on_message(client, userdata, msg):
    data = msg.payload.decode("utf-8")
    input_data(msg.topic, data)

    print(f"({datetime.now()}) | Topic: {msg.topic} | Payload: {data}")


if __name__ == "__main__":
    try:
        mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
    except:
        mqttc = mqtt.Client()

    mqttc.on_connect = on_connect_5
    mqttc.on_message = on_message

    mqttc.username_pw_set(username=username,password=password)
    mqttc.connect(ip, port, 60)


    mqttc.loop_forever()

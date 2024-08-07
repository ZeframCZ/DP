"""Collects MQTT data into SQL"""
import sqlite3
from datetime import datetime
import paho.mqtt.client as mqtt 


database_path = "mqtt_data.db"

username = "test_user_1"
password = "test_password_1"

ip = "160.217.169.226"
port = 1883



con = sqlite3.connect(database_path)
cur = con.cursor()

try:
    cur.execute("CREATE TABLE messages(day, month, year, time, topic, content)")
except:
    print("table already exists.")


def input_data(topic, content):
    date = datetime.now()
    day = date.day
    month = date.month
    year = date.year
    time = str(date.hour)+":"+str(date.minute)+":"+str(date.second)

    cur.execute("INSERT INTO messages (day, month, year, time, topic, content) VALUES(?, ?, ?, ?, ?, ?)",(day, month, year, time, topic, content))
    con.commit()

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
    
    mqttc.on_connect = on_connect_4
    mqttc.on_message = on_message

    mqttc.username_pw_set(username=username,password=password)
    mqttc.connect(ip, port, 60)


    mqttc.loop_forever()

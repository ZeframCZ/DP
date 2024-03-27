"""Collects MQTT data into SQL"""
import sqlite3
from datetime import datetime
import paho.mqtt.client as mqtt 

database_path = "mqtt_data.db"
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

def on_connect(client, userdata, flags, reason_code):
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
    mqttc = mqtt.Client()
    mqttc.on_connect = on_connect
    mqttc.on_message = on_message

    mqttc.username_pw_set(username="test_user_1",password="test_password_1")
    mqttc.connect("160.217.169.226", 1883, 60)


    mqttc.loop_forever()

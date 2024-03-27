"""Collects MQTT data into SQL"""
import sqlite3

con = sqlite3.connect("mqtt_data.db")
cur = con.cursor()

res = cur.execute("SELECT day, month, year, time, topic, content FROM messages")

import pprint
pprint.pprint(res.fetchall())

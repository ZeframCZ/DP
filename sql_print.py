"""Prints SQL data"""
import sqlite3
from datetime import datetime

con = sqlite3.connect("mqtt_data.db")
cur = con.cursor()



res = cur.execute("SELECT day, month, year, time, topic, content FROM messages")

import pprint
pprint.pprint(res.fetchall())

import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="Backora2024Ju.",
  database = "testdatabase"
)

cur = mydb.cursor()
cur.execute("SELECT timestamp, topic, content FROM messages")

import pprint
pprint.pprint(cur.fetchall())

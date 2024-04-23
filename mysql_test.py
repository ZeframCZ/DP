import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  password="Backora2024Ju.",
  database = "testdatabase"
)

cur = mydb.cursor()

try:
        cur.execute("CREATE TABLE messages(timestamp VARCHAR(255), topic VARCHAR(255), content VARCHAR(255>
except:
        print("table already exists.")

cur.execute("INSERT INTO messages(timestamp, topic, content) VALUES (%s, %s, %s)", ("test time","topic/tes>

mydb.commit()


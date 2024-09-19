from datetime import datetime
import logging

logger = logging.getLogger(__name__)
logging.basicConfig(filename = "/root/main/udp/udp_logger.log", level = logging.INFO)


import socket
logger.info("UDP logger start")
UDP_IP = "0.0.0.0"
UDP_PORT = 50000

try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.bind((UDP_IP, UDP_PORT))
        logger.info("Logger bind OK")
except:
        logger.info("Logger could not bind")
        exit(1)

import mysql.connector

def mysql_connect():
        try:
                mydb = mysql.connector.connect(
                        host="localhost",
                        user="root",
                        password="Backora2024Ju.",
                        database = "testdatabase"
                )
                cur = mydb.cursor()
                logger.info("MySQL connection OK")
                return mydb, cur
        except:
                logger.info("MySQL connection failed")
                exit(1)

while True:
        data, addr = sock.recvfrom(1024)
        logger.info("received message: %s" % data)
        try:
                mydb, cur = mysql_connect()
                timestamp = datetime.timestamp(datetime.now())
                topic = "UDP/test/2024/19.9"
                content = data
                cur.execute("INSERT INTO messages (timestamp, topic, content) VALUES(%s, %s, %s)",(timestamp, topic, content))
                mydb.commit()
                logger.info("SQL commited")
                mydb.disconnect()
        except Exception as err:
                logger.info("SQL INSERT failed"+str(err))

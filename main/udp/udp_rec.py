from datetime import datetime
import logging
logger = logging.getLogger(__name__)
logging.basicConfig(filename = "/root/main/udp/udp_logger.log", level = logging.INFO)
import socket

logger.info("UDP logger start")
UDP_IP = "0.0.0.0"
UDP_PORT = 50001

try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((UDP_IP, UDP_PORT))
    logger.info("Logger bind OK")
except:
    logger.info("Logger could not bind")
    exit(1)

while True:
    data, addr = sock.recvfrom(1024)
    logger.info("received message: %s" % data)

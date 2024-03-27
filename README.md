# DP
## Spuštění Mosquitto brokera
- mount -o remount,rw /
- mkdir /var/run/mosquitto
- chown mosquitto: /var/run/mosquitto
- chown mosquitto: /var/log/mosquitto/mosquitto.log
- mosquitto -c /etc/mosquitto/mosquitto.conf
- ctrl+z
- bg


## Spuštění sql_logger.py
- source /root/main/venv/bin/activate
- python3 /root/main/sql_print.py
- ctrl+z
- bg

## Základní config Mosquitto broker
- nano /etc/mosquitto/mosquitto.conf
| mosquitto.conf |
| ------------- |
| pid_file /var/run/mosquitto/mosquitto <br> persistence true|
  
- pid_file /var/run/mosquitto/mosquitto
- persistence true
- persistence_location /var/lib/mosquitto/
- log_dest file /var/log/mosquitto/mosquitto.log
- include_dir /etc/mosquitto/conf.d
- password_file /etc/mosquitto/pswd.txt
- listener 1883

## Password file 
- nano /etc/mosquitto/pswd.txt
  - uziv:heslo
  - uziv2:heslo2
  - uzivX:hesloX
- mosquitto_passwd -U /etc/mosquitto/pswd.txt 

## Mosquitto broker log
- sudo nano /var/log/mosquitto/mosquitto.log


| First Header  |
| ------------- |
| mount -o remount,rw / <br> mkdir /var/run/mosquitto|
| mkdir /var/run/mosquitto |
| chown mosquitto: /var/run/mosquitto |
| chown mosquitto: /var/log/mosquitto/mosquitto.log |
| mosquitto -c /etc/mosquitto/mosquitto.conf |
| ctrl+z |
| bg |

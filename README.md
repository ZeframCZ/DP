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
pid_file /var/run/mosquitto/mosquitto
persistence true
persistence_location /var/lib/mosquitto/
log_dest file /var/log/mosquitto/mosquitto.log
include_dir /etc/mosquitto/conf.d
password_file /etc/mosquitto/pswd.txt
listener 1883

![image](https://github.com/ZeframCZ/DP/assets/36083916/11df268f-fe82-49e8-bd74-55f42c7125af)

![image](https://github.com/ZeframCZ/DP/assets/36083916/6c0da983-f0b8-451f-b8f5-ac3d3de33c69)

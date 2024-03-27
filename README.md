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

![image](https://github.com/ZeframCZ/DP/assets/36083916/519c3096-025d-419b-980d-e9da93f1d477)

![image](https://github.com/ZeframCZ/DP/assets/36083916/11df268f-fe82-49e8-bd74-55f42c7125af)

![image](https://github.com/ZeframCZ/DP/assets/36083916/6c0da983-f0b8-451f-b8f5-ac3d3de33c69)

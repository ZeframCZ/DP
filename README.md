# DP
#### Spuštění Mosquitto brokera
- mount -o remount,rw /
- mkdir /var/run/mosquitto
- chown mosquitto: /var/run/mosquitto
- chown mosquitto: /var/log/mosquitto/mosquitto.log
- mosquitto -c /etc/mosquitto/mosquitto.conf
- ctrl+z
- bg


#### Spuštění sql_logger.py
- source /root/main/venv/bin/activate
- python3 /root/main/sql_print.py
- ctrl+z
- bg

#### Základní config Mosquitto broker
- nano /etc/mosquitto/mosquitto.conf
  
  | mosquitto.conf |
  | ------------- |
  | **pid_file /var/run/mosquitto/mosquitto** <br> persistence true <br> persistence_location /var/lib/mosquitto/ <br> log_dest file /var/log/mosquitto/mosquitto.log <br> include_dir     /etc/mosquitto/conf.d <br> **password_file /etc/mosquitto/pswd.txt** <br> **listener 1883** |
  
- nano /etc/mosquitto/pswd.txt
  
  | pswd.txt |
  | ------------- |
  | uziv:heslo <br> uziv2:heslo2 <br> uzivX:hesloX |

- mosquitto_passwd -U /etc/mosquitto/pswd.txt 

#### Mosquitto broker log
- sudo nano /var/log/mosquitto/mosquitto.log

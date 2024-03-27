from umqtt.simple import MQTTClient
import network


ssid = "xxx"
password = "xxx"

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.config(pm = 0xa11140) # Diable powersave mode
wlan.connect(ssid, password)

max_wait = 10
while max_wait > 0:
    if wlan.status() < 0 or wlan.status() >= 3:
        break
        max_wait -= 1
        print('waiting for connection...')
        utime.sleep(1)

#Handle connection error
if wlan.status() == 3:
    print("Connected")
    status = wlan.ifconfig()
    print("My IP : " + status[0])
else:
    print("Could not connect")
    exit(1)


def connectMQTT():
    client = MQTTClient(client_id=b"raspberrypi_picow",
    server=b"160.217.169.226",
    port=1883,
    user=b"test_user_1",
    password=b"test_password_1",
    keepalive=7200,
    ssl=False)

    client.connect()
    return client


client = connectMQTT()
client.publish("test/rpiW", "Hello there.")
print("published")

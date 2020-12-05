# WiFi-Local-Server
WiFi-Local-Server


Hello Everyone,

I created a demo for it works in WiFi as well as local operations I saw many places they are using the external gateway for the WiFi and Local operation. Such as Raspberry pi/ Zigbee/ Z-wave or WebServer mode(AP_STA Mode). But, Both two files are samples for the not required any gateway for local nad WiFi operation. One of the Master and the other one is a Slave(In Master, it can also work as a Slave.)

No Gateway  (Raspberry pi, Zigbee, Z-wave, etc.)

No WebServer(In ESP32/8266 or any wifi module etc.)

No Extra Hardware Require. 

Only Require WiFi Module/Chip/Modem. 

In this demo, I tested with 6(5 Slave + 1 Master) ESP32. It perfectly works and sends data without data loss.


Reuriemnt for Change before test:-

	-Set your ssid and password.
	
	-Set MQTT server(defult set:- "broker.mqtt-dashboard.com").
	
	-Set Static ip,subnet and gateway as per the your netwrok.

For Send Date from the local network:-

	- Android Application UDP Sender/Recevier
	
Check Demo and enjoy.

Looking forward to your suggestions.

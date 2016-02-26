WiFi controlled robot

Christopher Harvey

The core of this robot is the ESP8266-12 WiFi microchip. Useing this chip the robot connects to an exsiting wifi network and hosts a html page. That page contains the controls for the robot. The web client that loads the control page will comunicate back to the robot with http post requests.

TODO:
Have the esp8266 host a wifi network instaed of connecting to one.
Use web sockets instead of http post request

HARDWARE
1 Robot Frame
2 DC motors
2 Wheels
2 H-Bridges
1 ESP8266-12
1 Battery Pack (Optional seperate pack for motors)


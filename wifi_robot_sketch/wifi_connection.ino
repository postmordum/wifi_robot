
#include <ESP8266WiFi.h>

char ssid[] = "harvey";      // your network SSID (name)
char pass[] = "CFDOaAhvVxoS";   // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setupWifiConnection() {
 
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) {
    Serial.print(".");
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);

    delay(500);
  }
  server.begin();
  printWifiStatus();
}


char checkForConection() {
  char response = '\0';
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
//    Serial.println("new client");
    while(client.connected() && !client.available()){
      delay(1);
    }
    char c = '\0';
    while (client.connected()) {
      if (client.available()) {
        c = client.read();
//        Serial.print(c);
        if( c < 0 ){
          break;
        }
      }else{
        break;
      }
    }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    // the last character ends up being either \n 
    // for a request with no body, or the one 
    // character body of a POST request
    if(c == '0'){
      response = c;
      client.print(response);
    }else if(c == 'u'){
      response = c;
      client.print(response);
    }else if(c == 'd'){
      response = c;
      client.print(response);
    }else if(c == 'l'){
      response = c;
      client.print(response);
    }else if(c == 'r'){
      response = c;
      client.print(response);
    }else{
      client.println("<!DOCTYPE HTML>");
      client.println("<html><body style=\"margin:0px;width:100%;height:100%;background-color:#000\">");
      client.println("<div id=\"u\" style=\"width:50%;height:10%;background-color:#f00;position:absolute;top:5%;left:25%;border-top-left-radius:100px;border-top-right-radius:100px\"></div>");
      client.println("<div id=\"d\" style=\"width:50%;height:10%;background-color:#f00;position:absolute;top:85%;left:25%;border-bottom-left-radius:100px;border-bottom-right-radius:100px\"></div>");
      client.println("<div id=\"r\" style=\"width:10%;height:50%;background-color:#f00;position:absolute;top:25%;left:85%;border-top-right-radius:100px;border-bottom-right-radius:100px\"></div>");
      client.println("<div id=\"l\" style=\"width:10%;height:50%;background-color:#f00;position:absolute;top:25%;left:5%;border-top-left-radius:100px;border-bottom-left-radius:100px\"></div>");
      client.println("<script type=\"text/javascript\">var d=null;window.addEventListener(\"load\",function(){function e(g){document.getElementById(\"u\").style.background=\"#f00\";document.getElementById(\"d\").style.background=\"#f00\";document.getElementById(\"l\").style.background=\"#f00\";document.getElementById(\"r\").style.background=\"#f00\";document.getElementById(g).style.background=\"#0f0\";d=g;c()}function a(g){document.getElementById(\"u\").style.background=\"#f00\";document.getElementById(\"d\").style.background=\"#f00\";document.getElementById(\"l\").style.background=\"#f00\";document.getElementById(\"r\").style.background=\"#f00\";d=\"0\";c()}function c(){var g=new XMLHttpRequest();g.open(\"POST\",location.href,false);g.send(d);console.log(\"--\"+g.responseText+\"--\")}var f=[\"u\",\"d\",\"l\",\"r\"];for(var b=0;b<4;b++){(function(g){document.getElementById(g).addEventListener(\"mousedown\",function(h){e(g)},false);document.getElementById(g).addEventListener(\"mouseup\",function(h){a(g)},false);document.getElementById(g).addEventListener(\"mouseout\",function(h){a(g)},false);document.getElementById(g).addEventListener(\"touchstart\",function(h){e(g)},false);document.getElementById(g).addEventListener(\"touchenter\",function(h){e(g)},false);document.getElementById(g).addEventListener(\"touchend\",function(h){a(g)},false);document.getElementById(g).addEventListener(\"touchleave\",function(h){a(g)},false)})(f[b])}},false);</script>");
      client.println("</body></html>");
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
//    Serial.println("\nclient disonnected");
  }
  return response;
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}


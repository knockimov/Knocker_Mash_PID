#include <ESP8266WiFi.h>

#define USER_AGENT "UbidotsESP8266"
#define VERSION "1.6"
#define HTTPSERVER "things.ubidots.com"
#define SETID  "5a1fce25c03f971453d05759"           // Ubidots variable ID, Setpoint
#define TEMID1 "5a18ffe1c03f971bf4188766"           // Ubidots variable ID, Temperature
#define TEMID2 "5aaa6c9cc03f9775a7300187"           // Ubidots variable ID, Humidituý
#define TOKEN  "A1E-TXA4A6lGIVYy53ZFKwlWMk95wY69BY" // Ubidots TOKEN
#define WIFISSID "KnockTun"                         // Your WiFi SSID
#define PASSWORD "charles1dickens"                  // Your WiFi password

int temp1loc, temp2loc, setpointloc;
String readString, substring;
String temp1, temp2, setpoint;
char temp1Array[6], temp2Array[6], setpointArray[6];

unsigned long prevMillisUbidots  = 0;               // will store last time Ubidots was updated
const long interUbidots  = 30000;                   // interval at which to update UbiDots (milliseconds)

WiFiClient client;

void setup() {
  Serial.begin(9600); // Initialize serial port
  WiFi.begin(WIFISSID, PASSWORD);
}

void loop() {

  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {      //temp123.50,temp224.06,setpoint66.70
      //Serial.println(readString);
      temp1loc = readString.indexOf("temp1");
      temp1 = readString.substring(temp1loc + 5, temp1loc + 10);
      temp1.toCharArray(temp1Array, sizeof(temp1Array));
      Serial.print("Temperatur1: ");
      Serial.print(temp1Array);
      Serial.println("C");

      temp2loc = readString.indexOf("temp2");
      temp2 = readString.substring(temp2loc + 5, temp2loc + 10);
      temp2.toCharArray(temp2Array, sizeof(temp2Array));
      Serial.print("Temperatur2: ");
      Serial.print(temp2Array);
      Serial.println("C");

      setpointloc = readString.indexOf("setpoint");
      setpoint = readString.substring(setpointloc + 8, setpointloc + 13);
      setpoint.toCharArray(setpointArray, sizeof(setpointArray));
      Serial.print("Setpoint: ");
      Serial.print(setpointArray);
      Serial.println("C");

      readString = "";
      substring = "";
    } else {
      readString += c;
    }
  }

  unsigned long curMillisUbidots = millis();
  if (curMillisUbidots - prevMillisUbidots >= interUbidots) {
    prevMillisUbidots = curMillisUbidots;   // save the last time Ubidots was updated

    uint16_t i;
    String all = "[";
    all += "{\"variable\": \"";
    all += TEMID1;
    all += "\", \"value\":";
    all += temp1Array;
    all += "}";

    all += ",{\"variable\": \"";
    all += TEMID2;
    all += "\", \"value\":";
    all += temp2Array;
    all += "}";

    all += ",{\"variable\": \"";
    all += SETID;
    all += "\", \"value\":";
    all += setpointArray;
    all += "}";
    all += "]";
    i = all.length();

    String toPost = "POST /api/v1.6/collections/values/?force=true HTTP/1.1\r\n"
                    "Host: things.ubidots.com\r\n"
                    "User-Agent:" + String(USER_AGENT) + "/" + String(VERSION) + "\r\n"
                    "X-Auth-Token: " + String(TOKEN) + "\r\n"
                    "Connection: close\r\n"
                    "Content-Type: application/json\r\n"
                    "Content-Length: " + String(i) + "\r\n"
                    "\r\n"
                    + all +
                    "\r\n";

    if (client.connect(HTTPSERVER, 80)) {
      Serial.print(TOKEN); Serial.print(","); Serial.print(TEMID1); Serial.print(","); Serial.print(TEMID2); Serial.print(","); Serial.print(SETID);
      Serial.print("-- SENDING TO UBIDOTS -> ");
      Serial.print("Temperature1: "); Serial.print(temp1Array); Serial.print("*C,  "); Serial.print("Temperature2: "); Serial.print(temp2Array); Serial.print("*C,  "), Serial.print("Setpoint: "); Serial.print(setpointArray); Serial.print("*C");
      client.print(toPost);
    }

    int timeout = 0;
    while (!client.available() && timeout < 5000) {
      timeout++;
      delay(1);
    }
    client.stop();
  }
}

#include <ESP8266WiFi.h>

/**************************************************************************
 * Configuration of Knocker Mash PID
 * 
 * Change the variable ID och setpoint, temperature 1 and temperature 2
 * so they correspond to your account on Ubidots.
 * 
 * Match the SSID and password for your home network.
 **************************************************************************/
#define SETID  ""     // Ubidots variable ID, Setpoint
#define TEMID1 ""     // Ubidots variable ID, Temperature 1
#define TEMID2 ""     // Ubidots variable ID, Temperature 2
#define TOKEN  ""     // Ubidots TOKEN
#define WIFISSID ""   // Your WiFi SSID
#define PASSWORD ""   // Your WiFi password

/**************************************************************************
 * DO NOT EDIT BELOW, IT MAY CORRUPT THE PID
 **************************************************************************/
#define USER_AGENT "UbidotsESP8266"
#define VERSION "1.6"
#define HTTPSERVER "things.ubidots.com"
WiFiClient client;

/**************************************************************************
 * Serial reading and manipulation
 **************************************************************************/
int temp1loc, temp2loc, setpointloc;
char temp1Array[6], temp2Array[6], setpointArray[6];
String readString, substring, temp1, temp2, setpoint;

/**************************************************************************
 * Timer function
 **************************************************************************/
unsigned long prevMillisUbidots  = 0;   // will store last time Ubidots was updated
const long interUbidots  = 30000;       // interval at which to update UbiDots (milliseconds)

void serialRead(); {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
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

      readString = "";  // clear the string contents for new data
      substring = "";
    } else {
      readString += c;
    }
  }
}

void updateUbidots() {
  unsigned long curMillisUbidots = millis();
  if (curMillisUbidots - prevMillisUbidots >= interUbidots) { // check to see if enough time has passed
    prevMillisUbidots = curMillisUbidots;                     // save the last time Ubidots was updated

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
      client.print(toPost);   // update Ubidots variables
    }

    int timeout = 0;
    while (!client.available() && timeout < 5000) {
      timeout++;
      delay(1);
    }
    client.stop();
  }
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFISSID, PASSWORD);
}

void loop() {
  serialRead();
  updateUbidots();
}

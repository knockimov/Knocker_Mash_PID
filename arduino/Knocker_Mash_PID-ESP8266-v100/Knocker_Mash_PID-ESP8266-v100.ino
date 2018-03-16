#include <FS.h>                   //this needs to be first, or it all crashes and burns...
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson

#define USER_AGENT "UbidotsESP8266"
#define VERSION "1.6"
#define HTTPSERVER "things.ubidots.com"

char ubidotsToken[35] = "";
char tempID1[25] = "";
char tempID2[25] = "";
char setpointID[25] = "";

const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
boolean newData = false;

unsigned long prevMillisUbidots  = 0;               // will store last time Ubidots was updated
const long interUbidots  = 60000;                   // interval at which to update UbiDots (milliseconds)

bool shouldSaveConfig = false;
WiFiClient client;

void recvWithEndMarker() {
  static byte ndx = 0;
  char endMarker = '\n';
  char rc;

  // if (Serial.available() > 0) {
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (rc != endMarker) {
      receivedChars[ndx] = rc;
      ndx++;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    }
    else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

String getStringPartByNr(String data, char separator, int index) {
  // spliting a string and return the part nr index
  // split by separator

  int stringData = 0;        //variable to count data part nr
  String dataPart = "";      //variable to hole the return text

  for (int i = 0; i < data.length() - 1; i++) { //Walk through the text one letter at a time

    if (data[i] == separator) {
      //Count the number of times separator character appears in the text
      stringData++;

    } else if (stringData == index) {
      //get the text when separator is the rignt one
      dataPart.concat(data[i]);

    } else if (stringData > index) {
      //return text and stop if the next separator appears - to save CPU-time
      return dataPart;
      break;
    }
  }
  //return text if this is the last part
  return dataPart;
}

void updateUbidots() {
  unsigned long curMillisUbidots = millis();
  if (curMillisUbidots - prevMillisUbidots >= interUbidots) {
    prevMillisUbidots = curMillisUbidots;   // save the last time Ubidots was updated

    uint16_t i;
    String all = "[";
    all += "{\"variable\": \"";
    all += tempID1;
    all += "\", \"value\":";
    all += getStringPartByNr(receivedChars, ',', 0);
    all += "}";

    all += ",{\"variable\": \"";
    all += tempID2;
    all += "\", \"value\":";
    all += getStringPartByNr(receivedChars, ',', 1);
    all += "}";

    all += ",{\"variable\": \"";
    all += setpointID;
    all += "\", \"value\":";
    all += getStringPartByNr(receivedChars, ',', 2);
    all += "}";
    all += "]";
    i = all.length();

    String toPost = "POST /api/v1.6/collections/values/?force=true HTTP/1.1\r\n"
                    "Host: things.ubidots.com\r\n"
                    "User-Agent:" + String(USER_AGENT) + "/" + String(VERSION) + "\r\n"
                    "X-Auth-Token: " + String(ubidotsToken) + "\r\n"
                    "Connection: close\r\n"
                    "Content-Type: application/json\r\n"
                    "Content-Length: " + String(i) + "\r\n"
                    "\r\n"
                    + all +
                    "\r\n";

    if (client.connect(HTTPSERVER, 80)) {
      Serial.print(ubidotsToken); Serial.print(","); Serial.print(tempID1); Serial.print(","); Serial.print(tempID2); Serial.print(","); Serial.print(setpointID);
      Serial.print("-- SENDING TO UBIDOTS -> ");
      Serial.print("Temperature1: "); Serial.print(getStringPartByNr(receivedChars, ',', 0)); Serial.print("*C,  "); Serial.print("Temperature2: "); Serial.print(getStringPartByNr(receivedChars, ',', 1)); Serial.print("*C,  "), Serial.print("Setpoint: "); Serial.print(getStringPartByNr(receivedChars, ',', 2)); Serial.print("*C");
      client.print(toPost);
    }

    int timeout = 0;
    while (!client.available() && timeout < 5000) {
      timeout++;
      delay(1);
    }
    client.stop();
    return;
  }
}

void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

void setup() {
  Serial.begin(9600);
  Serial.println();

  //SPIFFS.format();    //clean FS, for testing

  Serial.println("mounting FS...");
  if (SPIFFS.begin()) {
    Serial.println("mounted file system");
    if (SPIFFS.exists("/config.json")) {
      Serial.println("reading config file");
      File configFile = SPIFFS.open("/config.json", "r");
      if (configFile) {
        Serial.println("opened config file");
        size_t size = configFile.size();
        std::unique_ptr<char[]> buf(new char[size]);
        configFile.readBytes(buf.get(), size);
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.parseObject(buf.get());
        json.printTo(Serial);
        if (json.success()) {
          Serial.println("\nparsed json");
          strcpy(ubidotsToken, json["ubidotsToken"]);
          strcpy(tempID1, json["tempID1"]);
          strcpy(tempID2, json["tempID2"]);
          strcpy(setpointID, json["setpointID"]);

        } else {
          Serial.println("failed to load json config");
        }
      }
    }
  } else {
    Serial.println("failed to mount FS");
  }

  WiFiManagerParameter custom_ubidotsToken_hint("<hr><label for=\"TOKEN\">Ubidots Token</label>");
  WiFiManagerParameter custom_ubidotsToken("token", "Ubidots Token", ubidotsToken, 35);
  WiFiManagerParameter custom_tempID1_hint("<hr><label for=\"ID\">Variable ID's</label>");
  WiFiManagerParameter custom_tempID1("tempid1", "Temp variable ID1", tempID1, 25);
  WiFiManagerParameter custom_tempID2("tempid2", "Temp variable ID2", tempID2, 25);
  WiFiManagerParameter custom_setpointID("setpointid", "Setpoint variable ID", setpointID, 25);

  WiFiManager wifiManager;
  wifiManager.setSaveConfigCallback(saveConfigCallback);

  wifiManager.addParameter(&custom_ubidotsToken_hint);
  wifiManager.addParameter(&custom_ubidotsToken);
  wifiManager.addParameter(&custom_tempID1_hint);
  wifiManager.addParameter(&custom_tempID1);
  wifiManager.addParameter(&custom_tempID2);
  wifiManager.addParameter(&custom_setpointID);

  //wifiManager.resetSettings();    //reset settings - for testing

  if (!wifiManager.autoConnect("AutoConnectAP", "password")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(5000);
  }

  Serial.println("connected...yeey :)");

  strcpy(ubidotsToken, custom_ubidotsToken.getValue());
  strcpy(tempID1, custom_tempID1.getValue());
  strcpy(tempID2, custom_tempID2.getValue());
  strcpy(setpointID, custom_setpointID.getValue());

  if (shouldSaveConfig) {
    Serial.println("saving config");
    DynamicJsonBuffer jsonBuffer;
    JsonObject& json = jsonBuffer.createObject();
    json["ubidotsToken"] = ubidotsToken;
    json["tempID1"] = tempID1;
    json["tempID2"] = tempID2;
    json["setpointID"] = setpointID;

    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
      Serial.println("failed to open config file for writing");
    }

    json.printTo(Serial);
    json.printTo(configFile);
    configFile.close();
  }

  Serial.println("local ip");
  Serial.println(WiFi.localIP());
}

void loop() {
  recvWithEndMarker();
  updateUbidots();
  if (newData == true) {
    Serial.print("This just in ... ");
    Serial.println(receivedChars);

    Serial.print("TEMP1: ");
    Serial.println(getStringPartByNr(receivedChars, ',', 0));

    Serial.print("TEMP2: ");
    Serial.println(getStringPartByNr(receivedChars, ',', 1));

    Serial.print("SETPOINT: ");
    Serial.println(getStringPartByNr(receivedChars, ',', 2));
    newData = false;
  }
}

//#include <ESP8266WiFi.h>
#include <PID_v1.h>
#include <PID_AutoTune_v0.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

/*// ************************************************
// WiFi cridentials, variables and constants
// ************************************************
#define IP "things.ubidots.com"
const char* ssid     = "KnockTun";
const char* password = "charles1dickens";
char token[35]  = "A1E-TXA4A6lGIVYy53ZFKwlWMk95wY69BY";
char varID1[25] = "5a18ffe1c03f971bf4188766";           // Temperature
char varID2[25] = "5a1fce25c03f971453d05759";           // Setpoint
WiFiClient client;*/

// ************************************************
// PID Variables and constants
// ************************************************
#define RELAY_PIN  A1
double Setpoint, Input1, Input2, Output;                                        // Define Variables we'll be connecting to
double Kp, Ki, Kd;                                                      // PID tuning parameters
const int SpAddress = 0, KpAddress = 8, KiAddress = 16, KdAddress = 24; // EEPROM addresses for persisted data
PID myPID(&Input1, &Output, &Setpoint, Kp, Ki, Kd, P_ON_M, DIRECT);     // Specify the links and initial tuning parameters. P_ON_M specifies that Proportional on Measurement be used, P_ON_E (Proportional on Error) is the default behavior
//PID myPID(&Input, &Output, &Setpoint, 85, 0.5, 0.5, P_ON_M, DIRECT);  // Specify the links and initial tuning parameters

// ************************************************
// Auto Tune Variables and constants
// ************************************************
byte ATuneModeRemember = 2;
double aTuneStep = 500,  aTuneNoise = 1;
unsigned int aTuneLookBack = 20;
boolean tuning = false;
PID_ATune aTune(&Input1, &Output);

// ************************************************
// Buttons
// ************************************************
#define BUTTON_SELECT 7
#define BUTTON_LEFT   3
#define BUTTON_RIGHT  4
#define BUTTON_UP     5
#define BUTTON_DOWN   6
unsigned long lastInput = 0; // last button press
volatile byte button_select, button_left, button_right, button_up, button_down;

// ************************************************
// Timers
// ************************************************
//unsigned long prevMillisUbidots = 0;           // will store last time Ubidots was updated
unsigned long previousMillis = 0;              // will store last time temp was updated
//const long interUbidots = 60000;               // interval at which to update UbiDots (milliseconds)
const long interval = 1000;                    // interval at which to update temp to Wemos (milliseconds)

// ************************************************
// Temperature sensors
// ************************************************
#define ONE_WIRE_BUS A2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress tempSensor1, tempSensor2;

// ************************************************
// States for state machine
// ************************************************
enum operatingState { OFF = 0, MANU, SETP, RUN, TUNE_P, TUNE_I, TUNE_D, AUTO};
operatingState opState = OFF;

// ************************************************
// LCD display
// ************************************************
byte degree[8] = { B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000 };  // define the degree symbol
LiquidCrystal_I2C lcd(0x27, 16, 2);

void read_but() {
  bool pin_status;
  delay(3);

  pin_status = digitalRead(BUTTON_SELECT);
  if (pin_status == LOW && button_select != 128) {
    button_select = 128;
  }
  if (pin_status == HIGH && button_select == 128) {
    button_select = 1;
    lastInput = millis();
    Serial.println("Button Select pressed!");
  }

  pin_status = digitalRead(BUTTON_LEFT);
  if (pin_status == LOW && button_left != 128) {
    button_left = 128;
  }
  if (pin_status == HIGH && button_left == 128) {
    button_left = 1;
    lastInput = millis();
    Serial.println("Button Left pressed!");
  }

  pin_status = digitalRead(BUTTON_RIGHT);
  if (pin_status == LOW && button_right != 128) {
    button_right = 128;
  }
  if (pin_status == HIGH && button_right == 128) {
    button_right = 1;
    lastInput = millis();
    Serial.println("Button Right pressed!");
  }

  pin_status = digitalRead(BUTTON_UP);
  if (pin_status == LOW && button_up != 128) {
    button_up = 128;
  }
  if (pin_status == HIGH && button_up == 128) {
    button_up = 1;
    lastInput = millis();
    Serial.println("Button Up pressed!");
  }

  pin_status = digitalRead(BUTTON_DOWN);
  if (pin_status == LOW && button_down != 128) {
    button_down = 128;
  }
  if (pin_status == HIGH && button_down == 128) {
    button_down = 1;
    lastInput = millis();
    Serial.println("Button Down pressed!");
  }
}

/*void updateUbidots() {
  unsigned long curMillisUbidots = millis();

  if (curMillisUbidots - prevMillisUbidots >= interUbidots) {
    prevMillisUbidots = curMillisUbidots;   // save the last time updated Ubidots

    if (!client.connect(IP, 80)) {
      return;
    }

    String url = "[";
    url += "\ {\"variable\": \"";
    url += varID1;
    url += "\", \"value\":";
    url += Input1;
    url += "}";

    url += "\," "\{\"variable\": \"";
    url += varID2;
    url += "\", \"value\":";
    url += Setpoint;
    url += "}";
    url += "]";

    client.print(String("POST /api/v1.6/collections/values/?token=") + token + " HTTP/1.1\r\n");
    client.print(String("Host: ") + IP + "\r\n");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(url.length());
    client.println();
    client.println(url);

    Serial.print("-------------- UPDATED UBIDOTS WITH SENSOR AND SETPOINT DATA --------------");
  }
}*/

void setup() {
  Serial.begin(9600);

  /*WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());*/

  pinMode(RELAY_PIN, OUTPUT); // Output mode to drive relay
  analogWrite(RELAY_PIN, 0);  // make sure it is off to start
  pinMode(BUTTON_SELECT, INPUT_PULLUP); pinMode(BUTTON_LEFT, INPUT_PULLUP); pinMode(BUTTON_RIGHT, INPUT_PULLUP); pinMode(BUTTON_UP, INPUT_PULLUP); pinMode(BUTTON_DOWN, INPUT_PULLUP);
  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;

  lcd.init();
  lcd.createChar(1, degree); // create degree symbol from the binary
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(F("Starting..."));

  sensors.begin();
  if (!sensors.getAddress(tempSensor1, 0))
  {
    lcd.setCursor(0, 0);
    lcd.print(F("Sensor 1 Error"));
  }
  if (!sensors.getAddress(tempSensor2, 1))
  {
    lcd.setCursor(0, 1);
    lcd.print(F("Sensor 2 Error"));
  }
  sensors.setResolution(tempSensor1, 12);
  sensors.setResolution(tempSensor2, 12);
  sensors.setWaitForConversion(false);
  Serial.print("Temperature sensor 1: "); Serial.println(tempSensor1[7], HEX);
  Serial.print("Temperature sensor 2: "); Serial.println(tempSensor2[7], HEX);

  LoadParameters();
  myPID.SetTunings(Kp, Ki, Kd);
  myPID.SetMode(AUTOMATIC);                     //turn the PID on
  //Setpoint = 67;
}

void loop() {
  lcd.clear();
  switch (opState) {
    case OFF:
      Off();
      break;
    case MANU:
      Man();
      break;
    case SETP:
      Tune_Sp();
      break;
    case RUN:
      Run();
      break;
    case TUNE_P:
      TuneP();
      break;
    case TUNE_I:
      TuneI();
      break;
    case TUNE_D:
      TuneD();
      break;
  }
  //updateUbidots();
}

// ************************************************
// Manual State - press UP/DOWN to set ouput
// ************************************************
void Man() {
  myPID.SetMode(MANUAL);
  Output = 0; // Reset the output-buffer
  lcd.clear();
  lcd.print("Set Output:");

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    float increment = 5;
    if (button_select == 1) {
      increment *= 50;
    }
    if (button_right == 1) {
      opState = OFF;
      button_right = 0;
      return;
    }
    if (button_up == 1) {
      Output += increment;
      button_up = 0;
      delay(50);
    }
    if (button_down == 1) {
      Output -= increment;
      button_down = 0;
      delay(50);
    }

    lcd.setCursor(0, 1);
    lcd.print(Output);
    lcd.print(" ");
    analogWrite(RELAY_PIN, Output);
    Serial.print("Analog value of "); Serial.print(Output); Serial.print(" sent to analog output "); Serial.println(RELAY_PIN);
  }
}

// ************************************************
// Initial State - press RIGHT to enter setpoint
// ************************************************
void Off() {
  myPID.SetMode(MANUAL);
  //lcd.setBacklight(0);
  analogWrite(RELAY_PIN, 0);  // make sure it is off
  lcd.print(F("   KNOCKIMOV"));
  lcd.setCursor(0, 1);
  lcd.print(F("   MASH  PID"));
  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;

  /*while (button_right != 1) {
    read_but();
  }*/

  while (true) {
    read_but();

    if (button_left == 1) {
      opState = MANU;
      button_left = 0;
      return;
    }
    if (button_right == 1) {
      opState = RUN;
      sensors.requestTemperatures(); // Start an asynchronous temperature reading
      myPID.SetMode(AUTOMATIC);
      button_right = 0;
      return;
    }

  //sensors.requestTemperatures(); // Start an asynchronous temperature reading
  //myPID.SetMode(AUTOMATIC);
  //opState = RUN;
  }
}

// ************************************************
// Setpoint Entry State
// UP/DOWN to change setpoint
// RIGHT for tuning parameters
// LEFT for OFF
// SELECT for 10x tuning
// ************************************************
void Tune_Sp() {
  lcd.clear();
  lcd.print("Set Temperature:");

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    float increment = 0.1;
    if (button_select == 1) {
      increment *= 10;
    }
    if (button_left == 1) {
      opState = RUN;
      button_left = 0;
      return;
    }
    if (button_right == 1) {
      opState = TUNE_P;
      button_right = 0;
      return;
    }
    if (button_up == 1) {
      Setpoint += increment;
      button_up = 0;
      delay(50);
    }
    if (button_down == 1) {
      Setpoint -= increment;
      button_down = 0;
      delay(50);
    }

    if ((millis() - lastInput) > 3000) {  // return to RUN after 3 seconds idle
      opState = RUN;
      return;
    }
    lcd.setCursor(0, 1);
    lcd.print(Setpoint);
    lcd.print(" ");
    DoControl();
  }
}

// ************************************************
// Proportional Tuning State
// UP/DOWN to change Kp
// RIGHT for Ki
// LEFT for setpoint
// SELECT for 10x tuning
// ************************************************
void TuneP() {
  lcd.clear();
  lcd.print(F("Set Kp"));

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    float increment = 0.1;
    if (button_select == 1) {
      increment *= 10;
    }
    if (button_left == 1) {
      opState = SETP;
      button_left = 0;
      return;
    }
    if (button_right == 1) {
      opState = TUNE_I;
      button_right = 0;
      return;
    }
    if (button_up == 1) {
      Kp += increment;
      button_up = 0;
      delay(50);
    }
    if (button_down == 1) {
      Kp -= increment;
      button_down = 0;
      delay(50);
    }

    if ((millis() - lastInput) > 3000) {  // return to RUN after 3 seconds idle
      opState = RUN;
      return;
    }
    lcd.setCursor(0, 1);
    lcd.print(Kp);
    lcd.print(" ");
    DoControl();
  }
}

// ************************************************
// Integral Tuning State
// UP/DOWN to change Ki
// RIGHT for Kd
// LEFT for Kp
// SELECT for 10x tuning
// ************************************************
void TuneI() {
  lcd.clear();
  lcd.print(F("Set Ki"));

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    float increment = 0.01;
    if (button_select == 1) {
      increment *= 10;
    }
    if (button_left == 1) {
      opState = TUNE_P;
      button_left = 0;
      return;
    }
    if (button_right == 1) {
      opState = TUNE_D;
      button_right = 0;
      return;
    }
    if (button_up == 1) {
      Ki += increment;
      button_up = 0;
      delay(50);
    }
    if (button_down == 1) {
      Ki -= increment;
      button_down = 0;
      delay(50);
    }

    if ((millis() - lastInput) > 3000) {  // return to RUN after 3 seconds idle
      opState = RUN;
      return;
    }
    lcd.setCursor(0, 1);
    lcd.print(Ki);
    lcd.print(" ");
    DoControl();
  }
}

// ************************************************
// Derivative Tuning State
// UP/DOWN to change Kd
// RIGHT for setpoint
// LEFT for Ki
// SELECT for 10x tuning
// ************************************************
void TuneD() {
  lcd.clear();
  lcd.print(F("Set Kd"));

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    float increment = 0.01;
    if (button_select == 1) {
      increment *= 10;
    }
    if (button_left == 1) {
      opState = TUNE_I;
      button_left = 0;
      return;
    }
    if (button_right == 1) {
      opState = RUN;
      button_right = 0;
      return;
    }
    if (button_up == 1) {
      Kd += increment;
      button_up = 0;
      delay(50);
    }
    if (button_down == 1) {
      Kd -= increment;
      button_down = 0;
      delay(50);
    }

    if ((millis() - lastInput) > 3000) {  // return to RUN after 3 seconds idle
      opState = RUN;
      return;
    }
    lcd.setCursor(0, 1);
    lcd.print(Kd);
    lcd.print(" ");
    DoControl();
  }
}

// ************************************************
// PID COntrol State
// SELECT and RIGHT for autotune
// RIGHT - Setpoint
// LEFT - OFF
// ************************************************
void Run() {
  lcd.print(F("Sp:"));
  lcd.print(Setpoint);
  lcd.write(1);
  //lcd.print(F(":  "));

  SaveParameters();
  myPID.SetTunings(Kp, Ki, Kd);

  button_select = 0; button_left = 0; button_right = 0; button_up = 0; button_down = 0;
  while (true) {
    read_but();

    if ( (button_select == 1) && (button_right == 1) && (abs(Input1 - Setpoint) < 0.5)) {  // Should be at steady-state
      StartAutoTune();
    }
    else if (button_right == 1) {
      opState = SETP;
      button_right = 0;
      return;
    }
    else if (button_left == 1) {
      opState = OFF;
      button_left = 0;
      return;
    }

    DoControl();

    lcd.setCursor(0, 1);
    lcd.print(Input1);
    lcd.write(1);
    lcd.setCursor(8, 1);
    lcd.print(Input2);
    lcd.write(1);

    int pct = map(Output, 0, 255, 0, 1000);
    lcd.setCursor(11, 0);
    lcd.print(F("      "));
    lcd.setCursor(11, 0);
    lcd.print(pct / 10);
    lcd.print("%  ");

    lcd.setCursor(15, 0);
    if (tuning) {
      lcd.print("T");
    } else {
      lcd.print(" ");
    }

    delay(100);
  }
}

void DoControl() {
  Input1 = sensors.getTempC(tempSensor1);
  Input2 = sensors.getTempC(tempSensor2);
  sensors.requestTemperatures();
  if (isnan(Input1)) {
    lcd.print("Sensor 1 error");
    return;
  }

  if (tuning) { // run the auto-tuner
    if (aTune.Runtime()) { // returns 'true' when done
      FinishAutoTune();
    }
  } else {  // Execute control algorithm
    myPID.Compute();
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   // save the last time temp was sent
    Serial.print("Setpoint: "); Serial.print(Setpoint); Serial.print(" ");
    Serial.print("Input1: "); Serial.print(Input1); Serial.print(" ");
    Serial.print("Input2: "); Serial.print(Input2); Serial.print(" ");
    Serial.print("Output: "); Serial.print(Output); Serial.print(" ");
    Serial.print("kP: "); Serial.print(myPID.GetKp()); Serial.print(" ");
    Serial.print("kI: "); Serial.print(myPID.GetKi()); Serial.print(" ");
    Serial.print("kD: "); Serial.print(myPID.GetKd()); Serial.println();
  }
}

// ************************************************
// Start the Auto-Tuning cycle
// ************************************************
void StartAutoTune() {
  ATuneModeRemember = myPID.GetMode(); // Remember the mode we were in
  aTune.SetNoiseBand(aTuneNoise);      // set up the auto-tune parameters
  aTune.SetOutputStep(aTuneStep);
  aTune.SetLookbackSec((int)aTuneLookBack);
  tuning = true;
}

// ************************************************
// Return to normal control
// ************************************************
void FinishAutoTune() {
  tuning = false;
  Kp = aTune.GetKp();  // Extract the auto-tune calculated parameters
  Ki = aTune.GetKi();
  Kd = aTune.GetKd();
  myPID.SetTunings(Kp, Ki, Kd); // Re-tune the PID and revert to normal control mode
  myPID.SetMode(ATuneModeRemember);

  SaveParameters();  // Persist any changed parameters to EEPROM
}

// ************************************************
// Save any parameter changes to EEPROM
// ************************************************
void SaveParameters() {
  if (Setpoint != EEPROM_readDouble(SpAddress)) {
    EEPROM_writeDouble(SpAddress, Setpoint);
  }
  if (Kp != EEPROM_readDouble(KpAddress)) {
    EEPROM_writeDouble(KpAddress, Kp);
  }
  if (Ki != EEPROM_readDouble(KiAddress)) {
    EEPROM_writeDouble(KiAddress, Ki);
  }
  if (Kd != EEPROM_readDouble(KdAddress)) {
    EEPROM_writeDouble(KdAddress, Kd);
  }
}

// ************************************************
// Load parameters from EEPROM
// ************************************************
void LoadParameters() {
  Setpoint = EEPROM_readDouble(SpAddress); // Load from EEPROM
  Kp = EEPROM_readDouble(KpAddress);
  Ki = EEPROM_readDouble(KiAddress);
  Kd = EEPROM_readDouble(KdAddress);

  if (isnan(Setpoint)) { // Use defaults if EEPROM values are invalid
    Setpoint = 65;
  }
  if (isnan(Kp)) {
    Kp = 85;
  }
  if (isnan(Ki)) {
    Ki = 0.5;
  }
  if (isnan(Kd)) {
    Kd = 0.5;
  }
}

// ************************************************
// Write floating point values to EEPROM
// ************************************************
void EEPROM_writeDouble(int address, double value) {
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    EEPROM.write(address++, *p++);
  }
}

// ************************************************
// Read floating point values from EEPROM
// ************************************************
double EEPROM_readDouble(int address) {
  double value = 0.0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(address++);
  }
  return value;
}
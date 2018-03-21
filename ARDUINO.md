<h2>Installation av Arduino IDE och överföring av sketcher</h2>
<h3>Översättning pågår!!!</h3>

<h4>Ubidots</h4>
Ubidots är en platform för att samla och grafiskt visa datapunkter, även där all data kommer att sparas från din Mash PID. Börja med att skapa ett konto på <a href="www.ubidots.com">Ubidots.com</a>. Det tar bara någon minut och är helt gratis. När du har ditt konto klart behöver du skapa en ny enhet genom att först klicka på "Devices" och sedan på "Add Device", namnge den MashPID eller liknande.<br>
<img width="500" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-002.JPG"></img>

Klicka nu på din nya enhet för att öppna den. Ubidots bygger på att data loggas i olika variabler, en för varje typ av data som loggas. Du behöver nu skapa tre nya variabler genom att trycka på "Add variable". Namnge den första variabeln "Temperatur1", andra "Temperatur2" och sista "Setpoint".<br>
<img width="300" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-003.JPG"></img>

Du behöver skriva ner fyra stycken ID, dem tre från variablerna och den fjärde är din token. ID-nr från variablerna hittar du om du klickar dig in på själva variabeln och sedan läser av i vänstermenyn. Din token hittar du under användarmenyn och "API Credentials".<br>
<img height="333" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-004.JPG"></img>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-005.jpg"></img>
<img width="550" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-006.jpg"></img><p>

Setup
You will need a laptop and a micro USB cable (like the one that you charge a phone with). On the laptop, we need to install some software to be able to program the ESP8266. Visit Arduino.cc and install the Arduino IDE.

Arduino IDE

Once the Arduino IDE is installed, open the program so we can do a couple of setup steps to get it ready to program ESP8266 devices. Under File, Preferences, and Additional Boards Manager URLs, add this link: http://arduino.esp8266.com/stable/package_esp8266com_index.json – this will allow the Arduino IDE to manage ESP8266 compatiable boards.

Arduino Preferences for ESP8266 programming
Installing with Boards Manager
Starting with 1.6.4, Arduino allows installation of third-party platform packages using Boards Manager. We have packages available for Windows, Mac OS, and Linux (32 and 64 bit).

Install the current upstream Arduino IDE at the 1.8 level or later. The current version is at the Arduino website.
Start Arduino and open Preferences window.
Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field. You can add multiple URLs, separating them with commas.
Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

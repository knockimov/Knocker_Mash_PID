<h2>Installation av Arduino IDE och överföring av sketcher</h2>
<h3>Översättning pågår!!!</h3>

<h4>Ubidots</h4>
Ubidots är en platform för att samla och grafiskt visa datapunkter, även där all data kommer att sparas från din Mash PID. Börja med att skapa ett konto på <a href="www.ubidots.com">Ubidots.com</a>. Det tar bara någon minut och är helt gratis. När du har ditt konto klart behöver du skapa en ny enhet genom att först klicka på "Devices" och sedan på "Add Device", namnge den MashPID eller liknande.
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-002.JPG"></img>

Klicka nu på din nya enhet för att öppna den. Ubidots bygger på att data loggas i olika variabler, en för varje typ av data som loggas. Du behöver nu skapa tre nya variabler genom att trycka på "Add variable". Namnge den första variabeln "Temperatur1", andra "Temperatur2" och sista "Setpoint".
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-003.JPG"></img>

Du behöver skriva ner fyra stycken ID, dem tre från variablerna och den fjärde är din token. Din token hittar du under användarmenyn och "API Credentials".
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-004.JPG"></img>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-005.jpg"></img>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-006.jpg"></img>

Setup
You will need a laptop and a micro USB cable (like the one that you charge a phone with). On the laptop, we need to install some software to be able to program the ESP8266. Visit Arduino.cc and install the Arduino IDE.

Arduino IDE

Once the Arduino IDE is installed, open the program so we can do a couple of setup steps to get it ready to program ESP8266 devices. Under File, Preferences, and Additional Boards Manager URLs, add this link: http://arduino.esp8266.com/stable/package_esp8266com_index.json – this will allow the Arduino IDE to manage ESP8266 compatiable boards.

Arduino Preferences for ESP8266 programming

The thing that you bought from Amazon uses the CP2102 USB driver. You might have to install a USB driver from Silicon Labs for this to work with your computer. Connect the ESP8266 to your laptop with the micro USB cable.

USB Driver for the ESP8266 CP2102

Back on the Arduino IDE, under tools, configure the following settings:
Arduino Board Settings for NodeMCU

Whew. We got through the setup. Now we can program this device or any ESP8266 compatible device and shouldn’t have to do that again.

Programming
The code that the Arduino IDE uses is called a “sketch” – this is just a short program that the device runs over and over. In our project, we are going to have the code measure the signal strength of the Wi-Fi connection and upload the data to ThingSpeak, wait, and repeat. Over time we can see the signal strength of our Wi-Fi connection. Copy the example code to your Arduino IDE and change some of the defaults to match your Wi-Fi network and ThingSpeak settings.

Once everything is set, click Sketch and then Upload. This will take the code and program the ESP8266 with it. It takes a minute so be patient. If anything goes wrong, make sure that you have the right board settings and that your “Port” matches what your laptop thinks the port is.

Back on ThingSpeak, you should see data start to come in. You are looking for the Private View of your channel and a chart that is updating. As new dsata comes in, the chart shows the latest value. If you carry the ESP8266 around the house, you might notice the signal strength changing.

<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<ul>
<li>Arduino IDE: <a href="https://www.arduino.cc/en/Guide/Windows"> länk</a> (ny hemsida)</li>
<li>ESP8266 Arduino: <a href="https://github.com/esp8266/Arduino#installing-with-boards-manager"> länk</a> (ny hemsida)</li>
<li>Överföra sketcherna: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/TRANSFER.md"> länk</a> - <b>Du är här!</b></li>
</ul>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>

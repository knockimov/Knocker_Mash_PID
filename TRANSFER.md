<h2>Installation av Arduino IDE och överföring av sketcher</h2>
<h3>Översättning pågår!!!</h3>
Oh, my. I am sure you have been hearing about the Internet of Things… The IoT! You might be wondering how to get started with i(o)t. There are many places to start. You might be interested in the data that devices collect and analyzing it or you might be interested in how to deploy thousands of sensors around a factory floor to better understand how efficient things are. You might just want to tinker. Be the cool person at the party talking about Arduino, Raspberry Pi, and Maroon 5. If you want to try out a “thing” – a small, connected device – that can measure data, I will help you get started with a quick tutorial using the ESP8266 “thing”.

Parts
First, you need to go by a thing on Amazon. I recommend for this project an ESP8266 compatible device like the esp-01. Don’t be scared. Add it to your Amazon shopping list or ask Alexa to buy you one. It’s $8.

ESP8266-01

Other parts that you will need:

Laptop
Micro USB cable
ThingSpeak
While you are waiting for your Amazon stuff to arrive, you can learn about ThingSpeak.

ThingSpeak IoT Platform

ThingSpeak is where we are going to store the data collected by our thing and where we can see the data that we collected. Visit ThingSpeak.com and Sign Up for an account. This will just take a minute and user accounts are free. Once you have a user account, you need to create a channel. ThingSpeak channels are where data gets stored. Create a new channel by selecting Channels, My Channels, and then New Channel. Name the channel, “ESP8266 Signal Strength” and name Field 1, “RSSI”. Click “Save Channel” at the bottom to finish the process.

Channel_Settings

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
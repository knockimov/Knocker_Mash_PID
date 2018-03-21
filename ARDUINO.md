<h2>Ubidots förberedelse och installation av Arduino IDE</h2>

<h4>Ubidots</h4>
Ubidots är en platform för att samla och grafiskt visa datapunkter, även där all data kommer att sparas från din Mash PID. Börja med att skapa ett konto på <a href="www.ubidots.com">Ubidots.com</a>. Det tar bara någon minut och är helt gratis. När du har ditt konto klart behöver du skapa en ny enhet genom att först klicka på "Devices" och sedan på "Add Device", namnge den MashPID eller liknande.<br>
<img width="500" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-002.JPG"></img>

Klicka nu på din nya enhet för att öppna den. Ubidots bygger på att data loggas i olika variabler, en för varje typ av data som loggas. Du behöver nu skapa tre nya variabler genom att trycka på "Add variable". Namnge den första variabeln "Temperatur1", andra "Temperatur2" och sista "Setpoint".<br>
<img width="300" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-003.JPG"></img>

Du behöver skriva ner fyra stycken ID, dem tre från variablerna och den fjärde är din token. ID-nr från variablerna hittar du om du klickar dig in på själva variabeln och sedan läser av i vänstermenyn. Din token hittar du under användarmenyn och "API Credentials".<br>
<img height="333" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-004.JPG"></img>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-005.jpg"></img>
<img width="550" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sk%C3%A4rmklipp-006.jpg"></img><p>

<h4>Installera Arduino IDE och ESP8266-platformen</h4>
För att kunna överföra sketcherna behöver du installera ett program från Arduino som de kallar för Arduino IDE. Besök <a href="https://www.arduino.cc/en/Guide/Windows">Arduino.cc</a> och installera den senaste versionen, 1.8 eller senare. När programmet är installerat startar du det och väljer "File" och sedan "Preferences".
Fyll i länken http://arduino.esp8266.com/stable/package_esp8266com_index.json i fältet "Additional Board Manager URLs". Tryck sedan OK.
Nu får du öppna "Boards Manager" genom att trycka op "Tools" och sedan "Board" för att installera ESP8266-platformen.<p>
  
Nu är hela installationen klar och det är dags att föra över sketcherna till din Arduino Nano och ESP-01.<p>

<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>

<ul>
<li>Installationsguide: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/TRANSFER.md"> länk</a> - <b>Du är här!</b></li>
<li>Arduino IDE: <a href="https://www.arduino.cc/en/Guide/Windows"> länk</a> (ny hemsida)</li>
<li>ESP8266 Arduino: <a href="https://github.com/esp8266/Arduino#installing-with-boards-manager"> länk</a> (ny hemsida)</li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<li>Överföra sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/TRANSFER.md"> länk</a> - <b>Du är här!</b></li>
</ul>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>

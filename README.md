# Knocker Mash PID
<h2>En PID-regulator för mäskning och kokning av vört. Byggd runt Arduino Nano och ESP-01.</h2>

<h4>Denna PID är en IoT (Internet of Things) och är uppkopplad mot Ubidots för loggning av mäsktemperatur och börvärdet som du ställer in.
Det ger dig möjlighet att visuellt få en bild av hur temperatturen varit under hela mäskningen genom att den loggade datan presenteras i
prydliga grafer. För att göra hela denna IoT ännu bättre är det även en PID som fixar att hålla din mäsk helt precis i rätt temperatur.<br>
Det kommer dock krävas av dig att du testar några startvärden som ligger utanför standardvärdena som är inställda. När du hittar ett värde
som ligger runt 0.5 grader kan du slå på autoPID och göra en automatisk inställning av värdena som behövs för att hålla din mäsk i perfekt
temperatur.</h4>

<h5>I kapitlen nedan kommer jag ge dig informationen om hur du gör detta helt själv, med relativt små ekonomiska medel.</h5>

<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/temp_setpoint_graph.png"></img>


<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>
<li>Installationsguide: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/ARDUINO.md"> länk</a></b></li>
<ul>
<li>Arduino IDE: <a href="https://www.arduino.cc/en/Guide/Windows"> länk</a> (ny hemsida)</li>
<li>ESP8266 Arduino: <a href="https://github.com/esp8266/Arduino#installing-with-boards-manager"> länk</a> (ny hemsida)</li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<li>Överföra sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/TRANSFER.md"> länk</a></b></li>
</ul>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul><p>

<h4>Idé och inspiration kommer från <a href="https://learn.adafruit.com/sous-vide-powered-by-arduino-the-sous-viduino/">Sous Viduino</a>.
Därifrån har jag gjort kodförändringar så den passar för mäskning istället.</h4>

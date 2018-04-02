<h2>Ladda upp sketcherna</h2>
Börja med att ladda ner sketcherna och biblioteket
<ul>
  <li>Nano & ESP8266 - <a href="https://github.com/knockimov/Knocker_Mash_PID/releases/latest">Ladda ner</a></li>
  <li>Bibliotek - <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/arduino/librarys/librarys.zip">Ladda ner</a></li>
</ul>
ZIP-filerna packas upp i din skissboksplats, biblioteket under "Libraries" och dem andra två direkt i mappen. Skissboksplatsen hittar du om du går in under inställningar i Arduino IDE. Skulle ingen mapp vara vald får du skapa och välja en.
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sketch_skissbokplats.png"></img>

Sedan är det dags att fylla i värdena från Ubidots, alltså din token och ID-numrena till variablerna du skapade i <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/ARDUINO.md">i detta steg</a>, i sketchen för din ESP8266 samt ditt SSID och lösenord. Öppna nu själva sketchen och fylla upp dessa uppgifter så sketchen är redo för att laddas upp.
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sketch_ESP.png"></img>

När detta är gjort är det dags att även öppna sketchen till din Nano. När sketchen är öppnad i Arduino IDE kopplar du in USB-sladden i datorn och i microkontrollern. Datorn bör hitta den direkt och du kan välja COM-porten som kontrollern är mappad till. Porten väljer du under "Tools", "Verktyg" om du ändrat programspråket till svenska. Sedan trycker du på knappen för att kontrollera sketchen, för att se så alla bibliotek kan hittas och inga fel uppstår innan du laddar upp sketchen. Statusen visas i medelandefältet längst ner i Arduino IDE. När det är klart och inga fel uppstår trycker du på knappen för att ladda upp sketchen. Tänk bara på att koppla bort byglingen mellan ESP8266 och Nano medans uppladdningen sker (om du byggt ihop din PID), annars kommer du få felmeddelanden. När uppladdningen är klar kan du koppla ur microkontrollern.
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Sketch_upload.png"></img>

Sedan är det dags att ladda upp sketchen för ESP8366. Du får nu koppla in USB-kabeln till USB-till-TTL-kortet istället. Från TTL-kortet dra jumperkablar till "RX/TX-" och "+IN-portarna" på kretskortet (eller din breadboard om du använder det). Tryck och håll in "FLASH-knappen" medan du en gång trycker på "RESET-knappen". Nu är din ESP8266 i programeringsläge och det går att ladda upp sketchen.<br>
Gör nu lika dant som ovan men att du istället använder sketchen för ESP8266.
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Knocker_Mash_PID-Nano_ESP8266F-v100_bb.png"></img>

Bygla nu tillbaka RX/TX-porten och koppla in USB-kabeln till din Nano. Nu kommer din PID att starta och börja logga temperatur och börvärde. Tänk på att inga värden ges så länge din PID står i startläget, tryck en gång till höger för att låta din PID att arbeta. Kontrollera nu din Ubidotskanal under "Devices" för att se så värden skickas upp.

<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>
<li>Installationsguide: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/ARDUINO.md"> länk</a></li>
<ul>
<li>Arduino IDE: <a href="https://www.arduino.cc/en/Guide/Windows"> länk</a> (ny hemsida)</li>
<li>ESP8266 Arduino: <a href="https://github.com/esp8266/Arduino#installing-with-boards-manager"> länk</a> (ny hemsida)</li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<li>Överföra sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/TRANSFER.md"> länk</a> - <b>Du är här!</b></li>
</ul>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>

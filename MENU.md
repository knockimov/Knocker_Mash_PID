# Knocker Mash PID
<h2>En PID-regulator för mäskning och kokning av vört. Byggd runt Arduino Nano och ESP-01.</h2>

För att styra din PID används dem fem knapparna. Menysystemet är uppbyggt enligt nedan schema.

<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menyorientering.png"></img>

<h4>Uppstart</h4>
När din PID startas kommer den stå i läget "Avstängd". I det läget händer inget och själva systemet
väntar på användarinput. Din PID är förinställd med P = 85, I = 0,5 och D = 0,5.<br>
<img width="40%" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menu_off.jpg"> <img width="40%" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menu_running.jpg"></img><br>

För att slå på den och ändra inställningar gör du så här:
1. Starta systemet genom att trycka på höger knapp en gång.
- Då slår systemet på temperaturmätarna och automatiskt ställa temperaturen efter börvärdet. Detta
är också startläget och där du ser alla temperaturer och effekten värmaren är på.
2. För att ställa in börvärdet trycket du en gång på höger knapp.
- Nu kan du höja eller sänka värdet genom att trycka upp eller ner. Värdet höjs med 0,1 grader
per knapptryckning, ökas eller minskad med 10 om man trycker in select. Trycker du in select
igen kommer den höja med 0,1 grader igen. När du slutar att trycka kommer systemet att automatiskt
spara värdet och gå tillbaka till startläget efter tre sekunder.
3. För att ändra P-värdet trycker du två gånger på högra knappen.
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,1 per knapptryckning,
10 om man trycker in select och 0,1 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.
4. För att ändra I-värdet trycker du tre gånger på högra knappen.
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,01 per knapptryckning,
10 om man trycker in select och 0,01 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.
5. För att ändra D-värdet trycker du fyra gånger på högra knappen.
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,01 per knapptryckning,
10 om man trycker in select och 0,01 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.<p>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menu_buttons.jpg"></img><br>

<h4>AutoPID - automatisk inställning av värden</h4>
Om du skulle vilja testa att be din PID att automatiskt ställa in värden som funkar för ditt systen så
behöver temperaturen ligga 0.5 grader celsius från ditt börvärde innan funktionen aktiveras. När du
håller ett relativt nära värde aktiveras autoPID med knappvalet "Select" och "Right" samtidigt. Då
kommer din PID att kalibrera sina värden automatiskt. När den är klar kommer du kunna att finjustera
värdena enligt anvisningarna ovan.

<h4>Startlägets layout</h4>
I startläget (automatiskt) ser du i övre raden på LCD-skärmen börvärdet och procentuellt hur hög
styrningen är för värmeelementet. I andra raden är båda temperaturmätarna som ger aktuell temperatur.<br>
<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menu_running.jpg"></img><br>

<h4>Manuellt läge</h4>
För att köra din PID i manuellt läge trycker du två gång på vänstra knappen om du står i startläget,
annars bara en gång. Här styr du manuellt den procentuella effekt som värmeelementet skall arbeta på.
Väldigt behändigt om du skall koka. Du ändrar värdet med knapparna upp och ner och värdet höjs med 5
procent per knapptryckning och 50 om du trycker på select, åter igen med 5 om select trycks in igen.
För att stänga av den snabbt vid kokslut trycker en gång åt höger, annars sänka värdet med nerknappen.<p>

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
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a> <b>- Du är här!</b></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>

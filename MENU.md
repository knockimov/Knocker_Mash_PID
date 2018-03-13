# Knocker Mash PID
<h2>En PID-regulator för mäskning och kokning av vört. Byggd runt Arduino Nano och ESP-01.</h2>

För att styra din PID används dem fem knapparna. Menysystemet är uppbyggt enligt nedan schema.

<img src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/menyorientering.png"></img>

När din PID startas kommer den stå i läget "Avstängd" I det läget händer inget och själva systemet
väntar på användarinput. Din PID är förinställd med P = 85, I = 0,5 och D = 0,5.<p>

För att slå på den och ändra inställningar gör du så här:
1. Starta systemet genom att trycka på höger knapp en gång.
- Då slår systemet på temperaturmätarna och börjar ställa temperaturen efter börvärdet.
2. För att ställa in börvärdet trycket du en gång på höger knapp.<br>
- Nu kan du höja eller sänka värdet genom att trycka upp eller ner. Värdet höjs med 0,1 grader
per knapptryckning, ökas eller minskad med 10 om man trycker in select. Trycker du in select
igen kommer den höja med 0,1 grader igen. När du slutar att trycka kommer systemet att automatiskt
spara värdet och gå tillbaka till startläget efter tre sekunder.<br>
3. För att ändra P-värdet trycker du två gånger på högra knappen.<br>
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,1 per knapptryckning,
10 om man trycker in select och 0,1 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.
4. För att ändra I-värdet trycker du tre gånger på högra knappen.<br>
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,01 per knapptryckning,
10 om man trycker in select och 0,01 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.
5. För att ändra D-värdet trycker du fyra gånger på högra knappen.<br>
- Höj eller sänk värdet med upp och ner knapparna. Höjs och minskas med 0,01 per knapptryckning,
10 om man trycker in select och 0,01 om man trycker in select en gång till. När du slutar att trycka
kommer systemet att automatiskt spara värdet och gå tillbaka till startläget efter tre sekunder.<p>

I startläget (automatiskt) ser du i övre raden börvärdet och procentuellt hur hög styrningen är för
värmeelementet. I andra raden är båda temperaturmätarna som ger aktuell temperatur.<p>

För att köra din PID i manuellt läge trycker du två gång på vänstra knappen. Här styr du manuellt
procentuellt vilken effekt som värmeelementet skall arbeta på. Väldigt behändigt om du skall koka.
Du ändrar värdet med knapparna upp och ner och stänger av den genom att trycka en gång åt höger.<p>

<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<li>Arduino IDE: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/ARDUINO.md"> länk</a></li>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a> - <b>Du är här!</b></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>
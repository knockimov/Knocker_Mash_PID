# Knocker Mash PID
<h2>En PID-regulator för mäskning och kokning av vört. Byggd runt Arduino Nano och ESP-01.</h2>

<h4>Att bygga denna PID är inte speciellt komplicerat eller invecklat. Antingen bygger du den med hjälp av en breadboard och jumprar eller
beställer ett färdigt kretskort (PCB). Länk till mina Gerber-filer finns lite längre ner.</h4>

<img width="500" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Knocker_Mash_PID-Nano_ESP8266F-v100_bb.png"></img>
<img width="250" src="https://github.com/knockimov/Knocker_Mash_PID/blob/master/images/Knocker_Mash_PID-PCB-v100.png"></img>

<h4>Jag länkar till komponenterna på Ebay för att där är det både enklast och till största del även billigast. När jag sökt sorterar jag
träfflistan efter försäljare i Europa för att slippa "Kina-kostnaderna" som Postnord numera tar ut. Länkarna givna kommer inte att ge dig
det lägsta priset med den lägsta (fria leveransen) leveransen utan bara en fingervisning på vilken produkt som behövs för att bygga denna
PID.</h4>

<h4>Jag ger dig förutom denna listan möjlighet att löda på allt på ett färdigt kretskort, även möjlighet att få allt färdigt men då till
ett pris som inte är lika fördelaktigt. Skulle kort, lödning eller något liknande så får du gärna kontakta mig på pierre"dot"tunander"at"gmail"dot"com
("dot = .", "at = @").

Antal|Komponent|Länk
-----|---------|----
1st|ESP8266-01|<a href="https://www.ebay.com/itm/D1-mini-Mini-NodeMcu-4M-Lua-WIFI-IoT-development-board-based-ESP8266-by-WeMos-/222620206044">LÄNK</a>
1st|Arudino Nano v3|<a href="https://www.ebay.com/itm/Nano-V3-0-Controle-Board-Atmega328P-Compatible-Arduino-Nano-V3-CH340-/322908047187">LÄNK</a>
1st|Solid State Relay|<a href="https://www.ebay.com/itm/Rele-SSR-40DA-statico-stato-solido-40A-380-24Vac-32-3Vdc-solid-state-relay/322373636211?hash=item4b0ef75073:g:YwEAAOSwzgBYzEgd">LÄNK</a>
1st|5V till 3.3V regulator|<a href="https://www.ebay.com/itm/25pcs-AMS1117-LDO-3-3v-low-dropout-voltage-regulator-SOT223/131815323527?hash=item1eb0ce3787:g:udEAAOxyyFhTehpM">LÄNK</a>
1st|5V Fläkt 40x40mm|<a href="https://www.ebay.com/itm/DC-5V-2P-4010-Brushless-Fan-Cooler-40mm-40x40x10mm-4010s-Cooling-Fan/252578080018?hash=item3aced3a512:g:9ocAAOSwU8hY8Sfa">LÄNK</a>
2st|DS18B20 Sensor|<a href="https://www.ebay.com/itm/Sonda-con-Sensore-Temperatura-DS18B20-Cavo-Digitale-Impermeabile-Inox-1m-Arduino/152534796710?hash=item2383c849a6:g:QqMAAOSwcrpadGHc">LÄNK</a>
1st|Resistor 4.7k Ohm|<a href="https://www.ebay.com/itm/Set-of-10-resistors-metal-1-4-watts-1-24-values-choice-1-Ohm-at-3-4-12ft/263390277429?hash=item3d5348af35:m:mtBeVcs4bTmH-uPQlroeYrQ">LÄNK</a>
7st|Knappar|<a href="https://www.ebay.com/itm/10x-Push-button-White-6x6x6-mm-PCB-Switch-mini-touch-micro-4-pin-arduino/282832592950?hash=item41da22e036:g:HS0AAOxyY3ZRmks42">LÄNK</a>
Xst|Jumperkablar - hane |<a href="https://www.ebay.com/itm/10-Cables-macho-macho-20cm-arduino-nano-uno-jumpers-dupont-2-54-protoboars/253483109669?hash=item3b04c54d25:g:KAgAAOSwHnFV4uwM">LÄNK</a>
Xst|Jumperkablar - hona |<a href="https://www.ebay.com/itm/40pcs-Dupont-Female-to-Female-Jumper-Wire-Ribbon-Cable-Pi-Breadboard-Arduino-CN/282673197345?hash=item41d0a2b121:g:Gd8AAOSw7rdaaPja">LÄNK</a>

<h3>Snabblänkar:</h3>
<ul>
<li>Komponentlista: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/COMPONENTS.md"> länk</a> - <b>Du är här!</b></li>
<li>Gerber-filer (PCB): <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/gerber"> länk</a></li>
<li>Bygginstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/BUILD.md"> länk</a></li>
<li>Sketcher: <a href="https://github.com/knockimov/Knocker_Mash_PID/tree/master/arduino"> länk</a></li>
<li>Arduino IDE: <a href="https://www.arduino.cc/en/Guide/Windows"> länk</a> (ny hemsida)</li>
<li>ESP8266 Arduino: <a href="https://github.com/esp8266/Arduino"> länk</a> (ny hemsida)</li>
<li>Menystruktur: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/MENU.md"> länk</a></li>
<li>Användarinstruktioner: <a href="https://github.com/knockimov/Knocker_Mash_PID/blob/master/GUIDE.md"> länk</a></li>
</ul>
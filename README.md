# Klocka
README - Temperatur- och Tidsövervakning med OLED och Servo
Beskrivning
Detta projekt är en temperatur- och tidsövervakare som använder en realtidsklocka (RTC), OLED-display, LED-lampa och servo. Systemet visar aktuell tid och temperatur på OLED-skärmen, justerar servons position baserat på temperaturen och blinkar en LED som en varning om temperaturen går utanför ett visst intervall (23–25 °C).

Komponenter
Realtidsklocka (RTC_DS3231): Håller reda på aktuell tid och datum samt levererar aktuell temperatur.
OLED-display (U8GLIB_SSD1306_128X64): Visar tid och temperatur i textformat.
Servo (Servo.h): Justeras utifrån temperaturen, där en högre temperatur ger ett större servo-vridningsvinkel.
LED (Pin 12): Tänds och blinkar för att varna om temperaturen går utanför det fördefinierade intervallet (23–25 °C).
Kodstruktur och Funktioner
setup()
Sätter upp OLED-skärmen, startar seriell kommunikation, initierar RTC och ställer in tiden.
Sätter LED-pinnen som en utgång.
Initierar servo på angiven pinne och ställer in dess ursprungliga position till 0 grader.
loop()
Anropas kontinuerligt för att:
Visa aktuell tid och temperatur på OLED-skärmen.
Justera servons position baserat på aktuell temperatur.
Blinkar LED-lampan om temperaturen är utanför det fördefinierade intervallet.
getTemp()
Hämtar temperaturen från RTC-modulen och returnerar den som en sträng för visning på OLED.
servoWrite(float value)
Mappar temperaturen till ett servo-vinkelintervall (0–180 grader).
Blinkar LED-lampan 5 gånger om temperaturen är utanför intervallet (23–25 °C).
Slår på LED-lampan när funktionen körs för att indikera aktivitet.
getTime()
Hämtar aktuell tid från RTC-modulen och returnerar den som en formaterad sträng för visning på OLED.
oledWrite(String text, String text2)
Skriver text (tid och temperatur) på OLED-skärmen genom att rensa och uppdatera displayen i varje uppdatering.
Krav
Bibliotek:
RTClib för RTC-funktionalitet.
U8glib för att hantera OLED-skärmen.
Servo.h för att styra servon.
Installation och Användning
Koppla upp hårdvaran enligt schemat:
Anslut RTC-modulen via I2C.
Anslut OLED-skärmen via I2C.
Anslut servon till angiven pin.
Anslut en LED till pin 12 (med resistor).
Ladda upp koden till din Arduino och kör.
OLED-skärmen visar nu tid och temperatur, servon justeras baserat på temperaturen, och LED
varnar om temperaturen går utanför intervallet.
Förbättringar och Utökningar
Justera intervallvärden för temperaturövervakning vid behov.
Utöka koden för att spara och visa tidigare temperaturvärden.

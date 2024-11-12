#include <RTClib.h>
#include <Wire.h>
#include "U8glib.h"
#include <Servo.h>
#define LED_PIN 12

RTC_DS3231 rtc;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
Servo myServo;

const int servoPin = 9;

void setup() {
  u8g.setFont(u8g_font_unifont);
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
  pinMode(LED_PIN, OUTPUT);
  myServo.attach(servoPin);  
  myServo.write(0);
}

void loop()
{
  oledWrite(getTime(), getTemp());
  servoWrite(rtc.getTemperature());

  delay(1000);  
}

String getTemp()
{
  float temperature = rtc.getTemperature();
  String tempText = "Temp: " + String(temperature) + " C";
  return tempText;
}

void servoWrite(float value)
{
  int servoAngle = map(value, 23, 25, 0, 180);
  servoAngle = constrain(servoAngle, 0, 180);
  myServo.write(servoAngle);
  if (value > 25 || value < 23)
  {
    for (int i = 0; i < 5; ++i)
    {
      digitalWrite(LED_PIN, HIGH);   
      delay(500);                     
      digitalWrite(LED_PIN, LOW); 
      delay(500);
    }
  }
  digitalWrite(LED_PIN, HIGH);
}

String getTime()
{
  DateTime now = rtc.now();
  String displayText = "Time: " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  return displayText;
}

void oledWrite(String text, String text2) {
  u8g.firstPage();
  do {
    u8g.drawStr(0, 20, text.c_str());
    u8g.drawStr(0, 40, text2.c_str());
  } while (u8g.nextPage());
}


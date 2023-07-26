#include <M5StickCPlus.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(9); // バックライトの明るさ(7-15)
  Wire.begin(32, 33, 100000);
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(2, 2);
  
  //Serial.begin(115200);
  if (! sgp.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }

  Serial.print("Found SGP30 serial #");
  Serial.print(sgp.serialnumber[0], HEX);
  Serial.print(sgp.serialnumber[1], HEX);
  Serial.println(sgp.serialnumber[2], HEX);
}

void loop() {
  unsigned long sec = millis() / 1000;
  M5.Lcd.setCursor(2, 2);
  
  if (!sgp.IAQmeasure()) {
    Serial.println("Measurement failed");
    return;
  }
  if (sgp.eCO2 < 1000) {
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setTextColor(TFT_WHITE);
  }
  else if ((1000 < sgp.eCO2) && (sgp.eCO2 < 2000)) {
    M5.Lcd.fillScreen(TFT_ORANGE);
    M5.Lcd.setTextColor(TFT_BLACK);
  }
  else if (2000 < sgp.eCO2) {
    M5.Lcd.fillScreen(TFT_RED);
    M5.Lcd.setTextColor(TFT_BLACK);
  }

  M5.Lcd.print("eCO2:\t");
  M5.Lcd.print(sgp.eCO2);
  M5.Lcd.println("\tppm");
  M5.Lcd.println("");

  M5.Lcd.print("TVOC:\t");
  M5.Lcd.print(sgp.TVOC);
  M5.Lcd.println("\tppb");
  
  delay(1000);
}

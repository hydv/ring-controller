#include <M5StickC.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

int i = 0;
int j = 0;

void setup() {
  M5.begin();
  M5.Axp.ScreenBreath(7);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Starting");
  Serial.begin(9600);
  bleKeyboard.begin();
  pinMode(33, INPUT);
}

void loop() {
  M5.update();
  if(bleKeyboard.isConnected()) {
//    if ( M5.BtnA.wasPressed() ){
//       M5.Lcd.fillScreen(TFT_BLACK);
//       M5.Lcd.setCursor(0, 0);
//       M5.Lcd.println("Send KEY_LEFT_ARROW from A");
//       bleKeyboard.press(KEY_LEFT_ARROW);
//       delay(30);
//       bleKeyboard.releaseAll();
//    }
    int d = digitalRead(33);
    Serial.println(d);
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(0, 0);
    if(d == 1) {
      bleKeyboard.press(KEY_LEFT_ARROW);
      M5.Lcd.println("Send KEY_LEFT_ARROW");
      delay(10);
      bleKeyboard.releaseAll();
      delay(300);
    }
  }
  delay(10);
}

#include "M5Atom.h"

int i = 0;

void setup()
{
  M5.begin(true, false, true);
  delay(10);
  Serial.begin(9600);
  Serial.println("Work");
  pinMode(32, OUTPUT);
}

void loop()
{
  if (M5.Btn.wasPressed()){
    digitalWrite(32, HIGH);
    Serial.println("Sending");
    i = 1;
    delay(300);
  }else{
    digitalWrite(32, LOW);
    i = 0;
  }
  delay(10);
  M5.update();
}

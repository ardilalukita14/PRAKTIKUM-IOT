#include <Arduino.h>

#define RED_LED D0 // mendefinisikan pin D0

void setup() {
  Serial.begin(115200);
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(RED_LED, HIGH); //LED RED menyala
  // digitalWrite(BUILTIN_LED, LOW); //LED BLUE mati
  delay(1000);
  digitalWrite(RED_LED, LOW);
  // digitalWrite(BUILTIN_LED, HIGH);
  delay(1000);
  // put your main code here, to run repeatedly:
}
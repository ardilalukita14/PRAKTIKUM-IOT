#include <Arduino.h>

#define RED_LED D7   // led warna merah
#define GREEN_LED D1 // led warna hijau
#define BLUE_LED D6  // led warnah biru
#define BIRU_LED D0  // led biru bawaan
#define MERAH_LED D4 // led merah bawaan

void setup()
{
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); // atur pin-pin digital sebagai output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BIRU_LED, OUTPUT);
  pinMode(MERAH_LED, OUTPUT);

  Serial.println("Program LED RGB dan LED ESP8266 SOS");
}

void loop()
{
  // 3 dits (3 titik atau huruf S)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(RED_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(GREEN_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(GREEN_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    // digitalWrite(BLUE_LED, HIGH); // LED nyala
    // delay(150);                  // delay selama 150ms
    // digitalWrite(BLUE_LED, LOW);  // LED mati
    // delay(100);                  // delay selama 100ms

    digitalWrite(BIRU_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(BIRU_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(MERAH_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(MERAH_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms


  }
  delay(100);

  // 3 dahs (3 garis atau huruf O)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); // LED nyala
    delay(400);                  // delay selama 400ms
    digitalWrite(RED_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(GREEN_LED, HIGH); // LED nyala
    delay(400);                  // delay selama 400ms
    digitalWrite(GREEN_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    // digitalWrite(BLUE_LED, HIGH); // LED nyala
    // delay(400);                  // delay selama 400ms
    // digitalWrite(BLUE_LED, LOW);  // LED mati
    // delay(100);                  // delay selama 100ms

    digitalWrite(BIRU_LED, HIGH); // LED nyala
    delay(400);                  // delay selama 400ms
    digitalWrite(BIRU_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(MERAH_LED, HIGH); // LED nyala
    delay(400);                  // delay selama 400ms
    digitalWrite(MERAH_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms


  }

  // 100ms delay to cause slight gap between letters
  delay(100);
  // 3 dits again (3 titik atau huruf S)
  for (int x = 0; x < 3; x++)
  {
    digitalWrite(RED_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(RED_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(GREEN_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(GREEN_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    // digitalWrite(BLUE_LED, HIGH); // LED nyala
    // delay(150);                  // delay selama 150ms
    // digitalWrite(BLUE_LED, LOW);  // LED mati
    // delay(100);                  // delay selama 100ms

    digitalWrite(BIRU_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(BIRU_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

    digitalWrite(MERAH_LED, HIGH); // LED nyala
    delay(150);                  // delay selama 150ms
    digitalWrite(MERAH_LED, LOW);  // LED mati
    delay(100);                  // delay selama 100ms

  }

  // wait 5 seconds before repeating the SOS signal
  delay(5000);
}
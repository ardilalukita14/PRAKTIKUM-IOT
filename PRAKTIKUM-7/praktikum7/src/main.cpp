#include <Arduino.h>

// #define sensorLDR A0
// int nilaiSensor;

// void setup()
// {
//   Serial.begin(115200);
//   Serial.println("Contoh Penggunaan Sensor LDR");
//   delay(3000);
// }

// void loop()
// {
//   nilaiSensor = analogRead(sensorLDR);
//   Serial.print("Nilai Sensor : ");
//   Serial.println(nilaiSensor);
//   delay(1000);
// }

// #define triggerPin D6
// #define echoPin D5

// void setup() {
//    Serial.begin (115200);
//    pinMode(triggerPin, OUTPUT);
//    pinMode(echoPin, INPUT);
//    pinMode(BUILTIN_LED, OUTPUT);
// }

// void loop() {
//    long duration, jarak;
//    digitalWrite(triggerPin, LOW);
//    delayMicroseconds(2);
//    digitalWrite(triggerPin, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(triggerPin, LOW);
//    duration = pulseIn(echoPin, HIGH);
//    jarak = duration * 0.034 / 2;
//    Serial.print(jarak);
//    Serial.println(" cm");
//    delay(2000);
// }

// #define triggerPin D6
// #define echoPin D5

// #define RED_LED D4   // led warna merah
// #define GREEN_LED D1 // led warna hijau
// #define BLUE_LED D2  // led warnah biru

// void setup()
// {
//   Serial.begin(115200);
//   pinMode(triggerPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   pinMode(RED_LED, OUTPUT); // atur pin-pin digital sebagai output
//   pinMode(GREEN_LED, OUTPUT);
//   pinMode(BLUE_LED, OUTPUT);
//   //pinMode(BUILTIN_LED, OUTPUT);
// }

// void loop() {
//    long duration, jarak;
//    digitalWrite(triggerPin, LOW);
//    delayMicroseconds(2);
//    digitalWrite(triggerPin, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(triggerPin, LOW);
//    duration = pulseIn(echoPin, HIGH);
//    jarak = duration * 0.034 / 2;
//    Serial.print(jarak);
//    Serial.println(" cm");
//    delay(2000);

//    if (jarak <= 1 )
//     {
//         Serial.println("Jarak benda 1 cm");
//         digitalWrite(RED_LED, LOW);
//         digitalWrite(GREEN_LED, LOW);
//         digitalWrite(BLUE_LED, HIGH);
//         //delay(1000);
//     }
//     if (2 <= jarak && jarak < 3 )
//     {
//         Serial.println("Jarak benda 2 cm");
//         digitalWrite(RED_LED, LOW);
//         digitalWrite(GREEN_LED, HIGH);
//         digitalWrite(BLUE_LED, LOW);
//         //delay(1000);
//     }
//     if (3 <= jarak && jarak < 4 )
//     {
//         Serial.println("Jarak benda 3 cm");
//         digitalWrite(RED_LED, HIGH);
//         digitalWrite(GREEN_LED, LOW);
//         digitalWrite(BLUE_LED, LOW);
//         //delay(1000);
//     }
//     if (jarak > 3 )
//     {
//         Serial.println("Jarak benda melebihi 3 cm");
//         digitalWrite(RED_LED, HIGH);
//         digitalWrite(GREEN_LED, HIGH);
//         digitalWrite(BLUE_LED, HIGH);
//         delay(1000);
//     }
// }

#include <DHT.h>

#define DHTTYPE DHT11
#define RED_LED D5   // led warna merah
#define GREEN_LED D6 // led warna hijau
#define BLUE_LED D4  // led warnah biru

DHT dht(D7, DHTTYPE);

#define sensorLDR A0
int nilaiSensor;

void setup()
{
  dht.begin();
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT); // atur pin-pin digital sebagai output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.println("Contoh Penggunaan Sensor LDR dan DHT 11");
  delay(3000);
}

void loop()
{
  nilaiSensor = analogRead(sensorLDR);
  Serial.print("Nilai Sensor : ");
  Serial.println(nilaiSensor);
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

  if (t <= 24 && nilaiSensor >= 700)
  {
    Serial.println("Cahaya redup dan suhu dingin!");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    delay(1000);
  }
  if (t >= 29 && nilaiSensor <= 600)
  {
    Serial.println("Cahaya terang dan suhu tinggi!");
    digitalWrite(RED_LED, HIGH);
    // digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }
}

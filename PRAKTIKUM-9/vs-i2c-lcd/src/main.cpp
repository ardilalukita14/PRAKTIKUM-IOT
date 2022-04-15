#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimeLib.h>
// #define DHTTYPE DHT11

#define DHTTYPE DHT11
#define RED_LED D5   // led warna merah
#define GREEN_LED D6 // led warna hijau
#define BLUE_LED D4  // led warnah biru

byte simbol_derajat = B11011111;
time_t t = now();
DHT dht(D7, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    dht.begin();
    Serial.begin(115200);
    setTime(t);
    setTime(8, 43, 00, 15, 4, 22); //(Jam,Menit,Detik,Tanggal,Bulan,Tahun)menunjukan mengatur sebuah tanggal dan jam
    pinMode(RED_LED, OUTPUT);      // atur pin:pin digital sebagai output
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    Serial.println("Menggunakan DHT11");
    lcd.init(); // initialize the lcd
    lcd.backlight();
    lcd.clear();
    lcd.home();
}

void scrollText(int row, String message, int delayTime, int lcdColumns)
{
    for (int i = 0; i < lcdColumns; i++)
    {
        message = " " + message;
    }
    message = message + " ";
    for (int pos = 0; pos < message.length(); pos++)
    {
        lcd.setCursor(0, row);
        lcd.print(message.substring(pos, pos + lcdColumns));
        delay(delayTime);
    }
}

void printkurangdarinol(int data)
{
    if (data >= 0 && data < 10)
    {
        lcd.write('0');
    }
    lcd.print(data);
}

void loop()
{
    delay(3000);
    // float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);

    if (isnan(t) || isnan(f))
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F"));
    Serial.print(F(" "));

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(t);
    lcd.write(simbol_derajat);
    lcd.print(F("C "));
    lcd.print(f);
    lcd.write(simbol_derajat);
    lcd.print(F("F"));
    // delay(3000);

    if (t <= 28)
    {
        Serial.println("Suhu Dingin!");
        digitalWrite(GREEN_LED, HIGH);
        delay(1000);
        digitalWrite(GREEN_LED, LOW);
        delay(100);
    }
    if (28 < t && t <= 30)
    {
        Serial.println("Suhu Normal!");
        digitalWrite(BLUE_LED, HIGH);
        delay(1000);
        digitalWrite(BLUE_LED, LOW);
        delay(100);
    }
    if (t > 30)
    {
        Serial.println("Suhu Panas!");
        digitalWrite(RED_LED, HIGH);
        delay(1000);
        digitalWrite(RED_LED, LOW);
        delay(100);
    }

    // 2018
    else if (day() >= 28 && month() == 2 && year() == 18)
    {
        setTime(0, 0, 0, 1, 3, 18);
    }
    else if (day() >= 30 && month() == 4 && year() == 18)
    {
        setTime(0, 0, 0, 1, 5, 18);
    }
    else if (day() >= 30 && month() == 6 && year() == 18)
    {
        setTime(0, 0, 0, 1, 7, 18);
    }
    else if (day() >= 30 && month() == 9 && year() == 18)
    {
        setTime(0, 0, 0, 1, 10, 18);
    }
    else if (day() >= 30 && month() == 11 && year() == 18)
    {
        setTime(0, 0, 0, 1, 12, 18);
    }

    // 2019
    else if (day() >= 28 && month() == 2 && year() == 19)
    {
        setTime(0, 0, 0, 1, 3, 19);
    }
    else if (day() >= 30 && month() == 4 && year() == 19)
    {
        setTime(0, 0, 0, 1, 5, 19);
    }
    else if (day() >= 30 && month() == 6 && year() == 19)
    {
        setTime(0, 0, 0, 1, 7, 19);
    }
    else if (day() >= 30 && month() == 9 && year() == 19)
    {
        setTime(0, 0, 0, 1, 10, 19);
    }
    else if (day() >= 30 && month() == 11 && year() == 19)
    {
        setTime(0, 0, 0, 1, 12, 19);
    }

    // 2020
    else if (day() >= 29 && month() == 2 && year() == 20)
    {
        setTime(0, 0, 0, 1, 3, 20);
    }
    else if (day() >= 30 && month() == 4 && year() == 20)
    {
        setTime(0, 0, 0, 1, 5, 20);
    }
    else if (day() >= 30 && month() == 6 && year() == 20)
    {
        setTime(0, 0, 0, 1, 7, 20);
    }
    else if (day() >= 30 && month() == 9 && year() == 20)
    {
        setTime(0, 0, 0, 1, 10, 20);
    }
    else if (day() >= 30 && month() == 11 && year() == 20)
    {
        setTime(0, 0, 0, 1, 12, 20);
    }

    // 2022
    else if (day() >= 28 && month() == 2 && year() == 21)
    {
        setTime(0, 0, 0, 1, 3, 21);
    }
    else if (day() >= 30 && month() == 4 && year() == 21)
    {
        setTime(0, 0, 0, 1, 5, 21);
    }
    else if (day() >= 30 && month() == 6 && year() == 21)
    {
        setTime(0, 0, 0, 1, 7, 21);
    }
    else if (day() >= 30 && month() == 9 && year() == 21)
    {
        setTime(0, 0, 0, 1, 10, 21);
    }
    else if (day() >= 30 && month() == 11 && year() == 21)
    {
        setTime(0, 0, 0, 1, 12, 21);
    }

    // 2022
    else if (day() >= 28 && month() == 2 && year() == 22)
    {
        setTime(0, 0, 0, 1, 3, 22);
    }
    else if (day() >= 30 && month() == 4 && year() == 22)
    {
        setTime(0, 0, 0, 1, 5, 22);
    }
    else if (day() >= 30 && month() == 6 && year() == 22)
    {
        setTime(0, 0, 0, 1, 7, 22);
    }
    else if (day() >= 30 && month() == 9 && year() == 22)
    {
        setTime(0, 0, 0, 1, 10, 22);
    }
    else if (day() >= 30 && month() == 11 && year() == 22)
    {
        setTime(0, 0, 0, 1, 12, 22);
    }
    else if (hour() == 0 && minute() == 0 && second() == 0)
    {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Date: ");
        printkurangdarinol(day());
        lcd.print("-");
        printkurangdarinol(month());
        lcd.print("-");
        printkurangdarinol(year());
        lcd.print("-");
        lcd.print("Time: ");
        printkurangdarinol(hour());
        lcd.print("");
        printkurangdarinol(minute());
        lcd.print(":");
    }


    lcd.setCursor(0, 1);
    // lcd.print("Date: ");
    printkurangdarinol(day());
    lcd.print("-");
    printkurangdarinol(month());
    lcd.print("-");
    printkurangdarinol(year());
    lcd.print(" ");
    /// lcd.print("Time: ");
    printkurangdarinol(hour());
    lcd.print(":");
    printkurangdarinol(minute());
    //delay(500);
}

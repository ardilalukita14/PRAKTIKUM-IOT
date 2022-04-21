#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Time.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTTYPE DHT11
DHT dht(D7, DHTTYPE);

#define RED_LED D6   // led warna merah
#define GREEN_LED D4 // led warna hijau
#define BLUE_LED D5  // led warnah biru


int timezone = 7 * 3600; // timezone
int dst = 0;             // date swing

const char *ssid = "Kochengimoet"; // nama SSID untuk koneksi Anda
const char *password = "wifigangguan"; // password akses point WIFI Anda
const uint16_t port = 2004; // diganti dengan port serve Anda
const char *host = "192.168.1.2";//diganti dengan host server Anda, bisa ip ataupun domain

WiFiClient client;

void connect_wifi()
{
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(250);
}

void connect_server()
{
  Serial.printf("\n[Connecting to %s ... ", host);
  while (!client.connect(host, port))
  {
    delay(1000);
    Serial.print(".");
    return;
  }
  Serial.println("connected]");
  delay(1000);
}

void setup()
{
  pinMode(RED_LED, OUTPUT); //atur pin-pin digital sebagai output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  Serial.begin(115200);
  Serial.println("Contoh penggunaan socket client");
  connect_wifi();
  connect_server();

  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov");
  Serial.println("Waiting for NTP");

  while (!time(nullptr))
  {
    Serial.print("*");
    delay(1000);
  }

  Serial.println("Time Response Ok");
}

void loop()
{
  delay(2000);
  time_t now = time(nullptr);
  struct tm *p_tm = localtime(&now);

  float h = dht.readHumidity();        // Read Humidity
  float c = dht.readTemperature();     // Read temp celcius
  float f = dht.readTemperature(true); // Read temp farenheit

  if (client.connected())
  {
    Serial.println("[Sending a request]");
    client.print(String("Temperature = ") + String(c) + String("C | ") + String(f) + String("F | Humidity = ") + String(h) + String("% Time=") + String(p_tm->tm_hour) + String(":") + String(p_tm->tm_min));
    Serial.print("[Response:]");
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.equalsIgnoreCase("led-on"))
    {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
    }
    else if (line.equalsIgnoreCase("led-off"))
    {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BLUE_LED, LOW);
    }
  }
  else
  {
    connect_server();
  }
  delay(250);
}
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SimpleDHT.h>

const char *ssid = "Kochengimoet";     // silakan disesuaikan sendiri
const char *password = "wifigangguan"; // silakan disesuaikan sendiri

const char *mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

// Lamp - LED - GPIO 4 = D2 on ESP-12E NodeMCU board
const int lamp = 4;

SimpleDHT11 dht11(D7);

long now = millis();
long lastMeasure = 0;

String macAddress = "";

void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
  macAddress = WiFi.macAddress();
  Serial.print(WiFi.macAddress());
}

void callback(String topic, byte *message, unsigned int length)
{
  Serial.print("Pesan diterima di topic: ");
  Serial.print(topic);
  Serial.print(". Pesan: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic 1941720043/room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if (topic == "1941720043/room/lamp")
  {
    Serial.print("Lampu Ruangan ");
    if (messageTemp == "on")
    {
      digitalWrite(lamp, HIGH);
      Serial.print("Nyala");
    }
    else if (messageTemp == "off")
    {
      digitalWrite(lamp, LOW);
      Serial.print("Mati");
    }
  }
  Serial.println();
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(macAddress.c_str()))
    {
      Serial.println("connected");
      client.subscribe("1941720043/room/lamp");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(lamp, OUTPUT);
  Serial.begin(115200);
  Serial.println("Mqtt Node-RED");
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  if (!client.loop())
  {
    client.connect("ESP8266Client");
  }

  // Serial.println(client.subscribe("1941720043/1941720043/room/lamp", 2));
  // client.unsubscribe("1941720043/1941720043/room/lamp");
  now = millis();

  if (now - lastMeasure > 5000)
  {
    lastMeasure = now;
    int err = SimpleDHTErrSuccess;

    byte temperature = 0;
    byte humidity = 0;
    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
    {
      Serial.print("Pembacaan DHT11 gagal, err=");
      Serial.println(err);
      delay(1000);
      return;
    }
    static char temperatureTemp[7];
    static char humidityHum[7];

    dtostrf(humidity, 4, 2, humidityHum);
    dtostrf(temperature, 4, 2, temperatureTemp);
    Serial.print("Temperature: ");
    Serial.println(temperatureTemp);
    Serial.print("Humidity: ");
    Serial.println(humidityHum);

    client.publish("1941720043/room/humadity", humidityHum);
    client.publish("1941720043/room/suhu", temperatureTemp);
  }
}
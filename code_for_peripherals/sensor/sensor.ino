#include <DHT.h>
#include <DHT_U.h>

int sensor = 10;
int temp;
int hum;

DHT dht(sensor, DHT22); 

void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" Humedad: ");
  Serial.println(hum);
  delay(500);
}

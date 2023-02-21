#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
char in;
int hum;
int temp;

void setup()
{
  Serial.begin(9600);
  dht.begin();
}
void loop()
{
  if(Serial.available()>0);
  {
    in=(byte)Serial.read()&~(0x20);

    if(in=='T')
    {
      temp= dht.readTemperature();
      Serial.println(temp);
    }
    else if(in=='H')
    {
      hum = dht.readHumidity();
      Serial.println(hum);
    }
  }
}

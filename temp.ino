#include <dht.h>

dht DHT;
String outgoing_message;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN,  OUTPUT);
}

void loop() {
  int chk = DHT.read11(7);
  float t = DHT.temperature;
  outgoing_message = "Temperature: " + String(DHT.temperature) + ", Humidity: " + DHT.humidity;
//  Serial.print("Temperature = ");
//  Serial.print(t);
//  Serial.println(" *C ");
  Serial.println(outgoing_message);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(30000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(30000);
}

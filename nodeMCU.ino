/*
  EchoBot on ESP8266

  This example shows how to program a Telegram Bot
  that echoes your messages.

  For a step-by-step tutorial visit:
  https://create.arduino.cc/projecthub/Arduino_Genuino/telegram-bot-library-ced4d4

  Updated 13 February 2018
  by Tommaso Laterza

  This example code is in the public domain.

*/

#include "arduino_secrets.h"
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>

// Initialize Wifi connection to the router
const char* ssid  = "UPC3885449";
const char* password = "Ab2f8awrTtww";
String from_telegram;
String from_mega = "empty yet";

// Initialize Telegram BOT
const char BotToken[] = "751604140:AAEbBlimYB8KDqDo0wPqgr_jf4it3chP6lU";

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);


void setup() {

  Serial.begin(115200);
  while (!Serial); // Wait for the Serial monitor to be opened

  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  bot.begin();

}

void loop() {
    if(Serial.available()){
      from_mega = Serial.readString();
      //Serial.write(Serial.read());
    }
    message m = bot.getUpdates(); // Read new messages
    if ( m.chat_id != 0 ){ // Checks if there are some updates
      from_telegram = m.text;
      if(from_telegram == "Temp"){
        //Serial.println("requested temp");
        bot.sendMessage(m.chat_id, from_mega);
      } else {
      //Serial.println(from_telegram);
      bot.sendMessage(m.chat_id, from_telegram);
      } 
    } else {
      //Serial.print(".");
    }
}

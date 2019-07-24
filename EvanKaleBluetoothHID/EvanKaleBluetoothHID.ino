/*******************************************************************
   A device for fetching Evan's sub count and typing it
   out via a bluetooth keyboard to the connected device

   Built using an ESP8266 with a Hc-05 flashed with HID
   firmware
   https://www.youtube.com/watch?v=y8PcNbAA6AQ

   By Brian Lough
   YouTube: https://www.youtube.com/brianlough
   Tindie: https://www.tindie.com/stores/brianlough/
   Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

// ----------------------------
// Standard Libraries - Already Installed if you have ESP8266 set up
// ----------------------------

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SoftwareSerial.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <YoutubeApi.h>
// Library for fetching the data from the YT API
//
// Install from the library manager
// https://github.com/witnessmenow/arduino-youtube-api


#include <ArduinoJson.h>
// JSON parsing library required by the YT API library
// NOTE: You must install 5.X, as the YT library doesnt
// support V6
//
// Install from the library manager (use the drop down to change version)
// https://github.com/bblanchon/ArduinoJson


#include <BPLib.h>
// Helper library for using HID features of Rn-42 modules
// (or modules with their fimrware)
//
// Install from Github
// https://github.com/witnessmenow/BPLib



//------- Replace the following! ------
char ssid[] = "SSID";       // your network SSID (name)
char password[] = "password";  // your network key
#define API_KEY "GOOGLE_API_KEY_GOES_HERE"  // your google apps API Token


// Evan's Channel ID
#define CHANNEL_ID "UCA-p1wZ5Tuz9J1_AI_A2NqA" // makes up the url of channel


// Pin config
#define RX_PIN D6 // connect to TXD of BT module
#define TX_PIN D5 // connect to RXD of BT module (logic level 3.3v!)


WiFiClientSecure client;
YoutubeApi api(API_KEY, client);


SoftwareSerial swSer(RX_PIN, TX_PIN, false, 128);

BPLib *BPMod;

unsigned long timeBetweenRequests = 60000; // 1 minute
unsigned long apiRequestDue = 0; // When API request is next Due

long subs = 0;

void setup() {

  Serial.begin(115200);

  swSer.begin(115200);

  BPMod = new BPLib(swSer);

  BPMod->begin(BP_MODE_HID, BP_HID_KEYBOARD);  //Begin HID Mode with HID KEYBOARD AS TYPE

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  //Comment out if you are using an earlier version of ESP8266
  client.setInsecure();


}

void typeOutSubCount(long subCount) {
  char message[] = "Hey! Evan's sub count is now %ld, isn't that great?";
  char buff[200];
  sprintf(buff, message, subCount);

  BPMod->sendString(buff);


}

void loop() {

  if (millis() > apiRequestDue)  {
    if (api.getChannelStatistics(CHANNEL_ID))
    {
      Serial.println("---------Stats---------");
      Serial.print("Subscriber Count: ");
      Serial.println(api.channelStats.subscriberCount);
      Serial.print("View Count: ");
      Serial.println(api.channelStats.viewCount);
      Serial.print("Comment Count: ");
      Serial.println(api.channelStats.commentCount);
      Serial.print("Video Count: ");
      Serial.println(api.channelStats.videoCount);
      // Probably not needed :)
      //Serial.print("hiddenSubscriberCount: ");
      //Serial.println(api.channelStats.hiddenSubscriberCount);
      Serial.println("------------------------");

      typeOutSubCount(api.channelStats.subscriberCount);
    }
    apiRequestDue = millis() + timeBetweenRequests;
  }
}

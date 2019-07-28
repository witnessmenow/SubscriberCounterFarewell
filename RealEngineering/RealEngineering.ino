/*******************************************************************
    Showing Real Engineering's sub count on 7 segment displays
 *                                                                 *
    Written by Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Tindie: https://www.tindie.com/stores/brianlough/
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

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

#include "Adafruit_LEDBackpack.h"
// Library used for controlling the 7 segment displays
// Can be installed from the library manager
// https://github.com/adafruit/Adafruit_LED_Backpack

#include <Adafruit_GFX.h>
// Adafruit GFX library is a dependancy for the Backpack Library
// Can be installed from the library manager
// https://github.com/adafruit/Adafruit-GFX-Library

// I2C address of the display.  Stick with the default address of 0x70
// unless you've changed the address jumpers on the back of the display.
#define DISPLAY_ONE_ADDRESS   0x70
#define DISPLAY_TWO_ADDRESS   0x71


// Create display and DS1307 objects.  These are global variables that
// can be accessed from both the setup and loop function below.
Adafruit_7segment displayOne = Adafruit_7segment(); // Left display
Adafruit_7segment displayTwo = Adafruit_7segment(); // Right display

// ----------------------------
// Config - Replace These
// ----------------------------

char ssid[] = "SSID";       // your network SSID (name)
char password[] = "password";  // your network key
#define API_KEY "GOOGLE_API_KEY_GOES_HERE"  // your google apps API Token

// The Real Engineering's Channel ID
#define CHANNEL_ID "UCR1IuLEqb6UEA_zQ81kwXfg" // makes up the url of channel


WiFiClientSecure client;
YoutubeApi api(API_KEY, client);

unsigned long timeBetweenRequests = 60000; // 1 minute
unsigned long apiRequestDue = 0; // When API request is next Due

long subs = 0;

void setup() {

  Serial.begin(115200);

  displayOne.begin(DISPLAY_ONE_ADDRESS);
  displayTwo.begin(DISPLAY_TWO_ADDRESS);

  displayOne.setBrightness(15); // Max brigthness
  displayTwo.setBrightness(15);

  displayOne.clear();
  displayTwo.clear();
  displayOne.writeDisplay();
  displayTwo.writeDisplay();

  delay(100);
  //  displayOne.print(1234, DEC);
  //  displayTwo.print(5678, DEC);
  //  displayOne.writeDisplay();
  //  displayTwo.writeDisplay();

  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  //  displayOne.clear();
  //  displayOne.writeDisplay();
  //  displayTwo.print(1, DEC);
  //  displayTwo.writeDisplay();

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  //  displayTwo.print(2, DEC);
  //  displayTwo.writeDisplay();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  //Comment out if you are using an earlier version of ESP8266
  client.setInsecure();

  delay(100);
}

void displaySubCount(long subCount) {

  long leastSignificantDigits = subCount % 10000;
  long mostSignificantDigits = subCount / 10000;
  displayOne.print(mostSignificantDigits, DEC);
  if (mostSignificantDigits < 1000) {
    displayOne.writeDigitNum(0, 0); //Padding with a 0 so it doesnt look not centered
  }
  displayTwo.print(leastSignificantDigits, DEC);
  if (leastSignificantDigits < 999) {
    displayTwo.writeDigitNum(0, 0);
    if (leastSignificantDigits < 99) {
      displayTwo.writeDigitNum(1, 0);
      if (leastSignificantDigits < 9) {
        displayTwo.writeDigitNum(2, 0);
      }
    }
  }
  displayOne.writeDisplay();
  displayTwo.writeDisplay();
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

      displaySubCount(api.channelStats.subscriberCount);
    } else {
      Serial.println("YT data fetch failed");
    }
    apiRequestDue = millis() + timeBetweenRequests;
  }
}

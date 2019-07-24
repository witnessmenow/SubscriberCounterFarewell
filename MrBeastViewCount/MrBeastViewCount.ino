/*******************************************************************
   A device for showing Mr Beast's logo on 2 64x32 RGB LED Matrix

   Built using an ESP32 and using my own ESP32 Matrix Shield
   https://www.tindie.com/products/brianlough/esp32-matrix-shield-mini-32/

   By Brian Lough
   YouTube: https://www.youtube.com/brianlough
   Tindie: https://www.tindie.com/stores/brianlough/
   Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

#include "image.h"

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <WiFi.h>
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

#define double_buffer // this must be enabled to stop flickering
#include <PxMatrix.h>
// The library for controlling the LED Matrix
//
// At time of writing this the double_buffer
// Have been merged into the main PxMatrix library,
// but have not been released, so you will need to install
// from Github
//
// https://github.com/2dom/PxMatrix

// Adafruit GFX library is a dependancy for the PxMatrix Library
// Can be installed from the library manager
// https://github.com/adafruit/Adafruit-GFX-Library

// ----------------------------
// Wiring and Display setup
// ----------------------------

#define P_LAT 22
#define P_A 19
#define P_B 23
#define P_C 18
#define P_D 5
#define P_E 15
#define P_OE 2
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// This defines the 'on' time of the display is us. The larger this number,
// the brighter the display. If too large the ESP will crash
uint8_t display_draw_time = 10; //10-50 is usually fine

//PxMATRIX display(matrix_width, matrix_height, P_LAT, P_OE, P_A, P_B, P_C);
//PxMATRIX display(64,32,P_LAT, P_OE,P_A,P_B,P_C,P_D);
PxMATRIX display(128, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D, P_E);

// Some standard colors
uint16_t myRED = display.color565(255, 0, 0);
uint16_t myGREEN = display.color565(0, 255, 0);
uint16_t myBLUE = display.color565(0, 0, 255);
uint16_t myWHITE = display.color565(255, 255, 255);
uint16_t myYELLOW = display.color565(255, 255, 0);
uint16_t myCYAN = display.color565(0, 255, 255);
uint16_t myMAGENTA = display.color565(255, 0, 255);
uint16_t myBLACK = display.color565(0, 0, 0);

bool finishedAnimating = false;
unsigned long resetAnimationDue = 0;

//------- Replace the following! ------
char ssid[] = "SSID";       // your network SSID (name)
char password[] = "password";  // your network key
#define API_KEY "GOOGLE_API_KEY_GOES_HERE"  // your google apps API Token


// Mr Beast's Channel ID
#define CHANNEL_ID "UCX6OQ3DkcsbYNE6H8uQQuVA" // Had to use this to get it: https://commentpicker.com/youtube-channel-id.php

WiFiClientSecure client;
YoutubeApi api(API_KEY, client);

unsigned long timeBetweenRequests = 60000; // 1 minute
unsigned long apiRequestDue = 0; // When API request is next Due

String viewCount = "";

void IRAM_ATTR display_updater() {
  display.display(display_draw_time);
}


void display_update_enable(bool is_enable)
{
  if (is_enable)
  {
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &display_updater, true);
    timerAlarmWrite(timer, 2000, true);
    timerAlarmEnable(timer);
  }
  else
  {
    timerDetachInterrupt(timer);
    timerAlarmDisable(timer);
  }
}

// Will center the given text
void displayText(String text, int yPos) {
  int16_t  x1, y1;
  uint16_t w, h;
  display.setTextSize(2);
  char charBuf[text.length() + 1];
  text.toCharArray(charBuf, text.length() + 1);
  display.setTextSize(1);
  display.getTextBounds(charBuf, 0, yPos, &x1, &y1, &w, &h);
  int startingX = 65 - (w / 2);
  display.setTextSize(1);
  display.setCursor(startingX, yPos);
  //Serial.println(startingX);
  //Serial.println(yPos);
  display.print(text);
}

void drawImage(int x, int y)
{
  int imageHeight = 29;
  int imageWidth = 128;
  int counter = 0;
  for (int yy = 0; yy < imageHeight; yy++)
  {
    for (int xx = 0; xx < imageWidth; xx++)
    {
      display.drawPixel(xx + x , yy + y, mrBeast[counter]);
      counter++;
    }
  }
}

void drawStuff(int x, int y)
{
  // Not clearing the display and redrawing it when you
  // dont need to improves how the refresh rate appears
  if (!finishedAnimating) {

    // Step 1: Clear the display
    display.clearDisplay();

    // Step 2: Draw the Image
    drawImage(x, y);

    // Step 3: Draw The Sub Count
    display.setTextColor(myMAGENTA);
    displayText(viewCount, 24);

    // Step 4: Display the buffer
    display.showBuffer();
  }
}

void setup() {
  Serial.begin(115200);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  /* Explicitly set the ESP32 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
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

  // Define your display layout here, e.g. 1/8 step
  display.begin(16);
  display.setPanelsWidth(2);

  // Define your scan pattern here {LINE, ZIGZAG, ZAGGIZ, WZAGZIG, VZAG} (default is LINE)
  //display.setScanPattern(LINE);

  // Define multiplex implemention here {BINARY, STRAIGHT} (default is BINARY)
  //display.setMuxPattern(BINARY);

  display.setFastUpdate(true);
  display.clearDisplay();
  display_update_enable(true);
  display.showBuffer();

}

void drawAll() {
  for (int i = 32; i >= -2; i--) {
    drawStuff(-1, i);
    delay(100);
  }
}

String getCommas(String number) {
  int commaCount = (number.length() - 1) / 3;
  String commaViewCount = "";
  commaViewCount.reserve(50);
  int commaOffsetIndex = 0;
  for (int j = 0; j < commaCount; j++) {
    commaOffsetIndex = number.length() - 3;
    commaViewCount = "," + number.substring(commaOffsetIndex) + commaViewCount;
    number.remove(commaOffsetIndex);
  }

  commaViewCount = number + commaViewCount;
  
  return commaViewCount;
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

      viewCount = getCommas(String(api.channelStats.subscriberCount));
      //viewCount = getCommas(api.channelStats.viewCount);
      drawAll();
    }
    apiRequestDue = millis() + timeBetweenRequests;
  }
}

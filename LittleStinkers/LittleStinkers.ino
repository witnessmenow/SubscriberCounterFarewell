/*******************************************************************
    Showing Drew Gooden's little stinkers on a 64x64 RGB LED Matrix
 *                                                                 *
    Written by Brian Lough
    YouTube: https://www.youtube.com/brianlough
    Tindie: https://www.tindie.com/stores/brianlough/
    Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

// ----------------------------
// Standard Libraries - Already Installed if you have ESP32 set up
// ----------------------------

#include <Ticker.h>
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
// Config - Replace These
// ----------------------------

char ssid[] = "SSID";       // your network SSID (name)
char password[] = "password";  // your network key
#define API_KEY "GOOGLE_API_KEY_GOES_HERE"  // your google apps API Token

// The Drew,s Channel ID
#define CHANNEL_ID "UCTSRIY3GLFYIpkR2QwyeklA" // From the URL

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
PxMATRIX display(64, 64, P_LAT, P_OE, P_A, P_B, P_C, P_D, P_E);

// Some standard colors
uint16_t myRED = display.color565(255, 0, 0);
uint16_t myGREEN = display.color565(0, 255, 0);
uint16_t myBLUE = display.color565(0, 0, 255);
uint16_t myWHITE = display.color565(255, 255, 255);
uint16_t myYELLOW = display.color565(255, 255, 0);
uint16_t myCYAN = display.color565(0, 255, 255);
uint16_t myMAGENTA = display.color565(255, 0, 255);
uint16_t myBLACK = display.color565(0, 0, 0);

Ticker animation_ticker;
bool finishedAnimating = false;
unsigned long resetAnimationDue = 0;

WiFiClientSecure client;
YoutubeApi api(API_KEY, client);

unsigned long timeBetweenRequests = 60000; // 1 minute
unsigned long apiRequestDue = 0; // When API request is next Due

String subCount = "";

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
void displayText(String text, int yPos, int textSize = 1) {
  int16_t  x1, y1;
  uint16_t w, h;
  display.setTextSize(textSize);
  char charBuf[text.length() + 1];
  text.toCharArray(charBuf, text.length() + 1);
  display.getTextBounds(charBuf, 0, yPos, &x1, &y1, &w, &h);
  int startingX = 33 - (w / 2);
  display.setCursor(startingX, yPos);
  Serial.println(startingX);
  Serial.println(yPos);
  display.print(text);
}

void drawStuff()
{
  // Not clearing the display and redrawing it when you
  // dont need to improves how the refresh rate appears
  if (!finishedAnimating) {

    // Step 1: Clear the display
    display.clearDisplay();

    // Step 3: Draw The Sub Count
    display.setTextColor(myCYAN);
    displayText("Number of", 2);
    displayText("channels", 10);
    display.setTextColor(myRED);
    displayText("1", 20, 2);

    display.setTextColor(myCYAN);
    displayText("Little", 37);
    displayText("Stinkers", 45);
    display.setTextColor(myRED);
    displayText(subCount, 54);

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
  display.begin(32);

  // Define your scan pattern here {LINE, ZIGZAG, ZAGGIZ, WZAGZIG, VZAG} (default is LINE)
  //display.setScanPattern(LINE);

  // Define multiplex implemention here {BINARY, STRAIGHT} (default is BINARY)
  //display.setMuxPattern(BINARY);

  display.setFastUpdate(true);
  display.clearDisplay();
  display.setTextColor(myRED);
  display.setCursor(2, 0);
  display.print("Sub");
  display.setCursor(2, 8);
  display.print("counter");
  display.setCursor(2, 16);
  display.print("works");
  display.setCursor(2, 24);
  display.print("ahead");

  display.setTextColor(myMAGENTA);
  display.setCursor(2, 40);
  display.print("I sure");
  display.setCursor(2, 48);
  display.print("hope");
  display.setCursor(2, 56);
  display.print("it does");
  display_update_enable(true);
  display.showBuffer();

  delay(3000);
  drawStuff();
}

String getCommas(String number) {
  int commaCount = (number.length() - 1) / 3;
  String numberWithCommas = "";
  numberWithCommas.reserve(50);
  int commaOffsetIndex = 0;
  for (int j = 0; j < commaCount; j++) {
    commaOffsetIndex = number.length() - 3;
    numberWithCommas = "," + number.substring(commaOffsetIndex) + numberWithCommas;
    number.remove(commaOffsetIndex);
  }

  numberWithCommas = number + numberWithCommas;
  
  return numberWithCommas;
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

      subCount = getCommas(String(api.channelStats.subscriberCount));

      drawStuff();
    } else {
      Serial.println("YT data fetch failed");
    }
    apiRequestDue = millis() + timeBetweenRequests;
  }
}

#include <led.h>

void AqaLeds::setupLeds() {
  #ifdef NUEVATARJETA
  FastLED.addLeds<LED_TYPE,LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  #else
  FastLED.addLeds<LPD8806, DI, CI, COLOR_ORDER>(leds, NUM_LEDS);
  #endif
}

void AqaLeds::ledParticulateQuality(plantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;
 
if(pm25 < 13){
     //alert = CRGB::Green; // CRGB::Green; // Alert.ok
      int color=255*pm25/13;
       alert = CRGB(0,color,0);
       DMSG_STR(color);
   }
  if(pm25 >= 13 && pm25 < 35) {
    //  alert = CRGB::Gold; // Alert.notGood;
      int color=255*pm25/35;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 35 && pm25 < 55) {
      //alert = CRGB::OrangeRed; // Alert.bad;
      int color=150*pm25/55;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 55 && pm25 < 75) {
    //alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
      int color=255*pm25/75;
       alert = CRGB(color,0,0);
       DMSG_STR(color);
  }
  if(pm25 >= 75 && pm25 < 255)  {
    //alert = CRGB::Purple;  // CRGB::Purple; // Alert.VeryDangerous;
      int color=180*pm25/255;
       alert = CRGB(175,0,color);
       DMSG_STR(color);
  }



  if (pm25>= 255) alert = CRGB::Brown; // Alert.harmful;
  
  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    for(int j=0; j < NUM_LEDS; j++) leds[j] = i%2 == 0 ? alert : CRGB::Black;// para el kit diadactico y los 64 leds
    /*#ifdef NUEVATARJETA
    leds[0] = leds[1] = leds[2] = i%2 == 0 ? alert : CRGB::Black;
    #else
    leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
    #endif*/
    FastLED.show();
    FastLED.delay(300);
  }
}

void AqaLeds::ledParticulateQuality2(plantowerData data) {
    int pm1 = data.pm1;
    int pm25 = data.pm25;
    int pm10 = data.pm10;

    CRGB alert = CRGB::Black;


if(pm25 < 13){
     //alert = CRGB::Green; // CRGB::Green; // Alert.ok
      int color=255*pm25/13;
       alert = CRGB(0,color,0);
       DMSG_STR(color);
   }
  if(pm25 >= 13 && pm25 < 35) {
    //  alert = CRGB::Gold; // Alert.notGood;
      int color=255*pm25/35;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 35 && pm25 < 55) {
      //alert = CRGB::OrangeRed; // Alert.bad;
      int color=150*pm25/55;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 55 && pm25 < 75) {
    //alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
      int color=255*pm25/75;
       alert = CRGB(color,0,0);
       DMSG_STR(color);
  }
  if(pm25 >= 75 && pm25 < 255)  {
    //alert = CRGB::Purple;  // CRGB::Purple; // Alert.VeryDangerous;
      int color=180*pm25/255;
       alert = CRGB(175,0,color);
       DMSG_STR(color);
  }



  if (pm25>= 255) alert = CRGB::Brown; // Alert.harmful;
  

    FastLED.setBrightness(millis() % 255);

    for(int i=0; i < 4; i++) {
    for(int j=0; j < NUM_LEDS; j++) leds[j] = i%2 == 0 ? alert : CRGB::Black;// para el kit diadactico y los 64 leds
      /*#ifdef NUEVATARJETA
      leds[0] = leds[1] = leds[2] = i%2 == 0 ? alert : CRGB::Black;
      #else
      leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
      #endif*/
      FastLED.show();
      FastLED.delay(100);
    }
}

void AqaLeds::ledParticulateQualityStreamming(plantowerData data) {
  int pm1 = data.pm1;
  int pm25 = data.pm25;
  int pm10 = data.pm10;

  CRGB alert = CRGB::Black;


if(pm25 < 13){
     //alert = CRGB::Green; // CRGB::Green; // Alert.ok
      int color=255*pm25/13;
       alert = CRGB(0,color,0);
       DMSG_STR(color);
   }
  if(pm25 >= 13 && pm25 < 35) {
    //  alert = CRGB::Gold; // Alert.notGood;
       int color=255*pm25/35;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 35 && pm25 < 55) {
      //alert = CRGB::OrangeRed; // Alert.bad;
      int color=150*pm25/55;
       alert = CRGB(255,color,0);
       DMSG_STR(color);
    }
  if(pm25 >= 55 && pm25 < 75) {
    //alert = CRGB::DarkRed; // CRGB::Red; // Alert.dangerous;
      int color=255*pm25/75;
       alert = CRGB(color,0,0);
       DMSG_STR(color);
  }
  if(pm25 >= 75 && pm25 < 255)  {
    //alert = CRGB::Purple;  // CRGB::Purple; // Alert.VeryDangerous;
      int color=180*pm25/255;
       alert = CRGB(175,0,color);
       DMSG_STR(color);
  }




  if (pm25>= 255) alert = CRGB::Brown; // Alert.harmful;
  
  FastLED.setBrightness(millis() % 255);

  for(int i=0; i < 4; i++) {
    for(int j=0; j < NUM_LEDS; j++) leds[j] = i%2 == 0 ? alert : CRGB::Black;// para el kit diadactico y los 64 leds
    /*#ifdef NUEVATARJETA
    leds[0] = leds[1] = leds[2] =  i%2 == 0 ? alert : CRGB::Black;
    #else
    leds[0] = leds[1] = i%2 == 0 ? alert : CRGB::Black;
    #endif*/
    FastLED.show();
    FastLED.delay(30);
  }
}

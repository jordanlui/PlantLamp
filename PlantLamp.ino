//#include <SPI.h>
//#include <Wire.h>
//#include <avr/pgmspace.h>
#include <Adafruit_NeoPixel.h>

// Parameter config
// The digital pin we use to control neopixel strip
#define PIN 6

// The number of pixels on the neopixel strip
#define NUMPIXELS 60

int delayval = 500; // delay for half a second

// Initial neopixel object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{

  pixels.begin(); // This initializes the NeoPixel library. 
  
}
  
void loop() 
{
    
  for(int i=0;i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255,0,255 )); // Purple light.
  }

  pixels.show(); // This sends the updated pixel color to the hardware.
  
  delay(delayval); // Delay for a period of time (in milliseconds).
  
} 

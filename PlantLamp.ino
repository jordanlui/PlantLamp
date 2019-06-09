#include <Adafruit_NeoPixel.h>

// Parameter config
#define PIN 6 // The digital pin we use to control neopixel strip
#define PinClock 7 // Timing control pin we use to control lighting using RPi. A zero means we should not activate lighting

// The number of pixels on the neopixel strip
#define NUMPIXELS 60

int delayval = 500; // delay for half a second

// Initial neopixel object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{

  pixels.begin(); // This initializes the NeoPixel library. 
  pinMode(PinClock, INPUT);
  Serial.begin(9600);
  Serial.print("Setup complete!");
  
}
  
void loop() 
{
    
  // Only activate lighting if lighting control pin IS NOT set to LOW
  Serial.print("Reading clock pin... ");
  Serial.print(digitalRead(PinClock));
  Serial.print("\n");
  
  if(digitalRead(PinClock) != LOW)
  {
    for(int i=0;i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(255,0,255 )); // Purple light.
    }
  
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  else
  {
    for(int i=0;i < NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0,0,0 )); // Purple light.
    }
  
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  
  
  delay(delayval); // Delay for a period of time (in milliseconds).
  
}

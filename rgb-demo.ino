// set a macro/pseudonym for the IO port to which LED is connected
#define RED_PIN 4
#define GREEN_PIN 5
#define BLUE_PIN 19

// RGB values for some colors for testing
#define COLORA 106, 90, 205
#define COLORB 255, 0, 0
#define COLORC 37, 99, 71

// provide RGB value of colors and rgb displays that color
void setLEDColor(int r, int g, int b)
{
  // we simply set the rgb value (r,g,b) by sending a corresponding PWM signal to the respective pins.
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

// cycles through all possible rgb (0-255 for each component) colors
void produceSpectrum()
{
  for (int i = 0; i < 255; i++)
  {
    for (int j = 0; j < 255; j++)
    {
      for (int k = 0; k < 255; k++)
      {
        setLEDColor(i, j, k);
      }
    }
  }
}

void setup()
{
  // set LED PINS to output mode
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
  setLEDColor(COLORA);
  delay(1500);
  setLEDColor(COLORB);
  delay(1500);

  produceSpectrum();
}
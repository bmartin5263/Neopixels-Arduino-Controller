#include <Arduino.h>
#include "Button.h"
#include "NeopixelRing.h"
#include "DigitalPin.h"
#include "Log.h"
#include "RingController.h"
#include "Effect.h"
#include "EffectTrailing.h"
#include "Timer.h"

constexpr int LED_PIN = 4;
constexpr int LED_COUNT = 16;

DigitalPin pin2{2};
DigitalPin pin3{3};
NeopixelRing ring{LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800};
Button nextPixelButton{&pin3};
Button nextColorButton{&pin2};
RingController<16> ringController{};
Effect effect{};
EffectTrailing effectTrailing{};

typedef struct {
  unsigned char r; // Red component [0, 255]
  unsigned char g; // Green component [0, 255]
  unsigned char b; // Blue component [0, 255]
} RGB;

double hueToRgb(double p, double q, double t) {
  if (t < 0) t += 1;
  if (t > 1) t -= 1;
  if (t < 1.0 / 6) return p + (q - p) * 6 * t;
  if (t < 1.0 / 2) return q;
  if (t < 2.0 / 3) return p + (q - p) * (2.0 / 3 - t) * 6;
  return p;
}

RGB hslToRgb(double h, double s, double l) {
  double r, g, b;

  if (s == 0) {
    // Achromatic (gray)
    r = g = b = l;
  } else {
    double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
    double p = 2 * l - q;
    r = hueToRgb(p, q, h + 1.0 / 3);
    g = hueToRgb(p, q, h);
    b = hueToRgb(p, q, h - 1.0 / 3);
  }

  // Convert to 0-255 range
  RGB rgb;
  rgb.r = (unsigned char)(r * 255);
  rgb.g = (unsigned char)(g * 255);
  rgb.b = (unsigned char)(b * 255);

  return rgb;
}

float h = 0.33; // Hue [0, 1]
float s = 1.0; // Saturation [0, 1]
float l = .5;  // Lightness [0, 1]

void setup() {
  Log::init();

  ring.init();
  ring.setBrightness(10);

  nextPixelButton.init();
  nextPixelButton.onPress([](){
    effectTrailing.move();
  });

  nextColorButton.init();
  nextColorButton.onPress([](){
    ringController.cycleColor();
  });

//  Color colors[] = {
//    Color::SALMON(),
//    Color::RED(),
//    Color::ORANGE(),
//    Color::GOLD(),
//    Color::MAROON(),
//    Color::YELLOW(),
//    Color::LIME(),
//    Color::SPRING_GREEN(),
//    Color::GREEN(),
//    Color::AQUAMARINE(),
//    Color::CYAN(),
//    Color::BLUE(),
//    Color::PURPLE(),
//    Color::VIOLET(),
//    Color::INDIGO(),
//    Color::MAGENTA(),
//  };

  Color colors[] = {
    {255, 0, 0, 0},
    {200, 55, 0, 0},
    {150, 105, 0, 0},
    {100, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
    {255, 0, 0, 0},
  };

  int counter = 0;
  for (auto& color : colors) {
//    ringController.setColor(counter++, color);
  }
}

int timer = 0;

void update() {
  Timer::Update();
  effectTrailing.update();
//  nextPixelButton.update();
//  nextColorButton.update();

  timer += 1;
  if (timer >= 8) {

    h += 0.01;
    if (h > 1.0) {
      h = 0.0;
    }

    RGB rgb = hslToRgb(h, s, l);
    Color color{rgb.r, rgb.g, rgb.b};

    for (int i = 0; i < LED_COUNT; ++i) {
      ringController.setColor(i, color);
    }

    timer = 0;
  }
}

void draw() {
  ring.clear();
//  ringController.draw(ring);
  effectTrailing.draw(ring);
  ring.draw();
}

void loop() {
  update();
  draw();
}
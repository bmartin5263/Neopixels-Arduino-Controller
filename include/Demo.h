//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_DEMO_H
#define NEOPIXELS_DEMO_H

#include "Adafruit_NeoPixel.h"
#include "Button.h"
#include "NeopixelRing.h"
#include "DigitalPin.h"
#include "Log.h"
#include "RingController.h"
#include "Effect.h"
#include "EffectTrailing.h"
#include "Timer.h"
#include "Car.h"

class Demo {
public:
  auto init() -> void;
  auto update() -> void;
  auto draw() -> void;

private:
  static constexpr int LED_PIN = 4;
  static constexpr int LED_COUNT = 16;

  NeopixelRing ring{LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800};
  Button accelerate{{3}};
  Button decelerate{{2}};
  EffectTrailing effectTrailing{};
  Car car{};
  bool accelerating{};

};

#endif //NEOPIXELS_DEMO_H

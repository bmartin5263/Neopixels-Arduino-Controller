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

class Demo {
public:
  auto init() -> void;
  auto update() -> void;
  auto draw() -> void;

private:
  static constexpr int LED_PIN = 4;
  static constexpr int LED_COUNT = 16;

  DigitalPin pin2{2};
  DigitalPin pin3{3};
  NeopixelRing ring{LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800};
  Button nextPixelButton{&pin3};
  Button nextColorButton{&pin2};
  RingController<16> ringController{};
  Effect effect{};
  EffectTrailing effectTrailing{};

};

#endif //NEOPIXELS_DEMO_H

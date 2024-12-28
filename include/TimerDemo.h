//
// Created by Brandon on 12/27/24.
//

#ifndef NEOPIXELS_TIMERDEMO_H
#define NEOPIXELS_TIMERDEMO_H

#include "NeopixelRing.h"
#include "Button.h"
#include "TimerId.h"
#include "TimerAction.h"
#include "TrailingColorGenerator.h"
#include "TrailingEffect.h"
#include "ColorGenerators.h"

class TimerDemo {
public:
  auto init() -> void;
  auto destroy() -> void;
  auto update() -> void;
  auto draw() -> void;

  auto setOn(bool value) -> void;

private:
  static constexpr int LED_PIN = 4;
  static constexpr int LED_COUNT = 16;

  NeopixelRing ring{LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800};
  Button button1{{2}};
  Button button2{{3}};
  TimerId timerId{};
  BlueRedGenerator colorGenerator{};
  RainbowGenerator colorGenerator2{};
  TrailingColorGenerator* current{&colorGenerator};
  TrailingEffect trailingEffect{};
  bool on{};
};

#endif //NEOPIXELS_TIMERDEMO_H

//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_APP_H
#define NEOPIXELS_APP_H

#include "TimerDemo.h"

class App {
public:
  auto init() -> void;
  auto loop() -> void;

private:
  TimerDemo demo{};

  auto update() -> void;
  auto draw() -> void;
  auto updateSubsystems() -> void;

  static constexpr u32 MAX_MS = 5; // ~200 FPS
};

#endif //NEOPIXELS_APP_H

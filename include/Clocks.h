//
// Created by Brandon on 12/25/24.
//

#ifndef NEOPIXELS_CLOCKS_H
#define NEOPIXELS_CLOCKS_H

#include "Types.h"

class Clocks {
public:
  static auto NextTick() -> void;
  static auto GlobalTime() -> u32;
  static auto GlobalFps() -> u32;

private:
  u32 global{};
  u32 globalFpsCounter{};
  u32 lastTimeMs{};
  float fps{};

  auto nextTick() -> void;
  auto globalTime() -> u32;
  auto globalFps() -> u32;

  static Clocks& Instance();
};

#endif //NEOPIXELS_CLOCKS_H

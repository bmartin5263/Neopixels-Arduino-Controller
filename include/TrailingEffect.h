//
// Created by Brandon on 12/26/24.
//

#ifndef NEOPIXELS_TRAILINGEFFECT_H
#define NEOPIXELS_TRAILINGEFFECT_H

#include "Types.h"

class TrailingColorGenerator;
class NeopixelLine;
class TrailingEffect {
public:
  auto init(TrailingColorGenerator& colorGenerator, u8 length, u8 speed) -> void;
  auto update() -> void;
  auto draw(NeopixelLine& line) -> void;

  auto setPhase(u16 phase) -> void;

private:
  TrailingColorGenerator* colorGenerator{};
  u8 length{};
  u8 speed{};
  u16 phase{};
};

#endif //NEOPIXELS_TRAILINGEFFECT_H

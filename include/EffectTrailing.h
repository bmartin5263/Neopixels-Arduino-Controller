//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_EFFECTTRAILING_H
#define NEOPIXELS_EFFECTTRAILING_H

#include "Color.h"

class NeopixelLine;
class EffectTrailing {
public:
  auto update() -> void;
  auto draw(NeopixelLine& ring) -> void;
  auto setMoveRate(int value) -> void;
  auto setColor(const Color& value) -> void;
  auto move() -> void;

private:
  Color color{Color::RED()};
  float h{};
  int moveTime{};
  int moveRate{50};
  int hueTime{};
  int pixel{};
};

#endif //NEOPIXELS_EFFECTTRAILING_H

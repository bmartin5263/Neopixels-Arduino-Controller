//
// Created by Brandon on 12/24/24.
//

#ifndef NEOPIXELS_EFFECTTRAILING_H
#define NEOPIXELS_EFFECTTRAILING_H

#include "Color.h"

class NeopixelRing;
class EffectTrailing {
public:
  auto update() -> void;
  auto draw(NeopixelRing& ring) -> void;
  auto setColor(const Color& color) -> void;
  auto move() -> void;

private:
  double h{};
  int moveTime{};
  int cycleTime{};
  int hueTime{};
  int pixel{};
  int cycle{};
};

#endif //NEOPIXELS_EFFECTTRAILING_H
